#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node *next;
};

typedef struct node node;
typedef node* link;

int count , visit[1001] , warrior;
link list[1001] , list2[1001];

void youHave ( int x , int n )
{
	//printf("AT NODE : %d\n",x);
	visit[x] = 1;
	//printf("COUNT = %d\n",count);
	//count ++;
	//printf("COUNT = %d\n",count);
	if ( list2[x] == NULL )
	{
		//if ( n != count )
		//{
		//	count --;
		//	visit[x] = 0;
		//}
		//printf("COUNT = %d\n",count);
		//printf("EXITING NODE : %d\n",x);
		return;
	}
	link temp = malloc(sizeof(node));
	temp = list2[x];
	while ( temp != NULL )
	{
		if ( visit[temp -> val] == 0 )
		{
			//printf("VISITING NODE : %d\n",temp -> val);
			youHave ( temp -> val , n );
		}
		temp = temp -> next;
	}
	//count --;
	//visit[x] = 0;
	//printf("COUNT = %d\n",count);
	//printf("EXITING NODE : %d\n",x);
	return ;
}


void noPowerHere ( int x , int n )
{
	//printf("AT NODE : %d\n",x);
	visit[x] = 1;
	count ++;
	//printf("COUNT = %d\n",count);
	if ( list[x] == NULL || n == count ) 
	{
		//printf("EXITING NODE : %d\n",x);
		//printf("COUNT = %d\n\n",count);
		return;
	}
	link temp = malloc(sizeof(node));
	temp = list[x];
	while ( temp != NULL )
	{
		if ( visit[temp -> val] == 0 ) 
		{
			//printf("VISITING NODE : %d\n",temp -> val);
			noPowerHere ( temp -> val , n );
		}
		temp = temp -> next;
	}
	//printf("EXITING NODE : %d\n",x);
	//printf("COUNT = %d\n\n",count);
	return ;
}

int main ()
{
	link temp1 , temp2;
	int t , n , i , j , x , k , m , win; 
	scanf("%d",&t);
	for ( i = 0 ; i < t ; i ++ )
	{
		scanf("%d",&n);
		for ( j = 1 ; j <= 1000 ; j ++ )
		{
			list[j] = NULL;	
			visit[j] = 0;
			list2[j] = NULL;
		}
		for ( j = 1 ; j <= n ; j ++ )
		{
			scanf("%d",&m);
			for ( k = 0 ; k < m ; k ++ )
			{
				scanf("%d",&x);
				temp1 = malloc(sizeof(node));

				temp1 -> val = j;
				temp1 -> next = list[x];
				list[x] = temp1;

				temp2 = malloc(sizeof(node));

				temp2 -> val = x;
				temp2 -> next = list2[j];
				list2[j] = temp2;

			}
		}
		warrior = 0;
		for ( j = 1 ; j <= n ; j ++ )
		{
			for ( k = 0 ; k < n ; k ++ ) visit[k] = 0;
			count = 0;
			noPowerHere ( j , n );
			if ( n == count ) break;
		}
		warrior = j;
		//printf("%d\n",j);
		for ( j = 1 ; j <= 1000 ; j ++ )
			visit[j] = 0;
		youHave ( warrior , n );
		count = 0;
		for ( j = 1 ; j <= n ; j ++ )
			if ( visit[j] == 1 ) count ++;
		printf("%d\n",count);
	}
	return 0;
}




