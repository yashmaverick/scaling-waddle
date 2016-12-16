#include<stdio.h>


int checker ( int pos , int in[] , int x , int y )
{
	int i , found = 0;
	for ( i = 0 ; i <= pos ; i ++ )
	{
		if ( in[i] == x ) found ++;
		if ( in[i] == y ) found ++;
		if ( found == 2 ) break;
	}
	return found;
}

int youKnowNothing ( int n , int in[] , int pre[] , int x , int y )
{
	int i , j , found , node;
	for ( i = 0 ; i < n ; i ++ )
	{
		if ( pre[i] == x )
		{
			found = 1;
			node = x;
			break;
		}
		if ( pre[i] == y )
		{
			found = 1;
			node = y;
			break;
		}

		for ( j = 0 ; j < n ; j ++ )
		{
			if ( pre[i] == in[j] )
			{
			//	printf("NODE %d FOUND AT %d\n",pre[i],j);
				found = checker ( j , in , x , y );
				if ( found == 1 ) node = pre[i];
				break;
			}
		}
		if ( found == 1 ) break;
	}
	return node;
}

int main ()
{
	int n , t , i , x , y , z , in[1000000] , pre[1000000];
	scanf("%d",&n);
	for ( i = 0 ; i < n ; i ++ )
		scanf("%d",&pre[i]);
	for ( i = 0 ; i < n ; i ++ )
	        scanf("%d",&in[i]);
	scanf("%d",&t);
	for ( i = 0 ; i < t ; i ++ )
	{
		scanf("%d %d",&x,&y);
		z = youKnowNothing ( n , in , pre , x , y );
		printf("%d\n",z);
	}
	return 0;
}


