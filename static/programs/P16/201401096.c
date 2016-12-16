#include<stdio.h>
int next_level=1;
int mylog(unsigned int v)
{
     // 32-bit word to find the log base 2 of
   int r = 0; // r will be lg(v)

    while (v >>= 1) // unroll for more speed...
    {
        
          r++;

    }
    return r;
}

void expss(int v)
{
    while(v>0)
    {next_level<<=1;v--;}


}



int main()
{
    int n,q;
    int val;
    scanf("%d",&n);
    for(q=0;q<n;++q)
    {
        next_level=1;
        scanf("%d",&val);
        int a=mylog(val);
        expss(a+1);
        //printf("height%d nextlev%d\n",a,next_level);
        int range=next_level-1-val;
        int b=next_level>>2;
        //printf("range%d b%d\n",range,b);
        if(range>=b)
        {
            if(val==1)
                printf("%d\n",0);
            else
            printf("%d\n",a+a-1);
        }
        else        
            printf("%d\n",a+a);
    }
return 0;
}
