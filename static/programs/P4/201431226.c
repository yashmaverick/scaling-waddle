#include<stdio.h>
#include<string.h>
void merge(int left[],int right[],int a[],int n)
{
	int mid=(n/2);
	int nl=(mid);
	int nr=(n-mid);
	int i=0,j=0,k=0;
	while(i<nl && j<nr)
	{
		if(left[i]<=right[j])
		{
			a[k]=left[i];
			i++;
		}
		else
		{
			a[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<nl)
	{
		a[k]=left[i];
		i++;
		k++;
	}
	while(j<nr)
	{
		a[k]=right[j];
		j++;
		k++;
	}
}
void part(int a[],int n)
{
	if(n<2)
		return;
	int mid=n/2;
	int left[mid];
	int right[n-mid];
	int i;
	for(i=0;i<mid;i++)
	{
		left[i]=a[i];
	}
	for(i=mid;i<n;i++)
	{
		right[i-mid]=a[i];
	}
	part(left,mid);
	part(right,(n-mid));
	merge(left,right,a,n);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[100001];
		int i,j,k;
		int a[100001];
		int n;
		//printf("%d",s[0]);
		scanf("%s",s);
		n=strlen(s);
		if(s[0]=='J')
			a[0]=10000;
		else if(s[0]=='M')
			a[0]=-9999;
		else if(s[0]=='R')
			a[0]=-1;
		for(i=1;i<n;i++)
		{
			if(s[i]=='J')
				a[i]=a[i-1]+10000;
			if(s[i]=='M')
				a[i]=a[i-1]-9999;
			if(s[i]=='R')
				a[i]=a[i-1]-1;
		}
		part(a,n);
		int cnt=1;
		int sum=0;
		int count=0;
		for(i=0;i<n;i++)
		{
			j=i+1;
			if(a[i]==0)
				count++;
			if(a[i]==a[j])
			{
				cnt++;	
			}
			else if(a[i]!=a[j]&&cnt>1)
			{
				sum=sum+(cnt*(cnt-1)/2);
				cnt=1;
			}
		}
		printf("%d\n",sum+count);
	}
	return 0;
}
