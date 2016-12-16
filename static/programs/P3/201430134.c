#include<stdio.h>
int main()
{
	int i,j,n,m,k,p;
	int t,z;
	long long int s;
	long long int orig[100010];
	long long int doit[100010];
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&orig[i]);
		}
		doit[0]=0;
		for(z=1;z<n;z++)
		{
			doit[z]=orig[z]-orig[z-1];
		}
		k=0;s=doit[0];
		for(i=0;i<n;i++)
		{
			k=k+doit[i];
			if(k>=doit[i])
			{
				if(k>s)
				{
					s=k;
				}
			}
			else
			{
				if(doit[i]>s)
				{
					s=doit[i];
				}
				k=doit[i];
			}
		}
		printf("%lld\n",s);
		t--;
	}
	return 0;
}
		
	
