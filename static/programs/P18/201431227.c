#include<stdio.h>
#include<stdlib.h>
typedef struct ganja
{
	int data;
	struct ganja *next;
}ganja;
int visited[100005];
ganja *canwin[100005];
ganja *canlose[100005];
void addganja(int i,int j)
{
	ganja *temp=malloc(sizeof(ganja));//ganja rocks
	temp->data=j;
	temp->next=canlose[i];
	canlose[i]=temp;
	ganja *temp1=malloc(sizeof(ganja));//ganja rocks
	temp1->data=i;
	temp1->next=canwin[j];
	canwin[j]=temp1;
}
void printlist(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		ganja *temp=canwin[i];
	//	if(!temp)
			printf("%d ",i);
		while(temp!=NULL)
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}
		printf("\n");

	}
}
void dfs2(int i)
{
	visited[i]=1;
	ganja *temp=canlose[i];
	while(temp!=NULL)
	{
		if(!visited[temp->data])
			dfs2(temp->data);
		temp=temp->next;
	}
}
void dfs1(int i)
{
	visited[i]=1;
	ganja *temp=canwin[i];
	while(temp!=NULL)
	{
		if(!visited[temp->data])
			dfs1(temp->data);
		temp=temp->next;
	}
}
int check(int n )
{
	int i;
	for(i=1;i<=n;i++)
	{
//		printf("%d ",visited[i]);
		if(!visited[i])

			return 0;
	}
	return 1;
}
int countvisited(int n)
{
	int i;
	int count=0;
	for(i=1;i<=n;i++)
	{
		if(visited[i])
			count++;
	}
	return count;
}

int flushgraph(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		canwin[i]=NULL;
		canlose[i]=NULL;
	}
}

int flush(int n)
{
	int i;
	for(i=1;i<=n;i++)
		visited[i]=0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int i=1;
		for(;i<=n;i++)
		{
			int no;
			scanf("%d",&no);
			int j;
			for(j=0;j<no;j++)
			{
				int data;
				scanf("%d",&data);
				addganja(i,data);
			}
		}
		flush(n);
		for(i=1;i<=n;i++)
		{
			dfs1(i);

			if(check(n)==1)
				break;
			flush(n);
		}
		if(i==n+1)
			printf("0\n");
		else
		{
		//	printf(" winner is %d\n",i);
			flush(n);
			dfs2(i);
			printf("%d\n",countvisited(n));
			flush(n);
			flushgraph(n);
		
		}
	}
	return 0;
}

			









		
			





	
	

	

		
