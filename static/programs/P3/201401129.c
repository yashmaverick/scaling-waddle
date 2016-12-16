#include<stdio.h>

int main ()
{
	int t , n , i , j , buy , sell , profit , a[100000] ;
	scanf("%d",&t);
	for ( i = 0 ; i < t ; i ++ )
	{
		scanf("%d",&n);
		for ( j = 0 ; j < n ; j ++ )
			scanf("%d",&a[j]);
		buy = a[0];
		profit = 0;
		for ( j = 1 ; j < n ; j ++ )
		{
			if ( a[j] < buy )
			{
				buy = a[j];
				sell = a[j];
			}
			else if ( a[j] - buy >= profit )
			{
				sell = a[j];
				profit = sell - buy;
			}
		}
		printf("%d\n",profit);
	}
	return 0;
}
					


