#include<stdio.h>
int main()
{
    int n,i,j,t;
    int a[100000];
    int b[100000];
    int node1;
    int node2;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
    }
    scanf("%d",&t);
    int x,y;
    while(t--)
    {
        scanf("%d%d",&x,&y);
        if(x==y)
            printf("%d\n",x);
        else

        {
            for(i=1;i<=n;i++)
        {
            if(b[i]==x)
                node1=i;
            else if(b[i]==y)
                node2=i;
        }
        int fl=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
               if(a[i]==b[j])
               {
                   if((j>=node1 && j<=node2) || (j<=node1 && j>=node2))
                   {
                       fl=1;
                       break;
                   }
               }
            }
            if(fl==1)
                break;
        }
        printf("%d\n",b[j]);
        }
    }
    return 0;

}
