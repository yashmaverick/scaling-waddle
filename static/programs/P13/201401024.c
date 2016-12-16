#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,n,a[100003],h[100003],st[100003],top=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        st[top]=n-1;
        h[n-1]=0;
        for(i=n-2;i>=0;i--)
        {
//            printf("%d\n",i);
            if(a[st[top]]<a[i])
            {
                //printf("%d\n",top);
                top++;
                st[top]=i;
                h[i]=h[st[top-1]]+1;
            }
            else
            {
                while(top>-1 && a[st[top]]>a[i])
                    top--;
               // printf("%d\n",top);
                h[i]=h[st[top+1]]+1;
                top++;
                st[top]=i;
            }
        }
        int maxh=0;
        int ans=a[0];
        for(i=0;i<n;i++)
        {
            if(maxh<h[i])
            {
                maxh=h[i];
                ans=a[i];
            }
            else if(maxh==h[i])
            {
                if(a[i]<ans)
                    ans=a[i];
            }
        }
        printf("%d %d\n",ans,maxh);
    }
    return 0;
}
