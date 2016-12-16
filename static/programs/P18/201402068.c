#include <stdio.h>
#include <stdlib.h>
typedef struct ll
{
	int d;
	struct ll *next;
}ll;
int head=-1;
//int tail=-1;
int elements=0;
void push(int x);
int pop();
int stack[10000];
ll *a[10000];
ll *b[10000];
int main()
{
	int t,n;
	int x,y;
	scanf("%d",&t);
	ll *temp;
	ll *temp2;
	while(t--)
	{
		scanf("%d",&n);
		int i;
		for(i=0;i<=n;i++)
		{
			a[i]=NULL;
			b[i]=NULL;
		}
		for(i=1;i<=n;i++)
			//representing a graph using adjacency list
		{

			x=i;
			int N;
			scanf("%d",&N);
			while(N--)

			{
				scanf("%d",&y);

				temp=(ll*)malloc(sizeof(ll));
				temp2=(ll*)malloc(sizeof(ll));
				temp2->d=y;
				temp2->next=NULL;
				temp->d=x;
				temp->next=NULL;
				if(a[y]==NULL)
				{   a[y]=malloc(sizeof(ll));
					a[y]=temp;
				}
				else
				{   
					temp->next=a[y];
					a[y]=temp;
				}
				if(b[x]==NULL)
				{
					b[x]=malloc(sizeof(ll));
					b[x]=temp2;
				}
				else
				{
					temp2->next=b[x];
					b[x]=temp2;
				}
			}

		}
		ll *te;
	/*	for(i=1;i<=n;i++)
		{
			te=a[i];
			printf("%d ",i);
			while(te!=NULL)
			{
				printf("%d ",te->d);
				te=te->next;
			}
			printf("\n");
		}*/

		int count=0;
		int sum=0;
		int flag=0;
		for(i=1;i<=n;i++)
		{
		int visited[10000]={};

			count=0;
			push(i);
			visited[i]=1;
			int tr;
			while(elements!=0)//depth first search
			{  
				tr=pop();
				te=a[tr];
				count++;
				//printf("%d ",tr);
				while(te!=NULL)
				{
					if(visited[te->d]!=1)
					{
						push(te->d);
						visited[te->d]=1;
					}
					te=te->next;
				}
			}
			if(count==n)
			{
				flag=1;
				break;
			}
			//printf("\n");

		}
		//dfs again on b[]
		if(flag==1)
		{
		int visited[10000]={};
		push(i);
		visited[i]=1;
		int tr;
		while(elements!=0)
		{
			tr=pop();
			te=b[tr];
			sum++;
			while(te!=NULL)
			{
				if(visited[te->d]!=1)
				{
					push(te->d);
					visited[te->d]=1;
				}
				te=te->next;
			}
		}
		}
		printf("%d\n",sum);



	}

	return 0;
}
void push(int x)
{
	if(head==-1)
	{
		head++;
		stack[head]=x;
		elements++;
	}
	else
	{
		elements++;
		stack[++head]=x;
	}
}
int pop()
{
	if(elements!=0)
	{
		elements--;
		return stack[head--];
	}
	return 0;
}
