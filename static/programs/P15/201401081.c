#include<stdio.h>
#define LIMIT 10005
#define lli long long int

lli a[LIMIT];
lli queue[LIMIT];
lli front,rear;

void push(lli data)
{
  if(front==-1)
    rear++;
  queue[++front]=data;
}

void pop()
{
  if(front==rear)
    {
      front=-1;
      rear=-1;
    }
  else
    rear++;
}

int main()
{
  int t;
  scanf("%d",&t);
  lli n,k;
  while(t--)
    {
      scanf("%lld",&n);
      scanf("%lld",&k);
      lli i;
      front=-1;
      rear=-1;
      for(i=1;i<=n;i++)
	scanf("%lld",&a[i]);
      if(k==0)
	{
	  for(i=1;i<=n;i++)
	    printf("1000000001 ");
	  printf("\n");
	  continue;
	}
      for(i=k;i<=n;i++)
	{
	  if(front==-1)
	    {
	      lli temp;
	      temp=i;
	      for(i=temp-k+1;i<=temp;i++)
		{
		  if(front==-1||a[i]<=a[queue[front]])
		    push(i);
		}
	      i=temp;
	    }
	  else if(a[i]<=a[queue[front]])
	    push(i);
	  if(i!=n)
	    printf("%lld ",a[queue[front]]);
	  else
	    printf("%lld",a[queue[front]]);
	  while(rear!=-1&&queue[rear]<=i-k+1)
	    pop();
	}
      printf("\n");
    }
  return 0;
}
