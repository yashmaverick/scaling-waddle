#include<stdio.h>
struct bags
{
	int m;
	int index1,index2;
	int s;
};
int main()
{
	int n,i,j,k,temp,mod,M[1000007],i1=0;
	scanf("%d%d",&n,&mod);
	int A[n];
	struct bags bag[n];
	for ( i=0 ; i<n ; i++ )
	{
		scanf("%d",&bag[i].m);
		bag[i].s=0;
		bag[i].index1=i1;
		for ( j=0 ; j<bag[i].m ; j++ )
		{
			scanf("%d",&M[i1]);
			bag[i].s=(bag[i].s+M[i1])%mod;
			i1++;
		}
		bag[i].index2=i1;
	}
	for( i=0 ; i<n ; i++ )
		A[i]=i;
	k=0;
	A[k]=0;
	for ( i=0 ; i<n-1 ; i++ )
	{
		for ( j=i+1 ; j<n ; j++ )
		{
			if ( bag[A[k]].s>bag[j].s )
			{
				temp=A[j];
				A[j]=A[k];
				A[k]=temp;
			}
		}
		k++;
	}
	for( i=0 ; i<n ; i++ )
	{
		printf("%d\n",bag[A[i]].s);
		//printf("%d %d\n",bag[A[i]].index1,bag[A[i]].index2);
		for ( j=bag[A[i]].index1 ; j<bag[A[i]].index2 ; j++ )
			printf("%d\n",M[j]);
		printf("\n");
	}
/*	for( i=0  ; i<bag[n].index2 ; i++ )
		printf("%d ",M[i]);*/
	return 0;
}
