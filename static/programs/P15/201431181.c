#include<stdio.h>
int main()
{
	int n,k,T,t;
	scanf("%d",&T);
	for( t=0 ; t<T ; t++ )
	{
		scanf("%d%d",&n,&k);
		int A[n],I[n],i,j,min,tmp,temp;
		scanf("%d",&A[0]);
		I[0]=0;
		j=0;
		//:w
		//printf("W\n");
		temp=A[0];
		for( i=1 ; i<k ; i++ )
		{
			scanf("%d",&A[i]);
			if( A[i]<temp )
			{
				temp=A[i];
				I[j]=i;
			}
		}
		j=1;
		for( i=k ; i<n ; i++ )
		{
			scanf("%d",&A[i]);
			if( I[j-1]==i-k)
			{
				if( A[i]<A[i-k] )
					I[j]=i;
				else
				{
					temp=A[i];
					for( tmp=i-k+1 ; tmp<=i ; tmp++ )
						if( A[tmp]<=temp )
						{
							temp=A[tmp];
							I[j]=tmp;
						}
				}
			}
			else if( A[i]<A[I[j-1]] )
				I[j]=i;
			else
				I[j]=I[j-1];
			j++;
		}
		if( n>2 )
		{
			for( i=0 ; i<n-k ; i++ )
				printf("%d ",A[I[i]]);
			printf("%d\n",A[I[n-k]]);
		}
		else if( n==2 )
		{
			if( k==1 )
				printf("%d %d\n",A[0],A[1]);
			else
				printf("%d\n",A[I[0]]);
		}
		else
			printf("%d\n",A[0]);
	}
	return 0;
}
