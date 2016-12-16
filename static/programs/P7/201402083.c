#include<stdio.h>
inline long long int combination(int a){
	long long int result=((long long)(a)*(long long)(a-1))/2;
	return result;
}
int main()
{
	int t,arr[1000001],hash[1000001];
	long long int count;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		int n,i,min=10000000;
		for(i=0;i<1000001;i++)
			hash[i]=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			if(arr[i]<min)
				min=arr[i];
		}
		if(min<0)
		{
			for(i=0;i<n;i++)
			{
				hash[arr[i]+abs(min)]++;
			}
		}
		else
			for(i=0;i<n;i++)
				hash[arr[i]-min]++;
		for(i=0;i<1000001;i++)
		{
			if(hash[i]>1)
				count+=combination(hash[i]);
		}
		printf("%lld\n",count);
	}
	return 0;
}




