#include<stdio.h>
#include<stdlib.h>
#define size 1000006

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;
typedef node* link;

link head[size];
int v[size],pptr=-1,dia=0,tv;

link insert(link,int);
void dfs(int);

link insert(link head,int val)
{
    link temp = (link) malloc(sizeof(node));
    temp->data=val;
    temp->next=head;
    head=temp;
    return head;
}

//DFS
void dfs(int j)
{
//    printf("dfs\n");
    ++pptr;
    v[j]=1;
    link temp=head[j];
    while(temp!=NULL)
    {
	if(dia<=pptr)
	{
	    dia=pptr;
	    tv=j;
	}
	if(v[temp->data]==0)
	    dfs(temp->data);
	temp=temp->next;
    }
    pptr--;
}
//END HERE

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
	pptr=-1;
	int n,m,q,i,j,x,y;

	for(i=0;i<=size;i++)
	    head[i]=NULL;
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	    v[i]=0;

	for(i=0;i<(n-1);i++)
	{
	    scanf("%d%d",&x,&y);
	    head[x]=insert(head[x],y);
	    head[y]=insert(head[y],x);
	}
	dia=0;
	dfs(1);
	pptr=-1;
	dia=0;
	for(i=0;i<=n;i++)
	    v[i]=0;
//	printf("tv=%d\n",tv);
	dfs(tv);
	dia++;
	printf("%d\n",dia);
    }
    return 0;
}
