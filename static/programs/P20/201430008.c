#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int v[ 1000001 ], n , c , h , e;
struct tree
{
	int data;
	struct tree* next;
};
struct tree*a[1000001];
void insert(int i,int j)
{
	struct tree * temp = (struct tree*)malloc(sizeof(struct tree));
	temp -> data = j;
	temp->next=NULL;	
	temp -> next = a[i] -> next;
	a[i] -> next = temp;

}
void dfs( int i, int c)
{
int flag=0;
	if(h<c)
	{
		flag=1;	
	}	
	if(flag==1)
	{
		h = c;
		e = a[i] -> data;
	}
	struct tree* p;
	p = a[i] ;
	v[i]=0;
	v[i] = v[i]+1;
	if(p != NULL)
		p = p -> next;
	int f;	
f=c+1;	
        while( p != NULL )
	{
		i = p -> data;
		if(!v[i])	
			dfs(i ,f );
		p = p -> next;
	}
	return;
}


int main()
{
	int t,w;
	scanf("%d", &t);
	while(t--)
	{
		h = 0;
		int i , j , p;
		scanf("%d", &n);
		int k=1;
		while( k <=n)
		{
			v[k] = 0;
			a[k] = (struct tree*)malloc(sizeof(struct tree));
			a[k]-> data = k;
			a[k] -> next = NULL;
			k++;		
		}


		for(k=0;k<=n-2;k++)	
		{
			scanf("%d %d",&i,&j);
			insert( i , j);
			insert( j , i);
		}
		e = 1;
	//	e=e*e;
		h=1;		
		c = 0;
		h = h-1;
	dfs( 1, c);
		k=1;
		while(k<=n)
		{
			v[k] = 0;
			k++;	
		}
		c = 1;
		c=c-1;
		h =5;
		int y;		
		for(y=0;y<5;y++)
		{
			h--;
		}
		dfs( e, c);
		printf("%d\n",h+1);
	}
	return 0;

}

