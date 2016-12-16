#include<stdio.h>
int ans;
int main()
{
    int n;
    scanf("%d",&n);
    int pre[n],in[n];
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&pre[i]);
    for(i=0;i<n;i++)
        scanf("%d",&in[i]);
    int t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n1,n2;
        scanf("%d%d",&n1,&n2);
        if(n1==pre[0]||n2==in[0])
        {
            ans=pre[0];
        }
        else
        {
            int j;
            int indexn1,indexn2;
            for(j=0;j<n;j++)
            {
                if(n1==in[j])
                    indexn1=j;
                if(n2==in[j])
                    indexn2=j;
            }
            int k;
            int flag=0;
            for(j=0;j<n;j++)
            {
                if(flag!=1)
                {
                    if(indexn1<=indexn2)
                    {
                        for(k=indexn1;k<=indexn2;k++)
                        {
                            if(pre[j]==in[k])
                            {
                                flag=1;
                                ans=pre[j];
                                break;
                            }
                        }
                    }
                    else if(indexn1>indexn2)
                    {
                        for(k=indexn2;k<=indexn1;k++)
                        {
                            if(pre[j]==in[k])
                            {
                                flag=1;
                                ans=pre[j];
                                break;
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
