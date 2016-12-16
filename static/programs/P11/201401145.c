#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define repf(i,l,n) for(i=l;i<n;i++)
#define repb(i,l,n) for(i=l;i>=n;i--)
typedef long long int LL;
LL max=0,ans,n,i,j,start=0,z;
void in (LL *address){
	scanf("%lld",address);
}
void out(LL val){
	printf("%lld\n",val);
}
LL stack[100001],a[100001],pos[100001];
int main()
{
	in(&n);
	while(n!=0)
	{
		start=0;
		in(&a[0]);
		stack[start]=0;
		pos[0]=-1;
		repf(i,1,n)
		{
			in(&a[i]);
			if(start==-1)
				start=0;
			if(stack[start]!=-1 && a[stack[start]]<a[i])
			{
				pos[i]=stack[start];
				stack[++start]=i;
			}
			else
			{
				while(a[stack[start]]>=a[i] && start>-1)start--;
				if(start!=-1)
					pos[i]=stack[start];
				else
					pos[i]=-1;
				stack[++start]=i;
			}
		}
		start=0;
		stack[start]=n-1;
		max=(n-pos[n-1]-1)*a[n-1];
		repb(i,n-2,0)
		{
			if(a[stack[start]]<a[i])
			{
				z=stack[start];
				stack[++start]=i;
			}
			else
			{
				while(a[stack[start]]>=a[i] && start>-1)start--;
				if(start!=-1)
					z=stack[start];
				else
					z=n;
				stack[++start]=i;
			}
			ans=(z-pos[i]-1)*a[i];
			max=fmax(ans,max);
		}
		out(max);
		in(&n);
	}
	return 0;
}
