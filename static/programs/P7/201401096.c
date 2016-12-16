#include<stdio.h>
long long int pairs( long long int n)

{
    return (n*(n-1))/2;

}
#define MAX 1000000
long long int array[MAX];

void Mergesort(long long int array[],long long int low,long long int mid,long long int high);
void split(long long int array[],long long int low,long long int high);
void split(long long int array[],long long int low,long long int high){

    long long int mid;

    if(low<high){
        mid=(low+high)/2;
        split(array,low,mid);
        split(array,mid+1,high);
        Mergesort(array,low,mid,high);
    }   
}
void Mergesort(long long int array[],long long int low,long long int mid,long long int high)
{

    long long int i,m,k,l;
    long long int temp[MAX];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

        if(array[l]<=array[m]){
            temp[i]=array[l];
            l++;
        }
        else{
            temp[i]=array[m];
            m++;
        }
        i++;
    }

    if(l>mid){
        for(k=m;k<=high;k++){
            temp[i]=array[k];
            i++;
        }
    }
    else{
        for(k=l;k<=mid;k++){
            temp[i]=array[k];
            i++;
        }
    }

    for(k=low;k<=high;k++){
        array[k]=temp[k];
    }
}
int main()
{
    long long int n,i;
    long long int test;long long int ct,ans;
    scanf("%lld",&test);
    while(test--)
    {
        ans=0;
        scanf("%lld",&n);
        for(i=0;i<n;++i)
            scanf("%lld",&array[i]);

        split(array,0,n-1);
        //for(i=0;i<n;++i)
        //  printf("%lld ",array[i]);
        i=0;
        while(i<=n-1)
        {   ct=1;
            if(array[i]==array[i+1])
            {
                while(array[i]==array[i+1])
                {
                    ct++;i++;}
            }
            else i++;
            ans+=pairs(ct);
            


        }

        printf("%lld\n",ans);
    }

}
