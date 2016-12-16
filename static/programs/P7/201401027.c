#include<stdio.h>
#include<stdlib.h>
long long int Array[1000007],Temp[1000007];
void merge(long long int i,long long int j)
{
	long long int k,mid,l,start;
	start=i;
	mid=(i+j)/2;
	k=mid+1;
	l=i;
	while(i<=mid&&k<=j)
		if(Array[i]<=Array[k])
			Temp[l++]=Array[i++];
		else
			Temp[l++]=Array[k++];
	if(i>mid)
		for(;k<=j;)
			Temp[l++]=Array[k++];
	else if(k>j)
		for(;i<=mid;)
			Temp[l++]=Array[i++];
	for(l=start;l<=j;l++)
		Array[l]=Temp[l];
	return;
}
void mergesort(long long int i,long long int j)
{
	long long int k,mid;
	if(i>=j)
		return;
	mid=(i+j)/2;
	mergesort(i,mid);
	mergesort(mid+1,j);
	merge(i,j);
}
int main()
{
	long long int N,i,tc,j,t,cnt,ans;
	scanf("%lld",&tc);
	for(j=0;j<tc;j++)
	{
		scanf("%lld",&N);
		for(i=0;i<N;i++)
			scanf("%lld",&Array[i]);
		mergesort(0,N-1);
		t=Array[0];
		i=1;
		cnt=1;
		ans=0;
		while(i<N)
		{
			if(Array[i]==t)
				cnt++;
			else
			{
				ans+=(cnt*(cnt-1))/2;
				t=Array[i];
				cnt=1;
			}
			i++;
		}
		ans+=(cnt*(cnt-1))/2;
		printf("%lld\n",ans);
	}
	return 0;
}
