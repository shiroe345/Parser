#ifndef COMPILER_COMMON_H
#define COMPILER_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/* Add what you need */
int scope_level;

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

static void create_symbol() {
    printf("> Create symbol table (scope level %d)\n", ++scope_level);
    stack[scope_level].size = 0;
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

#endif /* COMPILER_COMMON_H */