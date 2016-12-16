#include<stdio.h>
#include<assert.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int cmpfunc (const void *a , const void *b)
{
	return *(int *)a - *(int *)b ;
}

#define gi(x) scanf("%d",&x)
#define pi(x) printf("%d",x)
#define gc(x) scanf("%c",&x)
#define pc(x) printf("%c",x)
#define glli(x) scanf("%lld",&x)
#define plli(x) printf("%lld",x)
#define gllu(x) scanf("%llu",&x)
#define pllu(x) printf("%llu",x)
#define endl printf("\n")
#define tab printf("\t")
#define space printf(" ")
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b

void parr(int array[],int start,int end)
{
	int i;
	for (i=start; i<=end; i++)
	{
		pi(array[i]);
		space;
	}
	endl;
	return ;
}

void set_arr(int array[],int start,int end,int n)
{
	int i;
	for(i=start;i<=end;i++)
		array[i] = n;
	return ;
}

int vis[10010];
int prime[10010];
int fin[10010];
int count=0;


typedef struct vertex
{
	struct vertex *adj;
	int data;
}vertex;

vertex *head[10001];

void insert(int index,int val)
{
	vertex *temp;
	temp = (vertex *)malloc(sizeof(vertex));
	temp->data = val;
	temp->adj = NULL;
	if(head[index] == NULL)
	{
		head[index] = (vertex *)malloc(sizeof(vertex));
		head[index] = temp;
	}
	else
	{
		temp->adj = head[index];
		head[index] = temp;
	}
	return ;
}

int ans;
int num,num2;
int dist[10000],queue[10000];
int start,end;

void bfs()
{
	int p;
	p = queue[start];
	vertex *temp;
	temp = malloc(sizeof(vertex));
	temp = head[p];
	while(temp != NULL)
	{
		if(vis[temp->data] == 0)
		{
			queue[++end] = temp->data;
			dist[temp->data] = dist[p] + 1;
			vis[temp->data] = 1;
			if(temp->data == num2)
				return ;
//			pi(dist[temp->data]);
//			endl;
		}
		temp = temp->adj;
	}
	vis[p] = 2;
	start++;
	if(end < start)
		return ;
	bfs();
}

void sieve()
{
	set_arr(prime,0,10000,0);
	int i,j,temp;
	for(i=2;i<10000;i++)
	{
		if(prime[i] == 1)
			continue;
		j = 2;
		do
		{
			temp = i*j;
			if(temp > 10000)
				break;
			prime[temp] = 1;
			j++;
		}while(temp<10000);
	}
	return ;
}

void mapping()
{
	int i,num,temp,j,dig;
	for(i=1000;i<10000;i++)
	{
		if(prime[i] == 0)
			fin[count++] = i;
	}
	for(i=0;i<count;i++)
	{
		num = fin[i];
		temp = num;
		dig = num%10;
		j = dig;
		while(j<=8 && temp < 10000)
		{
			temp = temp + 1;
			if(prime[temp] == 0)
			{
				insert(num,temp);
				insert(temp,num);
			}
			j++;			
		}
		temp = num;
		dig = (num/10)%10;
		j = dig;
		while(j<=8 && temp < 10000)
		{
			temp  = temp + 10;
			if(prime[temp] == 0)
			{
				insert(num,temp);
				insert(temp,num);
			}
			j++;
		}
		temp = num;
		dig = ((num/10)/10)%10;
		j = dig;
		while(j<=8 && temp < 10000)
		{
			temp = temp + 100;
			if(prime[temp] == 0)
			{
				insert(num,temp);
				insert(temp,num);
			}
			j++;
		}
		temp = num;
		dig = (((num/10)/10)/10%10);
		j = dig;
		while(j<=8 && temp < 10000)
		{
			temp = temp + 1000;
			if(prime[temp] == 0)
			{
				insert(num,temp);
				insert(temp,num);
			}
			j++;
		}
	}		
	return ;
}

void print(int i)
{
	vertex *temp;
	temp = head[i];
	while(temp!=NULL)
	{
		pi(temp->data);
		space;
		temp = temp->adj;
	}
	endl;
	return ;
}

int main()
{
	int i,t;
	gi(t);
	sieve();
	mapping();
	while(t--)
	{
		gi(num);
		gi(num2);
		if(num == num2)
		{
			pi(0);
			endl;
			continue;
		}
		start = 0;
		end = -1;
		set_arr(vis,0,10000,0);
		set_arr(dist,0,10000,0);
		queue[++end] = num;
		vis[num] = 1;
		bfs();
	//	parr(queue,0,9999);
		pi(dist[num2]);
		endl;
	}
	return 0;
}
