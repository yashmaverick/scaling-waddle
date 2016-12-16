#include<stdio.h>
void sort( long long int a[100005], long long int p, long long int q);
int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		char str[100001];
		scanf("%s",str);
		long long int cc[100001]={0},l=0,j=100001,m=1,r=-100002,s,i,c=1,cnt=0;
		s=j+m+r;
		while(str[l]!='\0')
		{
			if(str[l]=='J')
				cc[l+1]=cc[l]+j;
			else if(str[l]=='R')
				cc[l+1]=cc[l]+r;
			else if(str[l]=='M')
				cc[l+1]=cc[l]+m;
			cc[l+1]=cc[l+1];
			l++;
		}
		//for(i=0;i<=l;i++)
		 // printf("%lld ",cc[i]);printf("\n");
		sort(cc,0,l+1);
		//for(i=0;i<=l;i++)
		//  printf("%lld ",cc[i]);printf("\n");
		int fl=0;
		for(i=0;i<l;i++)
		{
			if(cc[i]==cc[i+1])
			{c++;fl=1;}
			else if(fl==1)
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
	return 0;
}
void sort( long long int a[100005], long long int p, long long int q)
{
	if((q-p)==1)
		return;
	else if((q-p)==2)
		if(a[p]>a[p+1])
		{ long long int t;t=a[p];a[p]=a[p+1];a[p+1]=t;return;}
	long long int m,b[100005],i,j=0,k;
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
