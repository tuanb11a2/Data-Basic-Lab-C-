#include <stdio.h>

enum {SUCCESS, FAIL, MAX_ELEMENT=20};

typedef struct phoneaddress{
	char name[20];
	char tel[11];
	char email[25];
}phoneaddress_t;

int main()
{
	FILE *fp;
	phoneaddress_t phonearr[MAX_ELEMENT];
	int i,n, irc;
	int reval = SUCCESS;
	printf("How many contacts do you want to enter (<20)?");
	scanf("%d",&n);
	for (i=0; i<n; i++)
	{
		printf("Name: "); scanf(" %[^\n]s",phonearr[i].name);
		printf("Tel: "); scanf(" %[^\n]s",phonearr[i].tel);
		printf("Email: "); scanf(" %[^\n]s",phonearr[i].email);
	}
	if ((fp = fopen("phonebook.dat","w+b")) == NULL)
	{
		printf("Can't open %s.\n", "phonebook.dat");
		reval = FAIL;
	}

	irc = fwrite(phonearr, sizeof(phoneaddress_t),n, fp);
	printf("fwrite return code = %d\n",irc);
	if ((fp = fopen("phonebook.dat","rb")) == NULL)
	{
		printf("Can not open %s.\n", "phonebook.dat");
		reval = FAIL;
	}
	irc = fread(phonearr, sizeof(phoneaddress_t), n, fp);
	printf("fread return code = %d\n",irc);
	for (i=0 ;i<n; i++)
	{
		printf("%s-",phonearr[i].name);
		printf("%s-",phonearr[i].tel);
		printf("%s\n",phonearr[i].email);
	}
	fclose(fp);
	return reval;
}
