#include<stdio.h>
#include<string.h>
long long int tmp[100000],a[100000],b[100000]={1};
void mergesort(long long int s,long long int e)
{
	if(s==e)
		return ;
	int mid=(s+e)/2;
	mergesort(s,mid);
	mergesort(mid+1,e);
	long long int i=s,j=(mid+1),k=0,p;
	while(i<=mid || j<=e)
	{
		if(i>mid)
			tmp[k++]=a[j++];
		else if(j>e)
			tmp[k++]=a[i++];
		else
		{
			if(a[i]<a[j])
				tmp[k++]=a[i++];
			else
				tmp[k++]=a[j++];
		}
	}
	for(p=0;p<k;p++)
		a[s+p]=tmp[p];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int k,j=100001,m=1,r=-100002,zero=0,i,d=1,e=0,q,l,h=0;
		     char s[100000];
		scanf("%s",s);
		q=strlen(s);
		for(i=0;i<q;i++)
		{
			if(s[i]=='J')
				a[i]=a[i-1]+j;
			if(s[i]=='M')
				a[i]=a[i-1]+m;
			if(s[i]=='R')
				a[i]=a[i-1]+r;
		}
		mergesort(0,q-1);
		for(i=0;i<q;i++)
			b[i]=1;
		for(i=0;i<=(q-1);i++)
		{
		//	printf("a[%lld]=%lld",i,a[i]);
			if(a[i]==0)
				zero++;
			if(i<(q-1))
			{
			if(a[i]!=a[i+1])
			{
				b[e]=d;
				e++;
				d=1;
			}
			if(a[i]==a[i+1])
				d++;
			}
		}
        	b[e]=d;
	/*	for(i=0;i<q;i++)
			printf(" b[%lld]=%lld ",i,b[i]);
		printf(" zero=%lld\n ",zero);
		*/
		for(i=0;i<=e;i++)
		{
			k=b[i];
			l=((k)*(k-1))/2;
			h=h+l;
		}
		h=h+zero;
		printf("%lld\n",h);

	}
	return 0;
}
