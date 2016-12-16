#include<stdio.h>

int main()
{
	char query;
	int max_size;
	scanf("%d",&max_size);
	char cir_q[max_size][100];
	int front,end,cur_size;
	front = end = cur_size = 0;
	int n,i;
	
	
	while(1)
	{
		scanf("%c",&query);
//		printf("%c\n",query);

		switch(query)
		{
			case 'Q':		

				return 0;
				break;
			
			case 'A':
	
				scanf("%d",&n);
				/* The number of string to be appended */
//				printf("%d\n",n);
				for( i = 0; i < n; i++ )
				{
					/* 'front==end' when buffer full or empty */
					if( front == end )
					{
						if( cur_size == max_size ) //buffer full
						{
							scanf("%s",cir_q[end]);  
							
							if( end == (max_size-1) )
								end = 0;
							else
								end++;
							
							if( front == (max_size-1) )
								front = 0;
							else
								front++;
						}
						else
						{	
							scanf("%s",cir_q[end]);  
							
							if( end == (max_size-1) )
								end = 0;
							else
								end++;
							
							cur_size++;
						}
					}
					else // Normal cases
					{	
						scanf("%s",cir_q[end]);
						
						if( end == (max_size-1) )
							end = 0;
						else
							end++;
						
						cur_size++;
					}

				}
				
			break;
			
			case 'R':
				
				scanf("%d",&n);
				/* Number of string to be removed */		
				
				for( i = 0; i < n; i++)
				{

					if( front == end)
					{
					
						if( cur_size == max_size )	//buffer full
						{
						
							if( front == (max_size-1))
								
								front = 0;
							else
								front++;

						cur_size--;
						
						}
						else	//buffer empty
						{
							/*Attehmpting to remove elements from 
							 * an empty buffer */	
							return 1;							
						}
						
					}
					else //Normal cases
					{
						if( front == (max_size-1))
							front = 0;
						else
							front++;

						cur_size--;
					}
				}
			
			break;
			
			case 'L':
				
				for( i = 0; i < cur_size; i++)
				{
					printf("%s",cir_q[(front+i)%max_size]);
					printf("\n");
				}	
			
			break;
			
			default:
				continue;
			break;
		}

		getchar();
	}					
	
	return 0;
}
