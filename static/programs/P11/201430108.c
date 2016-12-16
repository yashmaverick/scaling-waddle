#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100001
void push (long long int i);
void pop();

struct stack{
	long long int num[MAXSIZE];
	long long int top;
};
typedef struct stack stack;
stack s;
int main()
{	
	long long int n,i;
	while(scanf("%lld",&n)!=0)
	{	
		s.top = -1;
		long long int *log;
	long long int maxarea=0;
	long long int artop=0;
	long long int top;
	long long int in;	
		if(n==0)
			return 0;
		log=(long long int *)malloc(n*sizeof(long long int));
		for(i=0;i<n;i++)
			scanf("%lld",&log[i]);	
		for(i=0;i<n;)
		{
			if(s.top==-1||log[s.num[s.top]]<=log[i])
				{
					push(i);
					i++;
				}
			else
			{
				top=s.num[s.top];
				pop();
				if(s.top!=-1)
					in=i-s.num[s.top]-1;
				else 
					in=i;
				artop=log[top]*in;//check
				if(maxarea<artop)
					maxarea=artop;
			}

		}
		while(s.top!=-1)
		{
			top=s.num[s.top];
			pop();
			if(s.top!=-1)
					in=i-s.num[s.top]-1;
				else 
					in=i;
			artop=log[top]*in;//check
				if(maxarea<artop)
					maxarea=artop;
		}
		printf("%lld\n",maxarea);
	}
	return 0;
}
void push (long long int i)
{
    
        s.top ++;
        s.num[s.top] = i;
    
    return;
}
void pop ()
{
    
        s.top = s.top - 1;
    return;
}
