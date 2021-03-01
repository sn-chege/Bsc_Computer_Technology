%%
is |
am |
are |
do  |
were | 
was |
be |
being | 
been | 
doing | 
does |
did |
will | 
would |
should |
can | 
could |
has |
have |
had |  
go { printf("%s ", yytext);} //buffer to hold the input characters that match the pattern
.	; //ignore other words not defined above
%%
int main() {
    printf("Verbs in the text are:\n");
    yyin =fopen("input.txt", "r"); //opening and reading the input file
    yylex(); //reads the input stream and tokenizes it
    puts("");// display the identified verbs
    return 0;
}

int yywrap() { return 1; } //returns 1 to show no more input will be taken
