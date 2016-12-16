#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	int k,count=0,ans,middle;
	long long int n;	
	scanf("%lld",&n);
	k=n;
	while(n!=1)
	{
	n=n/2;
	count++;
	}
	middle = pow(2,count)+pow(2,count)/2;
	if(k < middle)
		ans = 2*count -1 ;
	else if(k >= middle)
		ans = 2*count;

	//if(k==3)
	//	ans = 2;
	if(k==1)
		ans = 0;


	printf("%d\n",ans);
	}

}