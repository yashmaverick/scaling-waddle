#include <stdio.h>
#define s(t) scanf("%d",&t)
#define f(i,n) for(i=0;i<n;i++)
#define F(i,j,n) for(i=j;i<=n;i++)
#define p(t) printf("%d\n",t)
#define w(t) while(t--)
#define MAX(x,y) (((x)>(y))?(x):(y))
#define MIN(x,y) (((x)<(y))?(x):(y))
int main(void)
{
	int t,profit,cheap,i,n,a[100000];
	s(t);
	w(t)
	{
		s(n);
		f(i,n)
			s(a[i]);
		profit=0;
		cheap=a[0];
		f(i,n)
		{
			cheap=MIN(cheap,a[i]);
			profit=MAX(profit,a[i]-cheap);
		}
		p(profit);

	}

	return 0;
}