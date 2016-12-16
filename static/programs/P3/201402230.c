#include<stdio.h>
#include<malloc.h>
int main()
{ int t;
  scanf("%d",&t);
  while(t--)
  { int n,max=0,maxf=0,i;
    long long int min=1000000002;
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    { scanf("%d",&a[i]);
       if(min>a[i])
        min=a[i];
      
        if(i>=1)
      { //for(j=0;j<i;j++)
         if(max<a[i]-min && a[i]-min>=0)
          max=a[i]-min;
        }
        
       if(maxf<max && max>=0)
        maxf=max;
     }
  printf("%d\n",maxf);
}
return 0;
}

      

