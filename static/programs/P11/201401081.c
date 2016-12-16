#include<stdio.h>

long long int n;
long long int h[1000005];

long long int stack[1000005];
long long int top;

long long int max;
long long int currmax;

void push(long long int data)
{
  top++;
  stack[top]=data;
}

void pop()
{
  top--;
}

void prints()
{
  long long int i;
  for(i=0;i<=top;i++)
    printf("%lld ",stack[i]);
  printf("\n");
}

int main()
{
  scanf("%lld",&n);
  while(n)
    {
      max=0;
      currmax=0;
      long long int i;
      long long int width,j;
      for(i=0;i<n;i++)
	scanf("%lld",&h[i]);
      top=-1;
      for(i=0;i<n;i++)
	if(top==-1||h[i]>=h[stack[top]])
	  push(i);
	else
	  {
	    j=stack[top];
	    pop();
	    if(top==-1)
	      width=i;
	    else
	      width=i-stack[top]-1;
	    currmax=h[j]*width;
	    if(currmax>max)
	      max=currmax;
	    i--;
	  }
      while(top+1)
	{
	  j=stack[top];
	  pop();
	  if(top==-1)
	    width=i;
	  else
	    width=i-stack[top]-1;
	  currmax=h[j]*width;
	  if(currmax>max)
	    max=currmax;	   	  
	}
      printf("%lld\n",max);
      scanf("%lld",&n);
    }
  return 0;
}
