#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int data;
	struct tree* l;
	struct tree* r;
	struct tree* par;
};
typedef struct tree tree;
typedef tree* tee;
tee createnode(int d,tee parent)
{
	tee temp;
	temp=(tee)malloc(sizeof(tree));
	temp->data=d;
	temp->l=NULL;
	temp->r=NULL;
	temp->par=parent;
	return temp;
}
tee bt(int pre[],int in[],int h[],int str,int end,tee parent)
{
	tee node;
	int inindex;
	static int dex=0;
	if(str>end)
	{
		return NULL;
	}
	node=createnode(pre[dex++],parent);
	inindex=h[pre[dex-1]];
	if(str==end)
	{
		return node;
	}
	else
	{
		node->l=bt(pre,in,h,str,inindex-1,node);
		node->r=bt(pre,in,h,inindex+1,end,node);
	}
	return node;
}
tee search(int x,tee root)
{
	tee pl,pr;
	if(root==NULL)
	{
		return NULL;
	}
	else if(root->data==x)
	{
		return root;
	}
	else
	{
		pl=search(x,root->l);
		pr=search(x,root->r);
	}
	if(pl!=NULL)
	{
		return pl;
	}
	else if(pr!=NULL)
	{
		return pr;
	}
	else
	{
		return NULL;
	}
}
int main()
{
	int t,i,k,j,n,val1,val2;
	tee root,ref1,ref2;
	int a1[100000],a2[100000];
	int cnt1,cnt2;
	cnt1=cnt2=0;
	int in[100000],pre[100000],h[100000];//size of h should be 
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		h[in[i]]=i;
	}
	root=bt(pre,in,h,0,n-1,NULL);
//	printf("%d\n",root->data);
	scanf("%d",&t);
	while(t>0)
	{
		cnt1=0;cnt2=0;
		scanf("%d %d",&val1,&val2);
		ref1=search(val1,root);
		ref2=search(val2,root);
		while(ref1->par!=NULL)
		{
			a1[cnt1++]=ref1->data;
			//printf("%d ",ref1->data);
			ref1=ref1->par;
		}
		a1[cnt1]=ref1->data;
	//	printf("\n");
		while(ref2->par!=NULL)
		{
			a2[cnt2++]=ref2->data;
			//printf("%d ",ref2->data); 
			ref2=ref2->par;
		}
		a2[cnt2]=ref2->data;
	//	printf("\n");
		if(cnt1>=cnt2)
		{
			for(i=0;i<=cnt2;i++)
			{
				if(a2[i]==a1[i+cnt1-cnt2])
				{printf("%d\n",a2[i]);break;}
			}
		}
		else
		{
			for(i=0;i<=cnt1;i++)
			{
				if(a1[i]==a2[i+cnt2-cnt1])
				{printf("%d\n",a1[i]);break;}
			}
		}
		t--;
	}
	return 0;
}

