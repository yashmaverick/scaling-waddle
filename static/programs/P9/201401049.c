#include <stdio.h>
#include <stdlib.h>
#define s(t) scanf("%d",&t)
#define sl(t) scanf("%lld",&t)
#define ll long long
#define f(i,n) for(i=0;i<n;i++)
#define F(i,j,n) for(i=j;i<n;i++)
#define p(t) printf("%d\n",t)
#define pointblank printf("\n")
#define ret(a) return a
#define elif else if
#define LIM 1001000
#define MAX(x,y) (((x)>(y))?x:y)
#define MIN(x,y) (((x)<(y))?x:y)
struct q9{int start;int M;int sum;};
int main(void){int n,i,j;ll int mod;s(n);sl(mod);int A[LIM];struct q9 *a;a=(struct q9*)malloc(n*sizeof(struct q9)); f(i,n){s(a[i].M);a[i].sum=0;F(j,a[i].start,a[i].start+a[i].M){s(A[j]);a[i].sum+=A[j];a[i].sum=a[i].sum%mod;}a[i+1].start=a[i].start+a[i].M;}f(i,n)F(j,1,n)if(a[j].sum<a[j-1].sum){struct q9 temp = a[j];a[j] = a[j-1];a[j-1]= temp;}f(i,n){p(a[i].sum);F(j,a[i].start,a[i].start+a[i].M)p(A[j]);pointblank;}ret(0);}
