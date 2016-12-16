#include<stdio.h>
int arr[100010],a[100010],b[100010];
int depth;
int maxdepth;
int topa,topb;
int min;
void pusha(int num)
{
    topa++;
    a[topa]=num;
}
void pushb(int num)
{
    topb++;
    b[topb]=num;
}
void popa()
{
    if(topa>=0)
        topa--;
}
void popb()
{
    if(topb>=0)
        topb--;
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int j,n;
        topa=-1;
        topb=-1;
        depth=0;
        maxdepth=0;
        scanf("%d",&n);
        for(j=n-1;j>=0;j--)
            scanf("%d",&arr[j]);
        for(j=0;j<n;j++)
        {
            if(j==0)
            {
                pusha(arr[j]);
                min=arr[j];
                maxdepth=0;
                pushb(depth);
            }
            else
            {
                if(arr[j]>a[topa])
                {
                    depth=b[topb];
                    pusha(arr[j]);
                    depth++;
                    pushb(depth);
                }
                else
                {
                    if(arr[j]<a[topa])
                    {
                        while(arr[j]<a[topa]&&topa!=-1)
                        {
                            if(b[topb]>maxdepth)
                            {
                                maxdepth=b[topb];
                                min=a[topa];
                            }
                            if(b[topb]==maxdepth)
                            {
                                if(a[topa]<min)
                                    min=a[topa];
                            }
                            depth=b[topb];
                            popa();
                            popb();
                        }
                        pusha(arr[j]);
                        depth++;
                        pushb(depth);
                    }
                }
            }
        }
        while(topa!=-1)
        {
            if(b[topb]>maxdepth)
            {
                maxdepth=b[topb];
                min=a[topa];
            }
            if(b[topb]==maxdepth)
            {
                if(a[topa]<min)
                    min=a[topa];
            }
            popa();
            popb();
        }
        printf("%d %d\n",min,maxdepth);
    }
    return 0;
}
