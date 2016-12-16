#include<stdio.h>
#include<stdlib.h>
int ven[1000000], n , cnt , height , elem , stac[1000000] , place = 0 ;
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

void pu( int i )
{	
	stac[place] = i;
		place++;
}
void dfs( int i, int cnt)
{
	node* p;
	int aaaa,sss=1;
	p = a[i] ;

	for(aaaa=0;aaaa<10;aaaa++)
		sss++;
	ven[i] = 1;
	int ss;

	for(aaaa=0;aaaa<10;aaaa++)
		sss++;
	while( p != NULL )
	{
		ss = p -> values;
		
		for(aaaa=0;aaaa<10;aaaa++)
			sss++;
		if(!ven[ss])
			dfs(ss , cnt + 1 );
		p = p -> next;
	 }
	pu ( i );
}


int main()
{
		int aa;
		int i , j , p;
		scanf(" %d %d ", &n ,&aa );
		int k;
		
		for(k = 1; k <= n ; k++)
		{
			ven[k] = 0;
			a[k] = (node*)malloc(sizeof(node));
			a[k]-> values = k;
			a[k] -> next = NULL;
		}
		while(aa--)
		{
			scanf("%d %d", &i , &j);
			insert( i , j);
		}
		int ggg;
		for ( ggg=n ;ggg >=1;ggg--)
		{
			if ( ven[ggg]==0)
				dfs(ggg,7);
		}
		for ( ggg = place - 1 ;ggg >=1 ;ggg--)
		{
			printf("%d ",stac[ggg]);
		}
			printf("%d\n",stac[0]);

	return 0;

}
