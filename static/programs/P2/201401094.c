#include<stdio.h>
#include<stdlib.h>
#define gcu getchar_unlocked 
#define pcu putchar_unlocked
inline void bns(int *a,int r,int *p,int q,int l)
{
	if(l>r)
	{
		*p=r+1;
		return;
	}
	int end=r;
	register int mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(a[mid]<q)
			l=mid+1;
		else
			r=mid;
	}
	if(a[l]<q)
		r++;
	*p=r;
	return;
}
int main()
{
	int t,i,p,q,r;
	scanf("%d",&t);
	while(t--)
	{
		int *a,*b,*c,w;
		long long int *dp;
		unsigned long long int *total;
		scanf("%d",&p);
		a=(int*)malloc(p*sizeof(int));
		total=(unsigned long long int*) malloc(p*sizeof(unsigned long long int));
		for(i=0;i<p;i++)
		{
			scanf("%d",&a[i]);
			//	printf("%d",a[i]);
		}
		scanf("%d",&q);
		b=(int*)malloc(q*sizeof(int));
		dp=(long long int*)malloc(q*sizeof(long long int));
		for(i=0;i<q;i++)
			scanf("%d",&b[i]);
		scanf("%d",&r);
		c=(int*)malloc(r*sizeof(int));
		for(i=0;i<r;i++)
			scanf("%d",&c[i]);
		bns(c,r-1,&w,b[q-1],q-1);
		dp[q-1]=r-w;
		//	printf("dp:%lld\n",dp[q-1]);
		for(i=q-2;i>=0;i--)
		{
			bns(c,r-1,&w,b[i],i);
			dp[i]=r-w;
			dp[i]+=dp[i+1];
			//								printf("w:%d\n",w);
			//							printf("b:%d\n",b[i]);
			//		printf("dp:%lld\n",dp[i]);
		}
		bns(b,q-1,&w,a[p-1],p-1);
		if(w<q)
			total[p-1]=dp[w];
		else
			total[p-1]=0;
		//		printf("total:%lld\n",total[p-1]);
		for(i=p-2;i>=0;i--)
		{
			bns(b,q-1,&w,a[i],i);
			if(w<q)
				total[i]=dp[w];
			else
				total[i]=0;
			total[i]+=total[i+1];
			//		printf("w:%d\n",w);
			//			printf("total:%d\n",b[i]);
		}
		printf("%llu\n",total[0]);
		free(a);
		free(b);
		free(c);
		free(dp);
		free(total);
	}
	return 0;
}
