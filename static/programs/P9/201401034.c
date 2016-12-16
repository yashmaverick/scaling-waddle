#include<stdio.h>
#include<stdlib.h>

struct Node{
  int *next;
};

struct Node myarr[1001];
int marked[1001]={0};
long long int ans[1001]={0};
int sizes[1001]={0};

int main()
{
        int n,m,a,b,c,i,j,k;
        long long int tempor;
        int marker,temp2;
        int mod,sum=0,min;
        struct Node myown;
        scanf("%d%d", &n, &mod);
        for(i=0;i<n;i++)
        {
          scanf("%d", &m);
          sizes[i]=m;
          //printf("%d ", sizes[i]);
          sum=0;
          myarr[i].next=(int*)malloc(sizeof(int)*(m+1));
          for(j=0;j<m;j++)
          {
            scanf("%d", &c);
            sum=(sum+c)%mod;
            myarr[i].next[j]=c;
          }
          ans[i]=sum;
        }
        for(i=0;i<n;i++)
        {
                for(j=i+1;j<n;j++)
                {
                        if(ans[j]<ans[i])
                        {
                                myown=myarr[j];
                                myarr[j]=myarr[i];
                                myarr[i]=myown;
                                tempor=ans[j];
                                ans[j]=ans[i];
                                ans[i]=tempor;
                                temp2=sizes[j];
                                sizes[j]=sizes[i];
                                sizes[i]=temp2;
                        }
                }
        }
        for(i=0;i<n;i++)
        {
                printf("%d\n", ans[i]);
                for(j=0;j<sizes[i];j++)
                {
                        printf("%d\n", myarr[i].next[j]);
                }
                printf("\n");
        }
        return 0;
}
