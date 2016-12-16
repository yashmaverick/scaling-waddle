#include<stdio.h>
int main()
{
 long int a[100010],b[100010],c[100010],i,j,k,l,t,p,q,r,cnt,index1,x1,x2,z[100010],count=0;
 long long  int sum;
	scanf("%ld",&t);
	while(t--)
	{
		count=0;
		sum=0;
		scanf("%ld",&p);
		for(i=0;i<p;i++)
		{
			scanf("%ld",&a[i]);
		}
		scanf("%ld",&q);
		for(i=0;i<q;i++)
		{
			scanf("%ld",&b[i]);
		}
		scanf("%ld",&r);
		for(i=0;i<r;i++)
		{
			scanf("%ld",&c[i]);
		}
		i=0;
		j=0;
		cnt=-1;
		while(i<p&&j<q)
		{
			if(b[j] < a[i])
			{
				if(i<=j)
				{
		//			printf("index = %lld\n",cnt+1);
					x1=cnt+1;
					z[count]=x1;
					count++;
				}
				else
				{
		//			printf("index = %lld\n",j+1);
					x1=j+1;
					z[count]=x1;
					count++;
				}
				j++;
			}
			else
			{
				i++;
				cnt++;
			}
		}
		while(j<q)
		{
				if(j>=p)
				{
		//		printf("index = %lld\n",p);
					x1=p;
					z[count]=x1;
					count++;
				}
				else
				{
		//			printf("index = %lld\n",j+1);	
					x1=j+1;
					z[count]=x1;
					count++;
				}
				j++;
		}
	/*	for(i=0;i<q;i++)
		{
			printf("%lld ",z[i]);
		}
		printf("\n");*/
		count=0;
		i=0;
		j=0;
		while(j<r&&i<q)
		{
			if(b[i]<=c[j])
			{
				if(j<i)
				{
		//			printf("index1= %lld\n",r-i);
					x2=r-i;
					z[count]*=x2;
					count++;
				}
				else
				{
					if(r-j>=0)
					{
		//				printf("index1= %lld\n",r-j);	
						x2=r-j;
					   z[count]*=x2;
					   count++;
					}
					
					else
					{
			//			printf("index1= %lld\n",0);	
						x2=0;
							z[count]*=x2;
					count++;
					}
				}
				i++;	
			}
			else
			{
				j++;
			}
		}
		while(i<q)
		{
			if(i<r)
			{
		//		printf("index111 %lld\n",0);
				x2=0;
				z[count]*=x2;
				count++;
			}
			i++;
		}
		for(i=0;i<q;i++)
		{
			sum+=z[i];
		}
		printf("%lld\n",sum);
	}
	return 0;
}



