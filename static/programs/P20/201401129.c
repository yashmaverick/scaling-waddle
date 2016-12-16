#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node *next;
};

typedef struct node node;
typedef node* link;

int deep , max , visit[1000000];
link list[1000000];

void depth ( int x , int count )
{
	visit[x] = 1;
	if ( count > max ) deep = x;
	if ( list[x] == NULL ) return;
	link temp = malloc(sizeof(node));
	temp = list[x];
	//printf("DFS AT : %d\n",x);
	while ( temp != NULL )
	{
		//printf("NODE : %d\n",temp -> val);
		if ( visit[temp -> val] == 0 )
		{
			//printf("NODE : %d\n",temp -> val);
			depth ( temp -> val , count + 1);
		}
		if ( count > max ) max = count;
		temp = temp -> next;
	}
	//printf("ENDING NODE %d WITH %d\n",x,max);
	return ;
}

int main ()
{
	link temp;
	int t , n , i , j , x , y;
	//printf("TEST CASES : ");
	scanf("%d",&t);
	for ( i = 0 ; i < t ; i ++ )
	{
		//printf("NODES : ");
		scanf("%d",&n);
		for ( j = 0 ; j <= n ; j ++ )
		{
			list[j] = NULL;	
			visit[j] = 0;
		}
		for ( j = 0 ; j < n - 1 ; j ++ )
		{
			scanf("%d %d",&x,&y);
			
			link tempx = malloc(sizeof(node));
			link tempy = malloc(sizeof(node));

			tempx -> val = x;
			tempx -> next = list[y];
			list[y] = tempx;

			tempy -> val = y;
			tempy -> next = list[x];
			list[x] = tempy;

		}
		max = 0;
		depth( 1 , 0 );
		//printf("%d %d\n",max,deep);

		for ( j = 1 ; j <= n ; j ++ )
			visit[j] = 0;
		max = 0;
		depth( deep , 0 );
		printf("%d\n",max+1);
	}
	return 0;
}




