#include<stdio.h>
int main()
{
	long long int t,x,y,z;
	scanf("%lld",&t);
	for(x=0;x<t;x++)
	{
		long long int i,j,k,count,w;
		scanf("%lld",&i);
		long long int a[i];
		for(y=0;y<i;y++)
			scanf("%lld",&a[y]);
		scanf("%lld",&j);
		long long int b[j];
		for(y=0;y<j;y++)
			scanf("%lld",&b[y]);
		scanf("%lld",&k);
		long long int c[k];
		for(y=0;y<k;y++)
			scanf("%lld",&c[y]);
		long long int d[j];
		for(y=0;y<j;y++)
			d[y]=0;
		for(y=0;y<j;y++)
		{
			if(y==k)
				break;
			for(z=y;z<k;z++)
			{
				if(c[z]>=b[y])
				{
					d[y]=(k-z);
					//printf("%d ",d[y]);
//					z++;
					break;
				}
			}
		}
		for(y=(j-2);y>=0;y--)
			d[y]=(d[y]+d[y+1]);
		//printf("\n");
		count=0;
		for(y=0;y<i;y++)
		{
			for(z=y;z<j;z++)
			{
				if(a[y]<=b[z])
				{
					//a[y]=0;
					//for(w=z;w<j;w++)
					//	a[y]=(a[y]+d[w]);
					count=(count+d[z]);
//					printf("dfgd is %d\n",count);
//					printf("aaa %d %d \n",y,a[y]);
					break;
				}
			}
		}
	//	for(y=0;y<i;y++)
	//		printf("%d ",a[y]);
	//	printf("\n");
		printf("%lld\n",count);
	}
	return 0;
}
