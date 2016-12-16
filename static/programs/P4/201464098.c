#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int luck(const void *a,const void *b)
{
	return (*(int*)a-*(int*)b);
}
int main()
{
	long long int t,g;
	scanf("%lld",&t);
	for(g=0;g<t;g++)
	{
		char a[100005];
		long long int i;
		scanf("%s",a);
		char ch=getchar();
		long long int k=strlen(a);
		long long int arr[k];
		long long int j=100001;
		long long int r=1;
		long long int m=(-100002);
		int temp=0;
		for(i=0;i<k;i++)
		{
			if(a[i]=='J')
				{
					temp=temp+j;
					arr[i]=temp;
				}
				else if(a[i]=='R')
				{
					temp=temp+r;
					arr[i]=temp;
				}
				else
				{
					temp=temp+m;
					arr[i]=temp;
				}
		}
		qsort(arr,k,sizeof(long long int),luck);
		long long int count=0;
		long long int n=1;
		if(arr[0]==0)
			count++;
		for(i=1;i<k;i++)
		{
			if(arr[i]==0)
				count++;
			int h=0;
			if(arr[i]==arr[i-1])
			{
				n++;
			}
			else
			{
				count=count+(n*(n-1))/2;
				n=1;
			}
		}
		count=count+(n*(n-1))/2;
		printf("%lld\n",count);
	}
	return 0;
}