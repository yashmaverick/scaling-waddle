#define loop(n) for(l=0;l<n;l++)
#define si(m) scanf("%lld",&m)
#include<stdio.h>
long long int bless(long long int a[],long long int k,long long int low,long long int high){
	if(low>high)
		return -1;
	long long int mid;
	mid=(low+high)/2;
	if(a[mid]>k)
		return bless(a,k,low,mid-1);
	else{
		if(mid==high)
			return mid;
		else if(a[mid+1]>k)
			return mid;
		else
			return bless(a,k,mid+1,high);
	}
}
long long int bin(long long int a[],long long int low,long long int high,long long int k){
	if(low>high)
		return -1;
	long long int mid;
	mid=(low+high)/2;
	if(a[mid]<k)
		return bin(a,mid+1,high,k);
	else{
		if(mid==low)
			return mid;
		else if(a[mid-1]<k)
			return mid;
		else
			return bin(a,low,mid-1,k);
	}
}

int main(){
	long long int a[100000],b[100000],c[100000];
	long long int i,j,k,p,q,r,l,t;
	si(t);
	while(t--){
	si(p);
	loop(p)
		si(a[l]);
	si(q);
	loop(q)
		si(b[l]);
	si(r);
	loop(r)
		si(c[l]);
	long long int h3;
	long long int  na,nc,ans=0;
	h3=r-1;
	for(j=0;j<q&&j<r;j++){
		if(j>p-1)
		{
			i=bless(a,b[j],0,p-1);
		}
		else
			i=bless(a,b[j],0,j);
		if(i!=-1){
			na=i+1;
			k=bin(c,j,h3,b[j]);
		//	printf("%lld %lld ",k,na);
			if(k==-1)
				break;
			else{
				nc=h3-k+1;
			//	printf("%lld\n",nc);
				ans+=(na)*(nc);
			}
		}
	}
	printf("%lld\n",ans);
	}
	return 0;
}
