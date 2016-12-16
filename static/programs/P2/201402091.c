#include<stdio.h>
int main()
{
	int	i,j,t,p,q,r,ap,bp,cp,a[100007],b[100007],c[100007],temp[100007];
	long long int sum,ans;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&p);
		for(j=0;j<p;j++)
			scanf("%d",&a[j]);
		scanf("%d",&q);
		for(j=0;j<q;j++)
			scanf("%d",&b[j]);
		scanf("%d",&r);
		for(j=0;j<r;j++)
			scanf("%d",&c[j]);
		bp=0,ap=0;
		while(q>bp)
		{
			if(b[bp]>=a[ap] && bp>=ap && ap<p)
				ap++;
			else
			{
				temp[bp]=ap;
				bp++;
			}

		}
	
	bp=0,cp=0,ans=0,sum=0;
	while(r>cp)
	{
		if(c[cp]>=b[bp] && cp>=bp && bp<q)
		{sum=sum+temp[bp];
			bp++;}
		else
		{	ans=ans+sum;
			cp++;
		}
	}
	printf("%lld\n",ans);
}
return 0;
}
