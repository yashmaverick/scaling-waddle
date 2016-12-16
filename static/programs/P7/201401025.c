#include<stdio.h>
#include<stdlib.h>
int abc(const void *a,const void *b)
{
	return (*(int *)a - *(int *)b);
}
int main()
{
	int n,i,t,a[1000001];
	long long int ans,tmp;
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		qsort(a,n,sizeof(int),abc);
		tmp=1;ans=0;
		for(i=1;i<n;i++)
		{
			if(a[i]==a[i-1])
				tmp++;
			else
			{
				ans=ans+(tmp*(tmp-1))/2;
				tmp=1;
			}
		}
		ans=ans+(tmp*(tmp-1))/2;
		printf("%lld\n",ans);
		t--;
	}
	return 0;
}
