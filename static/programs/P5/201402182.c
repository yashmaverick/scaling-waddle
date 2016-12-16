#include<stdio.h>
int main()
{
	int o,t,i,n,fl=1,k,q,w,e,temp,a[100000],g;

	char d[1005];
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{ fl=1;

		scanf("%d%d",&n,&k);
		for(q=0;q<n;q++)
		{
			scanf("%s%d",d,&a[q]);
		}
		for(w=1;w<n;w++)
		{
			for(e=0;e<n-1;e++)
			{
				if(a[e]>a[e+1])
				{     temp=a[e+1];
					a[e+1]=a[e];
					a[e]=temp;
				}
			}
		}
		/*for(g=0;g<n;g++)
		  printf("%d",a[g]);*/
		for(o=0;o<n-2;o++)
		{	int p=o+1,m=n-1;
			while(p<m)
			{
				if(a[p]+a[m]+a[o]>k)
					m--;
				else if(a[p]+a[m]+a[o]<k)
					p++;
				else if(a[p]+a[m]+a[o]==k)
				{	
					fl=0;
					break;
				}
			}
			if(fl==0)
				break;
		}
		if(fl==0)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}
