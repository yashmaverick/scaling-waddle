#include<stdio.h>
typedef struct q
{
    int count;
    int val;
}q;
int main()
{
    int cases;
    scanf("%d",&cases);
    int prime[10001]={0},i,j,k;
    for(i=2;i<1000;i++)
    {
        if(prime[i]==0)
        {
            for(j=i+i;j<10001;j=j+i) prime[j]=1;
        }
    }
    while(cases--)
    {
        int ll,ul,flag=0;
        scanf("%d %d",&ll,&ul);
        if(ll==ul) { printf("0\n"); continue;  }
    //  printf("%d %d\n",ll,ul);
        int visited[10001]={0},ql=0,qu=1;
        visited[ll]=1;
        q queue[10001];
        queue[ql].val=ll;
        queue[ql].count=0;
        while(ql<qu && flag==0)
        {
            int x=queue[ql].val;
            if(x%1000==0){   ql++;continue; }
//           printf("x - >> %d  x->count %d \n",x,queue[ql].count);
            for(i=0;i<=9;i++)
            {
                int y=x/10;
                y*=10;y+=i;
//                printf("gen-> %d\n",y);
                if(prime[y]==0)
                {
                    if(visited[y]==0)
                    {
//                        printf("insert y->%d \n",y);
                        if(y==ul) { printf("%d\n",queue[ql].count+1); flag=1;  }
                        queue[qu].val=y; 
                        queue[qu].count=queue[ql].count+1;
                        qu++;
                        visited[y]=1;
                    }
                }
            }
            for(i=0;i<=9;i++)
            {
                int y=x/100;
                y*=100;
                y+=x%10;
                y+=i*10;
//                printf("gen-> %d\n",y);
                if(prime[y]==0)
                {
                    if(visited[y]==0)
                    {
//                       printf("2 y-> %d \n",y);
                        if(y==ul) { printf("%d\n",queue[ql].count+1); flag=1;  }
                        queue[qu].val=y; 
                        queue[qu].count=queue[ql].count+1;
                        qu++;
                        visited[y]=1;

                    }
                }
            }
            for(i=0;i<=9;i++)
            {
                int y=x/1000;
                y*=1000;
                y+=x%100;
                y+=i*100;
//                printf("gen-> %d\n",y);
                if(prime[y]==0)
                {
                    if(visited[y]==0)
                    {
//                        printf("3 y->%d \n",y);
                        if(y==ul) { printf("%d\n",queue[ql].count+1); flag=1;  }
                        queue[qu].val=y; 
                        queue[qu].count=queue[ql].count+1;
                        qu++;
                        visited[y]=1;

                    }
                }
            }
            for(i=1;i<=9;i++)
            {
                int y=x/10000;
                y*=1000;
                y+=x%1000;
                y+=i*1000;
//                printf("gen-> %d\n",y);
                if(prime[y]==0)
                {
                    if(visited[y]==0)
                    {
//                        printf("4 y->%d \n",y);
                        if(y==ul) { printf("%d\n",queue[ql].count+1); flag=1;  }
                        queue[qu].val=y; 
                        queue[qu].count=queue[ql].count+1;
                        qu++;
                        visited[y]=1;

                    }
                }
            }
            ql++;
        }
//        printf("reached");
        if(flag==0) printf("Impossible\n");

    }
    return 0;
}
