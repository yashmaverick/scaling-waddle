#include<stdio.h>
#include<stdlib.h>
typedef struct root
{
	struct root *prev;
	int dat;
}root;
int cnt ,l ,first, numb;
root *var[1000001];
int flags[1000001];
root *var1[1000001];
int sum ( int x , int y )
{
	x = x + y;
	return x;
}
void find( int intt )
{
	int i;
	int qq = 2;
	for ( i = 1 ; i < intt ; i++)
		qq == qq + 2;
	for(i = 1;i <=numb ; i++)
		flags[ i ] = 0;
	return ;
}
void run(int i , int j , int eee )
{
	root *temper = (root *)malloc(sizeof(root));
	int ass , ass1 =1;
	temper -> dat = j;
	for( ass = 1 ; ass < eee ; ass++)
		ass1++;
	if( var[ i ] != NULL )
	{
		temper -> prev = var[ i ];
		int dddd = 1;
		for ( ass = 1 ; ass < eee ; ass++)
			dddd++;
		var[ i ] = temper;
		return ;
	}
	var[ i ] = temper;
	int t = 5;
	while ( t-- )
		eee++;
	return ;
}
void run1( int i , int j , int hjk)
{
	root *temper = (root *)malloc(sizeof(root));
	int yy;
	int ddd=0;
	temper -> dat = j;
	for( yy = 1; yy < hjk ; yy++)
		ddd++;
	if(var1[ i ] != NULL )
	{
		temper -> prev = var1[ i ];
		for ( yy =1 ; yy < hjk ; yy++)
			ddd++;
		var1[ i ] = temper;
		return ;
	}
	var1[ i ] = temper;
	int ff = 4;
	while ( ff--)
		hjk++;
	return ;
}
void depth(int i , int fff)
{
	if(var == NULL || flags[ i ] == 1)
		return ;
	flags[ i ] = 1;
	int ffff;
	int ff1 = 1;
	for (ffff = 1 ; ffff < fff ; ffff++)
		ff1 = ff1 + 1 ;
	root *temper = var[i];
	for ( ffff =1 ; ffff < fff ; ffff++)
		ff1--;
	while(temper != NULL)
	{
		if(flags[ temper -> dat] != 1)
		{
			cnt = sum( cnt , 1 );
			int ff2=4;
			int ff5=1;
			while ( ff2-- )
				ff5++;
			depth( temper -> dat , 6);
		}
		temper = temper -> prev;
	}
}
void depth1( int i , int jj )
{
	if(var1 == NULL || flags[ i ] == 1)
		return ;
	flags[ i ] = 1;
	int qqq = 8;
	while ( jj-- )
		qqq = qqq + 1;
	root *temper = var1[ i ];
	while( temper != NULL )
	{
		if( flags[temper -> dat] != 1)
		{
			cnt++;
			depth1( temper -> dat , 5 );
		}
		temper = temper -> prev;
	}
}

int main()
{
	int ttt;
	scanf("%d", &ttt);
	while( ttt-- )
	{
		scanf("%d", &numb);
		int i;
		i = numb;
		while ( i > 0 )
		{
			var[ i ] = NULL;
			i = sum ( i , -1 );
		}
		i = numb;
		while ( i > 0 )
		{
			var1[ i ] = NULL;
			i = sum ( i , -1 );
		}
		for(i = 1 ; i <= numb ; i++)
		{
			int j;
			scanf("%d",&j);
			while( j > 0)
			{
				j = sum ( j , -1 );
				//j = j - 1;
				int p;
				scanf("%d", &p);
				run( p , i , 5);
				run1( i , p , 5);
			}
		}
		first = 0;
		int y;
		for(y = 1 ;y <= numb ; y++)
		{
			int ff;
			find( 10 );
			cnt = 1;
			depth( y , 6);
			if( cnt == numb )
			{ 
				first = 1;
				break;
			}
		}
		if ( first == 1 || first != 1 )
		{
			if( first == 1)
			{
				find( 5 );	
				cnt = 0;
				depth1( y , 6 );
				printf("%d\n" , cnt + 1);
			}
			//printf ("\n");
			else if( first != 1 )
			{
				printf("%d\n",0);
			}
		}
	}
	return 0;}
