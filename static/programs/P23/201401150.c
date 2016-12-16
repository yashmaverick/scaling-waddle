#include <stdio.h>
#include <stdlib.h>
#define s(n) scanf("%d",&n)
#define Node struct Node
#define MAX 100007
int minH[MAX],minHeapSize,precedence[MAX];

Node
{
	int val;
	Node *next;
};
Node *insert(Node *N,int v)
{
	Node *t=(Node*)malloc(sizeof(Node));
	t->val=v;
	t->next=N;
	N=t;
	return N;
}

void insertMin(int x)
{
	//printf("insertMin\n");
	if(minHeapSize==0)
	{
		minH[1]=x;
		minHeapSize++;
	}
	else
	{
		minHeapSize++;
		int i;
		for(i=minHeapSize;x<minH[i/2];i/=2)
			minH[i]=minH[i/2];
		minH[i]=x;
	}
}

void swap(int A[],int i,int j)
{
	int t=A[i];
	A[i]=A[j];
	A[j]=t;
}

void delete_min()
{
	int bot=minH[minHeapSize--];
	//M[1]=bot;
	int i,j;
	for(i=1;2*i<=minHeapSize;i=j)
	{
		j=2*i;
		if(j!=minHeapSize && minH[j+1]<minH[j])
			j++;
		if(bot>minH[j])
			minH[i]=minH[j];
		else
			break;
	}
	minH[i]=bot;
}

int peek(int M[])
{
	return M[1];
}

void towel(Node *G[],int N)
{
	int x,i;
	for(i=1;i<=N;i++)
		if(precedence[i]==0)
			insertMin(i);

	int printArray[MAX],c=0;
	while(minHeapSize>0)
	{
		x=peek(minH);
		delete_min();
		printArray[c++]=x;
		//printf("%d ",x);
		Node *T=G[x];
		while(T!=NULL)
		{
			if(--precedence[T->val]==0)
				insertMin(T->val);
			T=T->next;
		}
	}
	for(i=0;i<c-1;i++)
		printf("%d ",printArray[i]);
	printf("%d\n",printArray[i]);
}

void Ginit(Node *G[],int n)
{
	int i;
	for(i=0;i<=n;i++)
		G[i]=NULL;
}

int main()
{
	int N,M,i,a,b;//i,j=a,b
	s(N);s(M);
	Node *G[MAX];
	Ginit(G,N);	
	for(i=0;i<M;i++)
	{
		s(a);s(b);
		G[a]=insert(G[a],b);
		precedence[b]++;
	}
	towel(G,N);
	return 0;
}