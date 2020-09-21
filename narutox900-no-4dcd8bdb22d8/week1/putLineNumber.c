#include <stdio.h>

enum {SUCCESS,FAIL};

int main()
{
	FILE *fptr1, *fptr2;
	char filename1[]=  "test.txt";
	char filename2[]= "test+number.txt";
	int reval = SUCCESS;

	if ((fptr1 = fopen(filename1, "r")) == NULL)
	{
		printf("Cannot open %s.\n",filename1);
		reval = FAIL;
	} else if ((fptr2 = fopen(filename2, "w")) == NULL)
	{
		printf("Cannot open %s.\n",filename2);
		reval = FAIL;
	}	else {
		int c,i = 1;
		fprintf(fptr2,"%d ",i);
		fputc(' ',fptr2);
		putchar(i);
		putchar(' ');
		while ((c=fgetc(fptr1)) != EOF)
		{
			fputc(c,fptr2);
			putchar(c);
			if (c == '\n')
			{
				i++;
				fprintf(fptr2,"%d",i);
				fputc(' ',fptr2);
				putchar(i);
				putchar(' ');
			}

		}
	}
	return reval;
}

		

