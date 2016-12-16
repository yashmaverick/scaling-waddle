#include<stdio.h>
#include<stdlib.h>
int search(int arr[], int x, int n)
{
	int i;
	for(i=0;i<n;i++)
	  if(arr[i]==x)
		 return i;
	return -1;
}
void lca(int in[], int pre[], int n,int j,int w)
{	
	int lc,i;
	for(i=0;i<n;i++)
   {
   	int root=search(in, pre[i], n);
	int flagl=search(in,j,n); 
	int flagr=search(in,w,n); 
	if(root>=flagl&&root<=flagr)
	{
		lc=root;
		break;
	}
	if(root>=flagr&&root<=flagl)
	{
		lc=root;
		break;
	}
	} 	
printf("%d\n",in[lc]);
   	/*if(root!=0)
	  {
		lca(in,pre+1,root);
	  }  
	 if (root!=n-1)
	  {
		lca(in+root+1,pre+root+1,n-root-1);
	  }
	  if(node==pre[0])
	  flagl=1;*/


}
int main()
{
	int n,i;
	scanf("%d",&n);
	int *pre;
	pre=(int *)malloc(sizeof(int)*n);
	int *in;
	in=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
	scanf("%d",&in[i]);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int j,w;
		scanf("%d%d",&j,&w);
		lca(in,pre,n,j,w);
	} 
	return 0;
}
