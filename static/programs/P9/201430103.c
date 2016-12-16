#include<stdio.h>
#include<stdlib.h>
int main()
{
        int T,mod,i,j,k,l,m,p,sum,temp1,temp2;
        scanf("%d %d",&T,&mod);
        int cc[T][2],*bb[T],a[T];
        for(i=0;i<T;i++)
        {
                scanf("%d",&a[i]);
                bb[i]=(int *)malloc((a[i]+1)*(sizeof(int)));
                cc[i][0]=i;
                sum=0;
                for(j=0;j<a[i];j++)
                {
                        bb[i][0]=i;
                        scanf("%d",&bb[i][j+1]);
                        sum=((sum)%mod+(bb[i][j+1])%mod)%mod;
                        cc[i][1]=sum;
                }
        }
        for(k=0;k<(T-1);k++)
        {
                for(l=0;l<T-k-1;l++)
                {
                        if(cc[l][1]>cc[l+1][1])
                        {
                                temp1=cc[l][1];
                                cc[l][1]=cc[l+1][1];
                                cc[l+1][1]=temp1;
                                temp2=cc[l][0];
                                cc[l][0]=cc[l+1][0];
                                cc[l+1][0]=temp2;
                        }
                }
        }
        int w;
        for(m=0;m<T;m++)
        {
                w=cc[m][0];
                printf("%d\n",cc[m][1]);
                for(p=0;p<a[w];p++)
                {
                        printf("%d\n",bb[w][p+1]);
                }
                printf("\n");
        }
        return 0;
}
