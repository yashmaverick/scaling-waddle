#include<stdio.h>
#define cout(n) printf("%lld\n",n)
#define cin(n) scanf("%lld", &n)
#define N 100100
#define ll long long int
//using namespace std;
ll t, i, j, k, n, count, a[N], b[N], c[N], minimax[N], pre[N], na, nb, nc;
ll binsearch(ll a[], ll val, ll start, ll end){
	if(start>=end)return (a[start]>=val)?start:-1;
	ll mid = (start+end)/2;
	if(a[mid] >= val)return binsearch(a, val, start, mid);
	return binsearch(a, val, mid+1, end);
}
int main(){
	cin(t);
	while(t--){
		count=0;
		cin(na);
		for(i=0;i<na;i++)cin(a[i]);
		cin(nb);
		for(i=0;i<nb;i++)cin(b[i]);
		cin(nc);
		for(i=0;i<nc;i++)cin(c[i]);
		n = na;
		if(nb>nc)nb=nc; //nb=min(nb,nc);
		if(na>nb)na=nb; //na=min(na,nb);
		n=na;
		j=k=0;
		for(j=0;j<nb;j++){
			minimax[j] = binsearch(c, b[j], j, nc-1);
			if(minimax[j]==-1)minimax[j]=0;
			else
			minimax[j] = nc - minimax[j];
		}
		for(i=j;i<nb;i++)minimax[j]=0;
		for(j=nb-2; j>=0; j--)minimax[j] = minimax[j+1] + minimax[j];
		for(i=0;i<na;i++){
			//while((b[j]<a[i] || j<i))j++;
			//if(i>=na || j>=nb)break;
			j = binsearch(b, a[i], i, nb-1);
			if(j<i)continue;
			if(j==-1){continue;}
			else
			count+=minimax[j];
		}
		cout(count);
	}
}
