#include<stdio.h>
typedef long long int LL;
int main()
{
	LL i,j,k,l,h,g,f;
	LL max;
	scanf("%lld",&l);
	while(l!=0)
	{

		LL d[l],cnt=0; 
		for(i=0;i<l;i++)
		{
			scanf("%lld",&d[i]);
		}
		if(l==1 || l==2)
			printf("0\n");
		else{
			for(i=0;i<=l-2;i++)
			{
				max=d[i+1];
				for(j=i+1;j<l;j++)
				{
					if(d[j]>d[i])
					{
						cnt+=l-j-1;
						break;
					}
					if(d[j] < max)
						cnt++;

					if(d[j] > max)
						max = d[j];

				}
			}
			printf("%lld\n",cnt);
		}
		scanf("%lld",&l);
	}
	return 0;
}
