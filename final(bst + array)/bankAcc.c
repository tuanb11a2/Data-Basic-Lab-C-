#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bankAcc.h"

/*Tao 1 null tree moi*/
tree createNullTree(){
    return (tree)NULL;
};

/*Tao 1 leaf moi*/
tree createLeaf(struct Account account){
    return createTree(account,NULL,NULL);
};

/*Tao 1 tree moi*/
tree createTree(struct Account account, tree l, tree r){
    AccountDB new = (AccountDB)malloc(sizeof(struct TreeNode));
    new->left = l;
    int i;
    long int cost;
    new->right = r;
    strcpy(new->id,account.id);
    strcpy(new->name,account.name);
    //printf("%s\n",new->name);
    new->total_cost = 0;
    new->total = 1;
    if(account.elec_cost > 0){
      new->elec_num = 1;
    }else{
      new->elec_num = 0;
    }
    if(account.fashion_cost > 0){
      new->fashion_num = 1;
    }else{
      new->fashion_num = 0;
    }
    strcpy(new->accounts[0].name,account.name);
    //printf("%s\n",new->accounts[0].name);
    strcpy(new->accounts[0].id,account.id);
    //printf("%s\n",new->accounts[0].telephone);
    new->accounts[0].elec_cost = account.elec_cost;
    //printf("%f\n",new->accounts[0].balance);
    new->accounts[0].fashion_cost = account.fashion_cost;
    printf("%s\t%s\t%d\t%d\t", new->id, new->name, account.elec_cost,account.fashion_cost);
    printf("%p\n",new);
    return new;
};

/*Tra ve con trai*/
AccountDB left(tree t){
  if(isNullTree(t)){
    return NULL;
  }else{
    return t->left;
  }
};

/*Tra ve con phai*/
AccountDB right(tree t){
  if(isNullTree(t)){
    return NULL;
  }else{
    return t->right;
  }
};

/*Insert*/
AccountDB insertNode(tree t,struct Account new){
    if(isNullTree(t)){
        return createLeaf(new);
    }else if(strcmp(new.id,t->id)  < 0){
            t->left = insertNode(t->left,new);
            return t;
    }else{
            t->right = insertNode(t->right,new);
            return t;
    }
}

/*Tim TreeNode theo name*/
AccountDB findNodebyname(tree t,char* name){
    if(isNullTree(t)){
        return NULL;
    }else{
        if(strcmp(name,t->id) < 0){
            return findNodebyname(t->left,name);
        }else if(strcmp(name,t->id) > 0){
            return findNodebyname(t->right,name);
        }else{
            return t; //Found node
        }
    }
}

/*Them account vao node da co san*/
tree appendTreeNode(tree t,struct Account new){
    AccountDB exist = findNodebyname(t,new.id);
    int count = exist->total;
     exist->total = exist->total + 1;
    if(new.elec_cost > 0){
      exist->elec_num = exist->elec_num + 1;
    }
    if(new.fashion_cost > 0){
      exist->fashion_num = exist->fashion_num + 1;
    }
    strcpy(exist->accounts[count].name,new.name);
    //printf("%s\n",exist->accounts[count].name);
    strcpy(exist->accounts[count].id,new.id);
    //printf("%s\n",exist->accounts[count].telephone);
    exist->accounts[count].elec_cost = new.elec_cost;
    exist->accounts[count].fashion_cost = new.fashion_cost;
    
        return t;

}

/*Doc du lieu tu tep van ban*/
tree read_account(char* filename){
    FILE *fin;
    tree account_tree;
    struct Account tmp;
    account_tree = createNullTree();
    int total;

    if ((fin = fopen(filename, "r")) == NULL) {
        printf("Can't read from %s\n",filename);
    }else{
        while(fscanf(fin,"%s",tmp.id) == 1){
            fscanf(fin,"%s",tmp.name );
            fscanf(fin, "%ld\n", &tmp.elec_cost);
            fscanf(fin, "%ld\n", &tmp.fashion_cost);
            //printf("%s\n",tmp.id);
            //printf("%s\n",tmp.telephone);
            //printf("%f\n",tmp.balance);
            if(findNodebyname(account_tree,tmp.id) != NULL){
                account_tree = appendTreeNode(account_tree,tmp);
            }else{
                account_tree = insertNode(account_tree,tmp);
            }
        }
    }

    fclose(fin);
    return account_tree;
}



/*In ra tree = DFS*/
void DPS_InOrder(tree t){
    if(isNullTree(t)){
        return;
    }
	DPS_InOrder(t->left);
	// in thong tin trong array
	int i;
  long int cost = 0;
	
	printf("%s\t%s\t%d\t%d\t", t->id, t->name, t->elec_num,t->fashion_num);
	
  for(i = 0; i<t->total; i++)
  {
    cost = cost + t->accounts[i].elec_cost + t->accounts[i].fashion_cost;
  }
  printf("%d\t%p\n",cost,t);

	DPS_InOrder(t->right);
}

/*
void DPS_InOrder(tree t){
    if(isNullTree(t)){
        return;
    }
	DPS_InOrder(t->left);
	// in thong tin trong array
	int i;
  long int cost = 0;
	
	printf("%s\t%s\t%d\t%d\t", t->id, t->name, t->elec_num,t->fashion_num);
	
  for(i = 0; i<t->total; i++)
  {
    cost = cost + t->accounts[i].elec_cost + t->accounts[i].fashion_cost;
  }
  printf("%d\t%p\n",cost,t);

	DPS_InOrder(t->right);
}

/*Null tree?*/
int isNullTree(tree t) {
  return (t == NULL);
};

/*Leaf?*/
int isLeaf(tree t){
  return ((t != NULL) &&
	  (t->left == NULL) &&
	  (t->right == NULL)); 
};
