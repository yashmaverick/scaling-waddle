#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int p[1000000]={0};
int a[1000004];
int visited[1000000];
int front =-1;
int rear=-1;
int vis[1000004];
void prime();
void enq(int x)
{
	if(front ==-1 && rear==-1)
	{
		front=0;
		rear=0;
	}
	else
		rear++;
	a[rear]=x;
}
int deq()
{
	if(front==-1)
		return 0;
	else{
		int temp=a[front];
		front++;
		return temp;
	}
}
int peek()
{
	return a[front];
}
void todu(int arr[],int x)
{
	int i;
	for(i=0;i<=3;i++)
	{
		arr[3-i]=x%10;
		x=x/10;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	memset(p,0,10000);
	prime();
	while(t--)
	{
		front=-1;
		rear=-1;
		int t1,i,j,n,x,q,s;
		int str,end;
		int arr[4];
		scanf("%d %d",&str,&end);
		for(i=0;i<10000;i++)
		{
			vis[i]=-1;
			visited[i]=0;
		}
		//memset(vis,-1,200000);
		//memset(visited,0,200000);

		enq(str);
		vis[str]=0;
		visited[str]=1;
		//todu(arr,str);
		//for(i=0;i<=3;i++)
		//	printf("%d ",arr[i]);
		//	printf("%d",x);
		while((rear!=front || (front==0 && rear==0)))
		{
			x=peek();
			deq();
			//printf("\n");
			//todu(arr,x);
			for(i=3;i>=0;i--)
			{
				todu(arr,x);
				for(j=0;j<=9;j++)
				{
					if(i==3 && j==0)
						continue;
					arr[i]=j;
					//printf("%d ",t1);
					s=0;q=0;
					while(q<4)
					{
						s =((s*10) + arr[q++]);
					}
					t1=s;	
					if(p[t1]==0 && t1>=1000 && visited[t1]!=1)
					{
						vis[t1]=vis[x]+1;
						//printf("%d ",t1);
						visited[t1]=1;
						enq(t1);
						if(t1==end)
							break;


					}
				}
				if(t1==end)
					break;

			}
			if(t1==end)
				break;
		}
		//	for(i=0;i<100;i++)
		if(vis[end]!=-1)
			printf("%d\n",vis[end]);
		else
			printf("Impossible\n");
	}
	return 0;
}
void prime()
{
	int i,j;
	for(i=2;i<=100;i++)
	{
		if(p[i]==0)
		{
			for(j=i*i;j<=10000;j=j+i)
			{
				p[j]=1;
			}
		}
	}
}

