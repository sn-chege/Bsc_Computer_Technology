/*
   Recursive-descent integer arithmetic calculator
   according to the EBNF:


	E -> T+T
	T -> F*F
	F -> (E) | Num

   Inputs a line of text from stdin.
   Outputs "Error" or the result.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*variable to store the expected*/
char token;

int E(void);
int T(void);
int F(void);

/* report error and die */
void error(void)
{ fprintf(stderr,"Error\n");
  exit(1);
}

/* match input token, read next token */
void match(char expectedToken)
{ 
  if (token==expectedToken) 
	token = getchar();
  else 
	error();
}

/* process an expression */
int E()		
{ 
	int temp = T();
	if (token=='+')
	{	
		match('+');
		temp += T(); 
		return temp;
	}		
	else
	{
		return temp;
	}  
	
}

/* process a term */
int T()		
{ 
	int temp = F();
	if (token=='*')
	{ 
		match('*'); 
		temp *= F(); 
		return temp;
	}
	else
	{
	  return temp;
	}

}


/* process a factor */
int F()	
{
  int temp = 0;
  if (token=='(')
  {
	match('('); 
	temp = E(); 
	match(')'); 
  }
  else if (isdigit(token))
  { 
	ungetc(token,stdin);
	scanf("%d",&temp);
	token = getchar();
  }
  else
  {	  
	error();
  }
  return temp;
}

/* calculator driver program */
int main()
{ 
  int answer;
  token = getchar();
  answer = E();
  if (token=='\n') printf("Solution = %d\n",answer);
  else error();
  return 0;
}
