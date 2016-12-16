#include<stdio.h>
int minheap[200005],lastmin=0,lastmax=0,maxheap[200005];
#define mod 1000000007
void insertmin(long long int v)
{
    long long int temp,t;
    lastmin++;
    temp=lastmin;
    minheap[temp]=v;
    if(temp>1)
    {
     while((minheap[temp/2]>minheap[temp])&&(temp>1))
     {
         t=minheap[temp];
         minheap[temp]=minheap[temp/2];
         minheap[temp/2]=t;
         temp=temp/2;
    }
    }     

}
void delmin()
{
    long long int t,i,temp;
   t=minheap[lastmin]; 
   minheap[lastmin]=minheap[1];
   minheap[1]=t;
   temp=1;
  // minheap[lastmin]=0;
   lastmin--;
   
   while(((minheap[temp*2]<minheap[temp])||(minheap[(temp*2)+1]<minheap[temp]))&&(temp*2<lastmin))
   {
       if((minheap[temp*2]<minheap[temp])&&(minheap[(temp*2)+1]>minheap[temp*2]))
       {
           t=minheap[temp];
           minheap[temp]=minheap[temp*2];
           minheap[temp*2]=t;
           temp=temp*2;
       }
       else if(minheap[(temp*2)+1]<minheap[temp])
       {
           t=minheap[temp];
           minheap[temp]=minheap[(temp*2)+1];
           minheap[(temp*2)+1]=t;

           temp=(temp*2)+1;
             
       }

   }
   if((temp*2==lastmin)&&(minheap[temp*2]<minheap[temp]))
   {
     t=minheap[temp];
           minheap[temp]=minheap[temp*2];
           minheap[temp*2]=t;
       
   }

}
void insertmax(long long int v)
{
    long long int temp,t;
    lastmax++;
    temp=lastmax;
    maxheap[temp]=v;
    if(temp>1)
    {
     while((maxheap[temp/2]<maxheap[temp])&&(temp>1))
     {
         t=maxheap[temp];
         maxheap[temp]=maxheap[temp/2];
         maxheap[temp/2]=t;
         temp=temp/2;
    }
    }     

}
void delmax()
{
    long long int t,i,temp;
   t=maxheap[lastmax]; 
   maxheap[lastmax]=maxheap[1];
   maxheap[1]=t;
   temp=1;
 //  maxheap[lastmax]=0;
   lastmax--;
   while(((maxheap[temp*2]>maxheap[temp])||(maxheap[(temp*2)+1]>maxheap[temp]))&&(temp*2<lastmax))
   {
       if((maxheap[temp*2]>maxheap[temp])&&(maxheap[(temp*2)+1]<maxheap[temp*2]))
       {
           t=maxheap[temp];
           maxheap[temp]=maxheap[temp*2];
           maxheap[temp*2]=t;
           temp=temp*2;
       }
       else if(maxheap[(temp*2)+1]>maxheap[temp])
       {
           t=maxheap[temp];
           maxheap[temp]=maxheap[(temp*2)+1];
           maxheap[(temp*2)+1]=t;

           temp=(temp*2)+1;
             
       }

   }
   if((temp*2==lastmax)&&(maxheap[temp*2]>maxheap[temp]))
   {
     t=maxheap[temp];
           maxheap[temp]=maxheap[temp*2];
           maxheap[temp*2]=t;
       
   }
}
int main ()
{
   long long int n,i,q,l,v1,t,a,b,j,c,lsize=0,rsize=0;
   long long int sum=0,f;
   scanf("%lld",&t);
   for(i=0;i<t;i++)
   {
       lsize=0;
       rsize=0;
       sum=0;
   /*    for(v1=0;v1<t;v1++)
       {
           scanf("%lld",&q);
           insertmin(q);
       }
       for(v1=1;v1<=t;v1++)
           printf("%lld-",minheap[v1]);
       printf("\n");
       while(lastmin!=0)
       {
           printf("%lld-\n",minheap[1]);
           delmin();
       //    for(v1=1;v1<=lastmax;v1++)
         //  printf("%lld-",maxheap[v1]);


       }*/
       scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
     /*  for(j=0;j<=n;j++)
       {
          minheap[j]=0;
          maxheap[j]=0;
       }
        */    lastmin=0;
            lastmax=0; 
            f=0;
       for(j=1;j<=n;j++)
       {
           
           if(j==1)
           {
               insertmax(1);
               
               sum=1;
           }
           else
           {
             f=((a%mod*maxheap[1])%mod+(b%mod*j%mod)%mod+c%mod)%mod;
          //    f=j;
               if(f<=maxheap[1])
               {
                   insertmax(f);
                   if(lastmax-1==((j+1)/2))
                   {
                   insertmin(maxheap[1]);
                   delmax();
                   
                   }
                                   
               }
               else
               {
                   insertmin(f);
                  
                   if(lastmin-1==(j)/2)
                   {
                   insertmax(minheap[1]);
                   delmin();
                   
                   }
                  
               }
               sum=sum+f;
          //    printf("\n");
          /*     printf("f is %lld\n",f);

               for(l=lastmax;l>0;l--)
       printf("max-%lld",maxheap[l]);
               for(l=1;l<=lastmin;l++)
       printf("min-%lld",minheap[l]);
 
               printf("\n");
               */

           }

       }
       printf("%lld\n",sum);
       
      lastmin=0;
       lastmax=0;
   }
  
   return 0;
}

