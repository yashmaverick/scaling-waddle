#include<stdio.h>
int main()
{
	int t,i,n,k,h,ans;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		ans=0;
		scanf("%d",&n);
		k=1;h=-1;
		while(n>k-1)
		{
			k=k*2;
			h++;
		}
		if(n-k/2+1<=(k-k/2)/2)
			ans=2*h-1;
		else
			ans=2*h;
		printf("%d\n",ans);
	}
	return 0;
}
