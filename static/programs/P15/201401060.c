#include<stdio.h>
int main()
{
    int t;
    int l,i,j,m;
    int array[10001],stack[2][10001];
    scanf("%d",&t);
    int front=-1,rear=-1;
    for(l=0;l<t;l++)
    {
        front=-1;
        rear=-1;
        int n,k;
        scanf("%d%d",&n,&k);
        for(j=0;j<n;j++)
            scanf("%d",&array[j]);
        for(j=0;j<=k-1;j++)
        {
            if(front==-1)
            {
                front=rear=0;
                stack[0][rear]=array[j];
                stack[1][rear]=j;
                continue;
            }
            while(stack[0][rear]>=array[j] && rear>-1)
                rear--;
            rear++;
            stack[0][rear]=array[j];
            stack[1][rear]=j;
        }

        if(k==n)
        printf("%d\n",stack[0][0]);
        else
            printf("%d ",stack[0][0]);
        if(k!=n)
        {

            for(j=k,m=1;j<n-1;j++,m++)
            {
                while(stack[0][rear]>=array[j] && rear>=front)
                    rear--;
                rear++;
                stack[0][rear]=array[j];
                stack[1][rear]=j;

                if(stack[1][front]<m || stack[1][front]>j)
                    front++;
                printf("%d ",stack[0][front]);
            }

            while(stack[0][rear]>=array[j] && rear>=front)
                rear--;
//            printf("hi\n");

            rear++;
            stack[0][rear]=array[j];
            stack[1][rear]=j;
            if(stack[1][front]<m || stack[1][front]>j)
                front++;
            printf("%d\n",stack[0][front]);

        }
    }
    return 0;
}
