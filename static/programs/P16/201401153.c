#include<stdio.h>
#include<math.h>
int main()
{
	long long n,i,x,j,y,count;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		j=1;
		count=0;
		scanf("%lld",&x);
		while(x>0)
		{
			y=x;
			x=x-j;
			j*=2;
			count++;
		//	printf("y is %lld   count is %lld\n",y,count);
		}
		count--;
		if(y>pow(2,count-1))
		{
			printf("%lld\n",2*count);
		}
		else
			printf("%lld\n",2*count-1);
	}
	return 0;
}
