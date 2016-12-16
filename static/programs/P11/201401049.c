#include <stdio.h>
#define s(t) scanf("%d",&t)
#define mod 1000000007
#define ll long long
#define w while
#define f(i,n) for(i=1;i<=n;i++)
#define F(i,j,n) for(i=j;i<=n;i++)
#define p(t) printf("%lld\n",t)
#define blank printf("\n")
#define ret(a) return a
#define elif else if
#define LIM 100100
#define MAX(x,y) (((x)>(y))?x:y)
int n,A[LIM],B[LIM],size=0;
int main(void){int i;while(6){s(n);if(!n) break;f(i,n)scanf("%d", &A[i]);ll int toprint=0;size=0;A[0]=0;A[n+1]=0;f(i,n+1){w(size && A[B[size]]>=A[i]){toprint=MAX(toprint, (long long)A[B[size]]*(long long)(i-B[size-1]-1));size--;}B[++size] = i;}p(toprint);}return 0;}