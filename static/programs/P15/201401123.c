#include<stdio.h>
#define s(n) scanf("%lld",&n)
typedef long long L;

		L a[10002],q[10002];
int main()
{
	L n,k,i,j,t;s(t);
	while(t--)
	{
		s(n);s(k);
		L top,end,p;
		L min;
		for(i=0;i<n;i++)
			s(a[i]);
		if(k==1)
			for(i=0;i<n;i++)
			{
				if(i<n-1)
					printf("%lld ",a[i]);
				else
					printf("%lld\n",a[i]);
			}
		else
		{
			top = 0;
			p=0;
			end=0;
			q[top]=0;
			top=+1;
			L count = k-1;
			min = a[q[end]];
			//		printf("%lld %lld %lld %lld\n",top, end, q[end], a[q[end]]);
			for(i=1;i<n;i++)
			{
				if( i-q[end] >= k)
				{
					end=end+1;
					if(a[q[end-1]]==min)
						min = a[q[end]];
				}
				if(a[i] > a[q[top-1]])
				{
					q[top]=i;
					top++;
					count--;
				}
				else
				{
					top--;
					while((a[i] <= a[q[top]]) && (top >=end))
					{
						top--;
					}
					count--;
					top++;
					q[top] = i;
					top++;
					if(a[q[top-1]] < min)
						min=a[q[top-1]];
				}
				if(count<=0)
				{
					if(p<n-k)
						printf("%lld ",min);
					else if(p==n-k)
						printf("%lld\n",min);
					p++;
				}
			}
		}
	}
	return 0;
}
