#include<stdio.h>
#include<string.h>

int cmpfunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}


int main()
{
    int t;
    scanf("%d\n",&t);
    while(t>0)
    {
        char s[100001],f,b,c,e,r;
        int ans=0,i,n;
        long long a[100001],o[55];
        scanf("%s",s);
        n=strlen(s);
        if(s[0]=='J')
            a[0]=100004;
        else if(s[0]=='M')
            a[0]=-100005;
        else if(s[0]=='R')
            a[0]=1;
        for(i=1;i<n;i++)
        {
            if(s[i]=='J')
                a[i]=a[i-1]+100004;
            else if(s[i]=='M')
                a[i]=a[i-1]-100005;
            else if(s[i]=='R')
                a[i]=a[i-1]+1;
            if(a[i]==0)
                ans++;
        }
        int tempc=1;
        qsort(a,n,8,cmpfunc);
        for(i=1;i<n;i++)
        {
            if( a[i] == a[i-1] )
                tempc++;
            else
            {
                ans += (tempc*(tempc-1))/2;
                tempc=1;
            }
        }
        ans += (tempc*(tempc-1))/2;
        printf("%d\n",ans);
        t--;
    }
    return 0;
}
