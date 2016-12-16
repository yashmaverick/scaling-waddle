#include<stdio.h>
int main()
{
    int i,l,a,n,in[100000],pre[100000],hash2[100000],hash1[100000],q,x,y,k,ans,p1,p2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        hash1[i]=0;
        scanf("%d",&pre[i]);
    }
    hash1[n]=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&in[i]);
        hash2[in[i]]=i;
    }
    scanf("%d",&q);
    for(k=0;k<q;k++)
    {
       int  flag=0;
        scanf("%d %d",&x,&y);
        p1=hash2[x];
        p2=hash2[y];
        if(p1>p2)
        {
            for(l=p2;l<=p1;l++)
            {
                hash1[in[l]]=1;
            }
            for(a=0;a<n;a++)
            {
                if(hash1[pre[a]]==1)
                {
                    ans=a;
                    break;
                }
            }
        }
        else if(p2>p1)
        {
            for(l=p1;l<=p2;l++)
            {
                hash1[in[l]]=1;
            }
            for(a=0;a<n;a++)
            {
                if(hash1[pre[a]]==1)
                {
                    ans=a;
                    break;
                }
            }
        }
        else if(p1==p2)
        {
            printf("%d\n",x);
            flag=1;
        }
        if(flag==0)
        {
        printf("%d\n",pre[ans]);
        }
        for(a=0;a<=n;a++)
        {
            hash1[a]=0;
        }
    }
    return 0;
}



