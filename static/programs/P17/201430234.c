#include<stdio.h>
#include<stdlib.h>
int main()
{
	int c,d,j,fl=0,l,m,a[100000],t,i,n,b[100000],doy,yod;
	scanf("%d",&n);
i=0;
	while(i<n)
{
		scanf("%d",&a[i]);
i++;
}
i=0;
	while(i<n)
	{
	scanf("%d",&b[i]);
i++;
}
	scanf("%d",&t);
	while(t--)
	{

		int ci=0;
		scanf("%d %d",&c,&d);
i=0;
		while(i<n)
		{

			if(b[i]==c)
			{

				l=i;
			fl=1;
			if(fl==1)				

					ci=ci+1;
			}
			 if(b[i]==d)
			{
				m=i;
				fl=2;
				if(fl==2)
					ci=ci+1;

			}
			if(ci==2)
			{
				break;
			}
i++;
		}


		int flag=0;
		if(l>m)
			l=l+m-(m=l);

		for(doy=0;doy<n;doy++)
		{
			yod=l;
			while(yod<=m)
			{

				if(b[yod]==a[doy])
				{
					printf("%d\n",a[doy]);
					flag=1;
					break;
				}
				yod++;
			}
			if(flag==1)
				break;
		}
	}


	return 0;
}
