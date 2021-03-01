%{
	int words;
%}

%%
[a-zA-Z][a-zA-Z0-9_]* {
						words++;  
						printf("%s %d\n",yytext,words);
					}
.   ;
%%

int main(int argc, char* argv[])
{
    if(argc == 2)
    {

        yyin = fopen("sample.txt", "r");

        yylex();

        printf("No. of Words : %d\n",words);

        fclose(yyin);
    }

    else
        printf("Invalid No. of Arguments\n");

    return 0;
}
