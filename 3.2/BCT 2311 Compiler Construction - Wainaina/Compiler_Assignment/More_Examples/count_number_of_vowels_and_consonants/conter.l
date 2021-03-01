%{
	#include<stdio.h>
	int v=0,c=0;
%}


%%
[aeiouAEIOU]       {v++;}
[a-zA-Z]           {c++;}
.                  { }
%%

int main(){
	printf("Enter the Text");
	yylex();
	printf("\nNo. of Vowels=%d",v);
	printf("\nNo. of Consonents=%d\n",c);
	return 0;
}