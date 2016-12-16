#include<stdio.h>
#include<stdlib.h>
int indexes[1000005],*preorder,*inorder,n;
/*int findlca(int v1,int v2,int start,int end,int preindex)
{
	
	if(start>end)
		return -1;

	int ind=indexes[preorder[preindex]];
	int v1ind=indexes[v1];
	int v2ind=indexes[v2];
//	printf("rootindddex=%d v1ind=%d and v2ind=%d\n",ind,v1ind,v2ind);
	if(v1ind < ind && v2ind<ind)
	{
		int preind=ind-1;
		return findlca(v1,v2,start,ind-1,preind);
	}
	else if(v1ind > ind && v2ind> ind)
	{
		int preind=ind+1;
		return findlca(v1,v2,ind+1,end,preind);
	}
	else if((v1ind>=ind && v2ind<=ind) || (v1ind<=ind && v2ind>=ind))
		return inorder[ind];
}*/
	
int findlca(int v1,int v2)
{
	int i,ind,v1ind,v2ind;
	for(i=0;i<n;i++)
	{
		ind=indexes[preorder[i]];
		v1ind=indexes[v1];
		v2ind=indexes[v2];
		if((v1ind>=ind && v2ind<=ind) || (v1ind<=ind && v2ind>=ind))
			return inorder[ind];
	}
}


int main()
{
	int v1,v2,ans,i,t;
	scanf("%d",&n);
	preorder=malloc(sizeof(int)*n);
	inorder=malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&preorder[i]);
	for(i=0;i<1000003;i++)
		indexes[i]=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&inorder[i]);
		indexes[inorder[i]]=i;
	}
	scanf("%d",&t);
	while(t--)
	{
//		preindex=0;
		scanf("%d%d",&v1,&v2);
		ans=findlca(v1,v2);
		printf("%d\n",ans);
	}
	free(preorder);
	free(inorder);
	return 0;
}


		
