#include<stdio.h>
#include<math.h>
int setbit(int n)
{
    int count=-1;
    while(n)
    {
        n=n>>1;
        count++;
    }
return count;
}
int main()
{
    int t;
    scanf("%d",&t);
    int n;
    while(t--)
    {
        scanf("%d",&n);
        int size=setbit(n);
       // printf("%d\n",size);
       // printf("%d\n",3*(1<<size)/2);
        if(n>=3*((1<<size)/2))
            printf("%d\n",2*size);
        else {
            printf("%d\n",2*size-1);
        }
    }
}
