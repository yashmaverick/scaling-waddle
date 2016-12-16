#include<stdio.h>
#include<stdlib.h>
void print(long long int *p,long long int n)
{
        int i=0;
        for(i=0;i<=n;i++)
                printf("%lld ",p[i]);
        printf("\n");
}
int main()
{
        long long int n,*log,*p,i,j,k=0,top=-1,pop,area;
        long long int max=0,sum=0;
        scanf("%lld",&n);
        while(n!=0)
        {
                top=-1;
                area=0;
                max=0;
                k=0;
                log=(long long int *)malloc(sizeof(long long int)*n);
                p=(long long int *)malloc(sizeof(long long int)*n);
                for(i=0;i<n;i++)
                        scanf("%lld",&log[i]);
                for(i=0;i<n;)
                {
                        if(top==-1 || log[p[top]]<=log[i])
                        {
          //                      printf("push=%lld\n",log[i]);
                                p[++top]=i++;
  //                              print(p,top);
                        }
                        else
                        {
                                top--;
                                if(top==-1)
                                        area=log[p[top+1]]*(i);
                                else
                                        area=log[p[top+1]]*(i-p[top]-1);
//                                        printf("area is %lld\n",area);
                                if(max<area)
                                {
                                        max=area;
//                                        printf("%lld\n",max);
                                }
                        }
    //                    print(p,top);
                }
                while(top!=-1)
                {
                        top--;
                        if(top==-1)
                                area=log[p[top+1]]*(i);
                        else
                                area=log[p[top+1]]*(i-p[top]-1);
                        if(max<area)
                        {
                                max=area;
      //                          printf("%lld\n",max);
                        }
        //                print(p,top);
                }
                printf("%lld\n",max);
                scanf("%lld",&n);
        }
        return 0;
}

