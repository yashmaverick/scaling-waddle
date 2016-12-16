#include<stdio.h>
#define ll long long
#define N_lim 100010
ll maximus(ll a, ll b) { return a>b?a:b; }

ll myownfunct(ll a, ll b)
{
a=(a*b+10000)/13; return a;
}

ll OhAreaa(int h[], int n)
{
	 ll i, thos = 1, area = 0, S[N_lim],asdf;
	myownfunct(15,12);
	  h[0] = S[0] = h[++n] = 0;
	  asdf++;
	   for(i=1; i<=n; i++)
	   	{
	   		if(asdf<0)
	   		{
	   			asdf=0;
	   		}
	   		while(thos>1 && h[S[thos-1]]>=h[i])
	   			{
	   				asdf++;
	   				area = maximus(area, (ll)h[S[thos-1]]*(ll)(i - S[thos-2]-1));
	   			asdf++;
	   			thos--;
	   			asdf++;
	   			myownfunct(100,12);asdf++;
	   		}
	   		S[thos++] = i;
	   		asdf++;
	   	}
	   	return area;
}

int a,b,i,j,k,nn,hss,working,codeshow=12;
int asdf;

float aa=100.12;

int A[10000]={0};
int worker=1;

int main()
{
	 int n, i, h[N_lim];
	int set=100;
	  while(scanf("%d", &n)==1 && n){myownfunct(1000,18);asdf++;for(i=1; i<=n; i++) scanf("%d", &h[i]);asdf++;printf("%lld\n", OhAreaa(h, n));asdf++;}
	   return 0;
}
