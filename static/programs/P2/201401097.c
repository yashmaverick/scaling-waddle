#include<stdio.h>
int main ()
{
	long long int i,ltemp,j,k,t,l,m,n,an,bn,cn,a[2][100001],b[2][100001],c[2][100001],flag=0;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		for(j=0;j<100001;j++)
		{
			a[0][j]=0;
			b[0][j]=0;
			c[0][j]=0;
		}

		scanf("%lld",&an);
		for(j=0;j<an;j++)
		{
			
			scanf("%lld",&a[0][j]);
		}

		scanf("%lld",&bn);
		for(j=0;j<bn;j++)
		{
			scanf("%lld",&b[0][j]);
		}

		scanf("%lld",&cn);
		for(j=0;j<cn;j++)
		{
			scanf("%lld",&c[0][j]);
		}
		for(j=0;j<an;j++)
		{
			a[1][j]=0;
			
		}
		for(j=0;j<bn;j++)
		{
			b[1][j]=0;
			
		}
		for(j=0;j<cn;j++)
		{
			c[1][j]=0;
			
		}

		k=1;
		for(j=cn-1;j>=0;j--)
		{
			c[1][j]=k++;
		}
		k=0;
		
		ltemp=cn-1;
	

		for(j=bn-1;j>=0;j--)
		{
			flag=0;
			if(j!=bn-1)
				b[1][j]=b[1][j+1];

			for(k=ltemp;k>=j;k--)
			{

				if(b[0][j]>c[0][k])
				{

					break;
				}
			}



			if((c[0][k+1]>=b[0][j])&&(k+1>=j))
			{
				b[1][j]=b[1][j]+c[1][k+1];
				ltemp=k+1;
			}

		}

		k=0;
		
	

			ltemp=bn-1;

		
		for(j=an-1;j>=0;j--)
		{
			flag=0;
			if(j!=an-1)
				a[1][j]=a[1][j+1];

			for(k=ltemp;k>=j;k--)
			{
				if(a[0][j]>b[0][k])
				{


					break;
				}
			}

			if((b[0][k+1]>=a[0][j])&&(k+1>=j))
			{
				a[1][j]=a[1][j]+b[1][k+1];
				ltemp=k+1;
			}



		}



	/*	 for(j=0;j<an;j++)
		   printf("-%lld",a[1][j]);
		   printf("\n");
		   for(j=0;j<bn;j++)
		   printf("-%lld",b[1][j]);
		   printf("\n");
		   for(j=0;j<cn;j++)
		   printf("-%lld",c[1][j]);
		   printf("\n");
*/
		 
		printf("%lld\n",a[1][0]);










	}
	return 0;
}
