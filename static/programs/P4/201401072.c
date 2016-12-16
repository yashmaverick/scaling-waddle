#include<stdio.h>
#include<string.h>
int cmpfunc(const void *a,const void *b)
{
    return ( *(int *)a - *(int *)b );
}
int main()
{
    char s[100001];
    int a[100100];
    int t;
        scanf("%d",&t);
    while(t--)
    {
        int i;
        scanf("%s",s);
        int l=strlen(s);
        int sum=0;
        a[0]=0;
        for(i=0;i<l;i++)
        {
            if(s[i]=='J')
                a[i+1]=a[i]+l;
           else  if(s[i]=='M')
                a[i+1]=a[i]+1;
            else if(s[i]=='R')
                a[i+1]=a[i]-l-1;

        }

/*        for(i=0;i<=l;i++)
        printf("%d ",a[i]);*/
        qsort(a,l+1,sizeof(int),cmpfunc);
  /*     for(i=0;i<=l;i++)
        printf("%d ",a[i]);*/
        int val=a[0];
        int m=1;
        int count=0;
        for(i=1;i<=l;i++)
        {
            if(a[i]==val)
                m++;
            else {
                val=a[i];
                if(m&1)
                count+=((m-1)/2)*m;
                else {
                    count+=(m/2)*(m-1);
                }
                m=1;
            }
        }
                if(m&1)
                count+=((m-1)/2)*m;
                else {
                    count+=(m/2)*(m-1);}
        printf("%d\n",count);
    }
}


