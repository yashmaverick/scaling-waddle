#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
int main()
{       ll n,t,k,*a,m,*c,s,j,b,x=0,i;
	scanf("%lld",&t);
	while(t--)
	{      x=0;i=-1;b=10000000000;j=-1;
		scanf("%lld %lld",&n,&k);
		m=n;
		a=(ll *)malloc(sizeof(ll)*k);
		c=(ll *)malloc(sizeof(ll)*k);
		while(n--)
		        {               i++;
			i=i%k;
			if(x==1)        
				j=a[i];
			scanf("%lld",&a[i]);
//      			printf("%lld ",a[i]);
			if(b==j&&x==1)
                        {       for(s=0;s<k;s++)
                                c[s]=a[s];
                                qsort(c,k,sizeof(ll),cmpfunc);
                                b=c[0];
                        }
			if(b>a[i])
				b=a[i];
			if(i==k-1)
		{	/*printf("ya ");*/	x=1;}
			if(x==1 && n==m-k)
				printf("%lld",b);
				else if(x==1)
				printf(" %lld",b);
				             
		}
		free(a);
		free(c);       
		printf("\n");
	}
	return 0;
}
