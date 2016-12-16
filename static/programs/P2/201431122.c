#include<stdio.h>
/*long long int nap(long long int b[],long long int a,long long int st,long long int end)
{
	//	printf("%lld %lld\n",st,end);
	long long int i=(st+end+1)/2;
	while(st!=end)
	{
		i=(st+end+1)/2;

		if(b[i]>a)
			end = i-1;
		else
			st=i;
	}

	if(b[st]<=a)
		return st;
	else
		return st-1;

}*/
int main()
{
	long long int count,te,cstar,astar,i,j,k,kl,il,sum,a[100010],b[100010],c[100010],t[100010],p,q,r,jin,kin,na,nc;
	scanf("%lld",&te);
	while(te--)
	{
		sum=0;

		scanf("%lld",&p);
		for(i=0;i<p;i++)
			scanf("%lld",&a[i]);
		scanf("%lld",&q);
		for(i=0;i<q;i++)
			scanf("%lld",&b[i]);
		scanf("%lld",&r);
		for(i=0;i<r;i++)
			scanf("%lld",&c[i]);
		count=0;
		cstar=0;
		for(j=0;j<q;j++)
		{

				 if(j<r)
				{
					if(cstar<j)
						cstar = j;
					nc=0;
					for(i=cstar;i<r;i++)
					{
						if(b[j]<=c[i])
						{
							cstar=i;
							nc=r-i;
						//	printf("nc %lld\n",nc);
							break;
						}
					}
				}
				else if(j>=r)
					nc=0;
				 t[j]=nc;                                                                                                                                                            }
		
		for(i=q-2;i>=0;i--)
			t[i] +=t[i+1];
//		for(i=0;i<q;i++)
//			printf("%lld\n",t[i]);
		astar=0;
		for(j=0;j<p;j++)
		{
			if(j>astar)
				astar=j;
				for(i=astar;i<q;i++)
				{
					if(a[j]<=b[i])
					{
					sum += t[i];
					astar=i;
					break;
					}
				}
					
		}
		printf("%lld\n",sum);



	}
	return 0;
}
