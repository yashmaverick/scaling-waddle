#include<stdio.h>
int main()
{
  long long int n=5,top,i,x,t,area,s;
  while(n!=0)
    {
      top=-1;
      long long int arr[100100]={0},index[100100]={0};
      x=0;area=0;t=0;
      scanf("%lld",&n);
      if(n>0)
	{
	  for(i=0;i<=n;i++)
	    {
	      if(i<n)
		scanf("%lld",&x);
	      else
		x=0;
	      if(x>=arr[top]||top==-1)
		{arr[++top]=x;index[top]=i;}
	      else
		{
		  t=top;
		  while(arr[top]>x&&top>=0)
		    {
		      //   printf("arr[%lld]=%lld , i=%lld , index[%lld]=%lld\n",top,arr[top],i,top,index[top]);
		      if(area<((i-index[top])*arr[top]))
			area=((i-index[top])*arr[top]);
		      top--;
		    }
		  arr[++top]=x;
		  if(t==top-1)
		    index[top]=i;
		}
	      // printf("arr[%lld]=%lld\n",top,arr[top]);
	    }
	  printf("%lld\n",area);
	}
    }
  return 0;
}
