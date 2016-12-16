#include<stdio.h>

	int a[100005];int b[100005];
int maxSubArraySum( int size)
{
	long long int max_so_far = 0, max_ending_here = 0;
	int i;
	for(i = 0; i < size; i++)
	{
		max_ending_here = max_ending_here + b[i];
		if(max_ending_here < 0)
			max_ending_here = 0;
		if(max_so_far < max_ending_here)
			max_so_far = max_ending_here;
	}
	return max_so_far;
} 

/*
int cal	(int a[],int n)
{
	long long int t,i,n,maxcurr,s,j,k,max,flag;
//	scanf("%lld",&t);
//	for(i=1;i<=t;i++)
//	{
		maxcurr=0;
		s=0;
		flag=1;
		max=-2000000000;
		scanf("%lld",&n);
		for(j=0;j<n;j++)
		{
			scanf("%lld",&a[j]);
		}
		for(k=0;k<n&&a[k]<0;k++)
		{
			if(a[k]>max)
				max=a[k];
			if(k==n-1)
			{
				flag=0;
				printf("%lld\n",max);
				goto final;
			}
		}


		for(k=0;k<n&&flag==1;k++)
		{
			s=s+a[k];
			if(s<0)
				s=0;
			if(maxcurr<s)
				maxcurr=s;
			flag=1;
final:
			return;
		}
*/
int main()
{
	int tc,i;
	scanf("%d",&tc);int flag=0;
	int n;
	while(tc--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(i>=1)
				flag=1;
			if(flag==1)
			{
				b[i-1]=(a[i]-a[i-1]);
			}
		}
//		for(i=0;i<n;i++)
//			printf("%d",a[i]);
//		printf("\n");
//		for(i=0;i<n-1;i++)
//			printf("%d",b[i]);
//		printf("\n");
		printf("%d\n",maxSubArraySum(n-1));
	}
	return 0;
}
