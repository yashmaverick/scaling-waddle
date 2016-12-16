#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100009
int dist[MAX];
int queue[MAX];
int prime[MAX]={0},check[MAX]={0};
typedef struct node
{
	int val;
	struct node* next;
}node;
node* A[MAX];
node* insert(node* head,int x)
{
	node* temp=malloc(sizeof(int));
	temp->val=x;
	temp->next=head;
	return temp;
}
void genprime()
{
	int i,j;
	prime[0]=1,prime[1]=1;
	for(i=2;i<=9999;i++)
	{
		if(prime[i]==0)
		{
			for(j=2;j*i<=9999;j++)
				prime[i*j]=1;
		}
	}
}
int bfs(int src, int b)
{
	memset(dist,-1,sizeof(dist));
	int front=0,rear=0,i,m=-2,mm=0;
	dist[src]=0;
	queue[rear++]=src;
	while(front!=rear)
	{
		int p=queue[front];
		front++;
		node * tmp=A[p];
		while(tmp!=NULL)
		{
			if(dist[tmp->val]==-1)
			{
				queue[rear++]=tmp->val;
				dist[tmp->val]=dist[p]+1;
			}
			if(tmp->val==b)
			{
				mm=1;
				break;
			}
			tmp=tmp->next;
		}
		if(mm==1)
			break;
	}
	return dist[b];
}

/*int dfs(int a,int b,int lev)
{
	node* temp=A[a];
	check[a]=1;
	int c;
	while(temp!=NULL)
	{
		printf("%d\n",temp->val);
		if(temp->val==b)
			return lev;
		if(check[temp->val]==0)
			c=dfs(temp->val,b,lev+1);
		temp=temp->next;
	}
	return c;
}*/
int main()
{
	int i,tc,a,b,d1,d2,d3,d4,t,j,temp,ans;
	genprime();
	i=1033;
	for(i=1000;i<=9999;i++)
	{
		if(prime[i]==0)
		{
			t=i;
			d4=t%10;
			t/=10;
			d3=t%10;
			t/=10;
			d2=t%10;
			t/=10;
			d1=t%10;
			for(j=1;j<=9;j++)
			{
				temp=j*1000+d2*100+d3*10+d4;
				if(temp!=i && prime[temp]==0)
				{
					//		printf("%d\n",temp);
					A[i]=insert(A[i],temp);
					A[temp]=insert(A[temp],i);
				}
			}
			for(j=0;j<=9;j++)
			{
				temp=d1*1000+j*100+d3*10+d4;
				if(temp!=i && prime[temp]==0)
				{
					//		printf("%d\n",temp);
					A[i]=insert(A[i],temp);
					A[temp]=insert(A[temp],i);
				}
			}
			for(j=0;j<=9;j++)
			{
				temp=d1*1000+d2*100+j*10+d4;
				if(temp!=i && prime[temp]==0)
				{
					//		printf("%d\n",temp);
					A[i]=insert(A[i],temp);
					A[temp]=insert(A[temp],i);
				}
			}
			for(j=0;j<=9;j++)
			{
				temp=d1*1000+d2*100+d3*10+j;
				if(temp!=i && prime[temp]==0)
				{
					//		printf("%d\n",temp);
					A[i]=insert(A[i],temp);
					A[temp]=insert(A[temp],i);
				}
			}
		}

	}
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d%d",&a,&b);
		ans=bfs(a,b);
		if(ans!=-1)
			printf("%d\n",ans);
		else
			printf("Impossible\n");
	}
	return 0;
}
