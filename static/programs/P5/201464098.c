#include<stdio.h>
#include<stdlib.h>
int luck(const void *a,const void *b)
{
	return (*(long long int*)a-*(long long int*)b);
}
int main()
{
	long long int t,g,n,k,i,p,r;
	scanf("%lld",&t);
	for(g=0;g<t;g++)
	{
		int flag=0;
		scanf("%lld %lld",&n,&k);
		long long int a[n];
		char b[1111];
		for(i=0;i<n;i++)
		{
		   scanf("%s",b);
		   scanf("%lld",&a[i]);
		}
		qsort(a,n,sizeof(long long int),luck);
		long long int j,l;
		for(j=0;j<n-2;j++)
		{
			p=j+1;
			r=n-1;
			while(r>p)
			{
				if(a[j]+a[p]+a[r]==k)
					{flag=1;break;}
				else if(a[j]+a[p]+a[r]>k)
					r--;
				else if(a[p]+a[j]+a[r]<k)
					p++;
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}