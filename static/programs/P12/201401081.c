#include<stdio.h>
#define LIMIT 500005

long long int n;
long long int m[LIMIT];

typedef struct node
{
  long long int data;
  long long int count;
}st;

st stack[LIMIT];
long long int top;
long long int count;

void push(long long int data)
{
  top++;
  stack[top].data=data;
  stack[top].count=1;	  
}

void flush()
{
  if(top==-1)
    return;
  long long int c;
  count+=top;
  while(top>=0)
    {
      c=stack[top].count;
      count+=(c*(c-1))/2;
      if(top!=0)
	count+=c-1;
      top--;
    }
}

void calc(long long int h)
{
  if(top==-1)
    return;
  long long int c,distinct,total;
  long long int temp;
  temp=0;
  total=0;
  distinct=0;
  while(top>=0&&h>stack[top].data)
    {
      c=stack[top].count;
      total+=c;
      count+=(c*(c-1))/2;
      distinct++;
      if(top!=0)
	count+=c-1;
      top--;
      //printf("count=%lld\n",count);
    }
  //printf("%lld:%lld\n",distinct,total);
  if(top!=-1)
    count+=distinct;
  else
    count+=distinct-1;
  /* For in bet */
  count+=total;
  /* For rhs */

  if(h==stack[top].data)
    stack[top].count++;
  else
    push(h);
  //  printf("%lld\n",count);
}

void dump_stack()
{
  long long int i;
  for(i=0;i<=top;i++)
    printf("%lld:%lld  ",stack[i].data,stack[i].count);
  printf("\n");
  printf("%lld\n",count);
}

int main()
{
  scanf("%lld",&n);
  while(n!=0)
    {
      long int i;
      for(i=0;i<n;i++)
	scanf("%lld",&m[i]);
      top=-1;
      count=0;
      for(i=0;i<n;i++)
	{
	  /* printf("m[i]=%lld\nBEFORE: ",m[i]); */
	  /* dump_stack(); */
	  if(top==-1||m[i]<stack[top].data)
	    {
	      push(m[i]);
	    }
	  else if(m[i]==stack[top].data)
	    {
	      stack[top].count++;
	    }
	  else if(m[i]>stack[top].data)
	    {
	      calc(m[i]);
	    }
	  /* printf("AFTER: "); */
	  /* dump_stack(); */
	}
      flush();
      //printf("%lld\n",count);
      n=n*(n-1);
      n/=2;
      count=n-count;
      printf("%lld\n",count);
      scanf("%lld",&n);
    }
  return 0;
}
