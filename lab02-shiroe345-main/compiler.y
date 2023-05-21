/* Please feel free to modify any content */

/* Definition section */
%{
    #include "compiler_common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    static void create_symbol();
    static void insert_symbol();
    static void lookup_symbol();
    static void dump_symbol();

    /* Global variables */
    bool HAS_ERROR = false;
    static int scope_level = -1;
    static int addr = -1;
    char type[10];

    struct Symbol{
        char name[1000][100];
        int mut[1000];
        char type[1000][10];
        int addr[1000];
        int lineno[1000];
        char func_sig[1000][100];
        int size;
    };

    typedef struct Symbol symbol;

    symbol stack[100];
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 *  - you can add new fields if needed.
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
    /* ... */
}

/* Token without return */
%token LET MUT NEWLINE
%token INT FLOAT BOOL STR
%token TRUE FALSE
%token GEQ LEQ EQL NEQ LOR LAND
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN REM_ASSIGN
%token IF ELSE FOR WHILE LOOP
%token PRINT PRINTLN
%token FUNC RETURN BREAK
%token ID ARROW AS IN DOTDOT RSHIFT LSHIFT
%token IDENT

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <s_val> STRING_LIT
%token <f_val> FLOAT_LIT

/* Nonterminal with return, which need to sepcify type */
%type <s_val> Type

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : GlobalStatementList 
;

GlobalStatementList 
    : GlobalStatementList GlobalStatement
    | GlobalStatement
;

GlobalStatement
    : FunctionDeclStmt { dump_symbol(); }
    | declaration
    | NEWLINE {}
;

FunctionDeclStmt
    : declaration_specifiers declarator declaration_list compound_statement 
	| declaration_specifiers declarator compound_statement 
	| declarator declaration_list compound_statement 
	| declarator compound_statement 
;

primary_expression
	: IDENT { printf("IDENT (name=%s, address=%d)\n", $<s_val>1, ++addr); }
    | INT_LIT { printf("INT_LIT %d\n", $<i_val>1); strcpy(type, "i32");}
	| STRING_LIT { printf("STRING_LIT %s\n", $<s_val>1); strcpy(type, "str"); }
    | FLOAT_LIT { printf("FLOAT_LIT %f\n", $<f_val>1); strcpy(type, "f32"); }
	| '(' expression ')'
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENT
	| postfix_expression ARROW IDENT
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| unary_operator cast_expression
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LSHIFT additive_expression
	| shift_expression RSHIFT additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LEQ shift_expression
	| relational_expression GEQ shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQL relational_expression
	| equality_expression NEQ relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression LAND inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression LOR logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '='
	| ADD_ASSIGN
	| SUB_ASSIGN
    | MUL_ASSIGN
	| DIV_ASSIGN
    | REM_ASSIGN
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;

declaration_specifiers
	: type_specifier
	| type_specifier declaration_specifiers
    | func_specifier 
    | func_specifier declaration_specifiers 
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	| declarator '=' initializer 
	;

func_specifier
    : FUNC { printf("func: "); strcpy(type, "func"); }
    ;

type_specifier
	: INT 
	| FLOAT 
    | BOOL 
    | STR
	| Type
	;

Type
    :

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;

direct_declarator
	: IDENT { printf("%s\n", $<s_val>1);
            if(strcmp(type, "func") == 0){
                insert_symbol($<s_val>1, -1);
                create_symbol();
            }
    }
	| '(' declarator ')'
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' ')'
	;

pointer
	: '*'
	| '*' pointer
	;

parameter_type_list
	: parameter_list
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENT
	| identifier_list ',' IDENT
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

statement
	: labeled_statement
	| compound_statement 
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
    | print_statement
	;

labeled_statement
	: IDENT ':' statement
	;

compound_statement
	: '{' '}' 
	| '{' statement_list '}' 
	| '{' declaration_list '}' 
	| '{' declaration_list statement_list '}' 
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement
	| IF '(' expression ')' statement ELSE statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	;

jump_statement
	: BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

print_statement
    : PRINT '(' expression ')' ';' { printf("PRINT %s\n", type); }
    | PRINTLN '(' expression ')' ';' { printf("PRINTLN %s\n", type); }
    ;

%%

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    create_symbol();
    yylineno = 0;
    yyparse();
    dump_symbol();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

static void create_symbol() {
    printf("> Create symbol table (scope level %d)\n", ++scope_level);
    stack[scope_level].size = 0;
}
static void insert_symbol(char *str, int addr) {
    printf("> Insert `%s` (addr: %d) to scope level %d\n", str, addr, scope_level);
    int cur_size = stack[scope_level].size;
    strcpy(stack[scope_level].name[cur_size], str);
    stack[scope_level].mut[cur_size] = strcmp(type, "func") ? 0 : -1;  
    strcpy(stack[scope_level].type[cur_size], type);
    stack[scope_level].addr[cur_size] = strcmp(type, "func") ? addr++ : -1;  
    stack[scope_level].lineno[cur_size] = yylineno+1;
    strcpy(stack[scope_level].func_sig[cur_size], strcmp(type, "func") ? "-" : "(V)V" );
    stack[scope_level].size++;
}

static void lookup_symbol() {
}

static void dump_symbol() {
    printf("\n> Dump symbol table (scope level: %d)\n", scope_level);
    printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
        "Index", "Name", "Mut","Type", "Addr", "Lineno", "Func_sig");
    for(int i = 0;i<stack[scope_level].size;i++){
        printf("%-10d%-10s%-10d%-10s%-10d%-10d%-10s\n",
                i, stack[scope_level].name[i], stack[scope_level].mut[i], stack[scope_level].type[i], stack[scope_level].addr[i], stack[scope_level].lineno[i], stack[scope_level].func_sig[i]); 
    }
    scope_level--;
}
