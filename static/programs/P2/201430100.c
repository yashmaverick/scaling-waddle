#include<stdio.h>

int main()
{
	int t,z;
	scanf("%d",&t);

	for(z=0;z<t;z++)
	{
		long long int na,nb,nc,p;

		scanf("%lld",&na);
		long long int a[na];
		for(p=0;p<na;p++) scanf("%lld",&a[p]);

		scanf("%lld",&nb);
		long long int b[nb];
		for(p=0;p<nb;p++) scanf("%lld",&b[p]);

		scanf("%lldd",&nc);
		long long int c[nc];
		for(p=0;p<nc;p++) scanf("%lld",&c[p]);


		long long int ans2[nb];

		long long int j,k=0;

		for(j=0;j<nb;j++)
		{	
			if(k<j) k=j;
			if(k>=nc) ans2[j]=0;
			else
			{	
				while(k<nc) { if(b[j]>c[k]) k++; else break; }

				ans2[j]=nc-k;
			}
		}

		//for(p=0;p<nb;p++) printf("%d ",ans2[p]);

		long long int temp=ans2[nb-1];
		for(j=nb-2;j>=0;j--) { temp+=ans2[j]; ans2[j]=temp; }

		long long int ans=0;

		long long int i;
		j=0;
		for(i=0;i<na;i++)
		{	
			if(j<i) j=i;

			while(j<nb) { if(a[i]>b[j]) j++; else break; }

			if(j<nb)
			{
				ans+=ans2[j];
			}
			else {break;}
		}

		printf("%lld\n",ans);
	}
	return 0;
}

