%{
#include <stdio.h>

extern FILE *yyin;
%}

%start program

%token PLUS
%token MINUS
%token LPAREN
%token RPAREN

%left '+' '-'

%%

program     : expression { printf("%d\n", $1); } ;
expression  : term { $$ = $1; }
            | expression PLUS expression { $$ = $1 + $3; }
            | expression MINUS expression { $$ = $1 - $3; }
            | LPAREN expression RPAREN { $$ = $2; }
            ;
%%


void yyerror(char *s) { fprintf(stderr, "%s\n", s); }

int main(int argc, char **argv) {
    yyin = fopen(argv[1], "r");
    yyparse();
    return 0;
}
