#include <stdio.h>
#include <math.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		int x;
		int ans;
		int tmp;
		scanf("%d",&n);
		if (n == 1) printf("%d\n",0);
		else
		{
			ans = log2(n);
			//printf("%d\n",ans);
			tmp = (pow(2,ans+1)-pow(2,ans-1)-1);
			//printf("%d\n",tmp);
			if (n >= (pow(2,ans+1)-(pow(2,ans-1))))
			{
				x = 2*ans;
			}
			else
				x = 2*ans-1;
			printf("%d\n",x);
		}
	}
	return 0;
}
