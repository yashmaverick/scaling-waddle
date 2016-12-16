//DS Assignment 2, P11
#include<stdio.h>
#define MAXLOGS 1000005
typedef struct log
{
    long long index;
    long long height;
    long long lowerLimit;
    long long upperLimit;
}log;
log fence[MAXLOGS], stack[MAXLOGS];
int main()
{
    long long nofLogs, i, top, maxArea;
    do
    {
        top = -1;
        maxArea = 0;
        scanf("%lld", &nofLogs);
        for(i = 0; i < nofLogs; i++) //initializing fence
        {
            fence[i].index = i;
            fence[i].lowerLimit = -1;
            fence[i].upperLimit = -1;
        }
        for(i = 0; i < nofLogs; i++) //input loop
        {
            scanf("%lld", &fence[i].height);
        }
        for(i = 0; i < nofLogs; i++) //getting upper limits
        {
            if(top == -1)
            {
                stack[++top] = fence[i];
            }
            else
            {
                while(fence[i].height < stack[top].height)
                {
                    fence[stack[top--].index].upperLimit = i;
                    if(top == -1)
                    {
                        break;
                    }
                }
                stack[++top] = fence[i];
            }
        }
        while(top != -1) //clearing stack of max upper limit logs
        {
            fence[stack[top--].index].upperLimit = nofLogs;
        }
        for(i = nofLogs-1; i >= 0; i--) //getting lower limits
        {
            if(top == -1)
            {
                stack[++top] = fence[i];
            }
            else
            {
                while(fence[i].height < stack[top].height)
                {
                    fence[stack[top--].index].lowerLimit = i;
                    if(top == -1)
                    {
                        break;
                    }
                }
                stack[++top] = fence[i];
            }
        }
        while(top != -1) //clearing stack of min lower limit logs
        {
            fence[stack[top--].index].lowerLimit = -1;
        }
/*        printf("fence:\n");
        printf("index    height   ll       ul      \n");
        printf("-------- -------- -------- --------\n");
        for(i = 0; i < nofLogs; i++)
        {
            printf("%d        %d        %d        %d       \n", fence[i].index, fence[i].height, fence[i].lowerLimit, fence[i].upperLimit);
        }*/
        for(i = 0; i < nofLogs; i++) //finding max area
        {
            if((fence[i].upperLimit-fence[i].lowerLimit-1)*fence[i].height > maxArea)
            {
                maxArea = (fence[i].upperLimit-fence[i].lowerLimit-1)*fence[i].height;
            }
        }
        if(nofLogs)
        {
            printf("%lld\n", maxArea);
        }
    }while(nofLogs);
    return 0;
}
