#include<stdio.h>
int n;
int preorder[1000000];
int inorder[1000000];
int place[1000000];
int parent[1000000];
int hasher[1000000];
void find(int ref,int total,int back)
{
	int i,node,diff,min,new;
	node=preorder[ref];
	parent[node]=back;
	min=n+1;
	for(i=ref;i<ref+total;i++)
	{
		if(place[preorder[i]]<min)
			min=place[preorder[i]];
	}
	new=place[node]-min;
	if(new>0)
		find(ref+1,new,node);
	if(total-new>1)
		find(ref+new+1,total-new-1,node);
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&preorder[i]);
	}
	for(i=1;i<=n;i++)
	{       
		scanf("%d",&inorder[i]);
		place[inorder[i]]=i;
	}
	find(1,n,preorder[1]);
	int q,a,b;
	scanf("%d",&q);
	while(q--)
	{
		for(i=1;i<=n;i++)
			hasher[i]=0;
		scanf("%d%d",&a,&b);
		hasher[a]=1;
		while(a!=preorder[1])
		{
			a=parent[a];
			hasher[a]=1;
		}
		while(1)
		{
			if(hasher[b]==1)
				break;
			b=parent[b];
		}
		printf("%d\n",b);
	}
	return 0;
}
