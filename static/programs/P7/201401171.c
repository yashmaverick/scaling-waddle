#include<stdio.h>
#include<string.h>

#define s(n) scanf("%lld",&n)
#define maxN 1000001

long long int arr[maxN],arr1[maxN];

int main(){
    long long int t;
    s(t);
    while(t--)
    {
        memset(arr1,0,sizeof(arr1));
        long long int min,i,n;
        long long int ans=0;
        s(n); 
        s(arr[0]); 
        min=arr[0]; 
        for(i=1;i<n;i++)
        {
            s(arr[i]);
            if(arr[i]<min)min=arr[i];
        }
        for(i=0;i<n;i++)
        {
            arr[i]=arr[i]-min;
            arr1[arr[i]]++;
        }
        for(i=0;i<maxN;i++)
        {
            ans=ans+(arr1[i]*(arr1[i]-1))/2;
        }
        printf("%lld\n",ans);
    }   
    return (0);
}
