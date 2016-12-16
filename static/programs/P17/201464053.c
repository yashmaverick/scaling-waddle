#include<stdio.h>
int main()
{
	int j=0,i,flag=0;
	long long int node,parentnode=0,preorder[100005],inorder[100005],array[100005],test1,test2,test;
	scanf("%lld",&node);
	for(i=0;i<node;i++)
		scanf("%lld",&preorder[i]);
	for(i=0;i<node;i++)
		scanf("%lld",&inorder[i]);
	scanf("%lld",&test);
	for(i=0;i<=node;i++)
		array[inorder[i]]=i;
	for(i=0;i<test;i++)
	{
		j=0;
		flag=0;
		scanf("%lld",&test1);
		scanf("%lld",&test2);
		while(flag==0)
		{
			parentnode=preorder[j];
			if(array[parentnode]>array[test1] && array[parentnode]>array[test2])
				j++;

			else if(array[parentnode]<array[test1] && array[parentnode]<array[test2])
			{
				if(j<array[parentnode])
					j=array[parentnode]+1;
				else
					j++;
			}
			else if((array[parentnode]>=array[test1] && array[parentnode]<=array[test2])||(array[parentnode]<=array[test1] && array[parentnode]>=array[test2]))
			{
				printf("%lld\n",parentnode);
				flag=1;
			}
		}
	}
	return 0;
}





