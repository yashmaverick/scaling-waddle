#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define lli long long int
#define ulli unsigned long long int
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define test() int t; din(t); while(t--)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
#define loop(n) for(i=0;i<n;i++)
int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int sieve_array[8000];
int a[10005];
int indx=0;
void sieve()
{
	int i;
	for(i=2;i<=10005;i++)
	{
		if(a[i]==0)
		{
			if(i>1000 && i<10000)
			{
				sieve_array[indx]=i;
				indx++;
			}
			int j=2;
			while(i*j<=10005)
			{
				a[i*j]=-1;
				j++;
			}
		}
	}
}
typedef struct node{
	int data;
	struct node* next;
}node;
node* vertices[10005];
int visited[10005];
int q[10005];
int q_index=0;
int read_q=-1;
int flag=0;
int level[10005];
void bfs(int nodevalue,int target)
{
	read_q++;
	if(nodevalue==target)
	{
		dout(level[target]);
		flag=1;
		return;
	}
	node* temp=vertices[nodevalue];
	while(temp!=NULL)
	{
		if(!visited[temp->data])
		{
			visited[temp->data]=1;
			q[q_index]=temp->data;
			level[temp->data]=level[nodevalue]+1;
			q_index++;
		}
		temp=temp->next;
	}
	if(read_q==q_index)
		return; 
	bfs(q[read_q],target);
}

int main()
{

	sieve();
	//for(int i=0;i<indx;i++)
	//	printf("%d\n",sieve_array[i]);
	node* temp;
	int count=0;
	int i,j;
	for(i=0;i<indx;i++)
	{
		for(j=i+1;j<indx;j++)
		{
			if(sieve_array[i]%10==sieve_array[j]%10)
				count++;
			if((sieve_array[i]/10)%10==(sieve_array[j]/10)%10)
				count++;
			if((sieve_array[i]/100)%10==(sieve_array[j]/100)%10)
				count++;
			if((sieve_array[i]/1000)%10==(sieve_array[j]/1000)%10)
				count++;
			if(count==3)
			{
				temp=(node*)malloc(sizeof(node));
				temp->data=sieve_array[i];
				temp->next=vertices[sieve_array[j]];
				vertices[sieve_array[j]]=temp;
				temp=(node*)malloc(sizeof(node));
				temp->data=sieve_array[j];
				temp->next=vertices[sieve_array[i]];
				vertices[sieve_array[i]]=temp;
			}
			count=0;
		}
	}
	/*for(int i=1;i<=9999;i++)
	{
		if(vertices[i]!=NULL)
		{
			node* temp=vertices[i];
			printf("%d",i);
			while(temp!=NULL)
			{
				printf("->%d",temp->data);
				temp=temp->next;
			}
			putchar(10);
		}
	}
	*/
	int num1,num2;
	test()
	{
		din(num1);
		din(num2);
		level[num1]=0;
		visited[num1]=1;
		bfs(num1,num2);
		if(!flag)
			printf("Impossible\n");
		loop(10000)
		{
			visited[i]=0;
			level[i]=0;
		}
		q_index=0;
		read_q=-1;
		flag=0;
	}
	
	return 0;
}
