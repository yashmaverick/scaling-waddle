#include<stdio.h>
# define MAX 100001

int main()
{

    int Test,Stock_prices[MAX];
    scanf("%d",&Test);
    while(Test>0)
    {   
            int max = 0,i,Profit = 0,diff=0,N;

            scanf("%d",&N);

            for (i = 0; i < N; i++)
                scanf("%d",&Stock_prices[i]);

            int bottom = Stock_prices[0];

            for (i = 1; i < N; i++)
            {
                diff += Stock_prices[i] - Stock_prices[i - 1];

                if (diff > Profit)
                {
                    Profit = diff;
                    max = Stock_prices[i];
                }

                if (Stock_prices[i] < bottom)
                {
                    bottom = Stock_prices[i];
                    diff = 0;
                }
            }

            printf("%d\n",Profit);
            Test--;
    }        
    return 0;

}