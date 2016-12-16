#include<stdio.h>
#include<stdlib.h>
typedef struct structure
{
	int count;
	char value;
	struct structure *prev[10];
}structure;
int sum (int x)
{
	x= x + 1;
	return x;
}
structure *put( structure *nodes , char str [] , int var )
{
        if(nodes == NULL)
	{
		int flag;
		nodes = (structure*)malloc(sizeof(structure));
		for(flag=0 ; flag < 10 ; flag++)
			nodes -> prev[ flag ] = NULL;
		nodes -> count = 0;
		
		nodes -> count = nodes -> count + 1;
		nodes -> value = str[var];
		if( str [ sum ( var )] != '\0')
			nodes -> prev [(int)str[sum( var) ]- '0' ] = put( nodes -> prev[(int)str [sum ( var )] - '0'], str , sum ( var ) );
		return nodes;
	}
	else if(nodes != NULL)
	{
		nodes -> count = nodes -> count + 1 ;
		if( str[ sum ( var )] != '\0')
			nodes -> prev[(int)str[sum ( var )]- '0' ] = put(nodes -> prev[ (int)str[sum ( var )] - '0'], str , sum ( var ));
		return nodes;
	}

}
int variable=0;

void rem( structure *nodes )
{
	if (nodes == NULL)
		return;
	int var;
	for(var = 0 ; var < 10 ; var = sum ( var ))
	{
		if( nodes -> prev[var] != NULL )
			rem( nodes -> prev[ var ] );
	}
	free( nodes );
}
void verif(structure *nodes)
{
	int var;
	int fla = 0;
	for(var = 0 ; var < 10 ; var++)
	{
		if(nodes -> prev[var] != NULL)
			fla = fla + nodes -> prev[ var ] -> count;
	}
	if((nodes -> count != 1))
	{
		if( nodes -> count != fla )
		variable = 1;
		for(var = 0 ; var < 10; var++)
		{
			if( nodes -> prev [ var ] != NULL)
				verif( nodes -> prev[var]);
		}
	}
	else{
		fla=sum(fla);
	}
}
void print(structure *nodes)
{
	int var;
	if(nodes != NULL)
	{
//		printf("%c %d\num",nodes->value,nodes->count);
		for( var = 0; var < 10; var++)
		{
				if(nodes -> prev[var] != NULL)
					print( nodes -> prev [ var ] );
		}
	}
}
int main()
{
	char str[15];
	structure *array[10];
	int test;
	scanf(" %d",&test);
	while(test--)
	{
		int var,var1;
		var1 = 10;
		var = 0;
		while(var1--)
		{		
			array[ var ] = NULL;
			var = sum ( var );
		}
		int num;
		scanf("%d ",&num);
		variable = 0;
		while(num > 0)
		{
			scanf("%s",str);
			array[ (int)str[ 0 ] - '0' ] = put ( array [(int)str[ 0 ] - '0' ], str , 0 );
			num--;
		}
		for(var = 0; var < 10; var = sum ( var ))
		{
			if( array[var] != NULL )
			{
				verif( array[ var ] );
				rem( array[ var ] );
			}
		}
		if(variable == 1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
