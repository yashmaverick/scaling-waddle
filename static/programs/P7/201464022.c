#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void *a,const void *b)
{
	return (*(int *)a - *(int *)b);
}
int main()
{
	int t,i,*a,n,temp;
	long long int count,ans;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		a=malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		qsort(a,n,sizeof(int),cmpfunc);
		temp=a[0];
		count=1;
		for(i=1;i<n;i++)
		{
			if(a[i]==temp)
			{
				count++;
			}
			else {
				ans=ans+(count*(count-1))/2;
				count=1;
				temp=a[i];
			}
			//ans=ans+(count*(count-1))/2;
		}
			ans=ans+(count*(count-1))/2;

		printf("%lld\n",ans);
	}
	return 0;
}

