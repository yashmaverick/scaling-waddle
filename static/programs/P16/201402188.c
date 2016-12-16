#include<stdio.h>
#include<math.h>
int main()
{
	int jaa,test;
	scanf("%d",&test);
	for(jaa=0;jaa<test;jaa++)
	{
		int a[100000],n;
		scanf("%d",&n);
		int i=1;
		while(1)
		{
			a[i]=pow(2,i)-1;
			if(a[i]>=n)
				break;
			i++;
		}
		if(n>(a[i]+a[i-1])/2)
			printf("%d\n",2*(i-1));
		else 
			printf("%d\n",2*(i-1)-1);
	}
	return 0;
}
