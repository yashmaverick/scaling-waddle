#include<stdio.h>
#include<stdlib.h>
int ven[1000000], n , cnt , height , elem;
typedef struct node
{
	int values;
	struct node* next;
}node;
node*a[1000000];
void insert(int i,int j)
{
	node* temp = (node*)malloc(sizeof(node));
	temp -> values = j;
	temp -> next = NULL;
	temp -> next = a[i] -> next;
	a[i] -> next = temp;

}
void dfs( int i, int cnt)
{
	if( cnt > height )
	{
		height = cnt;
		elem = a[i] -> values;
	}
	node* p;
	p = a[i] ;
	ven[i] = 1;
	if(p != NULL)
		p = p -> next;
	while( p != NULL )
	{
		i = p -> values;
		if(!ven[i])
			dfs(i , cnt + 1 );
		p = p -> next;
	 }
	return;
}


int main()
{
	int t;
	scanf(" %d", &t);
	while( t-- )
	{
		height = 0;
		int i , j , p;
		scanf(" %d ", &n);
		int k;
		for(k = 1; k <= n ; k++)
		{
			ven[k] = 0;
			a[k] = (node*)malloc(sizeof(node));
			a[k]-> values = k;
			a[k] -> next = NULL;
		}
		k = n-1;
		while(k--)
		{
			scanf("%d %d", &i , &j);
			insert( i , j);
			insert( j , i);
		}
		elem = 1;
		cnt = 0;
		height = 0;
		dfs( 1, cnt);
		for(k = 1;k <= n; k++)
		{
			ven[k] = 0;
		}
		cnt = 0;
		height = 0;
		dfs( elem , cnt);
		printf("%d\n", height + 1);
	}
	return 0;

}

