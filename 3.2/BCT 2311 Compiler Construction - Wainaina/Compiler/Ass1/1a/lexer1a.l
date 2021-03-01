%{
	#include <stdio.h>
	int words=0, c_letters=0, total=0;
%}

%%
\n {words++;}
[\t ' '] words++;
[a-zA-Z] c_letters++;
%%

int main(){
	yyin=fopen("sample.txt","r");
	yylex();
	total = c_letters+words;
	printf("File Contents...\n");
	printf("\n\t%d Words",words);
	printf("\n\t%d Text Characters",c_letters);
	printf("\n\t%d Total Characters\n",total);
	return 0;
}
int yywrap(){
	return 1;
}