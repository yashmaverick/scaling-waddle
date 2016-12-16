#include<stdio.h>
#include<malloc.h>
int gc=0;
struct stack
{
	int top;
	int arr[1001];
}st;
void push(int val)
{
	st.top++;
	st.arr[st.top]=val;
}
int  pop()
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
}*shubh[1001];
int main()
{
	int test,i,j,k,n,n1,a,visited[1001],reachable[1001],flag,t,count;
	struct link *temp;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		st.top=-1;
		int count1=0;
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			shubh[j]=malloc(sizeof(struct link));
			shubh[j]->data=j;
			shubh[j]->next=NULL;
		}
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a);
			for(k=1;k<=a;k++)
			{
				scanf("%d",&n1);
				temp=malloc(sizeof(struct link));
				temp->data=j;
				temp->next=shubh[n1]->next;
				shubh[n1]->next=temp;
			}
		}

		//for printing the formed adjacency list
		/*for(j=1;j<=n;j++)
		{
			temp=shubh[j]->next;
			while(temp!=NULL)
			{
				printf("%d->",temp->data);
				temp=temp->next;
			}
			printf("\n\n");
		}*/
		for(j=1;j<=n;j++)
		{
			visited[j]=0;
		        reachable[j]=0;
		}
		for(t=1;t<=n;t++)	
		{
                         gc=t;
			int count=0,flag=0;
			st.top=-1;

			//for(j=1;j<=n;j++)
		//	{
		//		visited[j]=0;
		//	//	reachable[j]=0;
		//	}
			push(t);
			visited[t]=gc;
			while(st.top>=0)
			{
				int x=pop();
				temp=shubh[x]->next;
				while(temp!=NULL)
				{
					if(visited[temp->data]!=gc)
					{
						visited[temp->data]=gc;
						count++;
						if(reachable[temp->data]==1)
						{
							reachable[t]=1;
							count1++;
							flag=1;
							break;
						}
						push(temp->data);
						//temp=temp->next;
					}
				temp=temp->next;
				}
				if(flag==1)
				{
					break;
				}
			    
			       if(count==n-1)
			       {
				       break;
			       }
			}
			if(flag==0 && count==n-1)
			{
				reachable[t]=1;
			        count1++;
			}
		//printf("xxxxx\n");
		}
		count=0;
		//for(t=1;t<=n;t++)
		//{
		//	if(reachable[t]==1)
		//		count++;
		//}
		printf("%d\n",count1);
	}
	return 0;
}

















