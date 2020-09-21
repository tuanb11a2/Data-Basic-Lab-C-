#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	double expo;

	if (argc != 3)
	{
		printf("Invalid number of arguments!\n");
		return 1;
	}

	if (strcmp(argv[1],"E") == 0)
	{
		expo = exp(atof(argv[2]));
		printf("\nThe answer is %f\n",expo);
		return 0;
	} else 
	{
		printf("Invalid input!\n");
		return 0;
	}
}


