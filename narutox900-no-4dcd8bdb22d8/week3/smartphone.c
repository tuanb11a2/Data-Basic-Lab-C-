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

struct node
{
	smp_t data;
	struct node* next;
} ;

struct node* root;
struct node* cur;

void freeDB()
{
	struct node* tmp;
	cur = root;
	while (cur != NULL)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	root = NULL;
	cur = NULL;
}

struct node* makeNode(smp_t *smp)
{
	struct node* new = (struct node*) malloc(sizeof(struct node));
	new->data = *smp;
	new->next = NULL;
	return new;
}


void addDB(smp_t *smp)
{
	struct node* new_node = makeNode(smp);

	if (root == NULL)
	{
		root = new_node;
		cur = new_node;
	} else 
	{
		new_node->next = cur->next;
		cur->next = new_node;
		cur = new_node;
	}
}

void readDB() //into linked list
{
	FILE *fin;
	smp_t smp;
	freeDB();
	int i;
	if ((fin = fopen("NokiaDB.dat", "r+b")) == NULL)
	{
		printf("Can't read from NokiaDB.dat\n");
		return ;
	}
	while (!feof(fin))
	{
		i = fread(&smp, sizeof(smp_t), 1, fin);
		printf("%s,%s,%s,%s\n",smp.name,smp.mem,smp.disp,smp.price);
		addDB(&smp);
	}
	fclose(fin);
}

void printDB()
{
	struct node* it;
	for (it = root; it !=NULL; it = it->next)
	{
		printf("%s,%s,%s,%s\n",(it->data).name,(it->data).mem,(it->data).disp,(it->data).price);
	}
}

void searchDB() //search from linked list
{
	char name[20];
	struct node* it;

	printf("Enter model you want to search: ");
	scanf(" %[^\n]s",name);

	for (it = root; it != NULL; it = it->next)
	{
		if (strcmp(name ,(it->data).name) == 0 )
		{
			printf("\n%s,%s,%s,%s\n",(it->data).name,(it->data).mem,(it->data).disp,(it->data).price);
			break;
		}
	}

	if (it == NULL)
	{
		printf("Can't find %s \n",name);
	}
}

void inputDB()
{
	smp_t smp;

	printf("\nEnter name: ");
	scanf(" %[^\n]s",smp.name);
	printf("\nEnter mem: ");
	scanf(" %[^\n]s",smp.mem);
	printf("\nEnter screen: ");
	scanf(" %[^\n]s",smp.disp);
	printf("\nEnter price: ");
	scanf(" %[^\n]s",smp.price);

	if (root != NULL)
		for (cur = root; cur->next != NULL; cur = cur->next);

	addDB(&smp);
}




void convert()
{
	FILE *fin,*fout;

	if ((fin = fopen("NokiaDB.txt","r")) == NULL)
	{
		printf("Can not open NokiaDB.txt");
		return;
	}
	if ((fout = fopen("NokiaDB.dat","w+b")) == NULL)
	{
		printf("Can not open NokiaDB.dat");
		return;
	}


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
	fclose(fin);
	fclose(fout);
	return ;
}

/* read data into array
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

}*/

/* This is for searching from array
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
}*/


int main()
{
	int running = 1;
	int sel;

	root = NULL;
	cur = 0;

	while (running)
	{
		printf("\n1. Convert from txt to dat file\n");
		printf("2. Read from binary file\n");
		printf("3. Print database\n");
		printf("4. Search by name\n");
		printf("5. Add new entry\n");
		printf("6. Quit\n");
		printf("Please select: ");
		scanf("%d",&sel);
		switch(sel)
		{
			case 1: convert(); break;
			case 2: readDB(); break;
			case 3: printDB(); break;
			case 4: searchDB(); break;
			case 5: inputDB(); break;			
			case 6: running = 0; break;
		}
	}
	
	freeDB();
	return 0;
}			

