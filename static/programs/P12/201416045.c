#include<stdio.h>
long long int s[500001],p;
int main()
{
	long long int t,n,i,j,k,c,a;
	scanf("%lld",&n);
	while(n)
	{
		a=0;p=0;s[0]=-1;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			if(s[p]==-1) s[++p]=k;
			else if(s[p]>=k) { s[++p]=k ; if(s[1] != k) a++; }
			else
			{
				c=1;
				if(s[p]!=-1)
				{
					while(s[p] < k && s[p] != -1)
					{
						t=s[p]; p--;
						if(t == s[p]) c++;
						else { a+=c*(c-1)/2+c; c=1; }
					}
				}
				else a+=c*(c-1)/2+c;
				if(s[p]!=-1 && s[1] != k) a++;
				s[++p]=k;
			}
		} c=1;
		while(s[p]!=-1)
		{
			t=s[p]; p--;
			if(t == s[p]) c++;
			else { a+=c*(c-1)/2; c=1; }
		}
		printf("%lld\n",n*(n-1)/2-a);
		scanf("%lld",&n);
	}
	return 0;
}
