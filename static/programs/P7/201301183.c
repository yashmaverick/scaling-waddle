#include<stdio.h>
#include<stdlib.h>
int compare(const void * a, const void * b)
{		
   return ( *(int*)a - *(int*)b );
}		   
int main()
{
	long long int t,n,i,j,k,ansr=0,tmp;
	scanf("%lld",&t);
	while(t--)
	{
		ansr=0;tmp=0;
		scanf("%lld",&n);
		long long int array[n];
		for(i=0;i<n;i++)
			scanf("%lld",&array[i]);
		qsort(array,n,sizeof(long long int),compare);
		for(i=0;i<n-1;i++)
		{
			if( array[i]==array[i+1])
				tmp++;
			else
			{
				ansr+=((tmp+1)*(tmp))/2;
				tmp=0;
			}
		}
		ansr+=(tmp+1)*tmp/2;
		printf("%lld\n",ansr);
	}
	return 0;
}
