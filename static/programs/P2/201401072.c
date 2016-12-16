#include<stdio.h>
int bsearch1(int *,int ,int);
int bsearch2(int *,int,int);
int main()
{
    unsigned long long int count=0;
    int t;
    scanf("%d",&t);
    while(t--)
    {
       int a[100100],b[100100],c[100100];
        count=0;
        int i,i1,i2,i3,r;
     scanf("%d",&i1);
        for(i=0;i<i1;i++)
            scanf("%d",&a[i]);
        scanf("%d",&i2);
        for(i=0;i<i2;i++)
            scanf("%d",&b[i]);
        scanf("%d",&i3);
        for(i=0;i<i3;i++)
            scanf("%d",&c[i]);
        int d[100100];

        for(i=0;i<i2;i++)
        {
            int x=bsearch1(c,b[i],i3);
            if(x<i)
            {
                if(i>i3)
                    d[i]=0;
                else {
                    d[i]=i3-i;
                }
            }
            else {
                if(a[x]==b[i])
                    d[i]=i3-x;
               else  if(x==i3)
                    d[i]=0;
                else
                d[i]=i3-x;
            }
    //       printf("inserted %d at position %d and it is finally = %d \n",b[i],x,d[i]);

        }
       // printf("\n");
        for(i=0;i<i2;i++)
        {
            int x=bsearch2(a,b[i],i1);

            if(x>i)
            {
                r=i+1;
            }
            else
            {
                if(a[x-1]==b[i])
                    r=x;
                else if(x!=i1)
                r=x+1;
                else {
                r=x;
                }
            }


      //     printf("inserted %d at position %d and it is finally = %d \n",b[i],x,r);
        // printf("%d ",x);


          count+=r*d[i];



    }

    printf("%lld\n",count);
    }
    }
int bsearch1(int *a,int s,int l)
{
    if(s<a[0])
        return -1;
    else {
    int i,mid,b=0;
    while(b<=l)
    {
        mid=(b+l)/2;
        if(a[mid]<s)
            b=mid+1;
        else {
            l=mid-1;
        }
    }

 return mid;
}

}

int bsearch2(int *a,int s,int l)
{
    if(s<a[0])
        return -1;
    else {
    int i,mid,b=0;
    while(b<=l)
    {
        mid=(b+l)/2;
        if(a[mid]<=s)
            b=mid+1;
        else {
            l=mid-1;
        }
    }

 return mid;
    }
}
