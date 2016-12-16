
/*
   _____________________________________________

PURPOSE : 

created by -ABHINAV AGGARWAL
_____________________________________________ 

*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int na,i,max,min,max_profit;
    int input[100000];
    while(n--)
    {
        scanf("%d",&na);
        for(i=0;i<na;i++)
        {
            scanf("%d",&input[i]);
        }
        max_profit=0;
        min=input[0];
        for(i=1;i<na;i++)
        {
            max=input[i];
            if(max-min>max_profit)
                max_profit=max-min;
            if(input[i]<min)
                min=input[i];
        }
        printf("%d\n",max_profit);
    }


    return 0;
}
