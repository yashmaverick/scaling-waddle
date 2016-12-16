#include<stdio.h>
#include<string.h>
void merge(int ans[],int low,int mid,int high)
{
	int t[100007];
	int i=low,j=mid+1,k=0;
	while(i<=mid&&j<=high)
	{
		if(ans[i]<ans[j])
			t[k++]=ans[i++];
		else if(ans[j]<ans[i])
			t[k++]=ans[j++];
		else
		{
			t[k++]=ans[i++];
			t[k++]=ans[j++];
		}
	}
	while(i<=mid)
		t[k++]=ans[i++];
	while(j<=high)
		t[k++]=ans[j++];
	for(i=low,k=0;i<=high;i++)
	{
		ans[i]=t[k];
		k++;
	}
}
void mergesort(int ans[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(ans,low,mid);
		mergesort(ans,mid+1,high);
		merge(ans,low,mid,high);
	}
}
int main()
{
	int t;
	scanf("%d ",&t);
	while(t--)
	{
		char a[100007];
		int ans[100007],i,count0=0,count=0,inter;
		scanf("%s",a);
		int x=strlen(a);
		if(a[0]=='J')
			ans[0]=999;
		else if(a[0]=='M')
			ans[0]=-998;
		else
			ans[0]=-1;
		for(i=1;i<x;i++)
		{
			if(a[i]=='J')
				ans[i]=ans[i-1]+999;
			else if(a[i]=='M')
				ans[i]=ans[i-1]-998;
			else
				ans[i]=ans[i-1]-1;
			if(ans[i]==0)
				count0++;
		}
		mergesort(ans,0,x-1);
		for(i=0;i<x-1;i++)
		{
			inter=1;
			while(ans[i]==ans[i+1])
			{
				inter++;
				i++;
			}
			count+=(inter*(inter-1))/2;
		}
		printf("%d\n",count0+count);
	}
	return 0;
}
