#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compare (const void * a, const void * b)
{
        return ( *(int*)a - *(int*)b );
}


int main()
{
    int T,i,j,p,q;
    long long int finalsum;
    char s[100000];
    scanf("%d",&T);
    while(T--)
    {
        int arr[100001]={0},k,sum,J,R,M,arr2[100001]={0};
        J=-100000-1;
        M=1;
        R=100000;
        scanf("%s",s);
        q=strlen(s);
        sum=0;
        for(i=0;i<q;i++)
        {
            if(s[i]=='J')
            {
                arr[i]=sum + J;
                sum=arr[i];
            }
            else if(s[i]=='R')
            {
                arr[i]=sum+R;
                sum=arr[i];
            }
            else
            {
                arr[i]=sum+M;
                sum=arr[i];
            }
        }
        qsort(arr,q,sizeof(int),compare);
        finalsum=0;
        k=arr[0];
        p=0;
        for(i=0;i<q;i++)
        {
            if(arr[i]==k)
            {
                arr2[p]++;
            }
            else
            {
                p++;
                k=arr[i];
                arr2[p]=1;
            }
        }
        for(i=0;i<=p;i++)
        {
      //      printf("%d",arr2[p]);
            if(arr2[i]>=2)
                finalsum = finalsum + (arr2[i])*(arr2[i]-1)/2;
        } 
    //    for(i=0;i<q;i++)
   //         printf("%d ",arr[i]);
        for(i=0;i<q;i++)
            if(arr[i]==0)
                finalsum++;
  //      printf("\n");
        printf("%lld\n",finalsum);
    }
    return 0;
}

