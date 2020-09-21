#include <stdio.h>
#include <stdlib.h>

int compareFile1(FILE *file1, FILE *file2, int *line, int *col)
{
	char ch1, ch2;

	*line = 1;
	*col = 0;
	
	do
	{
		ch1= fgetc(file1);
		ch2= fgetc(file2);

		if (ch1 == '\n')
		{
			*line+=1;
			*col = 0;
		}
	

		if (ch1 != ch2 )
			return -1;
		*col +=1;
	} while (ch1 != EOF && ch2 != EOF);

	if (ch1 == EOF && ch2 == EOF)
		return 0;
	else 
		return -1;
}

vim compare2(FILE *file1, FILE *file2)
{
	char ch1,ch2;
	int i = 1;
	do
	{
		ch1 = fgetc(file1);
		ch2 = fgetc(file2);
		



int main()
{
	FILE *fptr1;
	FILE *fptr2;
	char filename1[] = "compare1.txt";
	char filename2[] = "compare2.txt";
	int reval = 0;
	int line, col,diff;

	if ((fptr1 = fopen (filename1, "r")) == NULL)
	{
		printf("Cannot open %s\n",filename1);
		reval = 1;
	} else if ((fptr2 = fopen (filename2 , "r")) == NULL)
	{
		printf("Cannot open %s\n",filename1);
		reval = 1;
	} else {
		diff = compareFile1(fptr1,fptr2,&line,&col);
		if (diff == 0)
		{
			printf("\nBoth files are equal.\n");
		} else 
		{
			printf("\nThe two files are different\n");
			printf("Line: %d, col: %d\n",line, col);
		}
	}
	fclose(fptr1);
	fclose(fptr2);

	return reval;
}


		
	

