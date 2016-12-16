#include<stdio.h>

int bst[100000];
int max_depth, min_node;

void tree(int left, int right,int depth);

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int n, i;
		scanf("%d",&n);

		for( i = 0; i < n; i++)
		{
			scanf("%d",&bst[i]);
		}
		
		max_depth = 0 ;
		min_node = 2147483647 ;	
	
		tree(0, n-1, 0);

		printf("%d %d\n",min_node, max_depth); 
			
	}

	return 0;
}

void tree(int left, int right, int depth)
{

	if( left > right )
	{
		return ;
	}
	else if( left == right )
	{
		if ( depth > max_depth )
		{
			max_depth = depth ;
			min_node = bst[right] ;
		}
		else if( (depth == max_depth) && (bst[right] < min_node) )
			min_node = bst[right] ;
				
		return ;
	}
	else
	{
		int i, start, end, mid;
		
		start = left;
		end = right - 1;
		
		while( end - start > 1 )
		{
			mid = ( start + end ) / 2 ;
			if( bst[mid] > bst[right] )
			{
				end = mid - 1;
			}
			else
			{
				start = mid;
			}
		}
		
		if ( bst[start] > bst[right] )
		{	
			i = start - 1;
		}
		else if( bst[end] <= bst[right] )
		{
			i = end ;
		}
		else
		{
			i = start ;
		}	

		tree(i+1, right-1, depth+1 );			//right
		tree(left, i, depth+1 );				//left		

		if ( depth > max_depth )
			max_depth = depth ;
		else if( (depth == max_depth) && (bst[right] < min_node) )
			min_node = bst[right] ;
	
		return ;
	}
}
