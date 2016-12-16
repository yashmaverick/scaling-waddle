#include<stdio.h>
void merge(long int A[], long int B[], long int m, long int n, long int C[])
{
	long int i,j;
	i=0;
	j=0;
	long int k=0;
	while(i<m && j<n)
	{
		if(A[i]<=B[j])
			C[k++]=A[i++];
		else
			C[k++]=B[j++];
	}
	for(;i<m;i++)
		C[k++]=A[i];
	for(;j<n;j++)
		C[k++]=B[j];
}
void sort(long int a[],long int n)
{
	long  int i;
	long  int left[n],right[n];
	if(n<=1)
		return;
	for(i=0;i<n/2;i++) 
		left[i]=a[i];
	for(i=n/2;i<n;i++)
		right[i-n/2]=a[i];
	sort(left,n/2);
	sort(right,n-n/2);
	merge(left, right, n/2,n-n/2, a);
}
int main()
{
//printf("d");
	int test;
	long int n,AR[1000000],i,j,count,total;
	scanf("%d",&test);
	while(test--)
	{
		total=0;
		scanf("%ld",&n);
		for(i=0;i<n;i++)
			scanf("%ld",&AR[i]);
		sort(AR,n);
		for(i=0;i<n;)
		{
			j=i;
			count=0;
			while(AR[j]==AR[j+1]&&j!=n)
			{
					count++;
					j++;
			}
			count++;
			total+= (count*(count-1))/2;		
			i=j+1;
		}
	//	printf("%ld\n",count);
		printf("%ld\n",total);
	}
	return 0;
}


