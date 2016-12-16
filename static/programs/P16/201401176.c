#include<stdio.h>
#include<math.h>
int main()
{
	int i,n,a,ans,x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		x=log(a)/log(2);
		y=(pow(2,x)+pow(2,x+1)-2)/2;
		if(y<a)
			ans=2*x;
		else
			ans=(2*x)-1;
		printf("%d\n",ans);
	}
	return 0;
}
