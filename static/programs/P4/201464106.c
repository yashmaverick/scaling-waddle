#include<stdio.h>
#include<string.h>
#define x 100000+1
#define y -100000-2
#define z 1

int compare(const void *p,const void *q)
{
    return ( *(int*)p-*(int*)q );
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[100000];
        scanf("%s",s);
        int l=strlen(s);
        int a[l];
        int i;

        if(s[0]=='J')
            a[0]=x;
        else if(s[0]=='M')
            a[0]=y;
        else
            a[0]=z;

        for(i=1;i<l;i++)
        {
            if(s[i]=='J')
                a[i]=a[i-1]+x;
            else if(s[i]=='M')
                a[i]=a[i-1]+y;
            else
                a[i]=a[i-1]+z;
        }
     /*   for(i=0;i<l;i++)
            printf("%d ",a[i]);
        printf("\n");*/

        qsort(a,l,sizeof(int),compare);
       /* for(i=0;i<l;i++)
            printf("%d ",a[i]);
        printf("\n");*/

        long long int c=0,n=1;
        if(a[0]==0)
            c++;
        for(i=1;i<l;i++)
        {
            if(a[i]==0)
                c++;

            if(a[i]==a[i-1])
                n++;

            if(a[i]!=a[i-1])
            {
                c+=n*(n-1)/2;
                n=1;
            }
        }
        c+=n*(n-1)/2;

        printf("%lld\n",c);
        c=0;
    }
    return 0;
}







