#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
node *a[10005];
void addedge(int i,int j)
{
	node *temp=malloc(sizeof(node));
	temp->data=j;
	temp->next=a[i];
	a[i]=temp;
}
int check(int a,int b)
{
	int cnt=0;
	while(a!=0)
	{
		if(a%10==b%10)
			cnt++;
		a/=10;
		b/=10;
	}
	if(cnt==3)
		return 1;
	return 0;
}
int primes[10005];
int q[10005];
int vis[10005];
int lev[10005];
int  bfs(int i,int j)
{
	int front=0;
	int rear=0;
	q[front]=i;
	lev[i]=0;
	vis[i]=1;
	while(front<=rear)
	{
		node *temp=a[q[front]];
		while(temp!=NULL)
		{
			if(!vis[temp->data])
			{
				rear++;
				q[rear]=temp->data;
				vis[temp->data]=1;
				lev[temp->data]=lev[q[front]]+1;
			}
			temp=temp->next;
		}
		front++;
	}
	return lev[j]-lev[i];
}
int fpr[1005];
int main()
{
	int i;
	primes[1]=1;
	for(i=2;i<10004;i++)
	{
		if(primes[i]==0)
		{
			int j=2;
			for(;j*i<10004;j++)
			{
				primes[j*i]=1;
			}
		}
	}
	int cnt=0;
	for(i=1000;i<10000;i++)
	{
		if(primes[i]==0)
		{
			fpr[cnt]=i;
			cnt++;
		}
	}
	
	for(i=0;i<cnt;i++)
	{
	//	printf("%d\n",fpr[i]);
		int j;
		for(j=i+1;j<cnt;j++)
		{
			if(check(fpr[i],fpr[j]))
			{
				addedge(fpr[i],fpr[j]);
				addedge(fpr[j],fpr[i]);
			}
		}
				
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int p1,p2;
		scanf("%d%d",&p1,&p2);
		if(p1==p2)
			printf("0\n");
		else
		{
			printf("%d\n",bfs(p1,p2));
		}
		for(i=0;i<cnt;i++)
		{
			vis[fpr[i]]=0;
		}
		
		

	}
	return 0;
}

			
	



	
	
	
	
