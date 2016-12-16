#include<stdio.h>
long long int hash[1000000],pre[1000000],in[1000000];
int main()
{
	long long int t,i,x,y,n,j,l=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&pre[i]);
		if(l<pre[i])
			l=pre[i];
	}
	for(i=0;i<n;i++)
		scanf("%lld",&in[i]);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&x,&y);
		if(x==y)
			j=x;
		//else if(pre[0]==x||pre[0]==y)
		//	j=pre[0];
		else
		{
		i=0;
		while(in[i]!=x&&in[i]!=y&&i<n)
		{
		//	printf("hi2\n");
			i++;
		}
		hash[in[i]]=1;
		i++;
		while(in[i]!=x&&in[i]!=y&&i<n)
		{
			hash[in[i]]=1;
			i++;
		}
		hash[in[i]]=1;
		//if(in[i]==x||in[i]==y)
		//	j=in[i+1];
		i=0;
		while(hash[pre[i]]!=1)
		{
			i++;
		}
		j=pre[i];
		}
		printf("%lld\n",j);
		for(i=0;i<=l;i++)
			hash[i]=0;
	}
	return 0;
}

