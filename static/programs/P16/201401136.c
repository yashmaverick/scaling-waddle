#include<stdio.h>
int expo(int a,int b)
{
    int ret=1;
    while(b>0)
    {
        if(b%2==1)
            ret=(ret*a);
        b=b/2;
        a=(a*a);
    }
    return ret;
}
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int q;
        scanf("%d",&q);
        int j;
        int temp;
        temp=q;
        if(q==1)
            printf("0\n");
        else
        {
            int flag=0;
            int div;
            j=1;
            while(flag!=1)
            {
                int quotient;
                div=expo(2,j);
                quotient=(int)(temp/div);
                if(quotient==1)
                {
                    flag=1;
                    int index;
                    index=j;
                }
                else j++;
            }
            if((q-div)<((div*2)-q))
                printf("%d\n",2*j-1);
            else
                printf("%d\n",2*j);
        }
    }
    return 0;
}
