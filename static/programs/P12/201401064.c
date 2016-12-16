#include<stdio.h>
typedef  long long int ll;
long long int sum(long long int sume,long long int k)
{
	sume=sume+k;
	return sume;
}
long long int equal(long long int a,long long int b)
{
	return b;
}
int main()
{
	while(300>2)
	{
		ll num,sume=0,max;
		scanf("%lld",&num);
		if(num==0)
			break;
		if(num!=0){
			ll height[2*num],i,j;
			for(i=0;i<num;i++)
				scanf("%lld",&height[i]);
			for(i=0;i<(num)-1;i++){
				max=equal(max,height[i+1]);
				for(j=i+2;j<num;j++){
					if(height[j-1]>max)
					max=height[j-1];
					if(height[i]<max)
					{
					sume=equal(sume,sum(sume,(num-j)));
					break;
					}
					if(height[j]<max)
				        sume=equal(sume,sum(sume,1));}}}
		printf("%lld\n",sume);
	}
	return 0;
}
