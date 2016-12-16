#include<stdio.h>
int main()
{
        int t,p,q,r;
        int i,j,l=0;
        int a[100001],b[100001],c[100001];
        int temp[100001];
        int pemp[100001];
        scanf("%d",&t);
        for(i=0;i<t;i++)
        {
                //               a[0]=0;
                //             b[0]=0;
                //           c[0]=0;
                scanf("%d",&p);
                for(j=0;j<p;j++)
                        scanf("%d",&a[j]);

                scanf("%d",&q);
                for(j=0;j<q;j++)
                        scanf("%d",&b[j]);

                scanf("%d",&r);
                for(j=0;j<r;j++)
                        scanf("%d",&c[j]);
                //         temp[0]=0;
                //       pemp[0]=0;
                int m=0;
                //                int count=0;
                j=0;
                long long int count=0;
                while(j<q)
                {
                        if(a[m]<=b[j] && m<=j && m<p)
                        {
                                m++;
                                count++;
                        }
                        else
                        {
                                temp[j]=count;
//                                printf("%d\n",temp[j]);
                                j++;
                               // m++;
                        }
                }

//                for(m=0;m<q;m++)
  //                    printf("%d ",temp[m]);
                count=0;
                long long int ans=0;
                int y=0;
                j=0;
                while(j<r )
                {
                        if(b[y]<=c[j] && y<=j && y<q)
                        {
                                count=count+temp[y];
                                y++;
                        }
                        else
                        {
                                ans=ans+count;       
                                j++;
                        }
//                        for(l=0;l<r;l++)
  //                              printf("%d ",pemp[l]);
                        //                        printf("%d",l);
                       // for(l=0;l<r;l++)
                      //  {//
                           //     ans = ans + pemp[l]*temp[l];
                       // }

                }
//                ans=ans+count;
                printf("%lld\n",ans);
        }
        return 0;
}

