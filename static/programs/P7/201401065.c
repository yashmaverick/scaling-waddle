#include<stdio.h>
void sort(long long int a[1000000],long long int p,long long int q);
int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n,a[1000000],cnt=0,i,fl=0,c=1;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
	//	for(i=0;i<n;i++)
	//		printf("%d ",a[i]);printf("\n");
		sort(a,0,n);
	//	for(i=0;i<n;i++)
	//		printf("%d ",a[i]);printf("\n");
		for(i=0;i<n-1;i++)
		{
			if(a[i]==a[i+1])
			{c++;fl=1;}
			else if(fl)
			{
				cnt+=(c*(c-1))/2;
				c=1;
				fl=0;
			}
		}
		if(fl==1)
			cnt+=(c*(c-1))/2;
		printf("%lld\n",cnt);
	}
}
void sort(long long int a[1000000],long long int p,long long int q)
{
	if((q-p)==1)
		return;
	long long int m,b[1000000],i,j=0,k;
	m=(q-p)/2;
	sort(a,p,p+m);
	for(i=p;i<p+m;i++)
		b[j++]=a[i];
	sort(a,p+m,q);
	i=0;j=p+m;k=p;
	while(i<m&&j<q)
		a[k++]=(a[j]<b[i])?a[j++]:b[i++];
	while(i<m)
		a[k++]=b[i++];
}
