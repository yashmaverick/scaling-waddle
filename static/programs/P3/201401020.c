#include<stdio.h>
int main()
{
	int n,l,k,j,i;
	unsigned long long int a[100000];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%llu",&a[i]);
		unsigned long long int max=0,min=a[0];
		unsigned long long int amax=0;
		unsigned long long int diff=0;
		a[n]=a[n-1]-1;
		int flag=0;
		for(i=0;i<n;i++)
		{
			
			if(a[i]<min)
				min=a[i];
			if(a[i]>max && flag==1)
				max=a[i];
			if(max>min)
			{
				diff=max-min;
				max=0;
			}
			if(diff>amax)
				amax=diff;
			if(a[i+1]>a[i] && flag==0)
			{
				flag=1;
				max=a[i+1];
			}

		}
		if(flag==0)
			amax=0;
		printf("%llu\n",amax);
	}
	return 0;
}
