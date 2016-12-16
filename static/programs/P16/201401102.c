#include<stdio.h>
int main()
{
        int x,c,t,n,i,n_copy;
        scanf("%d",&t);
        for(i=0;i<t;i++)
        {
                c=-1;
                scanf("%d",&n);
                n_copy=n;
                while(n!=0)
                {
                        n=n>>1;
                        c++;
                }
                x=1<<c;
                if(n_copy>=x+x/2)
                        printf("%d\n",c*2);
                else
                        printf("%d\n",c*2-1);
        }
        return 0;
}

