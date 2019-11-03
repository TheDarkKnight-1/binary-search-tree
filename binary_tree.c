/******************************************************************************

                            Binary search tree

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
struct node{
    int val;
    struct node *lchild;
    struct node *rchild;
};
struct node *insert(struct node *p,int key){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(p==NULL){
        newnode->val=key;
        newnode->lchild=newnode->rchild=NULL;
        p=newnode;
        return p;
    }
    else if(key<p->val)
        p->lchild=insert(p->lchild,key);
    else if(key>p->val)
        p->rchild=insert(p->rchild,key);
}
void inorder(struct node *p){
    if(p!=NULL){
        inorder(p->lchild);
        printf("%d ",p->val);
        inorder(p->rchild);
    }
}
void printLeafnodes(struct node *p){
    if(p!=NULL){
        if(p->lchild==NULL && p->rchild==NULL){
            printf("%d ",p->val);
            return;
        }
        printLeafnodes(p->lchild);
        printLeafnodes(p->rchild);
    }
        
}
void printLeftChild(struct node *p){
    if(p!=NULL){
        if(p!=NULL){
            printf("%d ",p->lchild->val);
            return;
        }
        printLeftChild(p->lchild);
        printLeftChild(p->rchild);
    }
        
}
void leftViewUtil(struct node* root, int level, int* max_level) 
{ 
    // Base Case 
    if (root == NULL) 
        return; 
  
    // If this is the first node of its level 
    if (*max_level < level) { 
        printf("%d\t", root->val); 
        *max_level = level; 
    } 
  
    // Recur for left and right subtrees 
    leftViewUtil(root->lchild, level + 1, max_level); 
    leftViewUtil(root->rchild, level + 1, max_level); 
} 
  
// A wrapper over leftViewUtil() 
void leftView(struct node* root) 
{ 
    int max_level = 0; 
    leftViewUtil(root, 1, &max_level); 
} 

int countNodes(struct node* p)
{
    static int count=0;
    if(p!=NULL){
        
        countNodes(p->lchild);
        countNodes(p->rchild);
        count++;
        return count;
        //return count;
    }
}
int countFullNodes(struct node *p){
    static int count=0;
    if(p!=NULL){
        countFullNodes(p->lchild);
        countFullNodes(p->rchild);
        if(p->lchild!=NULL && p->rchild!=NULL){
            count++;
        }
        return count;
    }
}
int main()
{
    struct node *root=NULL;
    root=insert(root,50);
    insert(root,20);
    insert(root,70);
    insert(root,65);
    insert(root,89);
    //inorder(root);
    //printLeafnodes(root);
    //leftView(root);
    //printLeftChild(root);
    //int n = countNodes(root);
    int n = countFullNodes(root);
    printf ("%d",n);
    return 0;
}

