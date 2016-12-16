#include<stdio.h>
#include<string.h>

#define maxN 100005

long long int  arr[maxN][3], n[3],arr1[maxN][2],arr2[maxN];

long long int mini(long long int a,long long int b)
{
    if(a<b)
        return a;
    else
        return b;
}

long long int maxi(long long int a, long long int b)
{
    if(a<b)
        return b;
    else
        return a;
}

int binsearch(long long int row, long long int ele)
{
    long long int find=arr[ele][row];
    long long int min =0, max=mini(ele,n[row-1]-1);
    //printf("MAX:%lld ele:%lld n:%lld\n",max,find,n[row-1]);
    long long int k,ans=-1;
    if(ele==0)ans=-1;
    while(min<=max)
    {
        //maximum element smaller than find in arr[][row-1]
        //prlong long intf("%lld %lld %lld\n",min,max,find);
        k=(min+max)/2;
        if(arr[k][row-1]<=find)
        {
            ans=k;
            min=k+1;
        }
        else
        {
            max=k-1;
        }
    }
    arr1[ele][row-1]=ans;
    return(0);
}

int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int i, ans=0;
        for(i=0;i<3;i++)
        {
            scanf("%lld",&n[i]);
            long long int j;
            for(j=0;j<n[i];j++)
            {
                scanf("%lld",&arr[j][i]);
                if(i!=0)
                {
                    binsearch(i,j);
                    //printf("row:%lld ele:%lld arr:%lld arr1:%lld\n",i,j,arr[j][i],arr1[j][i-1]);
                }
                if(i==1)
                {
                    long long int sup=arr1[j][0];
                    arr2[j]=sup+1;
                    if(j!=0)
                        arr2[j]=arr2[j]+arr2[j-1];
                    //printf("arr2[]:%lld\n",arr2[j]);
                }
                if(i==2)
                {
                    long long int sup=arr1[j][1];
                    if(sup!=-1)
                    {
                        ans=ans+arr2[sup];
                        //printf("ans:%lld sup:%lld\n",ans,sup);
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
}
