#include<stdio.h>
int left_child[100001],A[100001];
void max_depth(int root_index,int depth,int start,int end);
int min_value,max_depth_tree;
int main()
{
	int test_cases,n,i,j;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);
		left_child[0]=-1;
		max_depth_tree=0;
		min_value=A[n-1];
	//	printf("%d ",left_child[0]);
		for(i=1;i<n;i++)
		{
			if(A[i]>A[i-1])
				left_child[i]=i-1;
			else
			{
				j=i-1;
				while(A[j]>=A[i] && j>=0)
				{
					if(left_child[j]!=-1)
					{
						if(A[left_child[j]]<A[i])
						{
							left_child[i]=left_child[j];
							break;
						}
						else
							j=left_child[j];
					}
					else
					{
						left_child[i]=-1;
						break;
					}
				}
			}
		//	printf("%d ",left_child[i]);
		}
		if(n>=1)
		max_depth(n-1,0,0,n-1);
		printf("%d %d\n",min_value,max_depth_tree);
	//	printf("\n");
	}
	return 0;
}
void max_depth(int root_index,int depth,int start,int end)
{
	if(start>=end)
	{
		if(start==end)
		{
		if(max_depth_tree<depth)
		{
			max_depth_tree=depth;
			min_value=A[root_index];
		}
		}
	//	if(max_depth_tree==depth)
	//	{
	//		if(min_value>A[root_index])
	//			min_value=A[root_index];
	//	}
	//	printf("%d max_depth_tree %d min_value\n",max_depth_tree,min_value);
	}
	else
	{
	//	if(A[root_index-1]>A[root_index])
		if(left_child[root_index]!=-1)
			max_depth(left_child[root_index],depth+1,start,left_child[root_index]);
		if(A[root_index-1]>A[root_index] && root_index!=0)
		{
//			if(root_index!=0)
//			{
			if(left_child[root_index]!=-1 )
				max_depth(root_index-1,depth+1,left_child[root_index]+1,root_index-1);
			else
				max_depth(root_index-1,depth+1,start,root_index-1);
//		        }
		}
	}
}

