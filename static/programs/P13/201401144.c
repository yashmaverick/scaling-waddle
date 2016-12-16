#include <stdio.h>
void prepost(long long l,long long r,long long dep);
//long long b[50000];
long long max,maxel;
long long a[100100];
//long long ind=0;
long long int binarysearch(long long int start, long long int end, long long int val)
{
    
    if(start==end)
    {
        if(a[start]<a[val])
            return start;
        else return -1;
    }
    if(start>end)
        return -1;
    long long int mid=(start+end)/2;
    if(a[mid]<a[val])
    {
        if(a[mid+1]>a[val])
            return mid;
        else return binarysearch(mid+1,end,val);
    }
    else if(a[mid]>a[val])
    {
        if(a[mid-1]<a[val])
            return mid-1;
        else return binarysearch(start,mid-1,val);
    }
    return -1;
}
void prepost(long long l,long long r,long long dep){
    long long i;
    //printf("l= %d r= %d\n",l,r);
    if(l>r)return;
    if(l==r){
        if(dep>max){
            max=dep;
            maxel=r;
        }
        else if(max==dep){
            if(a[maxel]>a[r])
            maxel=r;
        }
        return;
    }
    if(l!=r){
        //printf("moving %d to %d",l,r);
        i=binarysearch(l, r-1, r);
        if(i==-1 || i==r-1){
            prepost( l, r-1, dep+1);
        }
        else{
            prepost(i+1,r-1,dep+1);
            prepost(l,i,dep+1);
        }
    }
    //b[ind++]=a[l];
    return;
}
int main() {
    long long test;
    scanf("%lld",&test);
    long long i;
    for (i=0; i<test; i++) {
        long long n,i;
        scanf("%lld",&n);
        for (i=0; i<n; i++) {
            scanf("%lld",&a[i]);
        }
        //printf("segtest\n");
        prepost(0,n-1,0);
        printf("%lld %lld\n", a[maxel], max);
        max=0;
        maxel=0;
    }
    return 0;
}