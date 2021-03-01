%{
#include <stdio.h>
int count = 0;
int yylex();
%}

%token NEWLINE

%%
start : S NEWLINE { return; }
	;

S: 	'a' S	{ count++; }
	| 'b'	{}
	|
	;
%%

int yyerror(char const *s)
{
	printf("yyerror %s\n", s);
	exit(1);
}

int main()
{
	printf("Enter the string\n");
	yyparse();
	printf("Number of a\'s: %d\n", count);
	return 1;
}
