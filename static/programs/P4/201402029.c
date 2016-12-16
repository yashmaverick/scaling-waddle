#include<stdio.h>
#define J -100001
#define M 1
#define R 100000
#define MAX 100000
void merge(long long int b[],long long int low,long long int mid,long long int high)
{
	long long int i,m,k,l,temp[MAX];
	l=low;
	i=low;
	m=mid+1;
	while((l<=mid)&&(m<=high))
	{
		if(b[l]<=b[m])
		{
			temp[i]=b[l];
			l++;
		}
		else
		{
			temp[i]=b[m];
			m++;
		}
		i++;
	}
	if(l>mid)
	{
		for(k=m;k<=high;k++)
		{
			temp[i]=b[k];
			i++;
		}
	}
	else
	{
		for(k=l;k<=mid;k++)
		{
			temp[i]=b[k];
			i++;
		}
	}
	for(k=low;k<=high;k++)
	{
		b[k]=temp[k];
	}
}
void partition_merge(long long int b[],long long int low,long long int high)
{
	long long int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		partition_merge(b,low,mid);
		partition_merge(b,mid+1,high);
		merge(b,low,mid,high);
	}
}
long long int b[100000];
int main()
{
	long long int x,j;
	char a[100000];
	scanf("%lld ",&x);
	while(x--)
	{
		long long int d,c,l=0,i=0,k=0,z,count=1,sum=0,flag=0;
		scanf("%s",a);
		while(a[l]!='\0')
		{
			if(a[l]=='J' && k==0)
			{
				b[k]=J;
				k++;
				flag=1;
			}
			if(a[l]=='M' && k==0)
			{
				b[k]=M;
				k++;
				flag=2;
			}
			if(a[l]=='R' && k==0)
			{
				b[k]=R;
				k++;
				flag=3;
			}

			if(a[l]=='J' && k!=0 && flag!=1)
			{
				b[k]=b[k-1]+J;
				k++;
			}
			if(a[l]=='M' && k!=0 && flag!=2)
			{
				b[k]=b[k-1]+M;
				k++;
			}
			if(a[l]=='R' && k!=0 && flag!=3)
			{
				b[k]=b[k-1]+R;
				k++;
			}
			l++;
			flag=0;
		}
		b[l]=0;
		partition_merge(b,0,k);
		d=b[0];
		for(j=1;j<=l;j++)
		{
			if(b[j]==d)
			{
				count++;
			}
			else
			{
				d=b[j];
				sum=sum+((count)*(count-1))/2;
				count=1;
			}
		}
		sum=sum+((count)*(count-1))/2;
		printf("%lld\n",sum);
	}
	return 0;
}
