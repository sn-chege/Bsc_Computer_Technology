%{
#include <stdio.h>

extern FILE *yyin;
int num = 0;
%}

%start string

%token A
%token B
%%

string      : A string { num++; }
            | B
            ;
%%


int main(int argc, char **argv) {
    
    yyin = fopen(argv[1], "r");
}
