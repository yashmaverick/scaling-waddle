#include<stdio.h>
int main()
{
	long long int x,P[100000],Q[100000],R[100000],A[100000],n,i,S,E,mid,pos,p,q,r;
	long long int sum;
	int test;
	scanf("%d",&test);
	while(test)
	{
		test--;
		scanf("%lld",&p);
		for(i=0;i<p;i++)
		{
			scanf("%lld",&P[i]);
		}
		scanf("%lld",&q);
		for(i=0;i<q;i++)
		{
			scanf("%lld",&Q[i]);
		}
		scanf("%lld",&r);
		for(i=0;i<r;i++)
		{
			scanf("%lld",&R[i]);
		}
		for(i=0;i<q;i++)
		{
			S=0;
			E=i;
			x=Q[i];
			pos=-1;
			if(E>p-1)
			{
				E=p-1;
			}
			while(S<=E)
			{
				mid=(S+E)/2;
				if((P[mid]<=x)&&(mid==i))
				{
					pos=mid;
					break;
				}
				else
					if((P[mid]>x)&&(mid==i))
					{
						break;
					}

				if((P[mid]<=x)&&((P[mid+1])>x))
				{
					pos=mid;
					break;
				}
				else if(P[mid]<=x)
				{
					pos=mid;
					S=mid+1;
				}
				else
				{
					E=mid-1;
				}
			}
			A[i]=pos+1;
		}
	int flag=0;
	for(i=0;i<q;i++)
	{
		x=Q[i];
		S=i;
		E=r-1;

		pos=-1;
		while(S<=E)
		{
			mid=(S+E)/2;
			if((mid==i)&&(R[mid]<x))
			{
				S=mid+1;

			}
			else if((mid==i)&&(R[mid]>=x))
			{
				pos=mid;
				break;
			}	
			if((R[mid]>=x)&&(R[mid-1]<x))
			{
				pos=mid;
				break;
			}
			else if(R[mid]>=x)
			{
				E=mid-1;
			}
			else
			{
				S=mid+1;
			}
			if((R[mid]==x)&&(S==i))
			{
				pos=i;
				break;
			}

		}
		if(pos==-1)
		{
			Q[i]=0;
		}
		else
		{
			Q[i]=r-pos;
		}
		}
		for(i=0;i<q;i++)
		{
			sum+=A[i]*Q[i];
		}
		printf("%lld\n",sum);
	}
	return 0;
}

