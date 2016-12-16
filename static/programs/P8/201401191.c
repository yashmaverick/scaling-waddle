#include<stdio.h>
typedef long long int ll;
ll upl,m,N;
ll power(ll i,ll d)
  {
  if(d==0)
  {
  return 1;
  }
  ll tmp=power(i,d/2);
  if(d%2==0)
  {
  return ((tmp%N)*(tmp%N))%N;
  }
  else
  {
  return ((i%N)*(tmp%N)*(tmp%N))%N;
  }
  } 
/*ll power(ll i,ll d)
{
	ll res=1;
	while(d>0)
	{
		if(d%2==0)
		{
			i=i%N;
		}
		else
		{
			res=((res%N)*(i%N))%N;
		}
		i=((i%N)*(i%N))%N;
		d=d/2;
	}
	return res;
} */
int main()
{
	int test;
	scanf("%d",&test);
	//	ll tmp=power(test,cut);
	//	printf("%Ld ",tmp);
	while(test--)
	{
		ll d;
		ll A[100]={0};
		//		ll Fin1=0,Fin2=0,Fin3=0;
		ll A1,A2,A3,i,j,k;
		scanf("%Ld%Ld%Ld%Ld",&upl,&d,&m,&N);
		ll tmp;
		for(i=0;i<N&&i<=upl;i++)
		{
			tmp=power(i,d);
			//			printf("Tmp:%Ld ",tmp);
			A[tmp]++;
			if(upl>tmp)
			A[tmp]+=(upl-i)/N;
		} 
		ll count=0;
		for(i=0;i<N;i++)
		{
		/*	if(A[i]==0)
			{
				continue;
			} */
			for(j=0;j<N;j++)
			{
			/*	if(A[j]==0)
				{
					continue;
				} */
				for(k=0;k<N;k++)
				{
					if(A[i]!=0&&A[j]!=0&&A[k]!=0)
					{
						if((i+j+k)%N==m%N)
						{
							count=((count%1000000007)+((((A[i]%1000000007)*(A[j]%1000000007))%1000000007)*(A[k]%1000000007))%1000000007)%1000000007;
						}
					}
				}
			}
		}
		printf("%Ld\n",count%1000000007);
	}
	return 0;
}
