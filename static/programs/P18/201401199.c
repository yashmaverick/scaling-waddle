#include<stdio.h>
#include<stdlib.h>
#define size 1003

struct node
{
    int data;
    struct node* next;
};

typedef struct node node;
typedef node* link;

link head[size];
int cnt=0,v[size];

link insert(link head,int val)
{
    link temp=(link) malloc(sizeof(node));
    temp->data=val;
    temp->next=head;
    head=temp;
    return head;
}
void show(link head)
{
    if(head==NULL)
	return;
    show(head->next);
    printf("%d ",head->data);
}
int dfsans[size];
void dfs(int j)
{
    dfsans[cnt++]=j;
    v[j]=1;
    link temp=head[j];
    while(temp!=NULL)
    {
	if(v[temp->data]==0)
	    dfs(temp->data);
	temp=temp->next;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
	int n,i,q,k,t,a[size][size],h[size],ans=0;
	scanf("%d",&n);
	for(i=0;i<=size;i++)
	    head[i]=NULL;
	for(i=1;i<=n;i++)
	{
	    int m,j;
	    scanf("%d",&m);
	    a[i][0]=m;
	    for(j=1;j<=m;j++)
	    {
		scanf("%d",&t);
		a[i][j]=t;
//		printf("head[%d]=insert(head[%d],%d)\n",t,t,i);
		head[t]=insert(head[t],i);
	    }
	}

	for(i=0;i<=n;i++)
	    h[i]=0;

	int mp;
	for(mp=1;mp<=n;mp++)
	{
	    if(h[mp]==0)
	    {
//		printf("------------>func for mp=%d\n",mp);
		h[mp]=1;
		for(i=0;i<=n;i++)
		    v[i]=0;
		cnt=0;
		dfs(mp);
//		printf("returned and count = %d\n",cnt);
		if(cnt==n)
		{
		    ans++;
//		    printf("cnt == n so making more h[] 1\n");
		    int m,k;
		    m=a[mp][0];
		    for(k=1;k<=m;k++)
		    {
			if(h[a[mp][k]]==0)
			    ans++;
//			printf("for %d\n",a[mp][k]);
			h[a[mp][k]]=1;
		    }
		}
	    }
	}
//	printf("ans = %d\n",ans);
	printf("%d\n",ans);
    }
    return 0;
}
