#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define s(n) scanf("%d",&n)
#define fo(i,m,n) for(i = m ; i < n ; i++)
#define rep(i,n) fo(i,0,n)
int main()
{
	int n,i,j,t;
	s(n);
	int pre[n] , in[n];
	rep(i,n) s(pre[i]);
	rep(i,n) s(in[i]);
	s(t); while(t--)
	{
		int a , b , ia , ib;
		s(a); s(b);
		if(a == b) { printf("%d\n",a); continue; }
		rep(i,n) if(in[i] == a) ia = i; else if(in[i] == b) ib = i;
		rep(i,n)
		{
//			if( i < n-1 &&(pre[i] == a && pre[i+1] == b) || (pre[i] == b && pre[i+1] == a))
//				break;
			int c[n] , f = 0; memset(c , 0 , 4 * n);
			rep(j,n) if(pre[i] != in[j] && !f) c[j] = 0; else if(f == 1) c[j] = 1; else { f = 1; c[j] = 1e9; }
			if(c[ia] != c[ib]) break;
		}
		printf("%d\n",pre[i]);
	}
	return 0;
}
