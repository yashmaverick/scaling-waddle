#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
	return (*(int*)a-*(int*)b);
}
int main()
{
	int t,n,i;
	long long int ans,cnt;
	scanf("%d",&t);
	while(t>0)
	{
		ans=0;cnt=1;

	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),cmp);//cumsum is now sorted
	for(i=0;i<n;i++)
	{
		if(a[i+1]==a[i])
		{
			cnt++;
		}
		else
		{
			ans=ans+((cnt)*(cnt-1))/2;
			cnt=1;
		}
	}
	printf("%lld\n",ans);
	t--;
	cnt=0;ans=0;
	}
	return 0;
}




