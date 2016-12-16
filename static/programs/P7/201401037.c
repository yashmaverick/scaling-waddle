#include<stdio.h>
typedef long long int lld;
lld a[1000100];
lld temp[1000010];

void merge(lld l,lld r,lld mid);
void merges(lld l,lld r);

void merges(lld l,lld r)
{    
     if(l>=r)
          return ;

     lld mid=(l+r)/2;
     merges(l,mid);
     merges(mid+1,r);
     merge(l,r,mid);
}

void merge(lld l,lld r,lld mid)
{     
     lld i=l,j=mid+1,k=l,i1;
     
     while((i<=mid) && (j<= r))
     {
          if(a[i] >= a[j])
          {
               temp[k]=a[j];
               k++; j++;
          }

          else if(a[i] < a[j])
          {
               temp[k]=a[i];
               k++; i++;
          }

     }

     while(i<=mid)
     {
          temp[k]=a[i];
          i++; k++;
     }

     while(j<=r)
     {
          temp[k]=a[j];
          j++; k++;
     }

    for(i1=l;i1<=r;i1++)
    {
         a[i1]=temp[i1]; 
    }
          
}

int main (){
     lld test,n,i,i1,j,ans=0,count=0;
          scanf("%lld",&test);

          for(i1=0;i1<test;i1++)
          {    ans=0; count=0;
               scanf("%lld",&n);

               for(i=0;i<n;i++)
               {
                    scanf("%lld",&a[i]);
               }

               merges(0,n-1);  //  for(i=0;i<n;i++) printf("%lld ",a[i]);
               for(i=0;i<n-1;)
               {    count=1;
                    for(j=i+1;j<n;j++)
                    {
                         if(a[i]!=a[j])
                              break;
                         else
                              count++;
                    }

                    i=j;
                    ans+=(count*(count-1))/2 ;
               }


               printf("%lld\n",ans);
          }

          return 0;
}
