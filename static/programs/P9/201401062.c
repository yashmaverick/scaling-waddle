#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define gu getchar_unlocked 
#define pu putchar_unlocked
#define lli long long int
#define ulli unsigned long long int
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define PLUSWRAP(index,n) index = (index+1)%n
#define MINUSWRAP(index,n) index = (index + n -1)%n

#define INF 1000000000	//1 billion (10^9)

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

typedef struct node{
	int val;
	struct node* next;
}node;
/*
void insert(node* head,int elem)
{
	while(head->next!=NULL)
		head = head->next;
	head->next = (node*)malloc(sizeof(node));
	head->next->val = elem;
	head->next->next  = NULL;
}*/
void print(node* head)
{
	while(head!=NULL)
	{
		printf("%d\n",head->val);
		head = head->next;
	}
}

#define MAXN 1001
long long sum[MAXN];
//node* items[2][MAXN];
int* items[MAXN];
int num[MAXN];
int bags[MAXN];
/*long long *sum;
node*** items;
int* bags;
*/

void mergesort(int A[],int l,int r)
{
	if(l==r-1)
		return;
	int mid = l + (r-l)/2;
	mergesort(A,l,mid);
	mergesort(A,mid,r);

	int  n = r - l;
	int B[n];
	int len=0;
	int p1,p2;
	for(p1=l,p2=mid ; p1<mid && p2<r ; )
		if(sum[A[p1]]<=sum[A[p2]])
			B[len++]=A[p1++];
		else
			B[len++]=A[p2++];
	while(p1<mid)
		B[len++]=A[p1++];
	while(p2<r)
		B[len++]=A[p2++];
	int i;
	for(i=l;i<r;i++)
		A[i] = B[i-l];
}



int main()
{
	int n,MOD;
	din(n);

	/*bags = (int*)malloc(sizeof(int)*n);
	sum = (long long*)malloc(sizeof(long long)*n);
	items = (node***)malloc(sizeof(node**)*2);
	items[0] = (node**)malloc(sizeof(node*)*n);
	items[1] = (node**)malloc(sizeof(node*)*n);
	*/
	din(MOD);
	int i,j;
	for(i=0;i<n;i++)
	{
		int m; din(m);
		sum[i]=0;
		bags[i] = i;
		//items[0][i]=items[1][i] = NULL;
		items[i] = (int*)malloc(sizeof(int)*m);
		num[i]=m;
		for(j=0;j<m;j++)
		{
			int in;
			din(in);
			items[i][j]=in;
			/*if(items[0][i]==NULL)
			{
				items[0][i] = (node*)malloc(sizeof(node));
				items[0][i]->next = NULL;
				items[0][i]->val = in;
				items[1][i] =items[0][i];
			}
			else
			{
				items[1][i]->next = (node*)malloc(sizeof(node));
				items[1][i] = items[1][i]->next;
				items[1][i]->val = in;
				items[1][i]->next = NULL;
			}*/
			sum[i] = (sum[i] + in)%MOD;
		}
	}
	mergesort(bags,0,n);
	for(i=0;i<n;i++)
	{
		printf("%lld\n",sum[bags[i]]);
		//print(items[0][bags[i]]);
		for(j=0;j<num[bags[i]];j++)
			printf("%d\n",items[bags[i]][j]);
		printf("\n");
	}



	return 0;
}
