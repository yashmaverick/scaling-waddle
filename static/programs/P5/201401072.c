#include<stdio.h>
int a[1001];
//void mergesort(int,int,int *);
//void merge(int,int,int,int,int *);

int cmpfunc(const void *a,const void *b)
{
    return ( *(int *)a - *(int *)b );
}
int n;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int k,l,r,flag=0;
        int i,j;
        char s[500];
        scanf("%d%d",&n,&k);

        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            scanf("%d",&a[i]);

        }
        qsort(a,n,sizeof(int),cmpfunc);
/*for(i=0;i<n;i++)
{
    printf("%d ",a[i]);

}
printf("\n");*/
//         mergesort(0,n-1,a);
   //     for(i=0;i<n;i++)
     //       printf("%d ",a[i]);
       // printf("\n");
        for(i=0;i<n-2&&flag==0 ;i++)
        {

            l=i+1;
            r=n-1;
            while(l<r)
            {
          // printf("sum of %d %d and  %d index is %d\n",i,l,r,a[i]+a[l]+a[r]);
            if((a[i]+a[l]+a[r])==k)
            {
                printf("YES\n");
                flag=1;
                break;
            }
             else if((a[i]+a[l]+a[r])<k)
                 l++;
             else
                 r--;
            }
        }
        if(flag==0)
        printf("NO\n");
    }
        return 0;
}

/*void mergesort(int b,int l,int *a)
{
 //   cout<<"merge= called with start"<<b<<"and end"<<l<<"\n";
    int mid=(b+l)/2;
    if(b==l)
        return;
    else {


    mergesort(b,mid,a);
    mergesort(mid+1,l,a);
    merge(b,mid,mid+1,l,a);
    }
    }
void merge(int b1,int l1,int b2,int l2,int *a)
{
   // cout<<"merging loop from"<<b1<<"to"<<l2<<"with mid as"<<l1<<"\n";
    //cout<<"intial array is like"<<"\n";prar();
    int b[n],i,j=0,k=0;
    int c[n];
  // cout<<"smaller array is like"<<"\n";
    for(i=0;i<=l1-b1;i++)
    {b[i]=a[b1+i];
   // cout<<b[i]<<" ";
    }
   // cout<<"\n";
   // cout<<"bigger array is like "<<"\n";
    for(i=0;i<=l2-b2;i++)
    { c[i]=a[b2+i];
   //     cout<<c[i];
    }
   // cout<<"\n";
    for(i=b1;i<=l2;i++)
    {
        if((b[j]<c[k]&&j<=l1-b1)||k>l2-b2)
        {a[i]=b[j];
            j++;

        }
        else {
            a[i]=c[k];
            k++;
        }

    }

  // cout<<"final array is like "<<"\n";prar();
}*/
