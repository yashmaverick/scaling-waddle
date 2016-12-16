#include<stdio.h>
int main()
{
	int n,a1[10000],a,b,min,i1,c[10000],k,i=0,k1,s,d,flag=0,f=0;
	scanf("%d",&d);
	for(s=0;s<d;s++)
	{
		i1=1;
		scanf("%d%d",&n,&k);
		for(a=1;a<=n;a++)
		{
			scanf("%d",&a1[a]);
		}
		k1=1;
		//	if(flag==0)
		min=a1[1];
		for(b=1;b<=n;b++)
		{
			//min=a1[b];
			if(b<=n-k+1)
			{
				if(b>1 && min!=a1[b-1])
				{
					if(min>a1[k1+k-1])
					{
						min=a1[k1+k-1];
					}

				}
				//	if(flag==0)
				else if(b==1 || (b>1 && min==a1[b-1]))
				{
						min=a1[b];
					for(a=k1;a<=k1+k-1;a++)
					{
						{
							if(a1[a]<min)
								min=a1[a];

						}

					}
				}
				c[i1]=min;

				i1++;
				k1++;

			}


		}

		for(a=1;a<n-k+1;a++)
		{

			printf("%d ",c[a]);
		}
		printf("%d",c[a]);
		printf("\n");
	}
	return 0;
}

