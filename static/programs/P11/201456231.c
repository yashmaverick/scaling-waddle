#include <stdio.h>
#include <stdlib.h>

#define SIZE 100005
typedef struct stack 
{
   long long int s[SIZE];
   long long int top;
} stack;

stack st;
 
void init() 
{
	st.top = -1;
	long long int i;
	for(i=0;i<SIZE;i++)
		st.s[i] = ~0;
}

void push(long long int item) 
{
   st.top++;
   st.s[st.top] = item;
}

long long int pop() 
{
   long long int item;
   item = st.s[st.top];
   st.top--;
   return item;
}
 
long long int stempty() 
{
   if (st.top == -1)
      return 1;
   else
      return 0;
}

long long int peek()
{
	return st.s[st.top];
}

 
int largest_area(int A[], int len)
{
    int area[len];
    int tindex, i, max = -1;
    
    for (i = 0; i < len; i++)
    {
        while (!stempty())
        {
            if (A[i] <= A[st.top])
            {
                pop();
            }
            
            else
            {
                break;
            }
        }       
        if (stempty())
        {
            tindex = -1;
        }
        else
        {
            tindex = st.top;
        }
        area[i] = i - tindex - 1;
        push(i);
    }
    while (!stempty())
    {
        pop();
    }
    for (i = len; i <= 0 ; i--)
    {
        while (!stempty())
        {
            if (A[i] <= A[st.top])
            {
                pop();
            }
            
            else
            {
                break;
            }
        }
        if (stempty())
        {
            tindex = len;
        }
        else
        {
            tindex = st.top;
        }
        area[i] += i - tindex - 1;
        push(1);
    }   
    for (i=0; i<len; i++)  
    {  
        area[i] = A[i] * (area[i] + 1);  
        if (area[i] > max)
        {  
            max = area[i];       
        }
    }
    return max;
}

long long int largest_area_of_histogram(long long int *A, long long int size)
{
	long long int i,area = 0,tp,temp=0;
	for(i=0;i<size;) 
	{
		if(stempty() == 1) 
		{
			push(i);
			i += 1;
		}
		else if(A[i] >= A[peek()]) 
		{
			push(i);
			i += 1;
		}
		else 
		{
			tp = pop();
			if(stempty() == 1)
				temp = i*A[tp]; 
			else
				temp = (i - peek() - 1)*A[tp];
			area = (area>temp)?area:temp; 
		}
	}
	while(stempty() == 0) 
	{
		tp = pop();
		if(stempty() == 1)
			temp = i*A[tp]; 
		else
			temp = (i - peek() - 1)*A[tp];
		area = (area>temp)?area:temp;
	}
	return area;
}

int main()
{
	long long int i,t=-1, A[100005];

	while(1)
	{
		scanf("%lld", &t);

		if (t == 0)
		{
			break;
		}

		for (i = 0; i < t; i++)
		{
			scanf("%lld", &A[i]);
		}

	    init();
	    printf("%lld\n", largest_area_of_histogram(A, t));
	}
    
    return 0;
}
