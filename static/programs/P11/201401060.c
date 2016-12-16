#include<stdio.h>
typedef struct fence{
    int height;
    int width;
}fence;

int main()
{
    fence stack[100001];
    int start=-1,end=-1;
    int n;
    scanf("%d",&n);
    int i,j,k;
    int h;

    while(n!=0)
    {
        for(i=0;i<n;i++)
            stack[i].width=0;
        start=-1;
        end=-1;
        long long int maxarea=0;

        for(i=0;i<n;i++)
        {
            int w=0;
            if (start==-1 && end==-1)
            {
                scanf("%d",&stack[0].height);
                stack[0].width=1;
                start=end=0;
            }

            else
            {
                scanf("%d",&h);
                for (j=end;j>=0;j--)
                {
                    if (stack[j].height>h)
                    {
                        long long int temp=(long long int )stack[j].height*(long long int )stack[j].width;
                        if(maxarea<temp)
                            maxarea=temp;
                        end--;
                        w=stack[j].width;
                        if (end==-1)
                        {
                            stack[0].height=h;
                            end=0;
                            stack[0].width=1+w;
                        }
                        //w=stack[j].width;
                    }
                    else if(stack[j].height<h)
                    {
                        end++;
                        stack[end].height=h;
                        stack[end].width=1+w;
                        for(k=0;k<end;k++)
                            stack[k].width++;
                        break;
                    }
                    else
                    {
                        for(k=0;k<=end;k++)
                            stack[k].width++;
                        break;
                    }
                }
            }
        }
        
        while (end !=-1)
        {

         long long int temp=(long long int )stack[end].height*(long long int )stack[end].width;
         if (maxarea<temp)
             maxarea=temp;
            end--;
        }
        printf("%lld\n",maxarea);
        scanf("%d",&n);
    }
    return 0;
}
