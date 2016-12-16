#include<stdio.h>
#include<string.h>
long long int cmp(const void *c,const void *b)
{
	return (*(long long int*)c-*(long long int*)b);
}
long long int comb(long long int n)
{
	if(n<=1)
		return (n*0);
	else return (n*(n-1))/2;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char a[100005];
		scanf("%s",a);
		long long int len,i;
		len=strlen(a);
		long long int b[100005];
		b[0]=0;
		for(i=0;i<=len;i++)
		{
			if(a[i]=='J')
				b[i+1]=b[i]-100001;
			else if(a[i]=='R')
				b[i+1]=b[i]-4;
			else if(a[i]=='M')
				b[i+1]=b[i]+100005;
		}
		qsort(b,len+1,sizeof(long long int),cmp);
		long long int count=1,sum=0,ans;
		for(i=0;i<len;i++)
		{
			if(b[i]==b[i+1])
				count++;
			else
			{
				ans=comb(count);
				sum=sum+ans;
				count=1;
			}
		}
		if(count>1)
		{
			ans=comb(count);
			sum=sum+ans;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
