#include<stdio.h>

typedef struct dabba
{
  long long int num;
  long long int pos;
}node;

int main()
{
  long long int t,a,prepos,val,flag,top;
  int n;
  long long int maxarea,temp;
  node stack[100005];
  scanf("%d",&n);
  while(n!=0)
    {
      scanf("%lld",&val);
      stack[0].num=val;
      stack[0].pos=temp=flag=0;
      maxarea=val;
      top=0;
      stack[n].num=0;
      for(a=1;a<=n;a++)
	{
	  flag=0;
	  if(a!=n)
	    scanf("%lld",&val);
	  else
	    val=0;
	 
	  while(top>=0 && stack[top].num>val)
	    {
	      flag=1;
	      prepos=stack[top].pos;
	      temp=stack[top].num*(a-stack[top].pos);
	      top--;
	      //printf("%lld ",temp);
	      if(temp>maxarea)
		maxarea=temp;
	    }
	  top++;
	  stack[top].num=val;
	  if(flag==0)
	    stack[top].pos=a;
	  else
	    stack[top].pos=prepos;

	}
      printf("%lld\n",maxarea);
      scanf("%d",&n);
    }
  return 0;
}
