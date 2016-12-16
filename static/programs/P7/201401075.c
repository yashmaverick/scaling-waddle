#include<stdio.h>
long long int cmpfunc(const void *a,const void *b)
{
	return (*(long long int *)a - *(long long int *)b);
}
int main()
{
	long long int t,n,ar[1000000],i,j,ct,ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&ar[i]);
		qsort(ar,n,sizeof(long long int),cmpfunc);
		ct=1;
		ans=0;//correct till here
		for(i=0;i<n;i++)
		{
			if(i>0)
			{
				if(ar[i]==ar[i-1])
					ct++;
				else
				{
					if(ct%2==0)
						ans=ans+ct/2*(ct-1);
					else
						ans=ans+ct*(ct-1)/2;
					ct=1;
				}
				if(i==n-1)
				{
					if(ct%2==0)
						ans=ans+(ct/2*(ct-1));
					else
						ans=ans+ct*(ct-1)/2;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}


