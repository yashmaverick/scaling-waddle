#include<stdio.h>
int comp(const void *a,const void *b){
     return *(int*)a-*(int*)b;
}

int main(){
     int test,flag,n,i,j,k,i1,a[10000],j1;
     char b[10000];
     long long int sum;
     scanf("%d",&test);

     for(i1=0;i1<test;i1++)
     {    sum=0; flag=0;
          scanf("%d%d\n",&n,&k);

          for(i=0;i<n;i++)
          {
               scanf("%s%d",b,&a[i]);
          }


          qsort(a,n,sizeof(int),comp);

          for(i=0;i<n-1;i++)
          {
               j=i+1; j1=n-1;
               while(j1>j)
               {    
                    sum=a[i]+a[j]+a[j1];          //  printf("sum=%lld\n",sum);
                    if(sum==k)
                    {
                         flag=1;
                         break;
                    }
               
                    else if(sum <k)
                    {
                         j++;
                    }

                    else if(sum > k)
                         j1--;
               }
               
               
               

               if(flag==1)
               {
                    break;
               }
          }

          if(flag==1)
               printf("YES\n");

          else
               printf("NO\n");
     }

     return 0;
}


