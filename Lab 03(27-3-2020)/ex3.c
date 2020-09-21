#include <stdio.h>

enum{SUCCESS, FAIL,MAXLEN = 80};
void BlockReadWrite(FILE *fin,FILE *fout){
	int num;
	char buff[MAXLEN+1];
	while(!feof(fin)){
		num=fread(buff, sizeof(char), MAXLEN, fin);
		fwrite(buff,sizeof(char),num,fout);
	}
};

int main(void){
	FILE *fptr1,*fptr2;
	char filename1[]="lab1a.txt";
	char filename2[]="lab1.txt";
	int reval = SUCCESS;
	
	if(fptr2 = fopen(filename2,"r") == NULL){
		printf("Cannot open %s\n",filename2);
		reval = FAIL;
	}else if(fptr1= fopen(filename1,"w") == NULL){
		printf("Cannot open %s\n",filename1);
		reval = FAIL;
	}else{
		BlocReadWrite(fptr2,fptr1);
		fclose(fptr1);
		fclose(fptr2);
	}
	return reval;
	
	}

