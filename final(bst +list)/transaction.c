#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transaction.h"

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
    new->right = r;
    strcpy(new->id,account.id);
    int cost = 0;
    int boolean = 0;
    printf("%d\n",account.elec_cost);
    //printf("%s\n",new->id);
    if(account.elec_cost > 0){
      boolean = 1;
      new->elec_num = boolean;
      cost = cost + account.elec_cost;
      new->total = cost;
      printf("%d\n",new->total);
      printf("%d\n",cost);
    }else{
      boolean = 0;
      new->elec_num = boolean;
    };
    if(account.fashion_cost > 0){
      boolean = 1;
      new->fashion_num = boolean;
      cost = cost + account.fashion_cost;
      new->total = cost;
    }else{
      boolean = 0;
      new->fashion_num = boolean;
    }
    printf("%d\n",new->total);
    strcpy(new->name,account.name);
    //printf("%s\n",new->name);
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
    if(new.elec_cost > 0){
      exist->elec_num = exist->elec_num+ 1;
      exist->total = exist->total + new.elec_cost;
    };
    if(new.fashion_cost > 0){
      exist->fashion_num = exist->fashion_num + 1;
      exist->total = exist->total + new.fashion_cost;
    }
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
            fscanf(fin, "%s", tmp.name);
            fscanf(fin, "%d",&tmp.elec_cost);
            fscanf(fin, "%d",&tmp.fashion_cost);
            
            printf("%s\n",tmp.id);
            printf("%s\n",tmp.name);
            printf("%d\n",tmp.elec_cost);
            printf("%d\n",tmp.fashion_cost);
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

// /*xoa 1 node*/
// tree deleteNode(tree t,AccountDB node){
//    tree p, tmp;
  
//   if (isNullTree(t))
//     return NULL;

//   if (t == node)
//     return removeRootBST(t);

//   p = NULL;
//   tmp = t;
//   while ((tmp != NULL) && (tmp != node)) 
//     if (strcmp(tmp->name,node->name) > 0) {
//       p = tmp;
//       tmp = tmp->left;
//     } else {
//       p = tmp;
//       tmp = tmp->right;
//     }

//   if (tmp != NULL) {
//     if (p->left == tmp) {
//       p->left = removeRootBST(tmp);
//     }
//     else {
//       p->right = removeRootBST(tmp);
//     }
//   }
//   return t;
// }

// xoa nut goc va tra ve cay BST sau khi da xoa
// tree removeRootBST(tree t) {
//   tree p, tmp;
  
//   if (isNullTree(t))
//     return NULL;
//   // Xoa nut la
//   if (isLeaf(t)) {
//     free(t);
//     return NULL;
//   }
//   // Xoa nut co 1 con phai
//   if (left(t) == NULL) {
//     tmp = right(t);
//     free(t);
//     return tmp;
//   }
//   // Xoa nut co 1 con trai
//   if (right(t) == NULL) {
//     tmp = left(t);
//     free(t);
//     return tmp;
//   }
//   // Xoa nut co hai con
//   int i;
//   p = t;
//   tmp = right(t);
//   while (left(tmp) != NULL) {
//     p = tmp;
//     tmp = left(tmp);
//   }
//   strcpy(t->name,tmp->name);
//   t->total = tmp->total;
//   t->list = tmp->list;
//   tmp = removeRootBST(tmp);
//   if (p == t)
//     p->right = tmp;
//   else
//     p->left = tmp;
//   return t;
// };

/*Ghi ra file = DPS*/
// void DPS_write(tree t,FILE* fout){
//     if(isNullTree(t)){
//         return;
//     }
//     DPS_write(t->left,fout);
//     tree tmp = t;
//     printf("%s\t%s\t%.2f\t%d\t%d\n",tmp->id,tmp->name,tmp->total,tmp->elec_num,tmp->fashion_num);
//     DPS_write(t->right,fout);
// }

/*Ghi du lieu tu tep van ban*/
// tree write_account(tree t,char* filename){
//     FILE *fout;
//     tree tmp = t;
//     if ((fout = fopen(filename, "w+")) == NULL) {
//         printf("Can't write from %s\n",filename);
//     }else{
//         DPS_write(t,fout);
//     }
//     fclose(fout);
//     return t;
// };



/*In ra tree = DFS*/
void DPS_InOrder(tree t){
    if(isNullTree(t)){
        return;
    }
	DPS_InOrder(t->left);
	// in thong tin trong list
  tree tmp = t;
  printf("%s\t%s\t%d\t%d\t%d\n",tmp->id,tmp->name,tmp->total,tmp->elec_num,tmp->fashion_num);
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