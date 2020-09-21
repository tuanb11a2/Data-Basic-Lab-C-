#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int MAX =  20;

typedef struct smartphone
{
	char name[20];
	char mem[20];
	char disp[20];
	char price[20];
} smp_t;


int convert(FILE *fin, FILE *fout)
{
	smp_t *smp;
	char c[100],*p;
	int i = 0,n = 0;
	while (fscanf(fin," %[^\n]s",c) == 1)
	{
		n++;
	}
	rewind(fin);
	
	smp = malloc(n*sizeof(smp_t));
	while (fscanf(fin," %[^\n]s",c) == 1)
	{	
		p = strtok (c,",");
		strcpy(smp[i].name,p);
		printf("%s ",p);
		p = strtok (NULL, ",");
		strcpy(smp[i].mem,p);
		printf("%s ",p);
		p = strtok (NULL, ",");
		strcpy(smp[i].disp,p);
		printf("%s ",p);
		p = strtok (NULL, ",");
		strcpy(smp[i].price,p);	
		printf("%s ",p);
		i++;
		

	}
	printf("\n");
	int irc;
	irc = fwrite(smp, sizeof(smp_t),i,fout);
	free(smp);
	return i;
}


void readData(FILE *fin,int i)
{
	int irc;
	printf("\n\n\n");
	smp_t *smp;
	smp = malloc((i)*sizeof(smp_t));
	irc = fread(smp, sizeof(smp_t),i,fin);
	for(int j=0;  j<(i) ;j++)
	{
		printf("%s %s %s %s\n",smp[j].name,smp[j].mem,smp[j].disp,smp[j].price);
	}
	free(smp);

}

void findByName(FILE *fin,int i)
{
	int irc;
	char name[20];
	smp_t *smp;
	smp = malloc((i)*sizeof(smp_t));
	irc = fread(smp, sizeof(smp_t),i,fin);
	printf("Enter the name of the model you want to find: ");
	scanf(" %[^\n]s",name);
	for (int j=0; j<i; j++)
	{
		if (strcmp(name,smp[j].name)==0)
		{
			printf("%s %s %s %s\n",smp[j].name,smp[j].mem,smp[j].disp,smp[j].price);
		}	
	}
}


int main()
{
	FILE *fin, *fout;
	int reval = 0;
	int n;
	if ((fin = fopen("NokiaDB.txt","r")) == NULL)
	{
		printf("Can not open %s.\n", "Nokia.txt");
		reval = 1;
	} 
	if ((fout = fopen("NokiaDB.dat","w+b")) == NULL)
	{
		printf("Can not open %s.\n", "NokiaDB.dat");
		reval = 1;
	}
	n = convert(fin,fout);
	rewind(fout);
	readData(fout,n);
	rewind(fout);
	findByName(fout,n);
	fclose(fin);
	fclose(fout);
	return reval;
		
			
}

