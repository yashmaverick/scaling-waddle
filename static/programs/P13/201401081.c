#include<stdio.h>
#define LIMIT 100005

long long int post[LIMIT];

typedef struct st
{
  long long int data;
  long long int depth;
}list;

list stack[LIMIT];
long long int top;
long long int maxdepth;
long long int val;

void push(long long int data)
{
  top++;
  stack[top].data=data;
}

void pop()
{
  top--;
}

void dump_stack()
{
  /* long long int i; */
  /* for(i=0;i<=top;i++) */
  /*   printf("%lld:%lld ",stack[i].data,stack[i].depth); */
  /* printf("\n"); */
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      long long int n,i;
      long long int temp;
      scanf("%lld",&n);
      for(i=0;i<n;i++)
	scanf("%lld",&post[i]);
      maxdepth=0;
      top=0;
      val=post[n-1];
      stack[top].data=post[n-1];
      stack[top].depth=0;
      for(i=n-2;i>=0;i--)
	{
	  //printf("BEG: ");
	  dump_stack();
	  if(top==-1)
	    {
	      push(post[i]);
	      stack[top].depth=0;
	    }
	  else if(post[i]>stack[top].data)
	    {
	      push(post[i]);
	      stack[top].depth=stack[top-1].depth+1;
	      if(stack[top].depth>maxdepth)
		{
		  maxdepth=stack[top].depth;
		  val=post[i];
		}
	      else if(stack[top].depth==maxdepth)
		if(val>stack[top].data)
		  val=stack[top].data;
	    }
	  else if(post[i]<stack[top].data)
	    {
	      while(top!=-1&&post[i]<stack[top].data)
		{
		  temp=stack[top].depth;
		  pop();
		}
	      push(post[i]);
	      stack[top].depth=temp+1;
	      if(stack[top].depth>maxdepth)
		{
		  maxdepth=stack[top].depth;
		  val=post[i];
		}
	      else if(stack[top].depth==maxdepth)
		if(val>stack[top].data)
		  val=stack[top].data;
	    }
	  //printf("END: ");
	  dump_stack();
	}
      printf("%lld %lld\n",val,maxdepth);
    }
  return 0;
}
