#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct  node* next;
	struct  node* prev;
};

void traverse( struct node* head);
struct  node* AddNodeFront(struct  node* head, int value);
void AddNodeEnd(struct  node* head, int value);
void AddNodeAfter(struct  node* head, int n, int value);
struct  node* deleteNodeFront(struct  node* head);
void deleteNodeEnd(struct  node* head);
void deleteNodeAfter(struct node* head, int n);
void backTraverse(struct node *head);
void show();


int main ()
{       
    struct  node* head=NULL;
    while (true) {
    show();
 	int choice; 
 	int n;
 	int index;
	scanf("%d",&choice); 
	switch (choice)
	{
	case 1 :
	{ 
	  printf("enter the data of this node\n");
	  scanf("%d",&n);
	  head=AddNodeFront (head,n);
	  break;
	}
	case 2 :
	{ 
	  printf("enter the data of this node\n");
	  scanf("%d",&n);
	  AddNodeEnd(head,n);
	  break;
	}
	case 3 :
	{
	  traverse(head);
	  break;
	}
	case 4 :
	
	{ 
	  printf("enter the data  of this node\n");
	  scanf("%d",&n);
	  printf("enter the index of n:\n");
	  scanf("%d",&index);
	  AddNodeAfter(head,index,n);
	  break;
	}
	
	case 5 :
	{ 
	  head= deleteNodeFront(head);
	  break;
	}
	 
	case 6 :
	{ 
		deleteNodeEnd(head);
	break;
	 
	}
	case 7 :
	{   
		printf("enter the index of this node\n");
	    scanf("%d",&index);
		deleteNodeAfter(head, index);
		break;
	}
	case 8 :
	{
	    backTraverse(head);
        break;
	}
    case 9:
    {
       exit(0);
	}
	}
}
    
}


// display options for user to select from 
void show () {
	printf("Select from the list below\n\n");
	printf("1-->Add new node from front to the system\n\n");
	printf("2-->Add new node from end \n\n");
	printf("3-->show all nodes of linked list from last  \n\n");
	printf("4-->create a node after n nodes of the list\n\n");
	printf("5--delete the first node \n\n");
	printf("6-->delete the last node \n\n");
	printf("7-->delete a node after n node \n\n");
	printf("8-->show all nodes of linked list from end \n\n");
	printf("9-->exit \n\n");
}

/// This method traverse all nodes of linked list and print their values
void traverse(struct  node* head)
{
	 struct node *temp=head;
     while(temp!=NULL)
    {
        printf(" data=%d\n",temp->data);
        temp=temp->next;
    }
}
 /// This method creates a node and prepends it at the beginning of the list
 struct node* AddNodeFront( struct node* head, int value)
 {   
    struct node*newnodes=(struct node*)malloc(1*sizeof( struct node));
    struct node *temp=head;
    newnodes->next=head;
    newnodes->prev=NULL;
    head=newnodes;
    newnodes->data=value;
    if (temp==NULL)
		return head;
    else
    {
		temp->prev=head;
		return head;
    }
}

/// This method creates a node and prepends it at the end of the list
 void AddNodeEnd( struct node* head, int value)
{ 
	  if (head==NULL)
		printf("it is the first node please add it in the front\n");	      	  
	   else
	   {
	
	    struct node*temp=head;
	    while (temp->next!=NULL)
        {
			temp=temp->next;
        }
	   struct node*newnode=(struct node*)malloc(1*sizeof( struct node));
       temp->next=newnode;
	   newnode->prev=temp;
       newnode->next=NULL;
       newnode->data=value ;
	   }
}

/// This method creates a node after n nodes of the list
void AddNodeAfter( struct node* head, int n, int value)
{
	node* temp=head;         
	for (int  i=1; i< n; i++)
	{
		if (temp == NULL)
		{
			printf ("Add new node failed because the list is shorter than %d elements\n", n);
			exit(0);
		}
		temp=temp->next;
	 }	   
	struct  node* newnode=(node*)malloc(sizeof(node));
	newnode->prev=temp;
	newnode->next=temp->next;
	temp->next->prev=newnode;
	temp->next=newnode;
    newnode->data=value;
}
/// This method deletes the first node of the list
struct  node* deleteNodeFront(node* head)
{
	// test if the list is empty
	if (head==NULL)
	{
		printf("the list is empty\n");
		exit(0);
	}
    else
    {
        struct node*del=head;
        if (head->next==NULL)
        {  
			head=head->next;
			free(del);
		}
	   else 
	   {
		   head=head->next;
		   head->prev=NULL;
		   free(del);		
	   }
	}
	return head;
}
/// This method deletes the last node of the list
void deleteNodeEnd(node* head)
{
	// test if the list is empty
	if (head==NULL)
	{
		printf("the list is empty");
	}
	else
	{
		node* temp=head;
		
		while ((temp->next->next)!=NULL)
		{
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
    }
}
/// This method deletes the a node after n nodes of the list
void deleteNodeAfter(node* head, int n)
{       
	node* temp=head;
    if (temp == NULL)
	{
		printf("delete node failed because list is  empty \n");
        exit(1);
	}
	else 
   {	
	    for (int i=1; i< n; i++)
	   {
	      temp=temp->next;
	   }
       if (temp->next->next==NULL)
       { 
		  free(temp->next);
		  temp->next=NULL; 
       }
        else
       {
		  struct  node* del; 
		  del=temp->next;  
		  temp->next=temp->next->next;   
		  (temp->next)->prev = del->prev;          
		  free(del);
        }     
       }     
}
/// This method  reversely  traverse all nodes of linked list and print their values
void backTraverse(struct node *head)
{
     struct node *temp=head;
     while(temp->next!=NULL)    
		temp=temp->next;
    
    while(temp->prev != NULL)
    {
		printf(" data=%d\n",temp->data);
		temp=temp->prev;
	}
	printf(" data=%d\n",temp->data);
}
