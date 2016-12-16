#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int *pre=(int *)malloc(sizeof(int)*n);
    int *in=(int *)malloc(sizeof(int)*n);
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&pre[i]);
    for(i=0;i<n;i++)
        scanf("%d",&in[i]);
    int t;

    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==y)
        {
            int root=x;
            printf("%d\n",root);
            continue;
        }
        int root=pre[0];
        int flagr=0;
        int flagx=0,flagy=0;
        int j;
        int start=-1;
        int ppre=0;
        for(j=0;j<n;j++)
        {
            //if (x==y)
            //{
              //  root=x;
               // break;
           // }

            if(in[j]==root)
                flagr=1;
            else if(in[j]==x)
                flagx=1;
            else if(in[j]==y)
                flagy=1;
            if(x==root||y==root)
                break;

            if(flagr==1 && ((flagx==0 && flagy==1) || (flagx==1 && flagy==0)))
                break;
            else if(flagr==1 && flagx==1 && flagy==1)
            {
                flagr=0;
                flagx=0;
                flagy=0;
                ppre++;
                j=-1;
               
                root=pre[ppre];
                
                continue;
            }
            else if(flagr==1 && flagx==0 && flagy==0)
            {
                flagr=flagx=flagy=0;
                
                ppre+=(j-start);
                start=j;
                root=pre[ppre];
                continue;
            }
        }

        printf("%d\n",root);
    }
    return 0;
}




