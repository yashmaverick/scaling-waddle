#include<stdio.h>
#define ll long long
void sort(ll int a[1000],ll int p,ll int q);
int binsearch(ll int a[1000],ll int k,ll int f,ll int l);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll int n,k,i,j,a[1000],fl=0;
		char band[100000];
		scanf("%lld %lld",&n,&k);
		for(i=0;i<n;i++)
			scanf("%s %lld",band,&a[i]);//scanf("%d",&a[i]);
		sort(a,0,n);
		//for(i=0;i<n;i++)
		//	printf("%d ",a[i]);printf("\n");
		for(i=0;i<n-2;i++)
		{
			for(j=i+1;j<n-1;j++)
				if(binsearch(a,(k-a[i]-a[j]),j+1,n-1))
				{fl=1;break;}
			if(fl==1)
				break;
		}
		if(fl==0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
void sort(ll int a[1000],ll int p,ll int q)
{
	if((q-p)==1)
		return;
	else if((q-p)==2)
		if(a[p]>a[p+1])
		{ll int t;t=a[p];a[p]=a[p+1];a[p+1]=t;return;}
	ll int m,b[1000],i,j=0,k;
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
int binsearch(ll int a[1000],ll int k,ll int f,ll int l)
{
	ll int m;
	while(f<=l)
	{
		m=(f+l)/2;
		if(a[m]==k)
			return 1;
		else if(k<a[m])
			l=m-1;
		else if(a[m]<k)
			f=m+1;
	}
	return 0;
}
