#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct jmr{
    int jr;
    int mr;
}jmr;
int cmpfunc(const void *a, const void *b)
{
    jmr *ia = (jmr *)a;
    jmr *ib = (jmr *)b;
    if(ia->jr == ib->jr)
        return ia->mr - ib->mr;
    else
        return ia->jr - ib->jr;
}
int main()
{
    int t;
    scanf("%d",&t);
    char s[100010];
    while(t--)
    {
        scanf("%s",s);
        int l = strlen(s),i;
        jmr *a = (jmr *)malloc(sizeof(jmr)*(l+1));
        int countj=0,countm=0;
        a[0].jr=0;
        a[0].mr=0;
        for(i=0;i<l;i++)
        {
            if(s[i]=='J')
                countj++;
            else if(s[i]=='M')
                countm++;
            else
                countj--,countm--;
            a[i+1].jr = countj;
            a[i+1].mr = countm;
        }
        qsort(a,l+1,sizeof(jmr),cmpfunc);
        //for(i=0;i<=l;i++)
          //  printf("%d %d\n",a[i].jr,a[i].mr);
          //  Right uptill here....
        jmr temp=a[0];
        int count=1,sum=0;
        for(i=1;i<=l;i++)
        {
            if(temp.jr==a[i].jr && temp.mr==a[i].mr)
                count++;
            else
            {
                sum += (count*(count-1))/2;
                count = 1;
                temp=a[i];
            }
        }
        sum += count*(count-1)/2;
        printf("%d\n",sum);
    }
    return 0;
}
