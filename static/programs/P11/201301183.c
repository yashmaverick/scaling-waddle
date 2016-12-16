#include<stdio.h>
int main(){
	int a[100005],b[100005],c[100005],n,p,q,r,t,y;
	long long area;
	scanf("%d",&n);
	while(n!=0)
	{
		area=0;
		for(p=0;p<n;p=p+1)scanf("%d",&a[p]);
		b[0]=-1;
		for(p=1;p<n;p=p+1)
		{
			q=p-1;
			while(q>=0)
				if(a[q]>=a[p])q=b[q];
				else break;
			b[p]=q;
		}
		c[n-1]=n;
		for(p=n-2;p>=0;p=p-1)
		{
			q=p+1;
			while(q<=n-1)
				if(a[q]>=a[p])q=c[q];
				else break;
			c[p]=q;
		}
		for(p=0;p<n;p=p+1)if(((long long)(c[p]-1-b[p])*a[p])>area)area=(long long)(c[p]-b[p]-1)*a[p];
		printf("%lld\n",area);
		scanf("%d",&n);
	}
	return 0;
}
