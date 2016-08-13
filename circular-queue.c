// implementation of circular queue
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 5

int front= -1;
int rear= -1;
int counter=0;

void addQueue (int* queue, int value);
void queueTraverse (int* queue);
int delQueue (int* queue);
int queueSize();
void isempty(int *queue);

int main ()
{       
	printf("This queue has a maximum elements of 5\n\n\n");
	int queue[MaxSize];
	int del;
    addQueue(queue,1);
	addQueue(queue,2);
	addQueue(queue,3);  
	addQueue(queue,4);
	addQueue(queue,5);
	
	printf("size of queue is %d\n",queueSize());
	queueTraverse(queue);
	printf("Adding new element\n");      
	addQueue(queue,7);
	printf("size of queue is %d\n",queueSize());
	queueTraverse(queue);
	printf("Deleting an element\n");            
	del=delQueue(queue);
    printf("deleted element is:%d\n",del);
    printf("size of queue is %d\n",queueSize()); 
	queueTraverse(queue);
	// add new element to the free space    
	printf("Adding new element\n");     
	addQueue(queue,6);
    printf("size of queue is %d\n",queueSize()); 
	queueTraverse(queue);
	     
}

/// add new element to the queue
void addQueue (int* queue, int value)
{
	if ( (front==rear && front!=-1) || (front==-1 && rear >= MaxSize-1))
		{
		    printf("Error: queue is full ,you can't insert any element  \n");
		    
		}
	else
    {
		rear=(rear+1)%MaxSize;
		queue[rear]=value;
		counter++;
    }
}
/// remove element out of the queue
int delQueue (int* queue)
  {
      isempty(queue);
      int t1=front+1;
      int t2=rear;

      front=(front + 1) % MaxSize;
      int temp =queue[front];
      if (t1 == t2) // reset the queue
    	{ 
			 front = -1;
            rear = -1;
	    }
	counter--;
	return temp;
}


int queueSize()
{
	return counter;
}

/// print all queue elements
void queueTraverse (int* queue)
{    
      int temp = front + 1;
      if (front == -1 && rear == -1)
    {
        printf("Error: queue is empty\n");
		exit(0);
    }

     if (temp<rear)
    {
        printf("Queue elements are:\n");
        while (temp <= rear)
		{
			
			printf("queue[%d]=%d\n", temp, queue[temp]);
			temp++;
		}
	}
	else  if (rear<=temp)
    {   int x = temp;
        printf("Queue elements are:\n");
        while(x <= MaxSize-1)
        {   
			printf("queue[%d]=%d\n", x, queue[x]);
			x++;
		}
            int t=0;
           	while(t <= rear)
             {
			printf("queue[%d]=%d\n", t, queue[t]);
			t++;
		    }

    }
}
// check if the queue is empty
void  isempty(int *queue)
{
   if (front == rear && front == -1)
    {
     printf("Error:queue is empty\n");
		exit(0);
    }
}


