#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int abc(const void *a,const void *b)
{
	return (*(int *)a - *(int *)b );
}
int main()
{
	int n,t,i,j,len,tmp,k;
	long long int a[100001],ans,b[100001];
	char s[100001],waste;
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%s",s);
		len=strlen(s);
		ans=0;
		for(i=0;i<len;i++)
		{
			if(i==0)
			{
				if(s[i]=='J')
					a[i]=100000;
				else if(s[i]=='M')
					a[i]=-100001;
				else if(s[i]=='R')
					a[i]=1;
			}
			else
			{
				if(s[i]=='J')
					a[i]=100000+a[i-1];
				else if(s[i]=='M')
					a[i]=-100001+a[i-1];
				else if(s[i]=='R')
					a[i]=1+a[i-1];
			}
			if(a[i]==0)
				ans++;
		}
		qsort(a,len,sizeof(long long int),abc);
		tmp=1;
		for(j=1;j<len;j++)
		{
			if(a[j]==a[j-1])
				tmp++;
			else
			{
				ans=ans+(tmp*(tmp-1))/2;
				tmp=1;
			}
		}
		ans=ans+(tmp*(tmp-1))/2;
		printf("%lld\n",ans);
		t--;
	}
}
