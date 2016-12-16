#include<stdio.h>
void mergesort(int s,int e);
int a[1000],b[1000];
int main()
{
	int n,k,h,i,p,q,r,f,t;
	char c[1000];
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%s",c);
		scanf("%d",&a[i]);
	}
	mergesort(0,n-1);
	p=0;
	q=n-1;
	f=0;
	for(p=0;p<n-2;p++)
	{
		q=p+1;
		r=n-1;
		while(r>q)
		{
			if(a[p]+a[q]+a[r]==k)
			{
				printf("YES\n");
				f=1;break;
			}
			else if(a[p]+a[q]+a[r]>k)
				r--;
			else  if(a[p]+a[q]+a[r]<k)
				q++;	

		}
		if(f==1)
			break;
	}
	if(f==0)
		printf("NO\n");
	}
	return 0;	
}

void mergesort(s,e)
{
	if(s==e)
		return;
	int m=(s+e)/2;
	mergesort(s,m);
	mergesort(m+1,e);
	int p1=s,p2=m+1,pf=s;
	while(p1<=m && p2<=e)
	{
		if(a[p1]<a[p2])
		{
			b[pf]=a[p1];
			pf++;p1++;
		}
		else if(a[p1]>=a[p2])
		{
			b[pf]=a[p2];
			pf++;p2++;
		}
	}
	if(p1<=m)
	{
		for(;p1<=m;p1++,pf++)
			b[pf]=a[p1];
	}
	else if(p2<=e)
		for(;p2<=e;p2++,pf++)
			b[pf]=a[p2];
	int i;
	for(i=s;i<=e;i++)
		a[i]=b[i];
}
