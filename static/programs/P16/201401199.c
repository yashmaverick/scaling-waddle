#include<stdio.h>
typedef long long int lli;

lli mipow(lli a,lli n)
{
    if(n==1)
	return a;
    return (mipow(a,n/2))*(mipow(a,n-(n/2)));
}

int main()
{
    lli N,Q,hh,i,val,pow[55];
    pow[0]=1;
    for(i=1;i<=50;i++)	
    {
	val=mipow(2,i);
	pow[i]=val;
    }
    scanf("%lld",&N);
    while(N--)
    {
	scanf("%lld",&Q);
	if(Q==1)
	{
	    printf("0\n");
	    continue;
	}
	for(i=0;i>=0;i++)
	{
	    if(pow[i]>Q)
		break;
	}
	hh=i-1;
//	printf("hh=%lld\n",hh);
	val=pow[hh];
	if(Q-val>=val/2)
	    printf("%lld\n",2*hh);
	else
	    printf("%lld\n",(2*hh)-1);
    }
    return 0;
}

