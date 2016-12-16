#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define inf 10000011111111111
#define mod 1000000007

unsigned long long int heapl[200101],heapr[200100];
unsigned long long int sl=0,sr=0;

void swap(unsigned long long int *a,unsigned long long int *b)
{
     unsigned long long int tmp = *a;
     *a = *b;
     *b = tmp;
}

void insertl(unsigned long long int a)
{    
     unsigned long long int i,tmp;
     sl++;
     heapl[sl]=a;
     i=sl;
     //ind[a]=sl;
     if(sl==1)
          return;
     while(heapl[i/2] < heapl[i] && i>1)
     {
          //ind[heap[i/2]]=i;
          //ind[heap[i]]=i/2;
          swap(&heapl[i/2],&heapl[i]);
          i=i/2;
     }
}

void insertr(unsigned long long int a)
{
     unsigned long long int i,tmp;
     sr++;
     heapr[sr]=a;
     i=sr;
     // ind[a]=sr;
     if(sr==1)
          return;
     while(heapr[i/2] > heapr[i] && i>1)
     {
          //ind[heap[i/2]]=i;
          //ind[heap[i]]=i/2;
          swap(&heapr[i/2],&heapr[i]);
          i=i/2;
     }
}



void heapify(unsigned long long int in,unsigned long long int bit)  // 0 means left and 1 means right
{
     unsigned long long int i=in;
     if(bit==0)
     {  
          while(heapl[i] < heapl[2*i] || heapl[i] < heapl[2*i+1] && i<sl)
          {
               if(heapl[2*i] >= heapl[2*i+1])
               {
                    // ind[heap[i]]=2*i;
                    //ind[heap[2*i]]=i;
                    swap(&heapl[i],&heapl[2*i]);
                    i=2*i;
               }

               else
               {
                    //ind[heap[i]]=2*i+1;
                    //ind[heap[2*i+1]]=i;
                    swap(&heapl[i],&heapl[2*i+1]);
                    i=2*i+1;
               }
          }
     }

     if(bit==1)
     {
          while(heapr[i] > heapr[2*i] || heapr[i] > heapr[2*i+1] && i<sr)
          {
               if(heapr[2*i] <= heapr[2*i+1])
               {
                    // ind[heap[i]]=2*i;
                    //ind[heap[2*i]]=i;
                    swap(&heapr[i],&heapr[2*i]);
                    i=2*i;
               }

               else
               {
                    //ind[heap[i]]=2*i+1;
                    //ind[heap[2*i+1]]=i;
                    swap(&heapr[i],&heapr[2*i+1]);
                    i=2*i+1;
               }
          }
     }
}

//0 for left and 1 for right 
void deletemin(unsigned long long int bit)
{
     if(sl==0 && bit==0)
          return;
     if(sr==0 && bit==1)
          return;
     //ind[heap[*sz]]=1;
     // ind[heap[1]]=0;
     if(bit==0)
     {   swap(&heapl[1],&heapl[sl]);
          heapl[sl]=inf;
          sl--;
          heapify(1,0);
     }
     else if(bit==1)
     {
          swap(&heapr[1],&heapr[sr]);
          heapr[sr]=inf;
          sr--;
          heapify(1,1);
     }

}


unsigned long long int findmin()
{
     return heapr[1];
}
unsigned long long int findmax()
{
     return heapl[1];
}


/*void deckey(int key,int nw,int *n)
  {
  int i;
  i=ind[key];
  ind[key]=0;
  heap[i]=nw;
  ind[heap[i]]=i;
  if(i==1)
  return ;
  while(heap[i/2] > heap[i] && i>1)
  {
  ind[heap[i/2]]=i;
  ind[heap[i]]=i/2;
  swap(&heap[i/2],&heap[i]);
  i=i/2;
  }
  }*/


int main(){
     unsigned long long int n,p,t,q,i,nw,med,tmp,fl=0,test,i1,i2;
     unsigned long long int a,b,c;
     unsigned long long int sum=0;
     scanf("%llu",&test);

     for(i2=0;i2<test;i2++)
     {   sum=0;fl=0;
          //memset(heap,1000000,sizeof(heap));
          scanf("%llu%llu%llu%llu",&a,&b,&c,&n);
          // scanf("%llu",&q);
          for(i=0;i<=n+4;i++)
               heapr[i]=inf;
          for(i=0;i<=n+4;i++)
               heapl[i]=0;

          sl=0; sr=0;
          if(n==0)
          {
               printf("1\n");
               continue;
          }
          
          for(i=1;i<=n;i++)
          {
               //   scanf("%llu",&t);
               if(fl==0)
                    t=1;
               else
                    t=(((a%mod)*(med%mod))%mod+((b%mod)*(i%mod))%mod+c)%mod;

               if(sl==0 && sr==0 && fl==0)
               {
                    med=t; fl=1;
               }

               else if(t<=med)
               {
                    if(sr-sl==1)
                    {           //  printf("if 1 diff of 1\n");
                         insertl(t);
                    }

                    else if(sl==sr)
                    {            //    printf("if 1 diff equal\n");
                         insertr(med);
                         if(sl==0)
                         {
                              med=t;
                         }
                         else
                         {
                              med=findmax();
                              if(t>med)
                                   med=t;
                              else
                              {
                                 heapl[1]=t;
                                 heapify(1,0);
                              }
                         }

                    }

               }

               else if(t > med)
               {
                    if(sr-sl==1)
                    {                    //  printf("if 2 diff 1\n");
                         insertl(med);
                         med=findmin();
                         if(t<med)
                              med=t;
                         else
                         {
                         heapr[1]=t;
                         heapify(1,1);
                         }
                    }

                    else if(sr==sl)
                    {                 // printf("if 2 diff equal\n");
                         insertr(t);
                    }
               }
              
               
               sum+=t; //printf("sum=%llu t=%llu med=%llu\n",sum,t,med);

                  /* printf("%llu sl=%llu sr=%llu\n\n",med,sl,sr);
                     if(sl!=0)
                     {  for(i2=1;i2<=sl;i2++)
                     printf("%llu ",heapl[i2]);
                     printf("\n");
                     }

                     printf("med=%llu\n",med);

                     if(sr!=0)
                     {   for(i2=1;i2<=sr;i2++)
                     printf("%llu ",heapr[i2]);
                     printf("\n");
                     } */ 
          }

          printf("%llu\n",sum);
     }

     return 0;
}

