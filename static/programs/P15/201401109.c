#include<stdio.h>
int a[10010],n,n1,k,b[10010];
void push(int num)
{
    n1++;
    b[n1]=num;
}
void pop()
{
    n1--;
}
void popbottom()
{
    int j;
    for(j=1;j<=n1;j++)
        b[j-1]=b[j];
 //   if(n1>0)
        n1--;
}

int main()
{
    int i,j,t,var,total,count;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        n1=0;b[0]=a[0];var=0;count=0;
        total=n-k+1;
        for(i=1;i<=n;i++)
        {
            if(i>var+k-1)
            {
                if(i!=n)

                    printf("%d ",b[0]);
                else
                    printf("%d\n",b[0]);
                count++;
                if(count==total)
                    break;
                if(a[var]==b[0])
                    popbottom();
                var++;
                i--;

            }
            else
            {

                if(a[i]>=b[n1])
                    push(a[i]);
                else
                {
                    while(a[i]<b[n1]&&n1>=0)
                    {
                        //while(a[i]<b[n1]&&n1>=-1)
                       // {
                        pop();
                     }
                        push(a[i]);

                    

                }
            }
//            for(j=0;j<=n1;j++)
  //              printf("%d ",b[j]);
    //        printf("\n");


        }
//        printf("n1==%d",n1);
  //      for(i=0;i<=n1;i++)
    //        printf("b==%d",b[i]);
    }
    return 0;
}


