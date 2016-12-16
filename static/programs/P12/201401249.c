#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
typedef struct mountain
{
	ll height;
	ll position;
	struct mountain *pointer;
}mountain;
ll size;
void push(ll height,ll position);
void pop();
mountain *stackpointer=0;

void enter()
{
printf("\n");
return ; 
}


int main()
{
	ll n,i,state,answer,duplicate,counter,got;
	ll array[1000000];
	mountain *router;
	
		
	while(1)

	{	
scanf("%lld",&n);
if(n==0)
		break;
		state=0;
		ll c[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&array[i]);
		}
		answer=0;
		size=0;
		//printf("answer:%d\n",answer);
		while(state<n)
		{
			if(stackpointer==0 || array[state]<=stackpointer->height)
			{
				push(array[state],state);
				if(size>2)
				{
				router=stackpointer;
				counter=-1;
				while(router!=0 && router->height==stackpointer->height)
				{
					counter++;
					router=router->pointer;
				}
				got=size-2-counter;
				if(got>0)
				answer=answer+got;
				}
				state++;
			}
			else if(array[state]>stackpointer->height)
			{
				answer=answer+(n-state-1);
				pop();
			}
		}
		while(stackpointer!=0)
		{
		pop();
		}
		printf("%lld",answer);
		enter();		
	}
		return 0;
}
void push(ll height,ll position)
{
    if (stackpointer == 0)
    {
        stackpointer =(mountain *)malloc(1*sizeof(mountain));
        stackpointer->pointer = 0;
        stackpointer->height=height;
	stackpointer->position=position;
    }
    else
    {
        mountain *duplicate=(mountain *)malloc(1*sizeof(mountain));
	duplicate->height=height;
        duplicate->position=position;
	duplicate->pointer=stackpointer;
        stackpointer=duplicate;
    }
    size++;
return ;
}

void pop()
{
	if(stackpointer==0)
		return ;
	mountain *duplicate=stackpointer;
	stackpointer=stackpointer->pointer;
		size--;
	free(duplicate);
	return ;
}

