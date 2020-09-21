#include <stdio.h>
#include <stdlib.h>
#include "stack-list.h"
#include <string.h>

int prec(char c) {
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
	       return 1;
	else return -1;
}
int isOperand(char c) {
	return ((c >= '0') && ( c<= '9') );// || (c>= 'A' && c <= 'Z');
}

void infixToPostfix(char* s) {
	stack l = create_stack();
	int i,k;
	for (i=0,k=-1; s[i]; i++) {
		if (isOperand(s[i]))
			s[++k] = s[i];
		else if (s[i] == '(') {
			push (l, s[i]);
		} else if (s[i] == ')') {
			while(!is_empty(l) && top(l) != '(') {
				s[++k] = top(l);
				pop(l);
      }
			if (!is_empty(l) && top(l) != '(') {
				printf("Invalid expression!\n");
				return ;
			} else
			       	pop(l);
			} else
		{
			while (!is_empty(l) && (prec(s[i]) <= prec(top(l) )))
			{
				s[++k]  = top(l);
				pop(l);
			}
			push(l,s[i]);
		}
	}
	while (!is_empty(l)){
		s[++k]= top(l);
		pop(l);
	}
	s[++k] = '\0';
	printf("%s\n",s);
}

int main() 
{
//	char s[]= "1+2*(3^4-5)^(6+7*8)-9";
	char s[] = "1^2^3";
	infixToPostfix(s);
	printf("%s\n",s);
	return 0;

}



