#include<stdio.h>
//# define max 1000000050
int main()
{
	long long int t,n,i,p,a[100005],l,u,mid,p1,p2,m,o,b[100005],c[100005];
	unsigned long long int sum;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		//a[n]=max;
		scanf("%lld",&m);
		for(i=0;i<m;i++)
			scanf("%lld",&b[i]);
		//b[m]=max;
		scanf("%lld",&o);
		for(i=0;i<o;i++)
			scanf("%lld",&c[i]);
		//c[o]=max;
		sum=0;
		for(i=0;i<m;i++)
		{
			p=b[i];
			l=0,u=n-1;
			while(l<=u){
				mid=(l+u)/2;
				if(a[mid]<=p)
				{
					if(mid==n-1)
						break;
					if(a[mid+1]>p)
						break;
					else
						l=mid+1;
				}
				else
					u=mid-1;

			}                                         
			if(i<mid)
				mid=i;
			//printf("p=%d mid=%d\n",p,mid);
			if(a[mid]<=p)
				p1=mid+1;
			else
				p1=mid;
			//printf("p1=%d\n",p1);
			//printf("p=%dmid=%d\n",p,mid);
			l=0,u=o-1;
			while(l<=u){
				mid=(l+u)/2;
				if(c[mid]>=p)
				{
					if(mid==0)
						break;
					if(c[mid-1]<p)
						break;
					else
						u=mid-1;
				}
				else
					l=mid+1;
				/*
				   if(p==c[mid]){
				   break;
				   }
				   else if(p<c[mid]){
				   u=mid-1;
				   }
				   else
				   l=mid+1;*/
			}
			if(i>mid)
				mid=i;
			//printf("p=%d mid=%d\n",p,mid);
			if(c[mid]<p)
				p2=o-mid-1;
			else 
				p2=o-mid;
			if(p2<0)
				p2=0;
			//printf("p2=%d\n",p2);
			sum=sum+p1*p2;
			//printf("sum=%llu\n",sum);
		}
		printf("%llu\n",sum);
	}
	return 0;
}

