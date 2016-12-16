#include<stdio.h>
void merge(long long int a[],int low,int mid,int high)
{
    int l,i,j;long long int c[100000];
    for(i=low,j=mid+1,l=low;i<=mid&&j<=high;l++)
    {
        if(a[i]<a[j])
        {
            c[l]=a[i];
            i++;
        }
        else
        {
            c[l]=a[j];
            j++;
        }
    }
    if(l<=high)
    {
        while(i<=mid)
        {
            c[l]=a[i];
            l++;
            i++;
        }
        while(j<=high)
        {
            c[l]=a[j];
            l++;
            j++;
        }
    }
    for(i=low;i<=high;i++)
        a[i]=c[i];
}
void mergesort(long long int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
    if(low==high)
        return;
}
int main()
{   int i;
    char a[100000];
    int test;
    scanf("%d",&test);
    while(test--)
    {getchar();
    scanf("%[^\n]s",a);
    long long int cf[100000];
    switch(a[0])
    {
        case 'J':cf[0]=0-100000-2;break;
        case 'M':cf[0]=1;break;
        case 'R':cf[0]=100000+1;break;



    }

    for(i=1;a[i]!='\0';++i)
    {
        if(a[i]=='J')
            cf[i]=cf[i-1]-100000-2;
        else if(a[i]=='M')
            cf[i]=cf[i-1]+1;
        else if(a[i]=='R')
            cf[i]=cf[i-1]+100000+1;


    }

    int n=i,j;
    mergesort(cf,0,n-1);
    long long int ans=0;
    for(i=0;i<n;++i)
    {   j=i;
//       printf("a\n"); 
        while(cf[j]==cf[j+1]&&j!=n-1)j++;
        
        ans+=(j-i+1)*(j-i)/2 ;
        if(cf[j]==0)
            ans+=j-i+1;
        i=j;
       
//       printf("%d ",cf[i]);
    }

    printf("%lld\n",ans);
    }
    return 0;
}
