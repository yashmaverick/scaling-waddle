#include<stdio.h>
#include<stdlib.h>
struct list{
	int data;
	struct list *left,*right;
};
typedef struct list element;
typedef element *link;
int state;
int srch(int a[],int s,int sp,int ed)
{
	int i=sp;
	for(i=sp;i<=ed;i++)
	{
		if(a[i]==s)
			return i;
	}
}
link tree(int pre[],int ino[],int spopre,int edopre,int spoin,int edoin)
{
	if(spopre>edopre)
		return NULL;
	link a;
	a=malloc(sizeof(element));
	a->data=pre[spopre];
	int i=srch(ino,pre[spopre],spoin,edoin);
	int small;
	small=i-spoin;
	(a->left)=tree(pre,ino,spopre+1,spopre+small,spoin,spoin+small-1);
	(a->right)=tree(pre,ino,spopre+1+small,edopre,spoin+small+1,edoin);
	return a;
}
void preorder(link n)
{
	if(n==NULL)
		return;
	printf("%d ",n->data);
	preorder(n->left);
	preorder(n->right);
}
void lca(int v,int arr[],link head,int index)
{
	if(state==-1)
	{
		if(head==NULL)
			return;
		arr[(index)]=head->data;
		if(head->data==v)
		{
			state=index;
			return;
		}
		else
		{  // (index)++;
			lca(v,arr,head->left,index+1);
			lca(v,arr,head->right,index+1);
		}
	}
}
int main()
{
	int nodes,i;
	int *pre,*ino;
	scanf("%d",&nodes);
	pre=(int *)malloc(nodes*sizeof(int));
	ino=(int *)malloc(nodes*sizeof(int));
	for(i=0;i<nodes;i++)
	{
		scanf("%d",&pre[i]);
	}
	for(i=0;i<nodes;i++)
	{
		scanf("%d",&ino[i]);
	}
	link head;
	head=tree(pre,ino,0,nodes-1,0,nodes-1);
//	preorder(head);
	int sw,j;
	scanf("%d",&sw);
    for(j=0;j<sw;j++)
    {
	    int v1,v2,spv1,spv2;
	    scanf("%d %d",&v1,&v2);
		int *a,*b;
		a=(int *)malloc(nodes*sizeof(int));
		b=(int *)malloc(nodes*sizeof(int));
		state=-1;
	//	spv1=0;
	//	spv2=0;
		lca(v1,a,head,0);
		spv1=state;
		state=-1;
		lca(v2,b,head,0);
		spv2=state;
/*		for(i=0;i<=spv1;i++)
		{
			printf("%d ",a[i]);
		}*/
//		printf("\n"); 
		for(i=0;(i<=spv1)&&(i<=spv2)&&(a[i]==b[i]);i++)
		{
	//		printf("%d ",b[i]);
		}
		i=i-1;
		printf("%d\n",a[i]);
	}
	return 0;
}