#include <stdio.h>
enum{SUCCESS, FAIL,MAX_ELEMENT = 20};

typedef struct phoneaddress_t{
	char name[20];
	char tel[11];
	char email[25];
}phoneaddress;

int main(void){
	FILE *fp;
	phoneaddress phonearr[MAX_ELEMENT];
	int i,n,irc;
	int reval = SUCCESS;
	printf("How many contacts do you want to enter (<20)?");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("name:");scanf("%s",&phonearr[i].name);
		printf("tel:");scanf("%s",&phonearr[i].tel);
		printf("email:");scanf("%s",&phonearr[i].email);
	}
	if((fp = fopen("phonebook.txt","w+b")) == NULL){
		printf("Can not open %s\n","phonebook.txt");
		reval = FAIL;
		
	}
	
	irc = fwrite(phonearr,sizeof(phoneaddress31),n,fp);
	printf("fwrite return code = %d\n",irc);
	fclose(fp);
}

#include <stdio.h>
enum {SUCCESS,FAIL,MAX_ELEMENT = 5};

typedef struct nokia{
	char name[20];
	char price[20];
	char memory[10];
}nokia_t;

int main(void){
	FILE *fp;
	unsigned char buffer[100];
	nokia_t productarr[MAX_ELEMENT];
	int i,line_number,irc;
	int reval = SUCCESS;
	char c;
	if((fp= fopen("NokiaDB.dat","rb")) == NULL){
		printf("Can not open the file\n");
		reval = FAIL;
	}else{
		line_number = 0;
		while (fgets(buffer, sizeof(buffer), fp)) {
        	++line_number;
        	/* note that the newline is in the buffer */
			
        	while(c != '\n'){
        		
			}
    	}
	}
}


