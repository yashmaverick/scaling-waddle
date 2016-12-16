#include<stdio.h>
int min(int a[],int start,int end)
{
	int i,mini=a[start];
	for(i=start+1;i<=end;i++)
	{
		if(a[i]<mini)
			mini=a[i];
	}
	return mini;
}
int main()
{
	int a[10001],i,j,n,k,temp,test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		scanf("%d",&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		temp=min(a,0,k-1);
		printf("%d%s",temp,n==k?"":" ");
		for(i=1;i+k-1<n;i++)
		{
			if(temp==a[i-1])
			{
				temp=min(a,i,i+k-1);
				printf("%d",temp);
			}
			else if(temp>a[i+k-1])
			{
				temp=a[i+k-1];
				printf("%d",temp);
			}
			else
				printf("%d",temp);
			if(i+k-1!=n-1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
