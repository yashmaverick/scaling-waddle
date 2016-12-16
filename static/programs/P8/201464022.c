#include<stdio.h>
#include<stdlib.h>
#define M 1000000007
int power(int a,int b,int c)
{
	int answer=1,ans2;
	while(b)
	{
		if(b&1)answer=(answer*(long long)a)%c;
		a=(a*(long long)a)%c;
		b=b/2;
	}
	return answer;
}
int  main()
{
	int upper,n,d,m,i,j,k,temp,t,*array,a,b;
	long long int ans,c=0;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d%d%d%d",&upper,&d,&m,&n);
		array=malloc(sizeof(int)*(n+1));
		for(i=0;i<n;i++)
			array[i]=upper/n + (upper%n>=i);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					c=0;
					c=c+power(j,d,n)+power(i,d,n)+power(k,d,n);
					if (c%n==m)
					{
						temp=array[i];
						temp=(temp*(long long)array[j])%M;
						temp=(temp*(long long)array[k])%M;
						ans=(ans+temp)%M;
					}
				}
			}
		}
		printf("%lld\n",ans);
		free(array);
	}
	return 0;
}




