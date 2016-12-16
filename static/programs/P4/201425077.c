#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define zz 1000000

 int compare (const void * a, const void * b)
{
  return ( *(long long int*)a - *(long long int*)b );
}


void mergesort(long long int a[],int start,int end);

int main()
{
long long int t,n,count,i,ans;
long long int a[100001];
char str[100001];
scanf("%lld",&t);

while(t--)
          {
          count=0;
          
          for(i=0;i<100001;i++)
                          {str[i]=0;a[i]=0;}
          scanf("%s",str);
          
          ans=strlen(str);
          
          for(i=0;i<ans;i++)
                          {
                          
                          if(str[i]=='J')
                                         {count+=zz;count+=1;} 
                          else if(str[i]=='M')
                                         count-=zz;
                          else
                                         count--;
                                         
                          a[i]=count;  
                          }
                          
        qsort (a, ans, sizeof(long long int), compare);
        //    mergesort(a,0,ans-1);      
         // for(i=0;i<ans;i++)
           //                 printf("%lld ",a[i]);
          long long int aans=0,c=1;
          for(i=0;i<ans;i++)
                          {
                          //if(a[i]==0)
                                   // aans++;
                                                           
                          if(a[i]==a[i+1])
                                         c++;
                          else
                                         {aans+=(c*(c-1))/2;c=1;} 
                                                                                       
                          }          
          for(i=0;i<ans;i++)                
                          if(a[i]==0)
                                         aans++;                                        
          printf("%lld\n",aans);
          }
             
       
return 0;    
}

void mergesort(long long int a[],int start,int end)
{
int mid=start/2+end/2,i,j,l,r,k;
if(start>end)
             {
             mergesort(a,start,mid);
             mergesort(a,mid+1,end);
             
             l=mid-start+1; r=end-mid;
             
             long long int L[l],R[r];
             
    
    
             for(i=0;i<l;i++)
                            L[i] =a[start+i];
                            
             for(i=0;i<r;i++)
                            L[i] =a[mid+i+1];
                                  
              i=j=0; k=start;      
             while(i<l&&j<r)
                            {
                            if(L[i]>R[j])
                                         a[k++]=L[i++];
                            else
                                         a[k++]=R[j++];       
                                   
                            } 
             while(i<l)     a[k++]=L[i++];
             while(j<r)     a[k++]=R[j++];
             
             }     
     
}
