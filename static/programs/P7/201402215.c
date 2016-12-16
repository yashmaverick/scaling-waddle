#include<stdio.h>
int merge(long int A[],long int B[],long int c[],int m,int n)
{	int i=0,j=0,k=0;
	while(i<m&&j<n)
	{	if(A[i]>B[j])
		{	c[k]=B[j];
			j++;k++;}
			else if(A[i]==B[j])
			{	c[k]=A[i];k++;
				c[k]=A[i];k++;
				i++;
				j++;}
				else
				{	c[k]=A[i];
					i++;
					k++;}
	}
	if(j<n)
	{	while(j<n)
		{	c[k]=B[j];
			k++;
			j++;
		}
	}
	if(i<m)
	{	while(i<m)
		{
			c[k]=A[i];
			k++;
			i++;
		}
	} 

}
void mergesort(long int a[],int n)
{	int i;
	long int left[n];
	long int right[n];
	if(n<=1)
	{	return;}
	for(i=0;i<n/2;i++){
		left[i]=a[i];
	}
	for(i=n/2;i<n;i++)
	{	right[i-n/2]=a[i];}
	mergesort(left,n/2);
	mergesort(right,(n-n/2));
	merge(left,right,a,n/2,(n-n/2)); 
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{	int n,i,flag=0;
		long long int count=0,sum=0;
		long int a[1000000];
		scanf("%d",&n);
			for(i=0;i<n;i++)
				scanf("%ld",&a[i]);
		mergesort(a,n);
//		for(i=0;i<n;i++)
//			printf("%ld ",a[i]);
		for(i=1;i<n;i++)
		{	if(a[i]==a[i-1])
			{	count++;
			//	printf("%d\n",i);
				if(i==n-1)
					flag=1;
			}
			if(a[i]!=a[i-1]||flag==1)
			{	
				if(count+1>=2)
					sum+=((count+1)*count)/2;
				count=0;
			}
		}
			printf("%lld\n",sum);
	}
	return 0;
}
