%{
int words = 0; // will be counter for our different words

char *cache = NULL; // the unique words will be put in the 'cache' variable
%}

%%
[a-zA-Z0-9]+	{
            int ret_code = 0; //retrival code: code to check if input matches regular expression
            char *target = NULL;
            char *found = NULL;
            // add a 'space' before and after the word for words matching and word boundaries.
            ret_code = asprintf(&target, " %s ", yytext);
            if (ret_code < 0) {//returns No<0 if input does not match reg exp
                exit(1);
            }

            // check for NULL in cache var 
            if (NULL != cache) {
                found = strstr(cache, target); //checks for first occurence of a word
            }
            // if the word has NOT been found
            if (NULL == found) {
                words++;
                // store this new different word into the cache
                ret_code = asprintf(&cache, "%s%s", cache, target);
                if (ret_code < 0) {
                    exit(1);
                }
                
            }
       }
.	; //ignore other words not defined above
%%

int main(int argc, char **argv) {
    yyin = fopen("input.txt", "r"); //open and read input file
    yylex(); //opening and reading input stream
    printf("\nDifferent words are: %d\n", words);
    return 0;
}
int yywrap() { return(1); } //shows end of input
