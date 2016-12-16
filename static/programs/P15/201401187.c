#include<stdio.h>
#define ll long long int
ll a[10000],st[20010],b[10000];
int t,n,k,i,j,l,p,q;
void first_k()
{
	while(j<k)
	{
		while(a[j]<=a[st[q]]&&q-p>=0)
		q=q-1;
		q=q+1;
		st[q]=j;
		j++;
	}
	return;
}
void next()
{
	while(j<n)
	{       
		b[i++]=a[st[p]];
		while(st[p]<=j-k&&q-p>=0)
		{
			p++;
		}
		while(a[j]<=a[st[q]]&&q-p>=0)
			q=q-1;
		q=q+1;
		st[q]=j;
		j++;
	}
	b[i]=a[st[p]];
	return;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		q=10004;p=10005;
		i=0;
		scanf("%d%d",&n,&k);
		for(j=0;j<n;j++)
			scanf("%lld",&a[j]);
		j=0;
		first_k();
		next();
		//	printf("%lld\n",a[st[p]]);
		for(i=0;i<n-k;i++)
			printf("%lld ",b[i]);
		printf("%lld\n",b[i]);
	}
	return 0;
}
