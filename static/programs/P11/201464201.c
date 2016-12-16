#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
/*typedef struct node{
	long long int data;
	struct node* next;
}node;
node *stack;
node *stack1;
node* push_stack(int k)
{
	node* new=(node*)malloc(sizeof(node));
	new->data=k;
	new->next=stack;
	stack=new;
	free(new);
	return stack;
}
void pop_stack()
{
	if(stack==NULL)
		return;
//	node* temp=stack;
	stack=stack->next;
	return;
}
node* push_stack1(long long int k)
{
	node* new=(node*)malloc(sizeof(node));
	new->data=k;
	new->next=stack1;
	stack1=new;
//	free(new);
	return stack1;
}
void pop_stack1()
{
	if(stack1==NULL)
		return;
	stack1=stack1->next;
	return;
}*/
int main()
{
	long long int i,num,x,y,n,min,max=0,tot,point,j;
	long long int array[100005],arraya[100005],arrayb[100005],stack[100005];
	n=-1;
	while(n!=0)
	{
		point=-1;
		scanf("%lld", &n);
	//	stack=NULL;
	//	stack1=NULL;
		max=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld", &array[i]);
			if(i==0)
			{
		//		push_stack(i);
				point++;
				stack[point]=i;
				arraya[i]=-1;
			}
	//		else if(array[i]<=array[stack->data])
			else if(array[i]<=array[stack[point]])
			{
		//		while(array[i]<=array[stack->data])
				while(array[i]<=array[stack[point]])
				{
			//		pop_stack();
					point--;
				//	if(stack==NULL)
					if(point==-1)
					{
						break;
					}
				}
			//	push_stack(i);
				point++;
				stack[point]=i;
			//	if(stack->next==NULL)
				if(point==0)
				{
					arraya[i]=-1;
				}
				else
				{
			//		arraya[i]=stack->next->data;
					arraya[i]=stack[point-1];
				}
			}
			else 
			{
			//	push_stack(i);
				point++;
				stack[point]=i;
			//	arraya[i]=stack->next->data;
				arraya[i]=stack[point-1];
			}
		}
		point=0;
		for(i=n-1;i>=0;i--)
		{
			if(i==n-1)
			{
			//	push_stack1(i);
				stack[point]=i;
				arrayb[i]=n;
			}
	//		else if(array[i]<=array[stack1->data])
			else if(array[i]<=array[stack[point]])
			{
			//	while(array[i]<=array[stack1->data])
				while(array[i]<=array[stack[point]])	
				{
				//	pop_stack1();
					point--;
				//	if(stack1==NULL)
					if(point==-1)
					{
						break;
					}
				}
		//		push_stack1(i);
				point++;
				stack[point]=i;
			//	if(stack1->next==NULL)
				if((point-1)==-1)
				{
			//		printf("n=%d\n",n);
					arrayb[i]=n;
				}
				else
				{
			//		arrayb[i]=stack1->next->data;
					arrayb[i]=stack[point-1];
				}
			}
			else 
			{
			//	push_stack1(i);
				point++;
				stack[point]=i;
				//arrayb[i]=stack1->next->data;
				arrayb[i]=stack[point-1];
			}
	//		printf("%lld %lld %lld\n",array[i],arraya[i],arrayb[i]);
			tot=(arrayb[i]-arraya[i]-1)*array[i];
			if(tot>max)
			{
				max=tot;
			}

		}
		if(n!=0)
		{
			printf("%lld\n", max);
		}
	}
	return 0;
}


