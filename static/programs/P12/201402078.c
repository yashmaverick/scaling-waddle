#include<stdio.h>
int main()
{
	long long int n,i,j,k;
	scanf("%lld",&n);
	while(n)
	{
		long long int ans=0;
		long long int a[500005],st[500005],ptr=-1;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=0;i<n;i++)
		{
			if(ptr==-1)
			{
				ptr++;
				st[ptr]=a[i];
			}
			else
			{
				if(st[ptr]<a[i])
				{
					//printf("%d,%d\n",a[i],st[ptr]);
					while ((ptr>-1)&&(st[ptr]<a[i]))
					{
						ans=ans+(n-i-1);
						//printf("$ans-%d,i-%d,ptr-%d\n",ans,i,ptr);
						/*if(ptr>=2)
						{
							for(j=ptr-1;j>=0;j--)
							{
								if(a[i]<st[j])
								{
									ans+=j;
									printf("#ans-%d,i-%d,ptr-%d\n",ans,i,ptr);
									break;
								}

							}
						}*/
						ptr--;
					//	printf("%d %d %d \n",a[i],st[ptr],ptr);
					}
				}
				ptr++;
				st[ptr]=a[i];
				if(ptr>=2)
				{
					for(j=ptr-1;j>=0;j--)
					{
						if(a[i]<st[j])
						{
							ans+=j;
						//	printf("##ans-%d,i-%d,ptr-%d\n",ans,i,ptr);
							break;
						}
					}
				}
			}			
		}
		printf("%lld\n",ans);
		scanf("%lld",&n);
	}
	return 0;
}
