#include<stdio.h>

int main()
{
  int arr[100001];
  int staq[100001];
  int t,n,k,a;
  int front,rear,front2,rear2;
  scanf("%d",&t);
  while(t>0)
    {
      front=rear=front2=rear2=0;
      scanf("%d%d",&n,&k);
      for(a=0;a<n;a++)
	{
	  scanf("%d",&arr[a]);
	}
      
      staq[rear2]=arr[rear];
      for(a=1;a<k;a++)
	{
	  while(front2>=rear2 && staq[front2]>arr[a])
	    {
	      front2--;
	    }
	  staq[++front2]=arr[a];
	}
      
      front=k-1;
      while(front<n)
	{
	  if(front==n-1)
	    printf("%d",staq[rear2]);
	  else
	    printf("%d ",staq[rear2]);

	  if(arr[rear]==staq[rear2])
	    rear2++;
	  rear++;
	  
	  front++;
	  while(front2>=rear2 && staq[front2]>arr[front])
	    {
	      front2--;
	    }
	  staq[++front2]=arr[front];
	  
	}
      printf("\n");
      t--;
    }
  return 0;
}
