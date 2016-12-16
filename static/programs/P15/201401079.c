#include<stdio.h>
int main()
{
     int i,j,k,m,n,t,cnt,head,tail,min,z;
     int a[10000];
     int b[10000];
     scanf("%d",&t);
     while(t--)
     {
          scanf("%d%d",&n,&k);
          for(i=1;i<=n;i++)
          {
               scanf("%d",&a[i]);

          }
          if(k==1)
          {
              for(i=1;i<=n-1;i++)
                   printf("%d ",a[i]);
              printf("%d\n",a[n]);
          }
          else
               
          {
               head=0;
          tail=-1;
          j=1;
        // j=0;
          cnt=0;
          for(i=1;i<=n;i++)
          {
               if(tail==-1)
               {
                    tail++;
                      b[tail]=i;
               }
               else if(a[i]<a[b[head]])
              {
                    
                    
                    b[head]=i;
               }
              else
               {
                    while(a[i]<a[b[tail]] && tail!=-1)
                         tail--;

                    tail++;
                    b[tail]=i;
              }
               cnt++;
               if(cnt==k)
               {
                    printf("%d ",a[b[head]]);
                    cnt=cnt-1;
                    j++;
                    while(j>b[head])
                         head++;
               }
               if(j==n-k+1)
               {
                    min=a[b[head]];
                    for(z=j;z<=n;z++)
                    {
                         if(a[z]<min)
                              min=a[z];
                    }
                    printf("%d\n",min);
                   
                    break;
               }

          }
          }
     }
     return 0;

}
