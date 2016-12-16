#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000000 
typedef struct l
{
	struct l * next;
	int val;
}node;
int ans[MAX];
int size=-1;
int a[MAX];
int n;
int count=0;
int indeg[MAX]={0};
node *arr[MAX];
node*insert(node* root,int a)
{
	node * temp=(node*)malloc(sizeof(node));
	temp->val=a;
	temp->next=root;
	return temp;
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void correct1(int n)
{
    while((n-1)/2>=0 && a[(n-1)/2] > a[n])
    {   
        swap(&a[n],&a[(n-1)/2]);
        n=(n-1)/2;
    }
}
void correct2(int n)
{
    while(1)
    {
        if(size<2*n+1)return;
	    int x=2*n+1;
	    if(a[x]>a[2*n+2])
		    x=2*n+2;
	    if(a[x]<a[n])
        {
            swap(&a[n],&a[x]);
		    n=x;
	    }
        else break;
    }
}
void insert_min(int x)
{
	size++;
	a[size]=x;
	correct1(size);
}
int getmin()
{
	int x=a[0];
	a[0]=a[size];
	size--;
	correct2(0);
	return x;
}
void topolog()
{
    int i;
	for(i=1;i<=n;i++)
		if(indeg[i]==0)
            insert_min(i);
	while(size!=-1)
	{
		int y=getmin();
		node*temp = arr[y];
		while(temp!=NULL)
		{
			indeg[temp->val]--;
            if(indeg[temp->val]==0)
                insert_min(temp->val);
			temp=temp->next;
		}
        ans[count]=y;
        count++;
	}
}
int main()
{
	int i,m;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		arr[u]=insert(arr[u],v);
		indeg[v]++;		
	}
	topolog();
	if(count==n)
    {
        for(i=0;i<count-1;i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[count-1]);
    }
    else printf("Sandro fails.\n");
    return 0;
}
