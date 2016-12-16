#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define ll long long int

void swap(ll *a,ll *b)
{
	ll temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return;
}

int main()
{
ll n,l[100100],r[100100],v[100100],res,w,h,s[100100],st,i,x,flag;
while(1)
{
	scanf("%lld",&n);
	if(n==0) break;
	res=st=0;
	for(i=0;i<n+5;i++)s[i]=0;
	flag=10000000;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x); 
		v[i]=x;
		flag=min(v[i],flag);
	}
	//for(i=1;i<=n;i++)printf("%lld ",v[i]);
	//printf("\n");
	s[0]=0;
	v[0]=-100;
	for(i=1;i<=n;i++)
	{
		while( v[s[st]] >= v[i] )st--;
		l[i] = s[st];
		s[++st]=i;
	}
	st=n+1;
	v[n+1]=-100;
	
	for(i=1;i<=n+5;i++)s[i]=r[i]=n+1;
	for(i=n;i>=1;i--)
	{
		while( v[s[st]] >= v[i] )st++;
		r[i] = s[st];
		s[--st]=i;
	}
	//for(i=1;i<=n;i++)printf("%lld ",v[i]);
	//printf("\n");
	for(i=1;i<=n;i++)
	{
		l[i]=n+1-l[i];
		r[i]=n+1-r[i];	
	}
	for(i=1;i<=(n/2);i++){swap(&r[i],&r[n+1-i]);swap(&v[i],&v[n+1-i]);}
	//for(i=1;i<=n;i++)printf("%lld %lld %lld\n",l[i],r[i],v[i]);
	for(i=1;i<=n;i++)
	{
		res=max(res,(l[n+1-i]-1-r[i])*v[i]);
	}
	//res=max(res,flag*n);
	printf("%lld\n",res);
}
return 0;
}
