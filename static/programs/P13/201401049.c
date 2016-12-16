#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define s(t) scanf("%lld",&t)
#define sl(t) scanf("%lld",&t)
#define ll long long
#define f(i,n) for(i=0;i<n;i++)
#define F(i,j,n) for(i=j;i<n;i++)
#define p(a,b) printf("%lld %lld\n",a,b)
#define pointblank printf("\n")
#define ret(a) return a
#define w(t) while(t--)
#define elif else if
#define LIM 100007
#define MAX(x,y) (((x)>(y))?x:y)
#define MIN(x,y) (((x)<(y))?x:y)
void tree(ll int,ll int,ll int,ll int[],ll int[]);
ll int bin(ll int,ll int,ll int,ll int[]);
ll int calc_max(ll int[],ll int,ll int);
int main(void){static ll int a[LIM],b[LIM];ll int t;s(t);w(t){ll int n,i,max,maxindex;s(n);f(i,n) s(a[i]);tree(0,n-1,0,a,b);max=maxindex=0;maxindex=calc_max(b,maxindex,n);max=b[maxindex];p(a[maxindex],max);}ret(0);}
ll int bin(ll int beg,ll int last,ll int n, ll int a[]){if(beg<=last){ll int mid=(beg+(last-beg)/2);if(a[mid]>n){if(a[mid-1]<n)ret(mid-1);else bin(beg,mid-1,n,a);}elif(a[mid]<n){if(a[mid+1]>n)ret(mid);else bin(mid+1,last,n,a);}}elif(beg>last)ret(-1);}
void tree(ll int beg,ll int last,ll int count, ll int a[], ll int b[]){if(!(last-beg<=1)){ll int left=bin(beg,last-1,a[last],a);b[last]=count;if(!(left+1))tree(beg,last-1,count+1,a,b);elif(left == last-1)tree(beg,last-1,count+1,a,b);else{tree(beg,left,count+1,a,b);tree(left+1,last-1,count+1,a,b);}}elif(!(last-beg-1)){b[last]=count;b[last-1]=count+1;}elif(beg==last)b[last]=count;}
ll int calc_max(ll int a[],ll int max, ll int n){ll int i;f(i,n){if (a[i]>a[max])max=i;}ret(max);}
