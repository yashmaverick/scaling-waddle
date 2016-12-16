#include<stdio.h>
int main()
{
	long long int n,i,j,max,A[100005],S[100005],Area[100005];
	while(7)
	{
		scanf("%lld",&n);
		if(n==0)
			return 0;
		scanf("%lld",&A[0]);
		max=0;
		S[0]=-1;
		Area[0]=A[0];
		for(i=1;i<n;i++)
		{
			scanf("%lld",&A[i]);
			if(A[i-1]<A[i])
				S[i]=i-1;
			else
			{
				j=i-1;
				while(A[j]>=A[i] && S[j]!=-1)
					j=S[j];
				if(A[j]<A[i])
					S[i]=j;
				else
					S[i]=-1;
			}
			if(S[i]==-1)
				Area[i]=A[i]*(i+1);
			else
				Area[i]=A[i]*(i-S[i]);
		}
		S[n-1]=-1;
		max=Area[n-1];
		for(i=n-2;i>=0;i--)
		{
			if(A[i+1]<A[i])
				S[i]=i+1;
			else
			{
				j=i+1;
				while(A[j]>=A[i] && S[j]!=-1)
					j=S[j];
				if(A[j]<A[i])
					S[i]=j;
				else
					S[i]=-1;
			}
			if(S[i]==-1)
				Area[i]=Area[i]+A[i]*(n-i)-A[i];
			else
				Area[i]=Area[i]+A[i]*(S[i]-i)-A[i];
			if(max<Area[i])
				max=Area[i];//printf("max=%lld\n",max);}
		}
		//for(i=0;i<n;i++)
		//printf("area=%lld\n",Area[i]);
		printf("%lld\n",max);
	}
	return 0;
}	
