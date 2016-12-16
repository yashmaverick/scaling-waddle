#include <stdio.h>
#include <stdlib.h>
//sdashdfjasf
//ddsadfsafa


typedef struct ll
{
	int d;
	struct ll *next;
}ll;
int head=-1;
//int tail=-1;
int elements=0;
void push(int x,int i);
int pop();
int stack[1000001];
int count[1000001];
ll *a[1000001];
int main()
{
	int n,m;
	int x,y;
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		m=n-1;
		ll *temp;
		ll *temp2;
		int N=m;
		int i;
		int visited[1000001]={0};
		for(i=1;i<=n;i++)
			a[i]=NULL;
		//representing a graph using adjacency list
		while(N--)
		{
			scanf("%d%d",&x,&y);
			temp=(ll*)malloc(sizeof(ll));
			temp2=(ll*)malloc(sizeof(ll));
			temp->d=y;
			temp->next=NULL;
			if(a[x]==NULL)
			{   a[x]=malloc(sizeof(ll));
				a[x]=temp;
			}
			else
			{   
				temp->next=a[x];
				a[x]=temp;
			}
			temp2->d=x;
			temp2->next=NULL;
			if(a[y]==NULL)
			{
				a[y]=(ll*)malloc(sizeof(ll));
				a[y]=temp2;
			}
			else
			{
				temp2->next=a[y];
				a[y]=temp2;
			}

			/*for(i=1;i<=n;i++)
			  {
			  printf("%d->",i);
			  while(a[i]!=NULL)
			  {
			  printf("%d ",a[i]->d);
			  a[i]=a[i]->next;
			  }
			  printf("\n");
			  }*/

		}

		ll *te;
/*		for(i=1;i<=n;i++)
		{
			printf("%d->",i);
			te=a[i];
			while(te!=NULL)
			{
				printf("%d ",te->d);
				te=te->next;
			}
			printf("\n");
		}*/
		int j=1;
		i=0;
		//scanf("%d",&j);
		push(j,i);
		visited[j]=1;
		int t;int max=0;
		int node;
		while(elements!=0)//dfs first search
		{  
			t=pop();
			i=count[head+1]+1;
			if(max<count[head+1])
			{
				max=count[head+1];
				node=t;
			}

			te=a[t];
			//printf("%d ",t);
			while(te!=NULL)
			{
				if(visited[te->d]!=1)
				{
					push(te->d,i);
					visited[te->d]=1;
				}
				te=te->next;
			}

		}
	//	printf("max first%d\n",max);

		i=0;
		push(node,i);
		for(j=0;j<=n;j++)
			visited[j]=0;
		visited[node]=1;


		max=0;
		while(elements!=0)//dfs first search
		{  
			t=pop();
			i=count[head+1]+1;
			if(max<count[head+1])
			{
				max=count[head+1];
			}

			te=a[t];
			//printf("%d ",t);
			while(te!=NULL)
			{
				if(visited[te->d]!=1)
				{
					push(te->d,i);
					visited[te->d]=1;
				}
				te=te->next;
			}

		}

		printf("%d\n",(max+1));
	}


	return 0;
}
void push(int x,int i)
{
	if(head==-1)
	{
		head++;
		stack[head]=x;
		count[head]=i;
		elements++;
	}
	else
	{
		elements++;
		stack[++head]=x;
		count[head]=i;
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
