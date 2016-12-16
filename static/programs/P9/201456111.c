#include<stdio.h>
#include<stdlib.h>
struct bunch{
	int m;
	long long int w;
	int* a;
};
int main()
{
	struct bunch b[1000];
	int n,k,l,s,r,t,m,i,f,o;
	long long int mod;
	int* u;
	scanf("%d",&n);
	scanf("%lld",&mod);
	for(k=0;k<n;k++)
	{
		long long int sum=0;
                scanf("%d",&b[k].m);
		int* p=(int*)malloc(sizeof(int)*b[k].m);
		b[k].a=p;
		for(l=0;l<b[k].m;l++)
		{
			scanf("%d",&b[k].a[l]);
			sum=sum+b[k].a[l];
			
		}
		/*for(l=0;l<b[k].m;l++)
		{
		printf("weights are %d \n",b[k].a[l]);	
		}*/
		b[k].w=sum%mod;
		//printf("sum of the %dth struct  is %d\n",k,b[k].w);
	}
	for(m=0;m<(n-1);m++)
	{
		for(r=0;r<(n-1);r++)
		{
			if((b[r].w)>(b[r+1].w))
			{
				o=b[r].m;
				b[r].m=b[r+1].m;
				b[r+1].m=o;
				u=b[r+1].a;
				b[r+1].a=b[r].a;
				b[r].a=u;
				s=b[r+1].w;
				b[r+1].w=b[r].w;
				b[r].w=s;
				//printf("if loop entered for %d of r\n",r);
				/*for(f=0;f<b[r].m;f++)
				{
					printf("%d\n",b[r].a[f]);
				}*/

			}
		}
	}
	for(t=0;t<n;t++)
	{
		printf("%lld\n",b[t].w);
		for(i=0;i<b[t].m;i++)
		{
			printf("%d\n",b[t].a[i]);
		}
		printf("\n");
	}
	return 0;
}
