#include<stdio.h>

typedef struct dabba
{
  int num;
  int height;
}node;

int max,minele;

int main()
{
  int n,a,t,top,max,min,temp,arr[100003];
  node stack[100003];
  scanf("%d",&t);
  while(t>0)
    {
      scanf("%d",&n);
      for(a=0;a<n;a++)
	{
	  scanf("%d",&arr[a]);
	}
      top=0;
      max=0;
      
      stack[0].num=arr[n-1];
      stack[0].height=0;
      min=stack[0].num;
      for(a=n-2;a>=0;a--)
	{
	  temp=stack[top].height;
	  
	  while(top>=0 && arr[a]<stack[top].num)
	    {
	      temp=stack[top].height;
	      top--;
	    }
	  
	  stack[++top].num=arr[a];
	  stack[top].height=temp+1;
	  if(stack[top].height>=max)
	    {
	      max=stack[top].height;
	      min=stack[top].num;
	    }
	}
      printf("%d %d\n",min,max);
      t--;
    }
  
  return 0;
}
	  
	  
