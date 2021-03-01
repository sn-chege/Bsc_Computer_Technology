%{
int words = 0, 
total_size = 0; //counters 
%}

%%
[a-zA-Z0-9]+	{ words++; total_size += yyleng; } 

%%
//yyleng() No. of characters in a word
int main() {
    yyin =fopen("myfile.txt", "r"); //open and read input file
    yylex(); //opening and reading input stream
    printf("words: %d\n", words);
    printf("total size: %d\n", total_size);
    return 0;
}
int yywrap() { return 1; } //returns 1 to show no more input will be taken
