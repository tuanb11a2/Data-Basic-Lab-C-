#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
enum {SUCCESS, FAIL};

void CharReadWrite(FILE *fin, FILE *fout)
{
	int c;
	while ((c = fgetc(fin)) != EOF)
	{
		fputc(c,fout);
		putchar(c);
	};
}

int main(int argc, char *argv[])
{
	FILE *fptr1, *fptr2;
	char filename1[] = "lab1w.txt";
	char filename2[] = "lab1.txt";
	int reval = SUCCESS;
	if ((fptr1 = fopen(filename1, "w")) == NULL)
	{
		printf("Cannot open %s.\n",filename1);
		reval = FAIL;
	} else if ((fptr2 = fopen(filename2, "r")) == NULL)
	{
		printf("Cannot open %s.\n",filename2);
	} else {
		CharReadWrite(fptr2,fptr1);
		fclose(fptr1);
		fclose(fptr2);
	}
	return reval;
}

