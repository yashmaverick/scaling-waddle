#include<stdio.h>
int main()
{
	long long int t,P,Q,R,i,j,k;
	long long int tmp,a[100001],b[100001],c[100001],x[100001],y[100001],sum;
	scanf("%lld",&t);
	while(t>0)
	{
		scanf("%lld",&P);
		for(i=0;i<P;i++)
			scanf("%lld",&a[i]);
		scanf("%lld",&Q);
		for(i=0;i<Q;i++)
			scanf("%lld",&b[i]);
		scanf("%lld",&R);
		for(i=0;i<R;i++)
			scanf("%lld",&c[i]);
		tmp=0;k=0;j=0;i=0;
		while(j<Q)
		{
			//if(i>=P)
			//	a[i]=b[j]+1;
			if(b[j]>=a[i] && j>=i)
			{
				tmp++;
				i++;
			}
			else// if(b[j]<a[i])
			{
				x[j]=tmp;
				j++;
			}
		}
		i=0;j=0;k=0;tmp=0;sum=0;
		while(j<R)
		{
			//if(i>=Q)
			//	b[i]=c[j]+1;
			if(c[j]>=b[i] && j>=i)
			{
				tmp=tmp+x[i];
				i++;
			}
			else// if(b[i]<c[j])
			{
				y[j]=tmp;
				sum=sum+y[j];
				j++;
			}
		}
		/*for(i=0;i<p;i++)
		  printf("%lld ",x[i]);
		  printf("\n");
		  for(i=0;i<j;i++)
		  printf("%lld ",y[i]);*/
		printf("%lld\n",sum);
		//int sum=0;
		/*for(i=0;i<q;i++)
		  {
		  sum+=
		  }*/
		t--;
	}
	return 0;
}
