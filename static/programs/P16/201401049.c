#include <stdio.h>
#include <math.h>
#define u unsigned
#define s(t) scanf("%d",&t)
#define sl(t) scanf("%lld",&t)
#define ll long long
#define f(i,n) for(i=0;i<n;i++)
#define F(i,j,n) for(i=j;i<n;i++)
#define p(a) printf("%d\n",a)
#define pointblank printf("0\n")
#define ret(a) return a
#define w(t) while(t--)
#define whilecheck(t) while(t)
#define elif else if
#define LIM 100004
#define MAX(x,y) (((x)>(y))?x:y)
#define MIN(x,y) (((x)<(y))?x:y)

int fire(int x,u int y){int tmp;if(!y) ret(1);tmp=fire(x,y/2);if (!(y%2))ret(tmp*tmp);else ret(x*tmp*tmp);}
int main(void){int t,i,k,query;s(t);w(t){s(query);k=0;i=query;if(query-1){whilecheck(i-1){i/=2;k++;}if(query<(fire(2,k)+fire(2,k-1)))p(2*k-1);else p(2*k);}else pointblank;}ret(0);}