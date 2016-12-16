#include<stdio.h>
#include<malloc.h>
struct stack
{
	int top;
	int arr[1000010];
}st;
void push(int val)
{
	st.top++;
	st.arr[st.top]=val;
}
int pop()
{
	if(st.top>=0)
	{
		int y=st.arr[st.top];
		st.top--;
		return y;
	}
}
struct link
{
	int data;
	struct link *next;
}*shubh[1000010];
int main()
{
	int test,n,j,n1,max,currnode,n2,i,height[1000010],visited[1000010],x;

	struct link *temp;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		//printf("no of nodes\n");
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			shubh[j]=malloc(sizeof(struct link));
			shubh[j]->data=j;
			shubh[j]->next=NULL;
		}
		for(j=1;j<n;j++)
		{
			scanf("%d%d",&n1,&n2);
			temp=malloc(sizeof(struct link));
			temp->data=n2;
			temp->next=shubh[n1]->next;
			shubh[n1]->next=temp;
			temp=malloc(sizeof(struct link));
			temp->data=n1;
			temp->next=shubh[n2]->next;
			shubh[n2]->next=temp;
		}
		for(j=1;j<=n;j++)
		{
			visited[j]=0;
		}
		st.top=-1;
		push(1);
		visited[1]=1;
		height[1]=1;
		max=1;
		while(st.top>=0)
		{
			x=pop();
			//printf(" the popped is%d\n",x);
			temp=shubh[x]->next;
			while(temp!=NULL)
			{
				if(visited[temp->data]==0)
				{
					visited[temp->data]=1;
					push(temp->data);
					height[temp->data]=height[x]+1;
					if(height[temp->data]>max)
					{
						max=height[temp->data];
						currnode=temp->data;
					}
					// printf("%d xx and node is %d \n",height[temp->data],temp->data);
				}
				temp=temp->next;
			}


		}

		for(j=1;j<=n;j++)
		{
			visited[j]=0;
		}
		st.top=-1;
		push(currnode);
		visited[currnode]=1;
		height[currnode]=1;
		max=1;
		while(st.top>=0)
		{
			x=pop();
			//printf(" the popped is%d\n",x);
			temp=shubh[x]->next;
			while(temp!=NULL)
			{
				if(visited[temp->data]==0)
				{
					visited[temp->data]=1;
					push(temp->data);
					height[temp->data]=height[x]+1;
					if(height[temp->data]>max)
					{
						max=height[temp->data];
						currnode=temp->data;
					}
					// printf("%d xx and node is %d \n",height[temp->data],temp->data);
				}
				temp=temp->next;
			}


		}

	printf("%d\n",max);
	}
	return 0;
}







