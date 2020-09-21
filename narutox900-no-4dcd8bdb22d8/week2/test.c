
#include <stdio.h>
#include <string.h>


int main() 
{ 
	    FILE* ptr = fopen("abc.txt","r"); 
	    if (ptr==NULL) 
	    { 
		    printf("no such file.");
		    return 0; 
     	    } 
		  
		    /* Assuming that abc.txt has content in below 
		     *        format 
		     *               NAME    AGE   CITY 
		     *                      abc     12    hyderbad 
		     *                             bef     25    delhi 
		     *                                    cce     65    bangalore */
	    char buf[100],*pch; 
	    while (fscanf(ptr," %[^\n]s",buf) == 1) 
	    {
		  		    printf("%s\n", buf); 
		    pch = strtok(buf,",");
		    while (pch!=NULL)
		    {
			    printf("%s ",pch);
			    pch = strtok(NULL,",");
		    }
		    printf("\n");
			  
			   
	    }
	    return 0;
}	 
