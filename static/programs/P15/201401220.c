#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,i,j,a[10000],b[10000];
		scanf("%d %d",&n,&k);
		for( i = 1 ; i < n + 1 ; i++)
			scanf("%d",&a[i]);
		int minimum = a[1];
		for( i = 1 ; i <= ( n - k + 1 ) ; i++)
		{ 
			if( i == 1)
			{
				for( j = i ;j <= ( i + k -1 ) ; j++)
				{
					if( minimum > a[j])
					{
						minimum = a[j];
					}
				}

			}
			else if(i > 1)
			{
				if(a[i - 1] == minimum)
				{
					minimum = a[i];
					for( j = i ; j <= i + k - 1 ; j++)
					{
						if(minimum > a[j])
						{
							minimum = a[j];
						}
					}
				}
				else
				{
					if(a[ i + k - 1 ] < minimum)
						minimum = a[ i + k - 1];
				}

			}
		//	printf("sahith\n");
			if(i != n- k + 1 )
			printf("%d ",minimum);
			else
			printf("%d",minimum);
		}
		printf("\n");
	}
	return 0;
}
