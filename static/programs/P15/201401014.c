#include<stdio.h>
//#include<string.h>
int A[10005];
int find_min(int start,int end);
int main()
{
	int n,k,test,i,j,min_index;
	scanf("%d",&test);
	while(test--)
	{
		min_index=0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);
		min_index=find_min(0,k-1);
		//  printf("%d",A[min_index]);
		if(n==k)
			printf("%d\n",A[min_index]);
		else
		{
			printf("%d ",A[min_index]);
			for(i=k;i<n-1;i++)
			{
				if(A[i]<=A[min_index])
					min_index=i;
				else
				{
					if(min_index<(i-k+1))
						min_index=find_min(i-k+1,i);
				}
			//  printf("%d",A[min_index]);
			//	if(i!=n-1)
					printf("%d ",A[min_index]);
			//	else
			//		printf("%d",A[min_index]);
			//	    j++;
			}
			if(A[n-1]<A[min_index])
				printf("%d\n",A[n-1]);
			else
			{
				if(min_index<(i-k+1))
					min_index=find_min(i-k+1,n-1);
				printf("%d\n",A[min_index]);
			}
		}
	}
	return 0;
}
int find_min(int start,int end)
{
	int i,min;
	min=start;
	for(i=start;i<=end;i++)
	{
		if(A[min]>A[i])
			min=i;
	}
	return min;
}
