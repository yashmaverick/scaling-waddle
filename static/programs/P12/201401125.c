#include<stdio.h>
int main()
{
    int height[500010],n,i,j,k,count;
    while(1)
    {
        count=0;
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&height[i]);
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                for(k=i+1;k<j;k++)
                {
                    if(height[k]>height[i]||height[k]>height[j])
                    {
                        count++;
                        break;
                    }
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
