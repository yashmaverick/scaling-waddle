#include<stdio.h>

int main()
{
	long long int n;
	scanf("%lld",&n);

	while( n != 0 )
	{
		long long int height[n], stack[n];
		long long int i, SP=-1, left, right, area, max_area;
		
		max_area = 0;
		SP = -1;

		for( i = 0; i < n; i++ )
			scanf("%lld",&height[i]);

		for( i = 0; i < n; i++ )
		{
			if( SP == -1 || height[stack[SP]] <= height[i] )
			{
				SP++;
				stack[SP] = i;
			}
			else
			{
				while( (SP != -1) && (height[stack[SP]] > height[i]) )
				{
					left = ( (SP == 0) ? -1 : stack[SP-1] );
					right = i ;

					area = height[stack[SP]] * ( right - left - 1 ) ;
					max_area = (area > max_area) ? area : max_area ;
					
//					printf("popping : %lld , area: %lld \n", height[stack[SP]], area);

					SP-- ;
				}

				SP++;
				stack[SP] = i;
			}
		}

		while( SP != -1 )		
		{
			left = ( (SP == 0) ? -1 : stack[SP-1] );
			right = i ;

			area = height[stack[SP]] * ( right - left -1 ) ;
			max_area = (area > max_area) ? area : max_area ;

//			printf("popping : %lld , area: %lld \n", height[stack[SP]], area);
			SP-- ;
		}
		
		printf("%lld\n",max_area);
		scanf("%lld",&n);

	}

	return 0;
}
