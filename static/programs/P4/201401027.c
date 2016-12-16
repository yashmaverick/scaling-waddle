#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long int Array[100100],Temp[100100];
void merge(int i,int j)
{
	int k,mid,l,start;
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
void mergesort(int i,int j)
{
	int k,mid;
	if(i>=j)
		return;
	mid=(i+j)/2;
	mergesort(i,mid);
	mergesort(mid+1,j);
	merge(i,j);
}
int main()
{
	long long int len,t,k,tc,i,j,sum,b,temp,cnt;
	char arr[100100];
	scanf("%lld\n",&tc);
	for(i=0;i<tc;i++)
	{
		scanf("%s",arr);
		if(arr[0]=='J')
			Array[0]=-100001;
		else if(arr[0]=='M')
			Array[0]=-1;
		else
			Array[0]=100002;
		sum=0;
		len=strlen(arr);
		for(j=1;j<len;j++)
		{
			if(arr[j]=='J')
				Array[j]=Array[j-1]-100001;
			else if(arr[j]=='M')
				Array[j]=Array[j-1]-1;
			else
				Array[j]=Array[j-1]+100002;
		}
		Array[j]=0;
		mergesort(0,j);
		temp=Array[0];
		cnt=1;
		for(k=1;k<=j;k++)
		{
			if(Array[k]==temp)
			{
				cnt++;
			}
			else
			{
				sum+=((cnt)*(cnt-1))/2;
				cnt=1;
				temp=Array[k];
			}
		}
		sum+=(cnt*(cnt-1))/2;
		printf("%lld\n",sum);
	}
	return 0;
}
