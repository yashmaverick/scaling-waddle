#include<stdio.h>
int binarysearch(int A[],int low, int high,int key)
{
if(key<=A[low])
	return low;
else if(key>A[high])
	return high+1;
else if(low>=high)
	return high;
	//else if(key>A[high])
//	return high;
else
{

		int mid = (low + high) / 2;
		if (key<=A[mid])
		{
			return binarysearch(A,low,mid,key);
		}
		else 
		{
			return binarysearch(A,mid+1,high,key);
		}
		

	
}
}

int main()
{
int tc;
int p,q,r,i,j,k;
int P[100001],Q[100001],R[100001];long long int arr1[100001];
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d",&p);
		for(i=0;i<p;i++)
		{
			scanf("%d",&P[i]);
		}
		scanf("%d",&q);
		for(i=0;i<q;i++)
		{
			scanf("%d",&Q[i]);
		}
		scanf("%d",&r);
		for(i=0;i<r;i++)
		{
			scanf("%d",&R[i]);
		}
	for(i=q-1;i>=0;i--)
	{
		if(i>r-1)
			arr1[i]=0;
		else
		{
			j=binarysearch (R,i,r-1,Q[i]);
			arr1[i]=(r-j);
		}
	}
//		for(i=0;i<r;i++)
//		{
//			printf("%d",arr1[i]);
//		}
//		printf("\n");
	long long int s=0;
	for(i=q-1;i>=0;i--)
	{
	s=s+arr1[i];
	arr1[i]=s;
	}
/*		for(i=0;i<r;i++)
		{
			printf("%d",arr1[i]);
		}
		printf("\n");
*/
	long long int pair=0;
	for(i=p-1;i>=0;i--)
	{
		if(i>q-1)
			continue;
		int  temp=binarysearch(Q,i,q-1,P[i]);
		if(temp!=-1)
			pair=pair+arr1[temp];
	}
	printf("%lld\n",pair);
	}
	return 0;
}
