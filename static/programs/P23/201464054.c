#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define ll long long int
#define sint(n); scanf("%d",&n);
#define pint(n); printf ("%d\n",n);
#define sll(n); scanf("%lld",&n);
#define pll(n); printf("%lld\n",n);
#define sst(n); scanf("%s",n);
#define pst(n); printf ("%s\n",n);
#define TEST ll test;scanf("%lld",&test);while(test--)
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)
#define f1r(i,n) for(i=n;i>=1;i--)
#define f0r(i,n) for(i=n;i>0;i--)
#define set(x,y) memset(x,y,sizeof(x));
#define SIZE 100005














ll heap[SIZE];
ll end;
void insertheap(ll x)
{
	end++;
	heap[end]=x;
	ll currind;
	ll t;
	currind=end;
	while (currind!=1)
	{
		if (heap[currind/2]>heap[currind])
		{
			t=heap[currind/2];
			heap[currind/2]=heap[currind];
			heap[currind]=t;
			currind=currind/2;
		}
		else
			break;
	}
	return;
}
ll delroot()
{
	ll ret;
	ret=heap[1];
	heap[1]=heap[end];
	end--;
	ll currind;
	ll t;
	currind=1;
	while (1)
	{
		if (2*currind>end)
			break;
		if (2*currind == end)
		{
			if (heap[currind]>heap[2*currind])
			{
				t=heap[2*currind];
				heap[2*currind]=heap[currind];
				heap[currind]=t;
				currind=2*currind;
			}
			else
				break;
		}
		else
		{
			if (heap[currind]<=heap[2*currind] && heap[currind]<=heap[(2*currind)+1])
				break;
			else
			{
				if (heap[2*currind]<=heap[(2*currind)+1])
				{
					t=heap[2*currind];
					heap[2*currind]=heap[currind];
					heap[currind]=t;
					currind=2*currind;
				}
				else if (heap[2*currind]>heap[(2*currind)+1])
				{
					t=heap[(2*currind)+1];
					heap[(2*currind)+1]=heap[currind];
					heap[currind]=t;
					currind=(2*currind)+1;
				}
			}
		}
	}
	return ret;
}
void printheap()
{
	ll i;
	printf ("Heap : ");
	for (i=1;i<=end;i++)
		printf ("%lld --> ",heap[i]);
	printf ("\n");
	return;
}














ll check[SIZE],indegree[SIZE];
struct node
{
	ll data;
	struct node* next;
};
struct node* head[SIZE];

void insertll ( ll x, ll y)
{
	if ( check[x] == 0 )
	{
		head[x]->data=y;
		head[x]->next=NULL;
	}
	else
	{
		struct node* temp;
		temp=malloc(sizeof(struct node));
		temp->data=y;
		temp->next=head[x];
		head[x]=temp;
	}
	return;
}
void insert ( ll x, ll y)
{
	if (check[x]==0)
	{
		head[x]=malloc(sizeof(struct node));
		head[x]->next=NULL;
		check[x]=1;
	}
	if (check[y]==0)
	{
		head[y]=malloc(sizeof(struct node));
		head[y]->next=NULL;
		check[y]=1;
	}
	insertll(x,y);
	//    insertll(y,x);
	return;
}
void printll(ll n)
{
	ll i;
	struct node* temp2;
	temp2=malloc(sizeof(struct node));
	for (i=0;i<SIZE;i++)
		if (check[i] == 1)
		{
			printf ("%lld :: ",i);
			temp2=head[i];
			while (temp2->next!=NULL)
			{
				//        printf ("entered  ");
				printf ("%lld -> ",temp2->data);
				temp2=temp2->next;
			}
			printf ("\n");
			//        printf ("%lld\n",temp2->data);
		}
	return;
}
int main()
{
	ll n,m,i,x,y;
	sll(n);	sll(m);
	set (indegree,0);	set(check,0);
	f0(i,m){sll(x);	sll(y);	if (x==y){continue;}	insert(x,y);	indegree[y]++;}
//	printll(n);
	end=0;
	f1(i,n){if (indegree[i]==0){insertheap(i);}}
//	printheap();
	ll tmp;
	struct node* temp;
	int count,array[100005];
	count=-1;
	temp=malloc(sizeof(struct node));
	while (end>=1)
	{
		tmp=delroot();
		array[++count]=tmp;
		if (check[tmp]!=0)
		{
			temp=head[tmp];
			while (temp->next!=NULL)
			{
				indegree[temp->data]--;
				if (indegree[temp->data]==0)
					insertheap(temp->data);
				temp=temp->next;
			}
		}
	}
	f0(i,count){printf ("%d ",array[i]);}
	pint(array[count]);
//	pll(end);
	return 0;
}
