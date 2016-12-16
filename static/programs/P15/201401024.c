#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,n,k,j;
        scanf("%d %d",&n,&k);
        int a[100004],b[100004];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        int top=0;
        int bottom=0;
        if(k==1)
        {
            for(i=0;i<n-1;i++)
                printf("%d ",a[i]);
            printf("%d\n",a[n-1]);
        }
        else
        {
            for(i=0;i<n;i++)
            {
                if(i==0)
                    b[top]=i;
                else if(a[i]>=a[b[top]] && (i-b[bottom])<k)
                {
                    top++;
                    b[top]=i;
                }
                else if(a[i]>=a[b[top]] && (i-b[bottom])>=k)
                {
                    bottom++;
                    top++;
                    b[top]=i;
                }
                else if(a[i]<a[b[top]] && (i-b[bottom])<k)
                {
                    while(top>bottom && a[i]<a[b[top]])
                        top--;
                    if(a[i]<a[b[top]])
                        b[top]=i;
                    else
                    {
                        top++;
                        b[top]=i;
                    }
                }
                else
                {
                    bottom++;
                    if(top<bottom)
                        top++;
                    while(top>bottom && a[i]<a[b[top]])
                        top--;
                    if(a[i]<a[b[top]])
                        b[top]=i;
                    else
                    {
                        top++;
                        b[top]=i;
                    }
                }
             //   for(j=bottom;j<=top;j++)
              //      printf("%d ",b[j]);
               // printf("\n");
                        if(i>=k-1 && i!=n-1)
                          printf("%d ",a[b[bottom]]);
                          else if(i==n-1)
                          printf("%d\n",a[b[bottom]]);
            }
        }
    }
    return 0;
}
