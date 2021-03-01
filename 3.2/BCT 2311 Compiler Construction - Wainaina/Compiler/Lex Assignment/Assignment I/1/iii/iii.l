
%%
abc 	printf("ABC"); 

%%

int main() {
    yylex(); 
}

int yywrap() { return 1; } 


