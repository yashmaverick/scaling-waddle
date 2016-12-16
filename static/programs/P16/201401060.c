#include<stdio.h>
int main()
{
    long long int power[32];
    int i,j;
    power[0]=1;
    for(i=1;i<31;i++)
        power[i]=power[i-1]*2;
    int n,q;
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
        scanf("%d",&q);
    for(i=0;i<31;i++)
        if(power[i]>q)
            break;
    int count=(i-2)*2;
    long long int pos=(power[i]+power[i-1])/2;
    if(q<pos)
        count++;
    else
        count+=2;
    printf("%d\n",count);
    }
    return 0;
}






