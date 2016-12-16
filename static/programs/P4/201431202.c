#include<stdio.h>
#define aji 13
#define ami 100012
#define ari -100025
#include<string.h>
#define MAX 100000
void partition(int *arr,int low,int high);
void mergeSort(int *arr,int low,int mid,int high);
int main()
{
	int t;
	scanf("%d\n",&t);
	while(t--)
	{
		char a[100001];
		int b[100001];
		scanf("%s",a);
		int j=strlen(a),i;
		b[j]=0;
		for(i=0;i<j;i++)
		{
			if(a[i]=='J')
			{
				if(i==0)
				{
					b[i]=aji;
				}
				else
				{
					b[i]=aji+b[i-1];
				}
			}
			else if(a[i]=='M')
			{
				if(i==0)
				{
					b[i]=ami;
				}
				else
				{
					b[i]=ami+b[i-1];
				}
			}
			else
			{
				if(i==0)
				{
					b[i]=ari;	
				}
				else
				{
					b[i]=b[i-1]+ari;
				}
			}
		}
		partition(b,0,j);
		long long int sum=0,count=1;
		i=1;
		while(i<=j)
		{
			count=1;
			while(b[i]==b[i-1])
			{
				count++;
				i++;
			}
			sum=sum+(count*(count-1)/2);
			while(b[i]!=b[i-1] && i<=j)
			{
				i++;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
void partition(int *arr,int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		partition(arr,low,mid);
		partition(arr,mid+1,high);
		mergesort(arr,low,mid,high);
	}
	return;
}
void mergesort(int *arr,int low,int mid,int high)
{
	int i,m,k,l,temp[MAX];
	l=low;
	i=low;
	m=mid+1;
	while((l<=mid)&&(m<=high))
	{
		if(arr[l]<=arr[m]){
			temp[i]=arr[l];
			l++;
		}
		else{
			temp[i]=arr[m];
			m++;
		}
		i++;
	}
	if(l>mid)
	{
		for(k=m;k<=high;k++){
			temp[i]=arr[k];
			i++;
		}
	}
	else
	{
		for(k=l;k<=mid;k++){
			temp[i]=arr[k];
			i++;
		}
	}
	for(k=low;k<=high;k++)
	{
		arr[k]=temp[k];
	}
	return ;
}
