#include<stdio.h>
void part(long long int arr[],long long int low,long long int high);
void sort(long long int arr[],long long int low,long long int mid,long long int high);
long long int temp[100007],b[100007];char a[100007];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int i;
		scanf("%s",a);
		char c;
		i=0;
		while(a[i]!='\0')
		{
			if(a[i]=='J')
				b[i]=-1;
			if(a[i]=='M')
				b[i]=100002;
			else if(a[i]=='R')
				b[i]=-100001;
			i++;
		}
		long long int n=i;
	//	for(i=0;i<n;i++)
	//		printf("%lld ",b[i]);
	//	printf("\n");
		for(i=1;i<n;i++)
			b[i]+=b[i-1];
		part(b,0,n-1);
	//	for(i=0;i<n;i++)
	//		printf("%lld  ",b[i]);
	//	printf("\n");
		 long long int ans=0;
		long long int count=1;
		for(i=1;i<n;i++)
		{
			if(b[i]==b[i-1])
				count++;
			if(b[i]!=b[i-1])
			{
				ans+=(count*(count-1))/2;
				count=1;
			}
			if(b[i]==0)
				ans++;
		}
		ans+=(count*(count-1))/2;
	printf("%lld\n",ans);
	}
	return 0;
}
void part(long long int c[],long long int start,long long int end)
{
	long long int mid;
	if(start<end)
	{
		mid=(start+end)/2;
		part(c,start,mid);
		part(c,mid+1,end);
		sort(c,start,mid,end);
	}
}
void sort(long long int c[],long long int start,long long int mid,long long int end)
{
	long long int i,m,k,l;
	l=start;
	i=start;
	m=mid+1;
	while((l<=mid)&&(m<=end))
	{
		if(c[l]<=c[m])
		{
			temp[i]=c[l];
			l++;
		}
		else
		{
			temp[i]=c[m];
			m++;
		}
		i++;
	}
	if(l>mid)
		for(k=m;k<=end;k++)
		{
			temp[i]=c[k];
			i++;
		}
	else
		for(k=l;k<=mid;k++)
		{
			temp[i]=c[k];
			i++;
		}
	for(k=start;k<=end;k++)
		c[k]=temp[k];
}
