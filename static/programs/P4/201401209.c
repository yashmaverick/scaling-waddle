#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmpfunc(const void* a,const void* b)
{
	return(*(int*)a-*(int*)b);
}
int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		char a[1000000];
		scanf("%s",a);
		int l=strlen(a);
		long long int b[l],i;
		unsigned long long int ans=0,count0=0,count=1;
		if(a[0]=='J') b[0]=1000000;
		else if(a[0]=='M') b[0]=-1000001;
		else if(a[0]=='R') b[0]=1;
		for(i=1;i<l;i++)
		{
			if(a[i]=='M') b[i]=b[i-1]+-1000001;
			else if(a[i]=='J') b[i]=b[i-1]+1000000;
			else if(a[i]=='R') b[i]=b[i-1]+1;
		}
//		for(i=0;i<l;i++) printf("%lld ",b[i]); printf("\n");
		qsort(b,l,sizeof(long long int),cmpfunc);
//		for(i=0;i<l;i++) printf("%lld ",b[i]); printf("\n");
		for(i=0;i<=l-2;i++)
		{
			if(b[i]==0) count0++;
			while(b[i]==b[i+1])
			{
				count++;
				i++;
				if(b[i]==0) count0++;				
			}
			ans=ans+(unsigned long long int)((unsigned long long int)count)*(unsigned long long int)(count-1)/2;
			count=1;
		}
		ans=(unsigned long long int)(ans+(unsigned long long int)count0);
		printf("%llu\n",ans);
	}
	return 0;
}
