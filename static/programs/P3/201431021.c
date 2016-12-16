#include<stdio.h>
int maxDiff(int a[], int b)
{
  int maxdiff = a[1] - a[0];
  int min = a[0];
  int o;
  for(o = 1; o < b; o++)
  {      
    if(a[o] - min > maxdiff)                              
      maxdiff = a[o] - min;
    if(a[o] < min)
         min = a[o];                    
  }
  return maxdiff;
}    
int main(int argc, char const *argv[])
{ 
	int i,count,j,b,min,maxdiff,a[1000000];
	scanf("%d",&count);
	/* code */for ( i = 0; i < count; ++i)
	{
		scanf("%d",&b);
		   for (j = 0; j< b; ++j)
		   {
				/* code */scanf("%d",&a[j]);
		   }
		   if(b<2)
		   {
		   	printf("0\n");
		   }
		   else{
		   		int ans=maxDiff(a,b);
		   
		   
		   if (ans>0)
		  	{
				/* code */printf("%d\n",ans);
			}
			else
			{
				printf("0\n");
			}
	}
	}
	return 0;
}