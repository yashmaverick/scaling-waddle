#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int arr[100005], ans[100005], itr;
int a[100005],len;
#define gc() getchar_unlocked()
int isSpaceChar(char c) {
            return c == ' ' || c == '\n' || c == '\r' ;
        }
inline int FAST_IO()
{
    char ch;
    int val=0;
    ch=gc();
    while(isSpaceChar(ch))
            ch=gc();
    val=0;
    while(!isSpaceChar(ch))
    {
        val=(val*10)+(ch-'0');
        ch=gc();
    }
    return val;
}
typedef struct node
{
	int v;
	struct node *next;
}node;

node *insert(int v, node *root)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->v=v;
	temp->next=root;
	return temp;
}

node *adj[100005];
void shuffle_up(int x)
{
	int temp;
	while(x>0 && a[x/2]>a[x])
	{
		temp=a[x/2];
		a[x/2]=a[x];
		a[x]=temp;
		x=x/2;
	}
}
void shuffle_down(int x)
{
	int p,temp;
	while((((2*x)<=len && a[2*x]<a[x]) || (((2*x)+1)<=len && a[(2*x)+1]<a[x])))
	{
		if((((2*x)+1)<=len)&& a[2*x]>a[(2*x)+1])
			p=2*x+1;
		else
			p=(2*x);
		temp=a[p];
		a[p]=a[x];
		a[x]=temp;
		x=p;
	}
}
void insertheap(int x)
{
	a[++len]=x;
	shuffle_up(len);
}
void delete_min()
{
	a[1]=a[len--];
	shuffle_down(1);
}

void compute(int n)
{
	while(len!=0)
	{
		int u=a[1];
		delete_min();
		ans[itr++]=u;
		node *temp=adj[u];
		while(temp!=NULL)
		{
			arr[temp->v]--;
			if(!arr[temp->v])
				insertheap(temp->v);
			temp=temp->next;
		}
	}
}	
int main()
{
	int i,n,m,u,v;
	//scanf("%d%d",&n,&m);
	n=FAST_IO();m=FAST_IO();
	a[0]=INT_MIN;len=0;
	for(i=0;i<100005;i++)
	{
		arr[i]=0;
		adj[i]=NULL;
	}
	itr=0;
	while(m--)
	{
		//scanf("%d%d",&u,&v);
		u=FAST_IO();v=FAST_IO();
		adj[u]=insert(v,adj[u]);
		arr[v]++;
	}
	for(i=1;i<=n;i++)
		if(!arr[i])
			insertheap(i);
	compute(n);
	//if(itr!=n)
//		puts("Sandro fails.");
//	else
//	{
		printf("%d",ans[0]);
		for(i=1;i<n;i++)
			printf(" %d",ans[i]);
		printf("\n");
//	}
	return 0;
}
