#include<stdio.h>

int inorder[10000]={0};
int preorder[10000]={0};
int inorderpos[10000]={0};
int preorderpos[10000]={0};
int leftchild[10000]={0};
int rightchild[10000]={0};
int leftchildfinal[10000]={0};
int rightchildfinal[10000]={0};
int height[10000]={0};
int parent[10000]={0};
int marked[10000]={0};
int stack[10000]={0};
int stackhead=-1;
int n,m;

void dfs(int a, int h)
{
	marked[a]=1;
	height[a]=h;
	if(a!=0)
	{
		if(marked[leftchild[a]]==0)
		{
			marked[leftchild[a]]=1;
			leftchildfinal[a]=leftchild[a];
			parent[leftchildfinal[a]]=a;
		}
		if(marked[rightchild[a]]==0)
		{
			marked[rightchild[a]]=1;
			rightchildfinal[a]=rightchild[a];
			parent[rightchildfinal[a]]=a;
		}
		dfs(leftchildfinal[a],h+1);
		dfs(rightchildfinal[a],h+1);
	}
}

int main()
{
	int a,b,c,i,j,k;
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d", &preorder[i]);
	for(i=0;i<n;i++)
	{
		scanf("%d", &inorder[i]);
		inorderpos[inorder[i]]=i; 
	}
	for(i=0;i<n;i++)
		preorderpos[i]=inorderpos[preorder[i]]+1;
	for(i=0;i<n;i++)
	{
		int val=preorderpos[i];
		while(stackhead!=-1 && val>stack[stackhead])
		{
			rightchild[stack[stackhead]]=val;
			stackhead--;
		}
		stackhead++;
		stack[stackhead]=preorderpos[i];
	}
	for(i=0;i<n-1;i++)
	{
		if(preorderpos[i+1]<preorderpos[i])
			leftchild[preorderpos[i]]=preorderpos[i+1];
	}
	dfs(preorderpos[0],0);
	height[preorderpos[0]]=0;
	scanf("%d", &k);
	for(j=0;j<k;j++)
	{
		int aa,bb;
		scanf("%d%d", &aa, &bb);
		aa=inorderpos[aa]+1;
		bb=inorderpos[bb]+1;
		while(height[aa]>height[bb])
			aa=parent[aa];
		while(height[bb]>height[aa])
		{
			bb=parent[bb];
		}
		while(aa!=bb)
		{
			aa=parent[aa];
			bb=parent[bb];
		}
		aa=inorder[aa-1];
		printf("%d\n", aa);
	}
	return 0;
}
