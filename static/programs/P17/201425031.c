#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
    long long int nodes,pre[10000],in[10000],T,jon,white,i,j,k,p,q,f=0,ans,m,n;
    scanf("%lld",&nodes);
    for(i=0;i<nodes;i++)
        scanf("%lld",&pre[i]);
    for(i=0;i<nodes;i++)
        scanf("%lld",&in[i]);
    scanf("%lld",&T);
    while(T--)
    {
        f=0;
        scanf("%lld %lld",&jon,&white);
        for(i=0;i<nodes;i++)
        {
            if(in[i]==jon)
            {
                p=i;
                break;
            }
        }
        for(i=0;i<nodes;i++)
        {
            if(in[i]==white)
            {
                q=i;
                break;
            }
        }
        if(q==p)
            ans=in[p];
        else if(q==p-1 || p==q-1)
        {
            for(i=0;i<nodes;i++)
            {
                if(pre[i]==in[p])
                {
                    ans=in[p];
                    break;
                }
                if(pre[i]==in[q])
                {
                    ans=in[q];
                    break;
                }
            }
        }
//        else if(q==p-2 || p==q-2)
  //          ans=in[(p+q)/2];
        else
        {
            if(p<q)
            {
                n=0;

                //       printf("ghgh");
                for(j=0;j<nodes;j++)
                {
                   for(k=p;k<=q;k++)
                    {
                        if(pre[j]==in[k])
                        {
                            ans=pre[j];
                            n=1;
                            break;
                        }
                    }
                    if(n==1)
                        break;
                }
            }
            else if(q<p)
            {
                 m=0;
                for(j=0;j<nodes;j++)
                {
                    for(k=q;k<=p;k++)
                    {
                        //                 printf("%lld %lld\n",pre[j],in[k]);
                        if(pre[j]==in[k])
                        {
                            ans=pre[j];
                            m=1;
                            break;
                        }

                    }
                    if(m==1)
                        break;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
