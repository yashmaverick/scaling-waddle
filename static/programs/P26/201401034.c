#include<stdio.h>
#include<stdlib.h>
#define MAX 100000000

struct Node{
	int val;
	struct Node* next;
};

struct Queue{
	int val;
	struct Queue* next;
};

int a,b;
int queue[1000000]={0};
int head=-1;
int tail=-1;

int marked[10000]={0};
int counter[10000]={MAX};

struct Node* mylist[10000]={NULL};
int primes[10000]={0};
int ans=0;

void enqueue(int x)
{
	head++;
	queue[head]=x;
}
void dequeue()
{
	if(head==tail && head!=-1)
	{
		head=-1;
		tail=-1;
	}
	else
	{
		tail++;
	}
}

int front()
{
	if(tail!=-1)
		return queue[tail];
}

void bfs()
{
	int val;
	marked[front()]=1;
	while(1)
	{
		if(tail==head && head==-1)
			return;
		val=front();
		dequeue();
		struct Node* temp=mylist[val];
		while(temp!=NULL)
		{
			if(marked[temp->val]==0)
			{
				marked[temp->val]=1;
				enqueue(temp->val);
				counter[temp->val]+=counter[val]+1;
				if(temp->val==b)
					return;
			}
			temp=temp->next;
		}
	}
}

void addedge(int a, int b)
{
	struct Node* temp=malloc(sizeof(struct Node));
	temp->val=a;
	temp->next=mylist[b];
	mylist[b]=temp;
	struct Node* temp2=malloc(sizeof(struct Node));
	temp2->val=b;
	temp2->next=mylist[a];
	mylist[a]=temp2;
}

void checkprimes(int i)
{
	int dig1,dig2,dig3,dig4;
	dig1=i%10;
	i=i/10;
	dig2=i%10;
	i=i/10;
	dig3=i%10;
	i=i/10;
	dig4=i%10;
	int ii,jj,kk,ll;
	for(ii=1;ii<10;ii++)
	{
		if(primes[(ii*1000+dig3*100+dig2*10+dig1)]==1)
		{
			addedge(dig4*1000+dig3*100+dig2*10+dig1,ii*1000+dig3*100+dig2*10+dig1);
		}
	}
	for(ii=0;ii<10;ii++)
	{
		if(primes[(dig4*1000+ii*100+dig2*10+dig1)]==1)
		{
			addedge(dig4*1000+dig3*100+dig2*10+dig1,dig4*1000+ii*100+dig2*10+dig1);
		}
	}
	for(ii=0;ii<10;ii++)
	{
		if(primes[(dig4*1000+dig3*100+ii*10+dig1)]==1)
		{
			addedge(dig4*1000+dig3*100+dig2*10+dig1,dig4*1000+dig3*100+ii*10+dig1);
		}
	}
	for(ii=0;ii<10;ii++)
	{
		if(primes[(dig4*1000+dig3*100+dig2*10+ii)]==1)
		{
			addedge(dig4*1000+dig3*100+dig2*10+dig1,dig4*1000+dig3*100+dig2*10+ii);
		}
	}
}

void makegraph()
{
	int j,i,state;
	primes[0]=0;
	primes[1]=0;
	for(i=2;i<=9999;i++)
	{
		if(primes[i]==1)
		{
			for(j=2;j*i<=9999;j++)
				primes[j*i]=0;
		}
	}
	for(i=1000;i<=9999;i++)
		if(primes[i]==1)
			checkprimes(i);
}

int main()
{
	int n,m,i,j,k,c,tc;
	for(i=0;i<=9999;i++)
		primes[i]=1;
	makegraph();
	scanf("%d", &tc);
	for(i=0;i<tc;i++)
	{
		head=-1;
		tail=-1;
		for(j=0;j<10000;j++)
		{
			ans=0;
			marked[j]=0;
			counter[j]=0;
		}
		scanf("%d%d", &a, &b);
		enqueue(a);
		marked[a]=1;
		counter[a]=0;
		bfs();
		printf("%d\n", counter[b]);
	}
	return 0;
}
