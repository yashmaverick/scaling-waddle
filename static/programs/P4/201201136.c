#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[100001];
struct node
{
    int F,S;
} a[100002];
typedef  struct node node;

int comp(const void *p1, const void *p2)
{
    node* a = (node*)p1;
    node* b = (node*)p2;
    if(a->F==b->F)
        return a->S - b->S;
    return a->F - b->F;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        n = strlen(s);
        a[0].F = a[0].S = 0;
        int i;
        for(i=0; i<n;i++)
        {
            a[i+1]=a[i];
            if(s[i]=='J'){a[i+1].F--;a[i+1].S--;}
            if(s[i]=='M')a[i+1].F++;
            if(s[i]=='R')a[i+1].S++;
        }
        n++;
        qsort(a,n,sizeof(a[0]),comp);
        long long ans=0;
        long long c = 1;
        for(i = 1; i < n; i++)
            if(a[i].F==a[i-1].F && a[i].S==a[i-1].S)
            {
                ans += c;
                c++;
            }
            else
                c=1;
        printf("%lld\n",ans);
    }
    return 0;

}

