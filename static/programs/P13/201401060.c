#include<stdio.h>
int main()
{
    int t,k;
    scanf("%d",&t);
    int i,n,j,element;
    int top=-1;
    int depth=0;
    int post[100005],stack[2][100005];
    
    for(i=0;i<t;i++)
    {
        
        depth=0;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&post[j]);
        }
        stack[0][0]=post[n-1];
        stack[1][0]=0;
        top=0;
        for(j=0;j<n;j++)
            stack[1][j]=0;
        element=post[n-1];
        int pop=0;
        for(j=n-2;j>=0;j--)
        {
            pop=0;
            if(top==-1)
            {
                top=0;
                stack[0][top]=post[j];
                stack[1][top]++;
            }
            else
            {
                while(stack[0][top]>post[j] && top>=0)
                {
                    if(depth<stack[1][top])
                    {
                        depth=stack[1][top];
                        element=stack[0][top];
                      //  top--;
                        //pop=1;
                    }
                    else if(depth==stack[1][top] && stack[0][top]<element)
                    {
                        element=stack[0][top];
                        //top--;
                        //pop=1;
                    }
                    top--;
                    pop=1;

                }
                    top++;
                    stack[0][top]=post[j];
                    if(pop==1)
                    {
                    stack[1][top]++;
                    pop=0;
                    }
                    else
                    {
                        stack[1][top]=stack[1][top-1]+1;
                        pop=0;
                    }
            }
        }


        while(top!=-1)
        {
            if(stack[1][top]>depth)
            {
               element=stack[0][top];
               depth=stack[1][top];
            }
            else if(stack[1][top]==depth && stack[0][top]<element)
                element=stack[0][top];
            top--;
        }

        printf("%d %d\n",element,depth);
    }
    return 0;
}
