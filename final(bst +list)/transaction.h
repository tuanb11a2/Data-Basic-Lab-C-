#ifndef _BANK_H_
#define _BANK_H_

struct Account{
    char id[5];
    char name[30];
    int elec_cost;
    int fashion_cost;
};

struct TreeNode{
    char id[5];
    char name[30];
    int total;  //All amout of money
    int elec_num;
    int fashion_num;
    struct TreeNode* left;
    struct TreeNode* right;
};
typedef struct TreeNode* AccountDB;
typedef struct TreeNode* tree;
/*Tao 1 null tree moi*/
tree createNullTree();

/*Tao 1 leaf moi*/
tree createLeaf(struct Account account);

/*Tao 1 tree moi*/
tree createTree(struct Account account, tree l, tree r);

/*Tra ve con trai*/
AccountDB left(tree t);

/*Tra ve con phai*/
AccountDB right(tree t);

/*Doc du lieu tu tep van ban*/
tree read_account(char* filename);

/*Ghi du lieu tu tep van ban*/
tree write_account(tree t,char* filename);

/*In ra tree*/
void DPS_InOrder(tree t);

/*Null tree?*/
int isNullTree(tree t);

/*Leaf?*/
int isLeaf(tree t);

/*Xoa 1 node*/
tree deleteNode(tree t,AccountDB node);

/* xoa nut goc va tra ve cay BST sau khi da xoa*/
tree removeRootBST(tree t);

/*Tim node theo ten*/
AccountDB findNodebyname(tree t,char* name);

/*Them vao node co san*/
tree appendTreeNode(tree t,struct Account new);

/*Them 1 node moi*/
AccountDB insertNode(tree t,struct Account new);
#endif