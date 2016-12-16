#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
  int arr[10000];
  char word[100000];
  int n,t,a,b,c,sum,item,flag;
  int tempsum;
  scanf("%d",&t);
  while(t>0)
    {
      scanf("%d%d",&n,&item);
      sum=0;
      for(a=0;a<n;a++)
	{
	  scanf("%s%d",word,&arr[a]);
	}
      
      qsort(arr,n,sizeof(int),cmpfunc);
      flag=0;
      for(a=0;a<n-2;a++)
	{
	  c=n-1;
	  b=a+1;
	  while(b<n&&c>b)
	    {
	      tempsum=arr[a]+arr[b]+arr[c];
	      if(tempsum<item)
		b++;
	      else if(tempsum>item)
		c--;
	      else if(tempsum==item)
		{
		  flag=1;
		  break;
		}
	    }
	  if(flag==1)
	    break;
	}
      
	    
      /*for(a=0;a<n;a++)
	{
	  printf("%d",arr[a]);
	  }*/

      if(flag)
	printf("YES\n");
      else
	printf("NO\n");
      t--;
    }
  
  return 0;
}

      
	  
      
