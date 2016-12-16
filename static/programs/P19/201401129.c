#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tree
{
	int isleaf;
	struct tree *digit[10];
};
typedef struct tree tree;
typedef tree* link;

int flag , leafpassed;

link createnode ()
{
	int i;
	link new = malloc(sizeof(tree));
	for ( i = 0 ; i < 10 ; i ++ ) new -> digit[i] = NULL;
	new -> isleaf = 0;
	return new;
}

link insert ( link head , char number[] , int i , int n )
{
	link temp ;
	//temp = malloc(sizeof(tree));
	int x = number[i] - '0';
	if ( head -> digit[x] != NULL )
		if ( head -> digit[x]-> isleaf == 1 ) leafpassed = 1;
	if ( head -> digit[x] == NULL )
	{
		if ( leafpassed == 0 )	flag = 1;
		head -> digit[x] = createnode ();
	}
	if ( i  == n - 1 ) head -> digit[x] -> isleaf = 1;
	else
	{
		temp = insert( head -> digit[x] , number , i + 1 , n );
		head -> digit[x] = temp;
	}
	return head;
}

int main()
{
	int t , i , j , n , meet;
	char patterns[10];
	scanf("%d",&t);
	for ( i = 0 ; i < t ; i ++ )
	{
		scanf("%d",&n);
		meet = 1;
		link root;
		root = createnode();
		for ( j = 0 ; j < n ; j ++ )
		{
			scanf("%s",patterns);
			flag = 0;
			leafpassed = 0;
			int length = strlen(patterns);
			root = insert ( root , patterns , 0 , length );
			if ( flag == 0 ) meet = 0;
		}
		if ( meet == 1 ) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
