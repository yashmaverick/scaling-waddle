#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct adj{
	long long val;
	struct adj *link;
}adj;

long long front=-1,rear=-1;
long long queue[10006];
adj *list[10006];
int sieve[10000];
void mrsieve()
{
	int i,j;
	for(i=2;i*i<=10000;i++)
	{
		if(sieve[i]==1)
		{
			for(j=2*i;j<=10000;j+=i)
			{
				sieve[j]=0;
			}
		}
	}
}
void insert(long long x)
{
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	else
		rear++;
	queue[rear]=x;
}
long long delete()
{
	long long ele;
	ele=queue[front++];
	if(front>rear)
	{
		front=-1;
		rear=-1;
	}
	return ele;
}
int main()
{
	long long testcase,i;
	scanf("%lld",&testcase);
	for(i=2;i<10000;i++)
		sieve[i]=1;
	mrsieve();
	for(i=1009;i<=9973;i++)
		list[i]=NULL;
	for(i=1009;i<=9973;i++)
	{
		if(sieve[i]==1)
		{
			list[i]=NULL;
			long long thing=i;
			int arr[4];
			int kl=3;
			while(thing)
			{
				int rem=thing%10;
				arr[kl--]=rem;
				thing/=10;
			}
			int way,grey;
			for(kl=0;kl<4;kl++)
			{
				int yi;
				way=arr[kl];
				if(kl==0)
					grey=1;
				else
					grey=0;
				for(yi=grey;yi<=9;yi++)
				{
					arr[kl]=yi;
					int tempans=arr[0]*1000+arr[1]*100+arr[2]*10+arr[3];
					//if(tempans==8017)
					//	printf("Yes\n");
					if(sieve[tempans]==1)
					{
						adj *temp=(adj*)malloc(sizeof(adj));
						temp->val=tempans;
						//temp->w=0;
						temp->link=list[i];
						list[i]=temp;
						adj *temp2=(adj*)malloc(sizeof(adj));
						temp2->val=i;
						temp2->link=list[tempans];
						//temp2->w=0;
						list[tempans]=temp2;
					}

				}
				arr[kl]=way;
			}
		}

	}

	while(testcase--)
	{
		long long count=0,i,m,n;
		scanf("%lld %lld",&n,&m);
		int visited[10006];
		long long weight[10006];
		for(i=0;i<10006;i++)
		{
			visited[i]=0;
			weight[i]=0;
		}
		front=-1;
		rear=-1;
		insert(n);
		visited[n]=1;
		weight[n]=0;
		int flag=0;
		if(n==m)
			printf("0\n");
		else
		{
		while(rear!=-1)
		{
			n=delete();
			adj*temp=list[n];
			while(temp!=NULL)
			{
				
				if(visited[temp->val]==0)
				{
					visited[temp->val]=1;
					weight[temp->val]=weight[n]+1;
					if(m==temp->val)
					{
						flag=1;
						break;
					}
					insert(temp->val);
				}
				temp=temp->link;
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			printf("%lld\n",weight[m]);
		else
			printf("Impossible\n");
		}

	}
	return 0;
}
