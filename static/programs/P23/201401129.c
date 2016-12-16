#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node *next;
};

typedef struct node node;
typedef node* link;

int a[100001] , rank[100001] , ans[100001] , SIZE = 0;
link list[100001];


void update ( int x )
{
	int temp;
	while ( a[x] < a[x/2] && x >= 1 )
	{
		temp  = a[x];
		a[x] = a[x/2];
		a[x/2] = temp;
		x = x/2;
	}
}

void del( int n )
{
	int y , x = 1 , flag = 0;
	while ( 2*x < n && flag ==  0 )
	{
		y = 2*x;
		if ( y != n && a[y+1] < a[y] )
			y ++;
		if ( a[n] > a[y] )
			a[x] = a[y];
		else flag = 1;
		if ( flag == 0 ) x = y;
	}
	a[x] = a[n];
}

int main ()
{
	int i , n , m , x , y ;
	scanf("%d %d",&n,&m);
	for ( i = 1 ; i <= n ; i ++ )
	{
		list[i] = NULL;
		rank[i] = 0;
	}
	for ( i = 0 ; i < m ; i ++ )
	{
		scanf("%d %d",&x,&y);
		link temp = malloc(sizeof(node));
		temp -> val = y;
		temp -> next = list[x];
		list[x] = temp;
		rank[y] ++;
	}
	int heapsize = 0 , count = n ;

	for ( i = 1 ; i <= n ; i ++ )
	{
		if ( rank[i] == 0 )
		{
			count --;
			heapsize ++;
			a[heapsize] = i;
			update(heapsize);
			rank[i] --;
		}
	}

	while ( count > 0 )
	{
		ans[SIZE++] = a[1];
		link move;
		move = list[a[1]];
		del ( heapsize );
		heapsize --;
		while ( move != NULL )
		{
			rank[move -> val] --;
			if ( rank[move -> val ] == 0 )
			{
				count --;
				heapsize ++;
				a[heapsize] = move -> val;
				update(heapsize);
				rank[i] --;
			}
			move = move -> next;
		}
	}
	while ( heapsize > 0 )
	{
		ans[SIZE++] = a[1];
		del ( heapsize );
		heapsize --;
	}
	for ( i = 0 ; i < SIZE ; i ++ ) 
	{
		if ( i != SIZE - 1 ) printf("%d ",ans[i]);
		else printf("%d\n",ans[i]);
	}
	return 0;
}
