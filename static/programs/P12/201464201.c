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
//	node* temp=*/
int main()
{
	long long int i,num,x,y,n,min,max=0,tot,point,j,count,final,ans,q;
	long long int array[500005],stack[500005];
	n=-1;
	while(n!=0)
	{
		count=0;
		point=-1;
		scanf("%lld", &n);
		max=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld", &array[i]);
			if(i==0)
			{
		//		printf("count%lld\n", count);
		//		push_stack(i);
				point++;
				stack[point]=i;
			//	arraya[i]=-1;
			}
	//		else if(array[i]<=array[stack->data])
			else if(array[i]>array[stack[point]])
			{
		//		while(array[i]<=array[stack->data])
				while(array[i]>array[stack[point]])
				{
			//		pop_stack();
					point--;
					count++;
					if(point==-1)
					{
						break;
					}
			//		printf("-1\n");
			//		printf("%lld\n", count);
				}
				q=point;
			//	printf("q%lld\n", q);
				while(q!=-1 && array[i]==array[stack[q]])
				{
					q--;
					count++;
				//	printf("%lld\n", count);
					if(q==-1)
					{
						break;
					}
				}
				if(q!=-1 && array[i]<array[stack[q]])
				{
					count++;
				}
			//	push_stack(i);
				point++;
				stack[point]=i;
		//		count++;
			//	if(stack->next==NULL)
				if(point==0)
				{
				//	arraya[i]=-1;
				}
				else
				{
			//		arraya[i]=stack->next->data;
				//	arraya[i]=stack[point-1];
				}
			}
			else if(array[i]==array[stack[point]])
			{
				q=point;
			//	count++;
				while(array[stack[q]]==array[i])
				{
					q--;
					count++;
					if(q==-1)
					{
						break;
					}
				}
				if(q != -1 && array[stack[q]]>array[i] )
				{
					count++;
				}
				point++;
				stack[point]=i;
			//	count++;
			}

			else 
			{
			//	push_stack(i);
				point++;
				stack[point]=i;
				count++;
			//	arraya[i]=stack->next->data;
			//	arraya[i]=stack[point-1];
			}
		//	printf("count=%lld i=%lld\n", count,i);
		}
	/*	point=0;
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

		}*/
	/*		if(arraya[i]<0)
			{
				arraya[i]=0;
			}
			else
			{
				arraya[i]=i-array[i]+1;
			}*/
	//		printf("%lld %lld\n", arraya[i], arrayb[i]);
		final=(n*(n-1))/2;
		ans=final-count;
		if(n!=0)
		printf("%lld\n", ans);
	}
	return 0;
}


