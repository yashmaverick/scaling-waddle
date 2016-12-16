#include<stdio.h>
#include <math.h>
int main()
{
    int i,j,k,flag;
    scanf("%d",&j);
    for (i=0; i<j; i++)
    {
        
        scanf("%d",&k);
        int h;
        if(k==1)
        {
            printf("0\n");
        }
        else
        {
            h=log2(k);
            if (k >= pow(2,h) && k<((pow(2, h)+pow(2, h+1))/2)) {
            flag=1;
            }
            else
            {
                flag=0;
            }
            if(flag==0)
                printf("%d\n",2*h);
            else if(flag==1)
                printf("%d\n",2*h-1);
        }
    }
    return 0;
}