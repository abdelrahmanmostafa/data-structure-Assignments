// this program check for   parentheses 
# include<stdio.h>
#include<stdlib.h>

void push (int  *arr,int x);
void pop();
int top=-1;
bool isempty();
int main()
{
	char equation[100];
	int  stack[100];
    int counter=0;
	printf("Enter The Equation:\n");
    printf("Maximum Numbers of characters  in Equation is 100\n"); 
    printf("Note: Use brackets only please\n");
	scanf("%[^\n]%*c",equation);
	printf("\n");
    int i;
	
	for( i=0; i<100; i++)
	{       
                     
        if(equation[i]!='(' && equation[i]!=')')
        counter++;
		if(equation[i]=='(')
		push(stack,1);
		if(equation[i]==')')
		pop();
               
	}
	    if (counter==i)
            {
               printf("your equation doesn't contain any brackets!\n");
               exit(0);
            }
               
        if(isempty())
			printf("Parentheses is balanced  \n");
	    else
			printf("Parentheses is not balanced {opening without closing} \n");
	    return 0;
}

 void push (int *arr, int  x )
 {
      if (top+1 >= 99)
        {
             printf("you have excedded the allowable range of charcterss in the equation  !\n");
             exit(0);
        }
       arr[++top] = x;
}
 void pop()
 {
	top = top-1;
	if (top<-1)
	{
		printf(" parentheses is not balanced {closing  without opening}\n");
		exit(0);
	}
}
bool isempty()
{    
	if (top == -1)
		return true;
	else 
		return false;
}
