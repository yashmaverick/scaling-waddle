#include <stdio.h>
#include <string.h>
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)

int main()
{   
	int a[100010],b[100010],c[100010];
	int t,p,q,r;
	long long x1[100010];
	scanf("%d",&t);
	while(t--)
	{  
	   	int i;
		scanf("%d",&p);
		for(i=0;i<p;i++)
			scanf("%d",&a[i]);
		scanf("%d",&q);
		for(i=0;i<q;i++)
			scanf("%d",&b[i]);
		scanf("%d",&r);
		for(i=0;i<r;i++)
			scanf("%d",&c[i]);
		int j=0;
		long long int sum=0;
		//memset(x1, 0, sizeof(long long)*(q+4));
		for(i=0;i<q+4;i++)
			x1[i]=0;
		for(i=0; i<(min(q,r)) ;i++)
		{   
			j = max(j,i);
			while(b[i]>c[j] && j<r)
				j++;
			x1[i] = r-j;

		}
		for(i=q-2;i>=0;i--)
			x1[i]+=x1[i+1];
        
        j=0;
		for(i=0;i<(min(p,q));i++)
		{   
			j = max(j,i);
			while(b[j]<a[i] && j<q)
				j++;
			sum += x1[j];
		}
		printf("%lld\n",sum);
	}
	return 0;
}
