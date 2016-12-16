#include<stdio.h>
#include<math.h>
int main()
{
long long int test;
long long int g,n;
scanf("%lld",&test);
for(g=0;g<test;g++)
{
 scanf("%lld",&n);
long long int k=n;
long long int count=0;
  	while(n!=0 && n!=1)
 	{
		count++;
		n=n/2;
	}
	long long int lol=pow(2,count);
	long long int sol=pow(2,count+1);
	long long int f=(lol+sol)/2;
	if(k<f)
	printf("%lld\n",2*count-1);
	else
	printf("%lld\n",2*count);
}
return 0;
}

