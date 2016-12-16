#include<stdio.h>
#include<string.h>
long long int a[100010],temp[100010];
void merge(long long int a[],long long int low,long long int mid,long long int high)
{
	long long int l,i,m,k;
	i=low;
	l=low;
	m=mid+1;
	while(l<=mid && m<=high)
		if(a[l]<=a[m])
			temp[i++]=a[l++];
		else
			temp[i++]=a[m++];
	for(k=m;k<=high;k++)
		temp[i++]=a[k];
	for(k=l;k<=mid;k++)
		temp[i++]=a[k];
	for(k=low;k<=high;k++)
		a[k]=temp[k];

}
void part(long long int a[],long long int low,long long int high)
{
	long long int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		part(a,low,mid);
		part(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
int main()
{
	int t;
	scanf("%d ",&t);
	for(;t>0;t--)
	{
		char c[100001];
		long long int i=0,j,n;
		scanf("%s",c);
		n=strlen(c);
		for(j=0;j<n;j++)
		{	
			if(c[j]=='J')
				a[j]=-100001;
			else if(c[j]=='M')
				a[j]=1;
			else if(c[j]=='R')
				a[j]=100000;
		}
		a[n]=0;
		for(j=1;j<n;j++)
			a[j]=a[j]+a[j-1];
		part(a,0,n);
		//for(i=0;i<=n;i++) printf("%lld ",a[i]);printf("\n");
		long long int l,sum=0;
		for(j=1;j<=n;j++)
		{
			l=0;
			if(a[j]==a[j-1])
			{
				while(a[j+l] == a[j+l-1] && j+l<=n)
					l++;
				l++;
				j=j+l-2;
			}
			//printf("%lld ",l);
			sum=sum+((l*(l-1))/2);
		}
		printf("%lld\n",sum);
	}
	return 0;
}
