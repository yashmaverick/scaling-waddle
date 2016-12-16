#include<stdio.h>
#include<stdlib.h>

long long int pt=0;
long long int count=0,b[100000];
void push(long long int m)
{
	pt++;
	b[pt]=m;
}
void pop()
{
	pt--;
}
long long int top()
{
	if(pt<=0)
		return -1;
	return b[pt];
}
int main()
{
	while(1)
	{
		long long int i,n,a[100000];
		scanf("%lld",&n);
		if(n==0)
			return 0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		count=0,pt=0;
		long long int max=0;
		for(i=0;i<n;i++)
		{
			long long int area=0;
			if(i==0)
			{
				push(i);
				count++;
			}
			else if(a[top()]<a[i])
			{
				push(i);
				count++;
			}
			else if(a[top()]>=a[i])
			{
				while(a[top()]>a[i] && count>0)
				{

					long long int var=top();
					area=(i-var)*a[var];
					long long int value=a[var];
					pop();
					long long int d=top();
					area=area+value*(var-d-1);
					if(area>max)
						max=area;
					count--;
				}
				push(i);
				count++;
			}
			//printf("1-----max:%d,count:%d,area:%d,pt:%d\n",max,count,area,pt);
			if(i==n-1 && count>0)
			{
				while(count>0)
				{
					long long int var=top();
					area=(i+1-var)*a[var];
					long long int value=a[var];
					pop();
					long long int d=top();
					//printf("2----d:%dcnt:%d,pt:%d\n",d,count,pt);
					area=area+value*(var-d-1);
					if(area>max)
						max=area;
					count--;
					//printf("3-----var:%d,area:%d,count:%d,max:%d\n",var,area,count,max);
				}
			}
		}
		printf("%lld\n",max);
	}
	return 0;
}
