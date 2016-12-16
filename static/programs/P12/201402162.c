#include<stdio.h>
int mains[500000],front[500000],stack[500000],lashit[500000];
int main()
{
	while(1)
	{
		long long int flag,n,i,star,starwar,pre;	
		long long int ans;
		scanf("%lld",&n);
		ans=0;
		if(n==0)
			break;
		scanf("%d",&mains[0]);
		stack[0]=mains[0];
		star=1;
		lashit[0]=0;
		front[0]=-1;
		for(i=1;i<n;i++)
		{
			flag=0;
			scanf("%d",&mains[i]);
			starwar=star;
			while(starwar--)
			{
				if(mains[i]<stack[star-1])
				{
					front[i]=lashit[star-1];
					star++;
					stack[star-1]=mains[i];
					lashit[star-1]=i;
					flag=1;
					ans++;
				}
				else if(mains[i]==stack[star-1])
				{
					front[i]=lashit[star-1];
					star++;
					stack[star-1]=mains[i];
					lashit[star-1]=i;
					flag=1;
					ans++;
					pre=star-2;
					while(pre--)
					{
						if(stack[pre]>stack[star-1])
						{
							ans++;
							break;
						}
						ans++;
					}

				}
				else
				{
					stack[star-1]=0;
					lashit[star-1]=-1;
					star--;
					ans++;
				}
				if(flag==1)
					break;
			}
			if(flag==0)
			{
				stack[0]=mains[i];
				lashit[0]=i;
				front[i]=-1;
				star++;
			}
		}
		//printf("hello\n");
		ans=(n*(n-1)/2)-ans;
		printf("%lld\n",ans);
	}
	return 0;
}
