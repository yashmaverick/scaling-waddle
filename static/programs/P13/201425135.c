#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int array[100001],kk;

int sum(int x,int y)
{
	return x+y;
}

int subtract(int x,int y)
{
	return x-y;
}

int answer(int,int,int);

void enter()
{
	printf("\n");
}

void space()
{
	printf(" ");
}

int big,max1,bb[100001],cc[100001],maxcount;

int main()
{
	int test,cnt=0;
	scanf("%d",&test);
	while(33==33)
	{
		
		if(cnt==test)
			break;
		cnt++;
		maxcount=-1;
		max1=0;
		int n,viva,size,j;
		size=0;
		scanf("%d",&n);
		kk=0;
		for( viva = 0 ; viva < n ; viva = viva + 1)
		{
			scanf("%d", &array[viva]);
		}
		maxcount = sum( maxcount , 1 );
		bb[maxcount] = n - 1;
		for( viva = n - 2 ; viva >= 0 ; viva--)
		{
		
			if(array[bb[maxcount]] < array[viva])
			{
				maxcount = sum( maxcount , 1);
				bb[maxcount] = viva;
			}
			else if(array[bb[maxcount]] > array[viva])
			{
		
				for( j = maxcount ; j >= 0 ; j-- )
		
				{
					if(array[bb[j]] < array[viva])
						{
							break;
						}
					else if( array[bb[j]] > array[viva])
						{
						cc[bb[maxcount]] = viva;
							maxcount = subtract(maxcount,1);
						}
					
				}	
					maxcount = sum( maxcount , 1);
					bb[maxcount] = viva;					
				}
		}
		int i;
		for(viva = maxcount ; viva >= 0 ; viva--)
		{
			cc[bb[viva]] = -1;
		}
		for(i = 0 ; i < 100 ; i++ )
		{
			i++;
		}
		answer( 0 , n - 1 ,0);
		printf("%d", big);
		space();
		printf("%d", max1);
		enter();
		
	}
	return 0;
}
int answer( int top , int bottom , int size)
{
	int viva , j;
	size = sum( size , 1);
	j = cc[bottom];	
	if( top - j < 0)
	answer( top , j , size);
	if( j + 2 - bottom < 0)
	answer( j + 1 , bottom - 1 , size);
	if( top - j >= 0 ) 
	{
		if((j + 2 - bottom) >= 0)
		{if( size > max1)
		{
			max1 = size;
			big = array[top];
		}
		else if( size == max1 && big > array[top])	
			big = array[top];
	}	
	}
}
