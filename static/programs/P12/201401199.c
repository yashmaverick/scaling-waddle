#include<stdio.h>
#define size 500005
typedef long long int lli;
void calclr(lli h[],lli cl[],lli n)
{
    lli i,temp;
    cl[n-1]=n;
    for(i=n-2;i>=0;i--)
    {
	temp=i+1;
	while(h[temp]<=h[i] && temp<n)
	{
	    temp=cl[temp];
	}
	cl[i]=temp;
    }
    return;
}

void calcll(lli h[],lli cl[],lli n)
{
    lli i,temp;
    cl[0]=-1;
    for(i=1;i<n;i++)
    {
	temp=i-1;
	while(h[temp]<=h[i] && temp>=0)
	{
	    temp=cl[temp];
	}
	cl[i]=temp;
    }
    return;
}
lli n,h[size],clr[size],cll[size],i,e[size],o[size],t;
int main()
{
    scanf("%lld",&n);
    while(n!=0)
    {
	lli ansr=0,ansl=0,anse=0,ans;
	for(i=0;i<n;i++)
	    scanf("%lld",&h[i]);
	calclr(h,clr,n);
	calcll(h,cll,n);
	for(i=0;i<n;i++)
	{
	    if(clr[i]!=n)
		ansr+=1;
	}
	for(i=0;i<n;i++)
	{
	    if(cll[i]!=-1)
		ansl+=1;
	}
	t=0;
	e[t]=h[0];
	o[t]=1;
	for(i=1;i<n;i++)
	{
	    if(h[i]==e[t])
		o[t]++;
	    else if(h[i]<e[t])
	    {
		t++;
		e[t]=h[i];
		o[t]=1;
	    }
	    else
	    {
		while(h[i]>e[t] && t>=0)
		{
		    t--;
		    if(o[t+1]>1)
		    {
			anse+=(lli)((o[t+1]*(o[t+1]-1))/2);
		    }
		}
		if(h[i]==e[t])
		{
		    o[t]++;
		}
		else
		{
		    t++;
		    e[t]=h[i];
		    o[t]=1;
		}
	    }
	}
	for(i=0;i<=t;i++)
	{
	    if(o[i]>1)
		anse+=(lli)((o[i]*(o[i]-1))/2);
	}
	ans=((n*(n-1))/2)-(anse+ansr+ansl);
	printf("%lld\n",ans);
	scanf("%lld",&n);
    }
    return 0;
}
