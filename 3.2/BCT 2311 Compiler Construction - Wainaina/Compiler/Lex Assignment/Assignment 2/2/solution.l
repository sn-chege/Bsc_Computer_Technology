%{
#include <stdio.h>
#include "y.tab.h"
%}

%%
a	return *yytext;
b	return *yytext;
[\n]	return NEWLINE;
%%

int yywrap()
{
	return 1;
}

