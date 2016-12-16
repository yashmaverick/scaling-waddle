#include <stdio.h>
#include <stdbool.h>
#define N 100048
int l[N], s[N], top = 0;
long long int h[N], maxa;
long long int MAX(long long int a, long long int b)
{
	return (a > b)?a:b;
}
#define sd(a) scanf("%d",&a)
#define p(a) printf("%lld\n",a)
#define sl(a) scanf("%lld",&a)
int main(void)
{
	int n;
	for(n; sd(n)==1 && n;)
	{
		maxa = 0; top = -1;
		int i;
		for(i=0; i<n;i++)
		{
			sl(h[i]);
			bool popped = top >= 0 && h[i] < h[s[top]];
			while(top >= 0 && h[i] < h[s[top]])
				maxa = MAX(maxa, h[s[top]] * (i - l[top--]));
			if(top == -1 || h[i] > h[s[top]]){
				s[++top] = i;
				if(!popped) l[top] = i;
			}
		}
		while(top >= 0) maxa = MAX(maxa, h[s[top]] * (n - l[top--]));
		p(maxa);
	}
	return 0;
}
