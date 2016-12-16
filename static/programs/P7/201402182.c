#include<stdio.h>
#define MAX 1000005
int main()
{
	long long int t,i,j,l,n,p,c,d,x,y,b[MAX],min,z,o;
	scanf("%lld",&t);
	y=0;
	for(o=1;o<=t;o++)
	{	
		for(i=0;i<MAX;i++){
			b[i]=0;
		}

		y=0;l=0;
		scanf("%lld",&n);
		long long int a[n];
		min=10000001;
		for(p=0;p<n;p++)
		{
			scanf("%lld",&a[p]); 
			if(a[p]<min)
				min=a[p];
		}
		for(z=0;z<n;z++)
		{
			b[a[z]-min]++;

		}
		for(z=0;z<MAX;z++)
		{
			j=b[z];
			y=y+(j*(j-1))/2;

		}


		printf("%lld\n",y);
	}
	return 0;
}
