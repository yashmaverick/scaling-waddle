#include <stdio.h>

int main()
{
	long long int k,i,j,a[100000],b[100000],c[100000],bp,cp,count;

	int T,alen,blen,clen;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&alen);
		for(i=0;i<alen;i++)
			scanf("%lld",&a[i]);
		scanf("%d",&blen);
		for(i=0;i<blen;i++)
			scanf("%lld",&b[i]);
		scanf("%d",&clen);
		for(i=0;i<clen;i++)
			scanf("%lld",&c[i]);

		bp=cp=count=0;

		for(i=0;i<alen;i++)
		{
			for(j=i;j<blen;j++)
			{
				if(a[i]>b[j])
					continue;
			//	bp=j;

				for(k=j;k<clen;k++)
				{
					if(b[j]>c[k])
						continue;

					cp=k;
					count+=clen-k;

					break;									
				}

			//	cp=0;
			}
			//cp=0;
		}

		printf("%lld\n",count);
	}

	return 0;
}
