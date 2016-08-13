#include <stdio.h>
#include <stdlib.h>

/// Binary tree node
struct bt_node
{
	int data;
	struct bt_node *lchild;
	struct bt_node *rchild;
};




struct bt_node *root=NULL;
struct  bt_node* allocateNewNode();
void binaryTreeInsert(int value);
void search(struct  bt_node* test ,int value);

int main ()
{
	binaryTreeInsert(6);
	binaryTreeInsert(9);
	binaryTreeInsert(7);
	binaryTreeInsert(10);
	binaryTreeInsert(5);
	binaryTreeInsert(0);
	binaryTreeInsert(3);
	binaryTreeInsert(-5);
	binaryTreeInsert(8);

	search(root,5);
	search(root,0);
	search(root,20);
	search(root,15);
}



/// Insert New Node in Binary Tree
void binaryTreeInsert(int value)
{
	struct bt_node *p,*q;

	if(root==NULL)
	{
		root=allocateNewNode();
		root->data=value;
		return;
	}

	p=root;
	while (p!=NULL)
	{
		q=p;
		if (value < (p->data))
			p=p->lchild;
		else
			p=p->rchild;
	}

/* Now, 'q' points to parent of new node */

	p=allocateNewNode();
	p->data=value;
	if (value < (q->data))
		q->lchild=p;
	else
		q->rchild=p;
	}


/// Allocate new Binary Tree Node
struct  bt_node* allocateNewNode()
{
	struct bt_node *newnode;
	newnode=(struct bt_node *) malloc (sizeof(struct bt_node));
	newnode->lchild= NULL;
	newnode-> rchild=NULL;
	return(newnode);
}
// search for a number in tree
void search(struct  bt_node* test ,int value)
{
    if ( root==NULL)
   {
       printf("the Binary tree is empty\n");
       exit(0);
   }
   if (test==NULL)
   {
       printf("\n%d is not found in the tree \n",value);
       return;
   }

   else if(test->data==value)
   {
	   printf("\n%d is found in the tree \n",value);
	   return;
   }

    if(value < test->data)
		search(test->lchild,value);
    else if(value > test->data)
		search(test->rchild,value);
    else
		printf("\n%d is not found in the tree \n",value);

}
