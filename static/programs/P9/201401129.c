#include<stdio.h>
#include<stdlib.h>

struct bag
{
	int wieght;
	int size;
	int *items;
};

typedef struct bag bag;

bag copybags ( bag b )
{	
	int i;
	bag a;
	a.wieght = b.wieght;
	a.size = b.size;
	//a.items=(int*)malloc(a.size*sizeof(int));
	a.items = b.items;
	return a ;
}

void justSimpleBubbleSort ( bag a[] , int n )
{
	int i , j , k;
	bag temp;
	temp.wieght = 0;
	temp.size = 0;
	for ( i = 0 ; i < n-1 ; i ++ )
		for ( j = 0 ; j < n-i-1 ; j ++ )
			if ( a[j].wieght > a[j+1].wieght )
			{
				temp = copybags ( a[j+1] );
				a[j+1] = copybags ( a[j] );
				a[j] = copybags ( temp );
			}
}

int main ()
{
	int n , m , mod , i , j , wieght , item;
	scanf("%d%d",&n,&mod);
	bag a[n];
	for ( i = 0 ; i < n ; i ++ )
	{
		scanf("%d",&m);
		wieght=0;
		a[i].items=(int*)malloc(m*sizeof(int));
		for ( j = 0 ; j < m ; j ++ )
		{
			scanf("%d",&item);
			a[i].items[j] = item;
			wieght = ((wieght)%mod+(item)%mod)%mod;
		}
//		wieght %= mod;
		a[i].wieght = wieght;
		a[i].size = m;
	}

	justSimpleBubbleSort ( a , n );

	for ( i = 0 ; i < n ; i ++ )
	{
		printf("%d\n",a[i].wieght);
		for ( j = 0 ; j < a[i].size ; j ++ )
			printf("%d\n",a[i].items[j]);
		printf("\n");
	}
	return 0;
}



