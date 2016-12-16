#include<stdio.h>
int main()
{
	int c,d,j,l,m,a[100000],t,i,n,b[100000],doy,yod;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	scanf("%d",&t);
	while(t--)
	{
		int ci=0;
		scanf("%d %d",&c,&d);
		for(i=0;i<n;i++)
		{
			if(b[i]==c)
			{

				l=i;
	//			printf("%d\n",i);
				ci++;
				//	printf("%d",l);
			}
			if(b[i]==d)
			{
				m=i;
	//			printf("%d\n",i);
				ci++;
				//	printf("%d",m);
			}
			if(ci==2)
			{
				break;
			}
		}
//       printf("%d %d",l,m);
                   /* int fi=l;
		int li=m;

		if(fi>li || m==0)
		{
                  //      printf("m53j7");
			for(i=0;i<n;i++)
			{
				for(j=m;j<=l;j++)
				{
					if(b[j]==a[i])
					{
						printf("%d\n",a[i]);
						break;
					}
				}
				if(b[j]==a[i])
					break;

			}
		}*/
		int ans=909;
		if(l>m)
		l=l+m-(m=l);
		//	printf("dsjhvdy");
			//printf("hi");
//			printf("%d %d\n",l,m);
			for(doy=0;doy<n;doy++)
			{
				for(yod=l;yod<=m;yod++)
				{
					//	printf("a value%d",a[i]);
					//	printf("b value%d",b[j]);
					if(b[yod]==a[doy])
					{
						printf("%d\n",a[doy]);
						ans=1923;
						break;
					}
				}
				if(ans==1923)
					break;
			}
	}

	//	else if(l==m)
	//		printf("%d\n",a[l]);


	return 0;
}
