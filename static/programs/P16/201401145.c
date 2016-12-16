#include<stdio.h>
#include<math.h>
#define rep(i,n) for(i=0;i<n;i++)
void in(int *address){
	scanf("%d",address);
}
void out(int *pointer){
	printf("%d\n",*pointer);
}
int main()
{
	int i,t,n,p,ans,k,j,a,b;
	in(&t);
	rep(i,t)
	{
		in(&n);
		a=n;
		a=pow(2,floor(log(n)/log(2)));
		p=n-a;
		ans=2*log(a)/log(2);
		if(a>1)
			a=pow(2,floor(log(a-1)/log(2)));
		if (p<a && n!=1) ans--;
		out(&ans);
	}
	return 0;
}
