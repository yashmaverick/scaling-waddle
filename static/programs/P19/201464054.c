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
#define TEST scanf("%lld",&test);while(test--)
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)
#define f1r(i,n) for(i=n;i>=1;i--)
#define f0r(i,n) for(i=n;i>0;i--)

ll flag;


struct node{
	int visited;
	int leaf;
	struct node* arr[10];
};

struct node* root;


int compare (const void * a, const void * b)
{
	   ll x;x=*(long long int*)a;
	  ll y;y= *(long long int*)b;
	  if (x>=y)return 1;
	  else
		  return -1;
}


void insertintrie (char string[])
{
	ll i,len,t,isnew=0,j;
	len=strlen(string);
//	printf ("len = %lld",len);
	struct node* temp;
	temp=malloc(sizeof(struct node));
	temp=root;
	f0(i,len)
	{
		t=string[i]-'0';
		if (temp->arr[t]==NULL)
		{
//			printf ("null\n");
			struct node* temp2;
			temp2=malloc(sizeof(struct node));
			temp2->leaf=0;
			f0(j,10){temp2->arr[j]=NULL;}
			temp->arr[t]=temp2;
			temp=temp2;
		}
		else
		{
			temp=temp->arr[t];
		}
		if (i==len-1)
		{
			if (temp->leaf==1)
				flag=1;
			temp->leaf=1;
		}
		if (temp->leaf==1 && i!=len-1)
			flag=1;
	}
}
void dfs_print_trie(struct node* curr_root)
{
	struct node* temp;
	temp=malloc(sizeof(struct node));
	temp=curr_root;
	ll i;
	f0(i,10)
		if (temp->arr[i]!=NULL)
		{
			pll(i);
			dfs_print_trie(temp->arr[i]);
		}
	return;
}
int main()
{
	ll test,n,i,arr[500005];
	char string[20];
	root=malloc(sizeof(struct node));
	TEST
	{
		sll(n);
		flag=0;
		root->visited=0;
		root->leaf=0;
		f0(i,10){root->arr[i]=NULL;}
		f0(i,n){
			sll(arr[i]);
		}
		qsort(arr, n, sizeof(ll), compare);
//		printf ("sorted : ");f0(i,n){pll(arr[i])}printf ("---------\n");
		f0(i,n){
			if (arr[i]==0)
			{
				string[0]=48;
				string[1]='\0';
			}
			else
			{
			ll t,x;
			t=arr[i];
			x=19;
			while (t>0)
			{
				string[x]=48+(t%10);
				x--;
				t=t/10;
			}
			x++;
			ll x2;
			x2=0;
			for (;x<20;x++)
			{
//				printf ("x = %lld x2 = %lld\n",x,x2);
				string[x2]=string[x];
				x2++;
			}
			string[x2]='\0';
			}
//			printf ("string = %s\n",string);
			insertintrie(string);
			if (flag==1)
				break;
		}
//		dfs_print_trie(root);
		if (flag==1)
			printf ("NO\n");
		else if (flag==0)
			printf ("YES\n");
	}
	return 0;
}
