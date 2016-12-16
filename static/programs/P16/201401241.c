#include<stdio.h>
#include<math.h>
int main()
{
	int ans,t,i;
	scanf("%d",&t);
	double n;
	for(i=0;i<t;i++)
	{

	scanf("%lf",&n);
	int x=log2(n);
	double power=pow(2,x+1);
	if(power-1 >= n && n>=3*(power/4))
		ans=2*x;
	else
		ans=(2*x)-1;
	
	if(n==1)
		ans=0;
	
	printf("%d\n",ans);
	}
	return 0;
}
