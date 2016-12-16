#include<stdio.h>
#include<stdlib.h>

typedef struct ll
{
	struct ll *next;
	int data;

}node;

node *a[100001];
int prime[100001],nos[100001],visited[100001];

int sieve()
{
	

	int i,j;
	for(i=1;i<=10000;i++)
	{
		visited[i]=0;
		prime[i]=1;
		a[i]=NULL;
	}

	for(i=2;i<=10000;i++)
		if(prime[i]==1)
			for(j=2;i*j<=10000;j++)
				prime[i*j]=0;
	j=0;

	for(i=1000;i<=10000;i++)
		if(prime[i]==1)
			nos[j++]=i;
	return j;
}

void adjlist(int t1,int t2)
{
	if(t1==t2)
		return;

	node *temp=(node *)malloc(sizeof(node));

	temp->next=a[t1];
	a[t1]=temp;
	temp->data=t2;

	temp=(node *)malloc(sizeof(node));
	temp->next=a[t2];
	a[t2]=temp;
	temp->data=t1;

}


int makeno(int a,int b,int c,int d)
{

	return a + 10*b + 100*c + 1000*d;
}

void dfs(int index,int depth,int t2)
{

	visited[index]=depth;

	if(index==t2)
		return;

	node *temp=a[index];
	while(temp)
	{
		if(visited[temp->data]==0)
		{
			//dfs(temp->data,depth+1,t2);
//			putinqueue(temp->data);
		}
		temp=temp->next;
	}


}

int queue[2][100001],start=0,end=0;
int aans[100001];

void bfs(int index,int t2)
{
	
	int count=0;

	queue[0][start]=index;
	queue[1][start]=count;
	start++;
	visited[index]=1;
	aans[start]=count;

	int n=1;

//	printf("%d %d %d",queue[0][start-1],queue[1][start-1],count);

	while(start!=end)
	{
		int ans=queue[0][end];	
		count=queue[1][end];
		end++;
		node *temp=a[ans];
		aans[ans]=count;

		if(ans==t2)
			break;

		while(temp)
		{
			if(visited[temp->data]==0)
			{
				queue[0][start]=temp->data;
				queue[1][start]=count+1;
				start++;
				visited[temp->data]=1;
			}

			temp=temp->next;
		}

	}


}

	int final[1100][1100];

int main()
{

int i,j;
	int no=sieve();

	for(i=0;i<no;i++)
	{
		int temp=nos[i];

		int t1,t2,t3,t4;
		t1=temp%10;	temp/=10;
		t2=temp%10;	temp/=10;
		t3=temp%10;	temp/=10;
		t4=temp%10;

		for(j=0; j<10&&j!=t1; j++)
		{
			int temp2=makeno(j,t2,t3,t4);

			if(prime[temp2]==1)
			{
				adjlist(nos[i],temp2);
			}
		}

		for(j=0; j<10&&j!=t2; j++)
		{
			int temp2=makeno(t1,j,t3,t4);

			if(prime[temp2]==1)
				adjlist(nos[i],temp2);

		}

		for(j=0; j<10&&j!=t3; j++)
		{
			int temp2=makeno(t1,t2,j,t4);

			if(prime[temp2]==1)
				adjlist(nos[i],temp2);

		}
	
		for(j=1; j<10&&j!=t4; j++)
		{
			int temp2=makeno(t1,t2,t3,j);

			if(prime[temp2]==1)
				adjlist(nos[i],temp2);

		}
	}


/*	node *temp=a[1033];
	
	while(temp)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}

	temp=a[1013];
	
	while(temp)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
*/

/*	for(i=0;i<no;i++)
	{
		visited[nos[i]]=0;
		aans[i]=-1;

		bfs(i);

		final[i][j]=
	
	
	}

*/
	int t;
	scanf("%d",&t);

	while(t--)
	{
		start=0;end=0;

		for(i=0;i<no;i++)
		{
			visited[nos[i]]=0;
//			queue[0][i]=0;
//			queue[1][i]=0;
			aans[i]=-1;
		}

		int t1,t2;
		scanf("%d %d",&t1,&t2);

//		dfs(t1,1,t2);
		bfs(t1,t2);

		
		printf("%d\n",aans[t2]);
	
	}

	return 0;
}
