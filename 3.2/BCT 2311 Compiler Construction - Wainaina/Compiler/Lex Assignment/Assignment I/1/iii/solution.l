
%%
[a][b][c]	printf("ABC"); 

%%

int main() {
    yyin =fopen("input.txt", "r"); //opening and reading the input file
    yylex(); //reads the input stream and tokenizes it
}

int yywrap() { return 1; } //returns 1 to show no more input will be taken


