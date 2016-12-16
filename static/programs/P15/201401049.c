#include <stdio.h>
#include <stdlib.h>
#define u unsigned
#define s(t) scanf("%d",&t)
#define sl(t) scanf("%lld",&t)
#define ll long long
#define f(i,n) for(i=0;i<n;i++)
#define F(i,j,n) for(i=j;i<n;i++)
#define p(a) printf("%d",a)
#define pspace(a) printf("%d ",a)
#define pointblank printf("\n")
#define ret(a) return a
#define w(t) while(t--)
#define whilecheck(t) while(t)
#define elif else if
#define LIM 1000001

int main(void)
{
	int t,n,k,*a,min;
	int i,j;
	s(t);
	w(t)
	{
		min=0;
		s(n);s(k);
		a=(int*)malloc(sizeof(int)*n);
		f(i,n)s(a[i]);
		f(i,n-k+1)
		{
			if((!i)||min<i||a[min]>=a[i+k-1])
			{
				//min=min(a,i,i+k-1);
				min=i;
				F(j,i,i+k)
				{
					if(a[j]<=a[min])
						min=j;
				}
			}
			/*else if(a[min]>=a[i+k-1])
			{
				min=min(a,i,i+k-1);//min=i+k-1;//
			}*/
			if(i<n-k)
				pspace(a[min]);
			else
				p(a[min]);
		}
		pointblank;
		free(a);
	}
	return 0;
}