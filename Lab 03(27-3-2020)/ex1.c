#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXLENGTH 50

char *connectString(char *str1,char *str2){
	int len1,len2;
	char *result;
	
	len1 = strlen(str1);
	len2 = strlen(str2);
	
	result = (char*)malloc((len1 + len2 + 1)*sizeof(char));
	if(result == NULL){
		printf("Allocate fail! Check memory!");
		return NULL;
	}
	
	strcpy(result,str1);
	strcpy(result + len1,str2);
	
	return result;
}

int main(){
	char str1[MAXLENGTH + 1],str2[MAXLENGTH + 1];
	char* result;
	printf("Enter the first string:\n");
	scanf("%s",str1);
	printf("Enter the second string:\n");
	scanf("%s",str2);
	result=connectString(str1,str2);
	printf("The result:%s\n",result);
	printf("The first string length:%d",strlen(str1));
	return 0;
}

