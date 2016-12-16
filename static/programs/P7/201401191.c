#include<stdio.h>
typedef long long int ll;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll min=10000001,i,n;	
		ll max=-10000001;
		scanf("%Ld",&n);
		ll a[n];
		ll new[1000100]={0};
		for(i=0;i<n;i++)
		{
			scanf("%Ld",&a[i]);
			if(a[i]>max)
			{
				max=a[i];
			}
			if(a[i]<min)
			{
				min=a[i];
			}
		}
		for(i=0;i<n;i++)
		{
			new[a[i]-min]++;
		}
		ll fin=0;
/*		for(i=0;i<=max-min;i++)
		{
			printf("%Ld ",new[i]);
		} */
		for(i=0;i<=max-min;i++)
		{
			ll tmp=(new[i]*(new[i]-1))/2;
			fin+=tmp;
		}
		printf("%Ld\n",fin);
	}
	return 0;
}
