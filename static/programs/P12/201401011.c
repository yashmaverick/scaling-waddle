#include<stdio.h>

int main()
{
	long long int n;
	scanf("%lld",&n);

	while( n != 0 )
	{
		long long int a[n], b[n], i, temp, circular, index_see_next;

		for( i = 0; i < n; i++)
		{
			scanf("%lld",&a[i]);
		}

		b[0] = -1;
		for( i = 0; i < n-1; i++)
		{
			if( a[i] >= a[i+1] )
				b[i+1] = i ;
			else
			{
				circular = b[i] ;
				if( circular == -1 )
				{	b[i+1] = -1;
					continue;
				}
				temp = a[circular] ;

				while( circular != -1 )
				{	

					if( temp >= a[i+1] )
					{
						b[i+1] = circular ;
						break;
					}
					else
					{
						circular = b[circular];
						if( circular == -1 )
						{
							b[i+1] = -1;
							break;
						}
						temp = a[circular];  
					}

				}
			}
		}

		/*	for( i = 0; i < n; i++ )
			{
			printf("%2d ",a[i]);	
			}
			printf("\n");
			for( i = 0; i < n; i++ )
			{
			printf("%2d ",b[i]);	
			}
			printf("\n");				*/

		long long int total, can_see_each_other = 0 ;
		total = ( n * ( n - 1 ) ) / 2 ;

		for( i = 1; i < n; i++ )
		{
			index_see_next = i-1 ;
			do
			{
				can_see_each_other++ ;
				temp = index_see_next;
				index_see_next = b[index_see_next];	
			
			}while( (a[i] >= a[temp]) && (index_see_next != -1) );
			
		}	

		printf("%lld\n",( total - can_see_each_other )) ;

		scanf("%lld",&n);
	}	
	return 0;
}
