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
go      { printf("%s: is a verb\n", yytext);} 
.	; 
%%
int main() {
    yylex(); 
    return 0;
}

int yywrap() { return 1; } 
