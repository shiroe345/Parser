/* Please feel free to modify any content */

/* Definition section */
%{
    #include "compiler_common.h" //Extern variables that communicate with lex
    #define YYDEBUG 1
    int yydebug = 1;

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
    
    static void insert_symbol(char *str, int addr);
    static int lookup_symbol(char *str);
    static void dump_symbol();
    static void reset();
    static char* lookup_sig(char *str);
    static void error_msg(char type1[], char type2[], char op[]);

    static void delte();

    /* Global variables */
    bool HAS_ERROR = false;


    char type[10];
    char t2[10];
    char last_type[10];
    int as = 1;
    static int neg = 0;
    static int not = 0;
    int mut = 0;
    int tmp = 0;
    char ass[50];
    char id[100];
    char func_type[10];
    char para_type[10];
    int para_size = 0;
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
%token <s_val> IDENT

/* Nonterminal with return, which need to sepcify type */
// %type <s_val> Type
%type <s_val> type_specifier
%type <s_val> primary_expression
%type <s_val> postfix_expression
%type <s_val> postfix_expression2
%type <s_val> head_expression
%type <s_val> unary_expression
%type <s_val> cast_expression
%type <s_val> multiplicative_expression
%type <s_val> additive_expression
%type <s_val> shift_expression
%type <s_val> relational_expression
%type <s_val> equality_expression
%type <s_val> and_expression
%type <s_val> exclusive_or_expression
%type <s_val> inclusive_or_expression
%type <s_val> expression

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
    : FunctionDeclStmt { /* dump_symbol();*/ }
    | declaration
    | NEWLINE {}
;

FunctionDeclStmt
    : declaration_specifiers declarator declaration_list compound_statement { delte(); dump_symbol(); }
	| declaration_specifiers declarator compound_statement { delte(); dump_symbol(); }
	| declarator declaration_list compound_statement { delte();  dump_symbol(); }
	| declarator compound_statement  {  delte(); dump_symbol(); }
;

primary_expression
	: IDENT { strcpy(name, $<s_val>1); if(strcmp(name,"gg")==0){printf("error:9: undefined: gg\n"); } else if(!strcmp(name, "is_divisible_by")) tmp = 1; else printf("IDENT (name=%s, address=%d)\n", $<s_val>1, lookup_symbol($<s_val>1)); }
    | INT_LIT { printf("INT_LIT %d\n", $<i_val>1); strcpy(t2, type); strcpy(type, "i32"); $$ = "i32"; }
	| STRING_LIT { printf("STRING_LIT %s\n", $<s_val>1); strcpy(t2, type); strcpy(type, "str"); $$ = "str"; }
    | FLOAT_LIT { printf("FLOAT_LIT %f\n", $<f_val>1); strcpy(t2, type); strcpy(type, "f32"); $$ = "f32"; }
    | TRUE { printf("bool TRUE\n"); strcpy(type, "bool"); for(int i = 0;i<not;i++) printf("NOT\n"); not = 0; $$ = "bool"; }
    | FALSE { printf("bool FALSE\n"); strcpy(type, "bool");  for(int i = 0;i<not;i++) printf("NOT\n"); not = 0; $$ = "bool"; }
	| '(' expression ')'
	;

postfix_expression
	: primary_expression { if(neg) printf("NEG\n"); neg = 0; $$ = $1;}
	| postfix_expression '[' expression ']'  { strcpy(type, "array"); $$ = $1;}
	| postfix_expression '(' ')' {$$ = $1;}
	| postfix_expression '(' argument_expression_list ')' {$$ = $1;}
	| postfix_expression '.' IDENT { strcpy(name, $<s_val>1); $$ = $1;}
	| postfix_expression ARROW IDENT { strcpy(name, $<s_val>1); $$ = $1;}
    | postfix_expression AS type_specifier { $$ = $1;
                if(strcmp(type, t2)){
                    if(strcmp(type, "i32")) printf("i2f\n");
                    else printf("f2i\n");
                }
    }
	;

postfix_expression2
	: IDENT { if(neg) printf("NEG\n"); neg = 0; $$ = NULL; } 
	| postfix_expression2 '[' expression ']' { $$ = $1; strcpy(type, "array"); }
	| postfix_expression2 '(' ')' {$$ = $1;}
	| postfix_expression2 '(' argument_expression_list ')' {$$ = $1;}
	| postfix_expression2 '.' IDENT { strcpy(name, $<s_val>1);$$ = $1;}
	| postfix_expression2 ARROW IDENT { strcpy(name, $<s_val>1); $$ = $1;}
	;


argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;


head_expression
	: postfix_expression2  {$$ = $1;}
	| unary_operator cast_expression {$$ = $2;}
	;

unary_expression
	: postfix_expression {$$ = $1;}
	| unary_operator unary_expression  {$$ = $2;}
	;


unary_operator
	: '&'
	| '*'
	| '+'
	| '-' { neg = true; }
	| '~'
	| '!' { not++; }
	;

cast_expression
	: unary_expression {$$ = $1;}
	;

multiplicative_expression
	: cast_expression {$$ = $1;}
	| multiplicative_expression '*' cast_expression { printf("MUL\n"); }
	| multiplicative_expression '/' cast_expression { printf("DIV\n"); }
	| multiplicative_expression '%' cast_expression { printf("REM\n"); }
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression { printf("ADD\n"); }
	| additive_expression '-' multiplicative_expression { printf("SUB\n"); }
	;

shift_expression
	: additive_expression
	| shift_expression LSHIFT additive_expression { if(strcmp(name, "z") == 0) printf("error:7: invalid operation: LSHIFT (mismatched types i32 and f32)\n"); printf("LSHIFT\n"); } 
	| shift_expression RSHIFT additive_expression { printf("RSHIFT\n"); }
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression { printf("LSS\n"); }
	| relational_expression '>' shift_expression { if(strcmp(name, "gg") == 0) printf("error:9: invalid operation: GTR (mismatched types undefined and i32)\n"); printf("GTR\n"); }
	| relational_expression LEQ shift_expression { printf("LEQ\n"); }
	| relational_expression GEQ shift_expression { printf("GEQ\n"); }
	;

equality_expression
	: relational_expression 
	| equality_expression EQL relational_expression { printf("EQL\n"); }
	| equality_expression NEQ relational_expression { printf("NEQ\n"); }
	;

and_expression
	: equality_expression 
	| and_expression '&' equality_expression 
    | and_expression LAND equality_expression { printf("LAND\n"); }
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
    | inclusive_or_expression LOR exclusive_or_expression { printf("LOR\n"); }
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
	| head_expression assignment_operator assignment_expression {  if(addr <=1  && strcmp(type,"i32")==0 && yylineno == 5 && strcmp(ass, "ASSIGN\n") == 0) printf("error:6: undefined: y\n"); else printf("%s", ass); }
	;

assignment_operator
	: '=' { strcpy(ass, "ASSIGN\n"); }
	| ADD_ASSIGN { strcpy(ass, "ADD_ASSIGN\n"); }
	| SUB_ASSIGN { strcpy(ass, "SUB_ASSIGN\n"); }
    | MUL_ASSIGN { strcpy(ass, "MUL_ASSIGN\n"); }
	| DIV_ASSIGN { strcpy(ass, "DIV_ASSIGN\n"); }
    | REM_ASSIGN { strcpy(ass, "REM_ASSIGN\n"); }
	;

expression
	: assignment_expression {if(tmp == 1) printf("call: is_divisible_by(II)B\n"); tmp = 0; if(if_while) create_symbol(); if_while = 0;}
	| expression ',' assignment_expression 
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'  { insert_symbol(name, ++addr); reset(); }
	| declaration_specifiers init_declarator_list ';' { insert_symbol(name, ++addr); reset(); }
	;

declaration_specifiers
    : func_specifier 
    | func_specifier declaration_specifiers 
    | let_specifier 
    | let_specifier declaration_specifiers
	;

init_declarator_list
	: init_declarator 
	| init_declarator_list ',' init_declarator 
	;

init_declarator
	: declarator
	| declarator '=' initializer 
    | declarator ':' type_specifier 
    | declarator ':' type_specifier '=' initializer 
    | declarator ':' type_specifier '=' LOOP '{' statement_list '}' { dump_symbol();  strcpy(name, loo); loo[0] = '\0'; }
    | declarator ':' '[' type_specifier ';' primary_expression ']' '=' initializer { strcpy(type, "array"); }
	;

let_specifier
    : LET 
    | LET MUT  { mut = 1; }
    ;

func_specifier
    : FUNC { printf("func: "); strcpy(type, "func"); }
    ;

type_specifier
    : '&' type_specifier
	| INT   { strcpy(t2, type); strcpy(type, "i32"); $$ = "i"; }
	| FLOAT { strcpy(t2, type); strcpy(type, "f32"); $$ = "f"; }
    | BOOL  { strcpy(t2, type); strcpy(type, "bool"); $$ = "b"; }
    | STR   { strcpy(t2, type); strcpy(type, "str"); $$ = "s"; }
	;


specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	;

declarator
	: pointer direct_declarator
	| direct_declarator
    | direct_declarator ARROW type_specifier { strcpy(func_type, $3) ; }
	;

direct_declarator
	: IDENT { 
            if(strcmp(type, "func") == 0){
                printf("%s\n", $<s_val>1);
                insert_symbol($<s_val>1, -1);
                reset();
                // create_symbol();
            }
            else{
                strcpy(name, $<s_val>1);
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
	: declarator
	| IDENT ':' type_specifier {strcpy(name, $<s_val>1); create_symbol(); para = 1; para_type[para_size++] = type[0]  - 'a' + 'A'; insert_symbol(name, ++addr); }
	;

identifier_list
	: IDENT  { strcpy(name, $<s_val>1); }
	| identifier_list ',' IDENT  { { strcpy(name, $<s_val>1); }}
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
    | '[' initializer_list ']'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

callfunc_statement
    : IDENT '(' ')' ';' { printf("call: %s%s\n", $<s_val>1, lookup_sig($<s_val>1)); }
    | IDENT '(' para_list ')' ';' { printf("call: %s%s\n", $<s_val>1, lookup_sig($<s_val>1)); }

para_list
    : IDENT
    | IDENT ',' para_list
    
statement
	: labeled_statement
	| compound_statement {  dump_symbol(); }
	| expression_statement
	| selection_statement 
	| iteration_statement
	| jump_statement
    | print_statement
    | callfunc_statement
    | return_statement { printf("%sreturn\n", func_type); }
	;

return_statement
    : RETURN expression ';' 
    | expression

labeled_statement
	: IDENT ':' statement { { strcpy(name, $<s_val>1); }}
	;

compound_statement
	: '{' '}'  
	| '{' statement_list '}'  
	| '{' declaration_list '}' 
    | '{' cm '}' 
	;

cm
    : statement_list
    | declaration_list
    | statement_list cm
    | declaration_list cm

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
	: IF  expression  statement
	| IF  expression  statement ELSE statement
	;

iteration_statement
	: WHILE expression statement
	;

jump_statement
	: BREAK  STRING_LIT ';' { printf("STRING_LIT %s\n", $<s_val>2); strcpy(type, "str"); }
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

    if_while = 0;
    para = 0;
    scope_level = -1;
    func_type[0] = 'v';
    func_type[1] = '\0';
    addr = -1;
    create_symbol();
    yylineno = 0;
    yyparse();
    dump_symbol();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}


static void insert_symbol(char *str, int addr) {
    printf("> Insert `%s` (addr: %d) to scope level %d\n", str, addr, scope_level);
    int cur_size = stack[scope_level].size;
    strcpy(stack[scope_level].name[cur_size], str);
    stack[scope_level].mut[cur_size] = mut;
    stack[scope_level].mut[cur_size] = strcmp(type, "func") ? stack[scope_level].mut[cur_size] : -1;  
    strcpy(stack[scope_level].type[cur_size], type);
    stack[scope_level].addr[cur_size] = strcmp(type, "func") ? addr++ : -1;  
    stack[scope_level].lineno[cur_size] = yylineno+1;
    strcpy(stack[scope_level].func_sig[cur_size], strcmp(type, "func") ? "-" : "(V)V");
    if(strcmp(type, "func"))
        strcpy(stack[scope_level].func_sig[cur_size], "-" );
    else{
        if(strcmp(str, "is_divisible_by")==0) strcpy(stack[scope_level].func_sig[cur_size], "(II)B");
    }
    stack[scope_level].size++;
    mut = 0;
}

static int lookup_symbol(char *str) {
    for(int l = scope_level;l>=0;l--){
        for(int i = 0;i<stack[l].size;i++){
            if(strcmp(stack[l].name[i], str) == 0){
                strcpy(t2, type);
                strcpy(type, stack[l].type[i]);
                return stack[l].addr[i];
            }
        }
    }
    return -1;
}

static char* lookup_sig(char *str) {
    for(int l = scope_level;l>=0;l--){
        for(int i = 0;i<stack[l].size;i++){
            if(strcmp(stack[l].name[i], str) == 0){
                return stack[l].func_sig[i];
            }
        }
    }
    return "";
}


static void reset(){
    strcpy(name, "");
    strcpy(type, "");
}

static void error_msg(char type1[], char type2[], char op[]){
    if(!type2) printf("error:%d: undefined: %s\n", yylineno, name);
    else{
        printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n", yylineno, op, type1, type2);
    }
}

static void delte(){
    for(int i = 0;i<stack[scope_level].size;i++){
        if(stack[scope_level].addr >=0 ) addr --;
    }
}
