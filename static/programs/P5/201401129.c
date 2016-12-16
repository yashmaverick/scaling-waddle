#include<stdio.h>

void sort ( int a[] , int n )
{
	int i , j , temp;
	for ( i = 1 ; i < n ; i ++ )
		for ( j = i ; j > 0 ; j -- )
		{
			if ( a[j] > a[j-1] )
				break;
			else
			{
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
}
				

void felicity ( int a[] , int n , int total )
{
	int i , j , k;
	for ( i = 0 ; i< n ; i ++ )
	{
		j = i + 1;
		k = n - 1;
		while ( j < k )
		{
			if ( a[i] + a[j] + a[k] == total )
			{
				printf("YES\n");
				return ;
			}
			else if ( a[i] + a[j] + a[k] > total )
				k--;
			else if ( a[i] + a[j] + a[k] < total )
				j++;
		}
	}
	printf("NO\n");
}


int main ()
{
	int a[100000] , n , x , t , i , j , k;
	char useless[100000];
	scanf("%d",&t);
	for ( x = 0 ; x < t ; x ++ )
	{
		scanf("%d %d",&n,&k);
		for ( i = 0 ; i < n ; i ++ )
		{
			scanf("%s",useless);
			scanf("%d",&a[i]);
		}
		sort ( a , n );
		//for ( i = 0 ; i < n ; i ++ ) printf("%d ",a[i]);
		//printf("\n");
		felicity ( a , n , k);
	}
	return 0;
}
		
