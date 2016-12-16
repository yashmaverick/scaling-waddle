#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int first = 0, last = 0;
int elem_added = 0;

void delete(char A[][105], int n, int size)
{
	while (n--)
    {    
    	first += 1;
    	first %= size;
    	elem_added -= 1;
    }
}

void insert(char A[][105], int n, int size)
{

	char string[105];
	while(n--) 
	{
		scanf("%s",string);
		if(elem_added == size) 
        {
        	delete(A, 1, size);
       	}
    	strcpy(A[last], string);
        last += 1;
        last %= size;
        elem_added += 1;
    }
}

void print(char A[][105], int size) 
{
    //printf("%d %d\n", first, last);
	int i;
    if(elem_added == 0)
    {
        return;
    }
	else if(first < last) 
    {
		for(i = first; i < last; i++)
		{
	    	printf("%s\n",A[i]);
		}
	}
	else 
    {
		for(i = first; i < size; i++)
		{
	    	printf("%s\n",A[i]);
		}
		for(i = 0; i < last; i++)
		{
	    	printf("%s\n", A[i]);
		}
	}
}

int main()
{
    int N, n, i;    
    scanf("%d", &N);
    char A[N + 1][105];
    char input;
    while(input != 'Q')
    {
        scanf("%c", &input);
        if (input == 'A')
        {
            scanf("%d", &n);
            insert(A, n, N);
             
        }
        else if (input == 'R')
        {
            scanf("%d", &n);
            delete(A, n, N);
        }
        else if (input == 'L')
        {
        	print(A, N);
        }
    }
    return 0;
}
