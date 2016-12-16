#include<stdio.h>
typedef struct stack
{
  int elf;
  int depth;
}stack;
int main()
{
  int t,arr[100100],maxdepth,e,d,elem;
  stack zeref[100100];
  scanf("%d",&t);
  while(t!=0)
    {
      elem=-1;maxdepth=-1;
      int n,top=-1;
      scanf("%d",&n);
      int i;
      for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
      if(n>1)
     	{
	  for(i=n-1;i>=0;i--)
	    {
	      e=zeref[top].elf;
	      d=zeref[top].depth;
	      if(i==n-1)
		{d=-1;e=-1;}
	      if(arr[i]>e)
		{
		  top=top+1;
		  zeref[top].elf=arr[i];
		  zeref[top].depth=d+1;
		  if(zeref[top].depth>=maxdepth)
		    {
		      maxdepth=zeref[top].depth;
		      elem=zeref[top].elf;
		    }
		}
	      else
		{
		  while(top>=0&&arr[i]<zeref[top].elf)
		    {
		      top--;
		    }
		  top++;
		  zeref[top].elf=arr[i];
		  zeref[top].depth=zeref[top].depth+1;
		  if(zeref[top].depth>=maxdepth)
		    {
		      maxdepth=zeref[top].depth;
		      elem=zeref[top].elf;
		    }
		}
	    }
	  printf("%d %d\n",elem,maxdepth);
	}
      if(n==1)
	printf("%d 0\n",arr[0]);
      t--;
    }
  return 0;
}
   
		      
