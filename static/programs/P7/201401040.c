#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * c, const void * b)
{
   return ( *(int*)c - *(int*)b );
}
 int a[1000000];
int main()
{
	int t,n,i;
	long long int ans,nk;
	scanf("%d\n",&t);
	while(t--)
	{
		ans=0;
		nk=1;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		qsort(a,n,sizeof(int),cmpfunc);
		for(i=0;i<n-1;i++)
		{
			if(a[i]==a[i+1])
				nk++;
			else if(nk>1)
			{
				ans+=nk*(nk-1)/2;
				nk=1;
			}
		}
		if(nk>1)
			ans+=nk*(nk-1)/2;
		printf("%lld\n",ans);
	}
	return 0;
}



