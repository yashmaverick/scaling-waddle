#include<stdio.h>
#include<stdlib.h>
#define size 100
int in[size],pre[size];
int ptop=0,n,tp=0,p=-1;
struct node
{
    int val;
    struct node* l;
    struct node* r;
};
typedef struct node node;
typedef node* link;

link insert(link root,int val)
{
    root=(node*) malloc(sizeof(node));
    root->l=NULL;
    root->r=NULL;
    root->val=val;
    return root;
}

int search(int val)
{
    int i=0;
    for(i=0;i<n;i++)
    {
	if(in[i]==val)
	    return i;
    }
}

link cons(int str,int end)
{
    int in;
    if(str>end)
	return NULL;

    link root=insert(root,pre[ptop++]);

    if(str==end)
	return root;

    in=search(root->val);

    root->l=cons(str,in-1);
    root->r=cons(in+1,end);

    return root;
}

void path(link root,int val,int rr[],int trr[])
{
    if(root==NULL)
	return;
    trr[++p]=root->val;
    if(root->val==val)
    {
	int i;
	for(i=0;i<=p;i++)
	    rr[i]=trr[i];
	tp=i;
    }
    path(root->l,val,rr,trr);
    path(root->r,val,rr,trr);
    p--;
    return;
}

int main()
{
    link root=NULL;
    scanf("%d",&n);

    int i;
    for(i=0;i<n;i++)
	scanf("%d",&pre[i]);
    for(i=0;i<n;i++)
	scanf("%d",&in[i]);

    ptop=0;
    root=cons(0,n-1);

    int t;
    scanf("%d",&t);
    while(t--)
    {
	int a,b,arr[size],brr[size],trr[size],ap,bp;
	scanf("%d%d",&a,&b);

	tp=0;
	path(root,a,arr,trr);
	ap=tp;
	
	tp=0;
	p=-1;
	path(root,b,brr,trr);
	bp=tp;

	int min;
	min=ap<=bp?ap:bp;

	int i;
/*
	printf("arr[]\n");
	for(i=0;i<ap;i++)
	    printf("%d ",arr[i]);
	printf("\n");
	
	printf("brr[]\n");
	for(i=0;i<bp;i++)
	    printf("%d ",brr[i]);
	printf("\n");
*/	
	for(i=0;i<=min-1 && arr[i]==brr[i];i++);
	printf("%d\n",arr[i-1]);
    }

    return 0;
}
