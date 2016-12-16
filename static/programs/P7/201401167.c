#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#define sc(n) scanf("%lld",&n)
#define ssc(n) scanf("%d",&n)
#define SET(a,b) memset(a,b,sizeof(a))
#define DRT()  LL t; sc(t); while(t--)
typedef long long LL;

int main()
{	
	DRT(){
		LL ar1[1000000],i,ar2[1000000],mn=INT_MAX,mx=INT_MIN,n;
		sc(n);
		for(i=0;i<n;i++)
		{sc(ar1[i]);if(ar1[i]<mn)mn=ar1[i];
			if(ar1[i]>mx)mx=ar1[i];}
		SET(ar2,0);
		LL cnt=0;
		for(i=0;i<n;i++)
			ar2[ar1[i]-mn]++;
		for(i=0;i<=mx-mn;i++)
			cnt+=(ar2[i]*(ar2[i]-1))/2;
		printf("%lld\n",cnt);
		}
}
			

