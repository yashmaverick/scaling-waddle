#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int n;
int b;
char s[100005];
long long int a[1000005];
int luck(const void *a,const void *b)
{
    return (*(long long int*)a-*(long long int*)b);
}
  
int main()
{
    int i,t,m;
    scanf("%d",&t);
    for(m=1;m<=t;m++)
    {
        b=0;
        scanf("%s",s);
        int l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]=='J')
                b=b+(-100000-2);
            if(s[i]=='M')
                b=b+1;
            if(s[i]=='R')
                b=b+100000+1;
            a[i]=b;
         //   printf("%lld ",a[i]);
        }
        qsort(a,l,sizeof(long long int),luck);
   //  for(i=0;i<l;i++)
     //      printf("%lld ",a[i]);
        int min=a[0];
        int minp=0;
        int maxp;
        long long int d,c;
        c=0;
        long long int v=0;
        for(i=0;i<l;i++)
        {
            if(a[i]==0)
                c++;
            int hh=0;
            if(a[i]==min)
            {
                maxp=i;
                if(i==l-1)
                {
                    d=(maxp-minp+1);
                    v=v+(d*(d-1))/2;
                }
            }
            else
            {
                d=(maxp-minp+1);
               // printf("d=%lld ",d);
                v=v+(d*(d-1))/2;
              //  printf("v=%lld\n",v);
                minp=i;
                min=a[i];
                maxp=i;
            }
           // printf("maxp=%d minp=%d\n",maxp,minp);
        }
        v=v+c;
        printf("%lld\n",v);            
    }
    return 0;
}
