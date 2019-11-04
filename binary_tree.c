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
//find max
struct node* FindMin(struct node* root)
{
	while(root->lchild != NULL) root = root->lchild;
	return root;
}
//delete function
struct node * deleteNode(struct node *p,int data){
    if(p==NULL) return p;
    else if(data<p->val) p->lchild=deleteNode(p->lchild,data);
    else if(data>p->val) p->rchild=deleteNode(p->rchild,data);
    else{
        //NO child
        if(p->lchild==NULL && p->rchild==NULL){
            free(p);
            p=NULL;
        }
        //1 left child
        else if(p->rchild==NULL){
            struct node *temp=p;
            p=p->lchild;
            free(p);
        }
        //1 right child
        else if(p->lchild==NULL){
            struct node *temp=p;
            p=p->rchild;
            free(p);
        }
        //2 nodes
        else{
            struct node *temp = FindMin(p->rchild);
			p->val = temp->val;
			p->rchild = deleteNode(p->rchild,temp->val);
        }
    }
    return p;
}
int main()
{
    struct node *root=NULL;
    root=insert(root,50);
    insert(root,20);
    insert(root,70);
    insert(root,65);
    insert(root,89);
    inorder(root);
    root=deleteNode(root,65);
    printf("\n");
    inorder(root);
    //printLeafnodes(root);
    //leftView(root);
    //printLeftChild(root);
    //int n = countNodes(root);
    //int n = countFullNodes(root);
   // printf ("%d",n);
    return 0;
}

