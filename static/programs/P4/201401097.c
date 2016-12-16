#include<stdio.h>
void merge(long long int a[],long long int l1,long long int r1,long long int l2,long long int r2)
{
    long long int i,j,k,l,t[100005];
    k=0;
    i=l1;

    while((l1<=r1)&&(l2<=r2))
    {
        if(a[l1]<a[l2])
            t[k++]=a[l1++];
        else
            t[k++]=a[l2++];
    }
    while(l1<=r1)
    {
        t[k++]=a[l1++];
    }
    while(l2<=r2)
    {
        t[k++]=a[l2++];
    }
    k=0;
    for(;i<=r2;i++)
    {

        a[i]=t[k++];

    }


    return;




}
void msort(long long int a[],long long int l,long long int r)

{
   long long int mid;

    if(l<r)
    {



        mid=(r+l)/2;

        msort(a,l,mid);
        msort(a,mid+1,r);
        merge (a,l,mid,mid+1,r);
    }
    return;

}
int main ()
{
    long long int i,count=0,fans=0,j,k,length=0,n,tsum=0,m,stor[100005];
    char a[100005];
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        length=0;
        count=1;
        tsum=0;
        fans=0;
        

        scanf("%s",a);
        for(j=0;a[j]!='\0';j++)
        {

            if(a[j]=='J')
                tsum=tsum-1;
            else if(a[j]=='R')
                tsum=tsum+100001;
            else
                tsum=tsum-100000;
            stor[j]=tsum;
        }
        for(j=0;a[j]!='\0';j++)
            length=length +1;
        msort(stor,0,length-1);
        for(j=0;a[j]!='\0';j++)
        {
            if(stor[j]==0)
                fans++;
            if(stor[j]==stor[j+1])
                count++;
            else
            {
                fans=fans+((count*(count-1))/2);
                count=1;
            }
        }
       // for(j=0;a[j]!='\0';j++)
         // printf("%lld\n",stor[j]);

        printf("%lld\n",fans);


    }
    return 0;
}
