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
	int i,num,x,y,n,min,max=0,tot,point,j,test,t,maxele;
	int array[100005],stack[100005];
	scanf("%d", &test);
	for(t=0;t<test;t++)
	{
		int arraya[100005];
		point=-1;max=0;maxele=0;
		scanf("%d", &n);
	//	stack=NULL;
	//	stack1=NULL;
		max=0;
		for(i=n-1;i>=0;i--)
		{
			arraya[i+1]=0;
			scanf("%d", &array[i]);
		}
		for(i=0;i<n;i++)
		{
			if(i==0)
			{
		//		push_stack(i);
				point++;
				stack[point]=i;
				arraya[i]=0;
				maxele=array[stack[point]];
			}
	//		else if(array[i]<=array[stack->data])
			else if(array[i]<=array[stack[point]])
			{
		//		while(array[i]<=array[stack->data])
				while(array[i]<=array[stack[point]])
				{
			//		pop_stack();
					num=stack[point];
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
				arraya[array[i]]=arraya[array[num]]+1;
				if(arraya[array[i]]==max)
				{
					if(array[stack[point]]<maxele)
					{
						maxele=array[stack[point]];
					}
				}
				if(arraya[array[i]]>max)
				{
					max=arraya[array[i]];
					maxele=array[stack[point]];
				}
			}
			else 
			{
			//	push_stack(i);	
				num=stack[point];
				point++;
				stack[point]=i;
			//	arraya[i]=stack->next->data;
				arraya[array[i]]=arraya[array[num]]+1;
				if(arraya[array[i]]==max)
				{
					if(array[stack[point]]<maxele)
					{
						maxele=array[stack[point]];
					}
				}
				if(arraya[array[i]]>max)
				{
					max=arraya[array[i]];
					maxele=array[stack[point]];
				}
			}
		}
		printf("%d %d\n", maxele,max);
	}
	return 0;
}


