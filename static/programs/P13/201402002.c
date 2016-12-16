#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int depth;
    int value;
};


int bsearch1_old(int *arr, int key, int l, int h)
{
    int mid=(l+h)/2;

    while(l<=h)
    {
        if (l==h && h==mid)
            break;

        mid=(l+h)/2;
        if (arr[mid]<key && mid==key-1)
            return mid;
        else if (arr[mid]<key)
            l=mid+1;
        else
            h=mid-1;
    }

//    printf("l is %d and h is %d\n",l ,h);
    // MODIFIED Section <------ That returns the highest index of the lower element.
    int count=l-1;            //
    if (count<0)              //
        count=0;              //
    while(arr[count]<key)     //
        count++;              //
    return count-1;           //
    //// MODIFIED Section <----- Ends

    return -1;
}

/*
int bsearch1(int *arr, int key, int l, int h)
{
    int mid=(l+h)/2;

    while(l<=h)
    {
        mid=(l+h)/2;
        if (mid+1<=h)
            if (arr[mid]<key && arr[mid+1]>key)
                return mid;
        if (mid-1>=l)
            if (arr[mid]>key && arr[mid-1]<key)
                return mid-1;
        if (arr[mid]<key)
            l=mid+1;
        else if (arr[mid]>key)
            h=mid-1;
        else
            return mid;
    }

    if (h<0)
        return 0;
    else
        if (l>h)
            return h;
        else
            return (l<h) ? l : (h+1);
}

*/

int binarylower(int a[],int m,int l,int u)
{
 //   printf("BIN: l=%d, u=%d , key=%d\n",l ,u ,m);
    int mid,c=0;
    //if (l==u)
    //return l;

    if(l<=u)
    {
        mid=(l+u)/2;
        if(m==a[mid])
        {
            c=m;
            return binarylower(a,m,l,mid-1);
        }
        else if(m<a[mid])
        {
            return binarylower(a,m,l,mid-1);
        }
        else
        {
            return binarylower(a,m,mid+1,u);
        }
    }
    else
        return u;
}


struct node count_maxdepth(int *arr, int l, int h)
{
   // printf("Rec: l=%d, h=%d\n",l ,h);
    struct node f;
    f.depth=1;
    f.value=arr[l];

    if (l>=h)
        return f;
    else if (h-l == 1)
    {
        f.depth=2;
        return f;
    }

    int i,mid_lower;
    /*
         for(i=h-1;i>=l;i--)
           if (arr[i]<arr[h])
           {
           mid_lower=i;
           break;
           }
           else
           mid_lower=i;
    */

    mid_lower=bsearch1_old(arr,arr[h],l,h-1);
   // printf("Mid_lower is %d, l is %d , h is %d\n",mid_lower ,l ,h);
    struct node A=count_maxdepth(arr,l,mid_lower);
  //  printf("First A's depth %d\n",A.depth);
    struct node B=count_maxdepth(arr,mid_lower+1,h-1);
    A.depth++;
    B.depth++;
    struct node K;

    if (A.depth > B.depth)
        return A;
    else if(B.depth > A.depth)
        return B;
    else
        if (A.value < B.value)
            return A;
        else
            return B;
}


int main()
{

    int t,i=0;
    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        int n,j;
        scanf("%d",&n);
        int arr[n];

        for(j=0;j<n;j++)
            scanf("%d",&arr[j]);
        struct node max=count_maxdepth(arr,0,n-1);

        printf("%d %d\n",max.value ,max.depth-1 );
    }

    return 0;
}
