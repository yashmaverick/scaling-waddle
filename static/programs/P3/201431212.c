#include<stdio.h>
int main()
{
	int m,t;
	long long int i,n,j;
	int a[100002];
	scanf("%d",&t);
	for(m=0;m<t;m++)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		i--;
		long long int k,dif=0,max=a[n-1];
		for(j=n-1;j>=0;j--)
		{
			if((max-a[j])>dif)
				dif=max-a[j];
			if(a[j]>max)
				max=a[j];	
			//dif=max-a[j];
		}
		printf("%lld\n",dif);
	}
	return 0;
}
