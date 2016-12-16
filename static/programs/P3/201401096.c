#include<stdio.h>
int main()
{
    int test,n,a[1000000];
    scanf("%d",&test);
    int i;
    int mdiff,min ;
    while(test--)
    {
        scanf("%d",&n);
        scanf("%d",&a[0]);
        scanf("%d",&a[1]);
        min=a[0];
        mdiff=a[1]-a[0];//maxdiff;
        if(a[1]<a[0])
            min=a[1];
        for(i=2;i<n;++i)
        {
            scanf("%d",&a[i]);
            if((a[i]-min)>mdiff)//find max diff so far
                        
                mdiff=a[i]-min;
            if(a[i]<min)//find min so far
                min=a[i];

        }
    if(mdiff<=0)
        printf("0\n");
    else
        printf("%d\n",mdiff);

    }
return 0;
}
