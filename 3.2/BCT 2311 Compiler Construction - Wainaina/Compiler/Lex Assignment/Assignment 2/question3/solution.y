%{
//c definitions
	#include<stdio.h>
	#include<stdlib.h>
	void yyerror(char *);
	int yylex(void);
	
%}
//yacc definitions
%token INTEGER 
%left '+' '-'

%%//productions

program:
	program statement '\n'
	|
	;
statement:
	expr		        { printf("%d\n", $1); }
	;


expr:
	INTEGER
	
	| expr '+' expr		{ $$ = $1 + $3; }
	| expr '-' expr		{ $$ = $1 - $3; }	
	| '(' expr ')'		{ $$ = $2; }
	;

%%

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
	exit(1);
}
int main(void) {
	yyparse();
	return 0;
}
