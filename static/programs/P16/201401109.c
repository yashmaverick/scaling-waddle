#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,k,n,level,var,q;
    scanf("%d",&n);
  //  int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&q);
        j=1;
        var=1;
        level=0;
       while(var<q)
       {
           var=var+pow(2,j);
           j++;
           level=level+2;
//           printf("lev==%d\n",level);
       }
       if(var==q)
           printf("%d\n",level);
           else
           {
               if(var-(pow(2,j-1))/2<q)
                   printf("%d\n",level);
                else
                    printf("%d\n",level-1);
           }
    }
    return 0;
}



