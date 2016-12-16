#include<stdio.h>
#include<stdlib.h>

int compare_function(const void *a,const void *b)
{
	return (*(long long int *)a-*(long long int *)b);
}


int main()
{
	int t,z;
	scanf("%d",&t);

	for(z=0;z<t;z++)
	{
		long long int n;
		scanf("%lld",&n);

		long long int a[n];

		long long int i;
		for(i=0;i<n;i++) scanf("%lld",&a[i]);

		qsort(a,n,sizeof(long long int),compare_function);	

		long long int check=a[0];
		long long int ans=0;
		long long int number=1;
		for(i=1;i<n;i++)
		{
			if(a[i]==check) { number++;  }
			else
			{
				ans+=(number*(number-1))/2;
				check=a[i];
				number=1;
			}
		}
		ans+=(number*(number-1))/2;




		printf("%lld\n",ans);
	}
	return 0;
}