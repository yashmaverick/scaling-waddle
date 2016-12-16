#include<stdio.h>
long long int equal(long long int a)
{
	return a;
}
long long int sume(long long int a,long long int b)
{
return a+b;
}
int main()
{
	while(1)
	{
		long long int num,sum=equal(0),maximum;
		scanf("%lld",&num);
		if(num==0)
			break;
		else
		{
			long long int height[num],i,j;
			for(i=equal(0);i<num;i=sume(i,1))
			{
				scanf("%lld",&height[i]);
			}
			for(i=equal(0);i<num-1;i=sume(i,1))
			{
				maximum=equal(height[i+1]);
				for(j=equal(i+2);j<num;j=sume(j,1))
				{
					if(height[j-1]>maximum)
						maximum=equal(height[j-1]);
					if(height[i]<maximum)
					{
						sum=equal(sum+num-j);
					break;
					}
                                         if(height[j]<maximum)
					{
						sum=sume(sum,1);
					}
                                        
					
				}
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
