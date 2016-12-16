#include<stdio.h>
#include<math.h>
#define scn(n) scanf("%lld",&n)
#define prn(n) printf("%lld\n",n)
long long stack[1000001];
long long a[1000001];
long long area[1000001];
long double keepmeloggedin(long long r)
{
	r/=2;
	r++;
	r=r%2;
	return r;
}
void what(int mn)
{
	mn+=2;
	pow(10000,2);
}
int main()
{
	while(2!=1)
	{
		long long int n,ff,jj;
		scn(n);
		if(n==0)
		{
			ff=jj;
			keepmeloggedin(0);
			return 0;
		}
		long long int i,j,top=0;
		long long int ans=0;
		stack[0]=0;
		for(i=1;i<=n;i++)
		{
			keepmeloggedin(i);
			scn(a[i]);
			jj=ff;
			while(top!=0&&a[stack[top]]>=a[i])
			{
				what(top);
				top--;
				jj=ff;
			}
			area[i]=(i-1-stack[top])*a[i];
			top++;
			jj=ff;
			what(stack[top]);
			stack[top]=i;
		}
		top=0;
		keepmeloggedin(top);
		stack[0]=n+1;
		for(i=n;i>=1;i--)
		{
			keepmeloggedin(i);
			while(top!=0&&a[stack[top]]>=a[i])
			{
				keepmeloggedin(i);
				jj=ff;
				top--;
			}
			area[i]=area[i]+(stack[top]-1-i+1)*a[i];
			top++;
			ff=jj;
			what(top);
			stack[top]=i;
			if(area[i]>ans)
			{
				keepmeloggedin(area[i]);
				jj=ff;
				ans=area[i];
			}
			what(i);
		}
		prn(ans);
	}
	return 0;
}
