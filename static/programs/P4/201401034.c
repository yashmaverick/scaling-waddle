#include<stdio.h>
#include<string.h>

void merge(long long int A[], long long int start, long long int end)
{
    long long int l,r,val,i,j,k;
    long long int C[100100];
    val=start; l=start; r=(start+end)/2+1;
    while(l<=(start+end)/2 && r<=end)
    {
        if(A[l]<A[r])
            C[val++]=A[l++];
        else
            C[val++]=A[r++];
    }
    while(l<=(start+end)/2)
        C[val++]=A[l++];
    while(r<=end)
        C[val++]=A[r++];
    for(j=start;j<=end;j++)
        A[j]=C[j];
    return;
}

void mergesort(long long int A[], long long int start, long long int end)
{
    if(end>start)
    {
        mergesort(A,start,(start+end)/2);
        mergesort(A,(start+end)/2+1,end);
        merge(A,start,end);
    }
    return;
}


int main()
{
   long long int ii,count,bbtemp,summ,a,b,c,i,j,k,sum,tot,temp;
   char AA[101000];
   long long int t;
   scanf("%lld", &t);
   for(ii=0;ii<t;ii++)
   {
       summ=0;
       long long int BB[101000]={0};
       bbtemp=1; BB[0]=0;
       scanf("%s", AA);
       tot=strlen(AA); sum=0;
       for(i=0;i<tot;i++)
       {
           if(AA[i]=='J')
               sum+=1;
           if(AA[i]=='M')
               sum+=100000;
           if(AA[i]=='R')
               sum-=100001;
           BB[bbtemp++]=sum;
           //printf("%lld\n", BB[bbtemp]);
       }
        mergesort(BB,0,bbtemp-1); count=1;
        //for(j=0;j<bbtemp;j++)
          //printf("%lld\n", BB[j]);
        for(j=0;j<bbtemp;j++)
        {
            if(BB[j]==BB[j+1])
                count++;
            else
            {
                summ+=count*(count-1)/2;
                count=1;
            }
        }
        printf("%lld\n", summ);
   }
   return 0;
}
