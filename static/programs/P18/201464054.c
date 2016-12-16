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






int ispossible[1001];
int ct;	// 	no of nodes visited
int check[1001],dfscheck[1001],revcheck[1001];
struct node
{
	int data;
	struct node* next;
};
struct node* head[1001];
struct node* revhead[1001];


void revinsert ( int x, int y)
{
	if (revcheck[x]==0)
	{
		revhead[x]=malloc(sizeof(struct node));
		revhead[x]->next=NULL;
		revcheck[x]=1;
	}
	if (revcheck[y]==0)
	{
		revhead[y]=malloc(sizeof(struct node));
		revhead[y]->next=NULL;
		revcheck[y]=1;
	}

	if ( revcheck[x] == 0 )
	{
		revhead[x]->data=y;
		revhead[x]->next=NULL;
	}
	else
	{
		struct node* temp;
		temp=malloc(sizeof(struct node));
		temp->data=y;
		temp->next=revhead[x];
		revhead[x]=temp;
	}
	return;
}
void insert ( int x, int y)
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
void printll(int n)
{
	int i;
	struct node* temp2;
	temp2=malloc(sizeof(struct node));
	f1(i,n){
		if (check[i] == 1)
		{
			printf ("%d :: ",i);
			temp2=head[i];
			while (temp2->next!=NULL)
			{
				//        printf ("entered  ");
				printf ("%d -> ",temp2->data);
				temp2=temp2->next;
			}
			printf ("\n");
			//        printf ("%lld\n",temp2->data);
		}
	}
	return;
}
void revdfs ( int x )
{
	/*if (flag==1)
	  return flag;*/
	/*if (check[x]==0 || check[y] == 0)
	  return;*/
	if (dfscheck[x] == 1)
		return;
	else
	{
		struct node* temp;
		temp=revhead[x];
		dfscheck[x]=1;
		//		printf ("%d --> ",x);
		ct++;
		while (temp->next!=NULL)
		{
			/*if (temp->data == y)
			  {
			  flag=1;
			  return flag;
			  }
			  else*/
			{
				revdfs(temp->data);
				temp=temp->next;
			}
		}
	}
	return;
}
int flag;
void dfs ( int x )
{
	/*if (flag==1)
	  return flag;*/
	/*if (check[x]==0 || check[y] == 0)
	  return;*/
	if (dfscheck[x] == 1)
		return;
	else
	{
		struct node* temp;
		temp=head[x];
		dfscheck[x]=1;
		//		printf ("%d --> ",x);
		ct++;
		while (temp->next!=NULL)
		{
			dfs(temp->data);
			temp=temp->next;
		}
	}
	return;
}
int main()
{
	TEST{
		int n,ans,m,i,j;
		ans=0;
		//printf ("Enter no. of edges :\n");
		sint(n);
		f1(i,n){check[i]=0;revcheck[i]=0;}
		int x,y;
		//printf ("Enter vettex pairs which are connected by one edge :\n");
		f1(i,n){
			sint(m);
			while (m--)
			{
				sint(x);
				insert(x,i);
				revinsert(i,x);
				//insert(y,x);
			}
		}


	/*	ct=0;
		f1(j,n){dfscheck[j]=0;}
		dfs(1);
		if (ct==n)
		{
			ct=0;
			f1(j,n){dfscheck[j]=0;}
			revdfs(1);
			if (ct==n)
			{
				printf ("%d\n",n);
				ct=0;
				continue;
			}
		}


		//		printll(n);
		set(ispossible,0);
		f1(i,n)
		{
			ct=0;	flag=0;
			set(dfscheck,0);
			//printf ("Enter vertex pair to check :\n");
			//scanf ("%lld %lld",&x,&y);
			//			printf ("----------  %d ----------\n",i);
			dfs(i);
			//			printf ("------------------\n");
			//printf ("ct = %lld\n",ct);
			if (ct==n || flag==1)
			{
				ispossible[i]=1;
				ans++;
			}
		}
//		f1(i,n){printf ("%d ",ispossible[i]);}printf ("\n");
		pint(ans);*/

		flag=0;
		int flag2,vertexcount;
		flag2=0;	vertexcount=0;
		f1(i,n)
		{
			ct=0;
			set(dfscheck,0);
			dfs(i);
			if (ct==n)
			{
				flag2=1;
				vertexcount=0;
				break;
			}
		}
		ct=0;
		if (flag2==1)
		{
			set(dfscheck,0);
			revdfs(i);
			vertexcount+=ct;
			pint(vertexcount);
		}
		else
		{
			printf ("0\n");
		}

	}
	return 0;
}
