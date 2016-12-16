
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#define Sc(n) scanf("%lld",&n)
#define sc(n) scanf("%d",&n)
#define SET(a,b) memset(a,b,sizeof(a))
#define DRT()  int t; sc(t); while(t--)
typedef long long LL;
int main()
{	
	DRT(){
		int n,p;
		sc(n);
		p=n>1?1:0;
		while(n>3)
		{n>>=1;p++;}
		if(n&1)
			printf("%d\n",2*p);
		else
			printf("%d\n",2*p-1); 
		}
}
