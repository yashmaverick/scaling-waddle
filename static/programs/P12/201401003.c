#include<stdio.h>
long long int a[1000009],b[1000009],c[1000009],d[1000009];
int main()
{
	long long int i,n,ans,ans1,len,j;
	scanf("%lld",&n);
	while(n!=0)
	{
		ans1=0;
		ans=0;
		len=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
//		for(i=0;i<n;i++)
//		{
//			printf("%lld : %lld\n",i,a[i]);
//		}
		b[len++]=0;
		for(i=1;i<n;i++)
		{
			while(len>0 && a[b[len-1]]<a[i])
			{
				ans+=n-i-1;
				len--;
			}
			b[len++]=i;
		}
		/*	for(i=0;i<n;i++)
			{
			printf("%lld\n",c[i]);
			}*/
		len=0;
		b[len++]=n-1;
		for(i=n-2;i>=0;i--)
		{
			while(len>0 && a[b[len-1]]<a[i])
			{
				ans+=i;
				len--;
			}
			b[len++]=i;
		}
		len=0;
		b[len++]=0;
		for(i=1;i<n;i++)
		{
			while(len>0 && a[b[len-1]]<=a[i])
			{
//				if(b[len-1]==148)
//					printf("hello\n");
				c[b[len-1]]=i-b[len-1]-1;
				len--;
			}
			b[len++]=i;
		}
//		for(i=0;i<len;i++)
//			printf("%lld ",b[i]);
//		printf("\n");
//		printf("%lld\n",c[148]);
		while(len>0)
		{
			c[b[len-1]]=n-1-b[len-1];
			len--;
		}
//		for(i=0;i<(n-1);i++)
//		{
//			if(a[i]==a[i+1])
//				c[i]=c[i+1];
//		}
//		printf("%lld\n",c[148]);
		//		for(i=0;i<n;i++)
		//			printf("%lld ",c[i]);
		//		printf("\n");
		b[len++]=n-1;
		for(i=n-2;i>=0;i--)
		{
			//		for(j=0;j<len;j++)
			//			printf("%d ",b[j]);
			//		printf("\n");
			while(len>0 && a[b[len-1]]<=a[i])
			{
				d[b[len-1]]=b[len-1]-i-1;
				len--;
			}
			b[len++]=i;
		}
		while(len>0)
		{
			d[b[len-1]]=b[len-1];
			len--;
		}
		b[len++]=0;
		for(i=1;i<n;i++)
		{
			while(len>0 && a[b[len-1]]<=a[i])
			{
				if(a[b[len-1]]==a[i])
				{
					d[i]+=d[b[len-1]];
				}
				len--;
			}
			b[len++]=i;
		}
		//		for(i=0;i<n;i++)
		//			printf("%lld ",d[i]);
		//		printf("\n");
//		printf("%lld\n",ans);
		for(i=0;i<n;i++)
		{
		//			printf("%lld %lld\n",c[i],d[i]);
					ans1+=(c[i]*d[i]);
			ans-=(c[i]*d[i]);
		}
		printf("%lld\n",ans);		
		scanf("%lld",&n);
	}
	return 0;
}
