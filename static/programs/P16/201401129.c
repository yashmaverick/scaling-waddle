#include<stdio.h>
#include<math.h>

int main () 
{
	int n , i , val , width , add , max;
	scanf("%d",&n);
	for ( i = 0 ; i < n ; i ++ )
	{
		scanf("%d",&val);
		width = 1;
		max = 1;
		add = 1;
		if ( val == 1 ) width = 0;
		else
		
			while ( 1 )
			{
			        max += add;
				if ( val <= max ) break;
				max += add;
				width ++;
				if ( val <= max ) break;
				width ++;
				add *= 2;
			}
			printf("%d\n",width);
	}
	return 0;
}

	
