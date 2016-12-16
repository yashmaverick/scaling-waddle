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
#define SIZE 1000005






ll ct;	// 	no of nodes visited
ll check[SIZE],dfscheck[SIZE];
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
int flag;
ll maxlength,length,deepest;
void dfs ( ll x )
{

	//printf ("before\n");
	int stack[SIZE];
	int levelstack[SIZE];
//	printf ("after\n");
	struct node* temp;
	ll y,lev;
	temp=malloc(sizeof(struct node));
	ll top;
	top=0;
	stack[top]=x;
	levelstack[top]=1;
	dfscheck[x]=1;
	while (top>=0)
	{
		y=stack[top];
		lev=levelstack[top];
		if (lev>maxlength)
		{
			maxlength=lev;
			deepest=y;
		}
//		printf ("%lld -> ",y);
		top--;
		dfscheck[y]=1;
		temp=head[y];
		while (temp->next!=NULL)
		{
			if (dfscheck[temp->data]==0)
			{
				stack[++top]=temp->data;
				levelstack[top]=lev+1;
			}
			temp=temp->next;
		}
	}
//	printf ("\n");
	return;
}
int main()
{
//	printf ("%d\n",sizeof(struct node));
	TEST{
		ll n,ans,m,i;
		ans=0;
		set(check,0);
		//printf ("Enter no. of edges :\n");
		sll(n);
		if (n==1)
		{
			printf ("1\n");
			continue;
		}
		ll x,y;
		//printf ("Enter vettex pairs which are connected by one edge :\n");
		f1(i,n-1){
				sll(x);	sll(y);
				insert(x,y);
				insert(y,x);
			//	if (i>999990)printf ("%lld %lld\n",x,y);
				//insert(y,x);
		}
//		printf ("insert fin\n");
//		printll(n);
		set(dfscheck,0);
		length=0;	maxlength=INT_MIN;
		dfs(1);
		//pll(maxlength);
		//printf ("\n l = %lld d = %lld\n",maxlength,deepest);
		length=0;	maxlength=INT_MIN;
		set(dfscheck,0);
		dfs(deepest);
		pll(maxlength);
	}
	return 0;
}
