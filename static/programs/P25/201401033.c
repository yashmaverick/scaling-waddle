#include<stdio.h>
#include<stdlib.h>
#define MAX 1000009
typedef struct node
{
	long long int val;
	long long int weight;
	struct node* next;
}node;
node* Arr[MAX];
long long int check[MAX]={0};
node* insert_into(node* head,long long int x,long long int y)
{
	node* temp=malloc(sizeof(node));
	temp->val=x;
	temp->weight=y;
	temp->next=head;
	return temp;
}
long long int size=0;
typedef struct heap
{
	long long int v;
	long long int w;
}heap;
heap A[MAX];
void shuffleup(long long int x)
{
	long long int temp;
	while(x>0 && A[x/2].w>A[x].w)
	{
		temp=A[x].v;
		A[x].v=A[x/2].v;
		A[x/2].v=temp;
		temp=A[x].w;
		A[x].w=A[x/2].w;
		A[x/2].w=temp;
		x=x/2;
	}
}
void shuffledown(long int x)
{
	long long int temp;
	while(1)
	{
		long long int j=2*x;
		if(j>size)
			return;
		if(j+1<=size && A[j+1].w<A[j].w)
			j++;
		if(A[x].w>A[j].w)
		{
			temp=A[x].v;
			A[x].v=A[j].v;
			A[j].v=temp;
			temp=A[x].w;
			A[x].w=A[j].w;
			A[j].w=temp;
			x=j;
		}
		else
			return;
	}
}
void insert(long long int x,long long int y)
{
	++size;
	A[size].v=x;
	A[size].w=y;
	shuffleup(size);
}
void deletemin()
{
	//printf("%d\n",A[1]);
	long long int temp=A[size].v,tw=A[size].w;
	size--;
	A[1].v=temp;
	A[1].w=tw;
	shuffledown(1);
}
int main()
{
	long long int n,m,i,x,y,w,min=MAX,ver;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&w);
		Arr[x]=insert_into(Arr[x],y,w);
		Arr[y]=insert_into(Arr[y],x,w);
		if(min>w)
		{
			min=w;
			ver=x;
		}
	}
//	printf("%d...\n",ver);
	long long int cnt=0,sum=0,flag;
	insert(ver,min);
	check[ver]=1;
	while(size!=0)
	{
		if(cnt==n-1)
			break;
		check[ver]=1;
		node* temp=Arr[ver];
		while(temp!=NULL)
		{
			if(check[temp->val]==0)
			{
			//	check[temp->val]=1;
				insert(temp->val,temp->weight);
			}
			temp=temp->next;
		}
		while(size>=1 && check[A[1].v]==1)
		{
	//		printf("sd\n");
			deletemin();
		}
	//	printf(",..,.%d\n",A[1]);
		sum+=A[1].w;
		ver=A[1].v;
	//	deletemin();
		cnt++;
	}
	check[ver]=1;
/*	for(i=1;i<=n;i++)	
	{
		if(check[i]==0)
	//	if(cnt!=n-1)
		{
	//		printf("no for %d\n",i);
			flag=0;
		//	break;
		}
	}*/
	//printf("cnt is %d\n",cnt);
	if(cnt==n-1)
		printf("%lld\n",sum);
	else
		printf("-1\n");
//	printf("------%d\n",sum);
	return 0;
}
