#include<stdio.h>
#include<stdlib.h>
int arr[1000000],n;

long long int check(long long int k, int ar[])
{
	if(k==0)return 0;
	int i,j;
	for(i=0;i<n;i++)
		if(ar[i]!=ar[0]){ break;}

	if(ar[i-1]<ar[i])
		for(j=i-1;j>=0&&k>0;j--)
		{
			ar[j]++;
			k--;
		}
	return check(k,ar);
}

int main()
{
	long long int k;
	int i,j;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	scanf("%lld",&k);

	for(i=0;i<n;i++)
		for(j=1;j<n-i;j++)
			if(arr[j-1]>arr[j])
				arr[j-1]=arr[j]-arr[j-1]+(arr[j]=arr[j-1]);

	k=check(k,arr);

	printf("%d\n",arr[0]);
	return 0;
}
