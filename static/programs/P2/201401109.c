#include<stdio.h>
long long int temp=-1;
long long int binarySearch(long long int arr[], long long int l, long long int r, long long int x)
{
  while (l <= r)
  {
   long long int m = l + (r-l)/2;
                     
   if (arr[m] == x) return m;  
                              
   if (arr[m] < x) 
   {
       temp=m;
       l = m + 1;

   }
                                       
   else
    {
        r = m - 1;
    }
    
  }
  return temp; 
}
long long int binarySearch1(long long int arr[], long long int l, long long int r, long long int x)
{
   
 while (l <= r)
  {
   long long int m = l + (r-l)/2;
  
                     
   if (arr[m] == x) return m;
                              
   if (arr[m] > x) 
   {
       temp=m;
       r = m - 1;

   }
                                       
   else
    {
        l = m + 1;
    }
    
  }
  return temp; 
}

long long int main()
{
    long long int i,j,k,n,t,p,q,r,index1,index2,sum,num,demo,demo1,ran,ran1;
    scanf("%lld",&t);
    while(t--)
    {
        sum=0;temp=-1;
        scanf("%lld",&p);
        long long int a[p];
        for(i=0;i<p;i++)
            scanf("%lld",&a[i]);
            scanf("%lld",&q);
            long long int b[q];
        for(i=0;i<q;i++)
            scanf("%lld",&b[i]);
            scanf("%lld",&r);
            long long int c[r];
        for(i=0;i<r;i++)
            scanf("%lld",&c[i]);


            for(j=0;j<q;j++)
            {
                num=b[j];temp=-1;ran=0;ran1=0;
               // index2=j;
               if(p-1>=j)
                demo1=binarySearch(a,0,j,num);
                else
                    demo1=binarySearch(a,0,p-1,num);
                    if(demo1+1<=p-1&&demo1+1<=j)
                    {
                    if(a[demo1]==a[demo1+1])
                    {
                      ran1=demo1+1;
                      while(ran1<=p-1&&a[ran1]==a[demo1]&&ran1<=j)
                      {
                          ran1++;
                      }
                          
                    }
                    }
                    if(ran1>0)
                    index1=ran1-1;
                    else
                        index1=demo1;
//                   printf("index1=%lld   ",index1+1);
                 //  temp=-1;
                 if(b[j]>c[r-1])
                     index2=0;
                     else
               {
                if(r-1>=j)
                {

                demo=binarySearch1(c,j,r-1,num);
  //              printf("demo==%lld  ",demo);
                if(demo-1>=j)
                {
                if(c[demo]==c[demo-1])
                {
                    ran=demo-1;
                    while(ran>=j&&c[ran]==c[demo])
                        ran--;
                        //ran=ran-demo;
                
                demo=ran+1;
                }
                }
                index2=r-demo;
                
                }
                if(r-1<j)
                index2=0;
                    if(index2==-1)
                       index2=0;
               }
    //            printf("index2=%lld  ",index2);
                sum=sum+(index1+1)*index2;
            }
            printf("%lld\n",sum);
    }
    return 0;
}
