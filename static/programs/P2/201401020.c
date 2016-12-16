#include<stdio.h>
int main()
{
	int na,nb,nc;
	int l,k,j,i,t;
	scanf("%d",&t);
	while(t--)
	{
		long long int a[100002],b[100002],c[100002],d[100002],total;
		scanf("%d",&na);
		for(i=0;i<na;i++)
			scanf("%lld",&a[i]);
		scanf("%d",&nb);
		for(i=0;i<nb;i++)
			scanf("%lld",&b[i]);
		scanf("%d",&nc);
		for(i=0;i<nc;i++)
			scanf("%lld",&c[i]);
		long long int num=0;
		int x=0,y=0;
		for(i=0;i<nb;i++)
		{
		
			while(x<=i && a[x]<=b[i] && x<na)
				x++;
			d[i]=x;
	//		printf("%lld ",d[i]);
		}
//		for(i=1;i<=nb;i++)
//			printf("%llu  ",d[i]);
//		for(k=0;k<nb;k++)
//			printf("%lld ",d[k]);
		x=0;
		total=0;
		for(i=0;i<nc;i++)
		{
			while(x<=i && b[x]<=c[i] && x<nb)
			{
				
				num=num+d[x];
				x++;
			}
		//	num=num+count;
			total=total+num;
		}
		num=num+d[x];
		printf("%lld\n",total);
	}
	return 0;
}



