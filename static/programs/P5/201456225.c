#include<stdio.h>
#define MAX 1001
int merge_sort(int A[], int s, int e);
int merge(int A[], int temp[], int s1, int e1, int s2, int e2);
int copy(int A[], int temp[], int s, int e);
int merge_sort(int A[], int s, int e)
{
	int mid;
	int temp[MAX];
	if(s<e)
	{
		mid=(s+e)/2;
		merge_sort(A,s,mid);
		merge_sort(A,mid+1,e);
		merge(A,temp,s,mid,mid+1,e);
		copy(A,temp,s,e);
	}
	return 0;
}
int merge(int A[], int temp[], int s1, int e1, int s2, int e2)
{
	int i=s1;
	int j=s2;
	int m=s1;
	while((i<=e1)&&(j<=e2))
	{
		if(A[i]<=A[j])
			temp[m++]=A[i++];
		else
			temp[m++]=A[j++];
	}
	while(i<=e1)
		temp[m++]=A[i++];
	while(j<=e2)
		temp[m++]=A[j++];

	return 0;
}
int copy(int A[], int temp[], int s, int e)
{
	int i;
	for(i=s;i<=e;i++)
	{
		A[i]=temp[i];
	}
	return 0;
}
int main()
{
	int a;
	scanf("%d",&a);
	while(a--)
	{
		int i,n,A[MAX];
		int K,x,y,c=0;
		char B[100];
		scanf("%d%d",&n,&K);

		for(i=0;i<n;i++)
		{
			scanf("%s %d",B,&A[i]);

		}
		merge_sort(A,0,n-1);
		for(i=0;i<n-2;i++)
		{
			x=i+1;
			y=n-1;
			while(x<y)
			{
				if(A[i]+A[x]+A[y]==K)
				{
					c=1;
					break;
				}
				else if(A[i]+A[x]+A[y] < K)
					x++;
				else
					y--;	

			}
			if(c==1)
				break;
		}
		if(c==1)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}

