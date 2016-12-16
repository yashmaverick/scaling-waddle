#include<stdio.h>
int main()
{
    int t,i,j,max,a,b,m,n,max1,min,c,diff;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        diff=0;
   min=1000000001;
   max=0;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {scanf("%d",&c);
                if(c<min)
                {
                    min=c;
                }
                if((c-min)>diff)
                    diff=c-min;
        }
 printf("%d\n",diff);
                }
    return 0;
    }



                



