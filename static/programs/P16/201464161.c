#include<stdio.h>
int main()
{
    int test,n;
    scanf("%d",&n);
    for(test=1;test<=n;test++)
    {
        int ans=0,num;
        scanf("%d",&num);
        for(;num>3;ans++)
        {
           num=num/2;
        }
        if(num==2)
            printf("%d\n",2*ans+1);
        else if(num==3)
            printf("%d\n",2*ans+2);
        else
            printf("0\n");
    }
    return 0;
}
