#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	long long int data;
	struct node *next;
}node;
node *b[100005];
void addedge(long long int i,long long int j)
{
	node *temp=malloc(sizeof(node));
	temp->data=j;
	temp->next=b[i];
	b[i]=temp;
}
long long int ar[100005];
long long int in[100005];
long long int size=0;
void print()
{
	long long int i;
	for(i=1;i<=size;i++)
		printf("%lld ",ar[i]);
	printf("\n");
}
void printlist(long long int n)
{
	long long int i;
	for(i=1;i<=n;i++)
	{
		node *temp=b[i];
		printf("%lld->",i);
		while(temp!=NULL)
		{
			printf(	"%lld->",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

void insertheap(long long int data)
{
//	printf("Heap before insertion of %d\n",data);
//	print();
	long long int i=size+1;
	while(i>1 && ar[i/2]> data)
	{
		ar[i]=ar[i/2];
		i=i/2;
	}
	ar[i]=data;
	size++;
///	printf("Heap after insertion of %d\n",data);
//	print();
}
long long int min(long long int a,long long int b,long long int i)
{
	if(a>b)
		return 2*i+1;
	return 2*i;
}
void heapify(int i)
{
	if(i>size/2)
		return ;
	long long int ind;
	if(2*i==size)
		ind=2*i;
	else
		ind=min(ar[2*i],ar[2*i+1],i);
	if(ar[i]>ar[ind])
	{
		long long int t=ar[i];
		ar[i]=ar[ind];
		ar[ind]=t;
		heapify(ind);
	}
}
long long int vis2[100005];
long long int flag2=0;
long long int dep[100005];
long long int arr[100005];
int time=0;
void dfs(int i)
{
	node *t=b[i];
	vis2[i]=1;
	arr[i]=time++;
	while(t!=NULL)
	{
		if(!vis2[t->data])
		{
			dfs(t->data);
			if(flag2==1)
				return ;
		}
		else if(dep[t->data]==0)
		{
			flag2=1;
			return ;
		}
		t=t->next;
	}
	dep[i]=time++;
}
void deletemin()
{

//	printf("Heap before deletion of min\n");
//	print();
	long long int t=ar[size];
	ar[size]=ar[1];
	ar[1]=t;
	size--;
	heapify(1);
//	printf("Heap after deletion of min\n");
//	print();

}
long long int vis[100005];
int main()
{
	long long int n,m;
	scanf("%lld%lld",&n,&m);
	long long int i=0;
	for(i=0;i<m;i++)
	{
		long long int p,q;
		scanf("%lld%lld",&p,&q);
		addedge(p,q);
		in[q]++;
	}
	i=1;
//	printlist(n);
/*	for(i=1;i<=n;i++)
	{
		if(!vis2[i])
			dfs(i);
//		printf(" flag2 is %d\n",flag2);
		if(flag2==1)
		{
		//	printf("%d ",i);
			printf("Sandro fails.\n");
			return 0;
			
		}
	//	for(i=1;i<=n;i++)
	//		vis2[i]=0;
	}*/

	for(i=1;i<=n;i++)
	{
		if(in[i]==0)
		{
			insertheap(i);
		//	vis[i]=1;
		}
	}
	long long int cnt=0;
	while(size>0)
	{
		long long int t=ar[1];
		deletemin();
		if(cnt==0)
		
			printf("%lld",t);
		else
		printf(" %lld",t);
		node *temp=b[t];
		while(temp!=NULL)
		{
			in[temp->data]--;
			if(in[temp->data]==0)
			{
				insertheap(temp->data);
			//	vis[temp->data]=1;
			}
			temp=temp->next;
		}
		cnt++;
		
	}
	printf("\n");
	return 0;
}
			








	


	
