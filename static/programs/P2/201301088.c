#include<stdio.h>
#include<stdlib.h>
#define ll long long int

int main() {
	int t,p,q,r,a[100010],b[100010],c[100010],sk,sj,v,i,j;
	ll ans,bcount[100010];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d",&p);
		for(i=0;i<p;i++)
		{
			scanf("%d",&a[i]);
			bcount[i]=0;
		}
		scanf("%d",&q);
		for(i=0;i<q;i++)
		{
			scanf("%d",&b[i]);
			bcount[i]=0;
		}
		bcount[q]=0;
		scanf("%d",&r);
		for(i=0;i<r;i++)
			scanf("%d",&c[i]);
		ans=0;
		sj=r-1;
		for(i=q-1;i>=0;i--)
		{
			bcount[i]=(ll)bcount[i+1];
			for(j=sj;j>=i;j--)
			{
				if(c[j]>=b[i])
					bcount[i]++;
				else
					break;
			}
			sj=j;
		}
		for(i=q-1;i>=0;i--)
		{	
			bcount[i]=(ll)bcount[i]+bcount[i+1];
		}
		sj=ans=0;
		for(i=0;i<p;i++)
			for(j=sj;j<r;j++)
			{
				if(b[j]>=a[i])
				{
					ans=(ll)ans+bcount[j];
					if(j>=i+1)
						sj=j;
					else
						sj=i+1;
					break;
				}
			}
		printf("%lld\n",ans);
	}
	return 0;
}
