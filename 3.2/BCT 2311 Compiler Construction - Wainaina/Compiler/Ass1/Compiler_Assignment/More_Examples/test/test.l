%{
	#include <stdio.h>
%}

%%

-[0-9]+		   	printf("negative integer"); 
\+?[0-9]+ 		printf("positive integer"); 
-0.[0-9]+	 	printf("negative fraction, no whole number part");
rail[ \t]+road	printf("railroad is one word"); 
crook		    printf("Here's a crook"); 
G[a-zA-Z]*		{
					printf("may have a G word here:%s", yytext); 
   		        }
%%

int main(){
	yylex();
	return 0;
}

int yywrap(){
	return 1;
}