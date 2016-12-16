#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long int count=0;
long long int maxcount=0;
long long  int min=100001;
int zz;
long long int deepestnode(long long int post[],long long int l,long long int m)
{

//    printf("%lld-count %lld-start %lld-end\n",count,post[l],post[m]);
    long long int j;

    if(l==m && count<maxcount)
    {count=0;return min;}
    if(l==m && count>maxcount)
    {//printf("%d %d\n",maxcount,count);
        maxcount=count;
        // printf("%d %d\n",maxcount,count);
        min=post[m];
        count=0;

        return min ;
    }
    if(l==m && count==maxcount && post[m]<=min)
    {
        //  printf("%d %d\n",maxcount,count);
        maxcount=count;
        //  printf("%d %d\n",maxcount,count);
        min=post[m];
        count=0;

        return min ;
    }

  //  if(m<=0)
  //      return;
    long long int last=m-1;
    long long int first=l;
    long long int middle=(first+last)/2;
    while( first <= last )
    {
        if ( post[middle] < post[m] )
            first = middle + 1;    
        else if ( post[middle] == post[m] ) 
        {
            printf("%lld found at location %lld.\n", post[m], middle+1);
            break;
        }
        else
            last = middle - 1;

        middle = (first + last)/2;
    }
    if ( first > last )
        j=last;
//    printf("%lld-left sub point\n",j);




   /*     for(j=m-1;j>=l;j--)
          {
          if(post[m]>post[j])
          {
          break;
          }
          }*/
  //     printf("%lld--left sub position\n",post[j]);   

     int   trackcount=count;
    if( j+1<=m-1)
    {
        //   printf("%d %d\n",maxcount,count);
        count++;
        min=deepestnode(post,j+1,m-1);
    }
    count=trackcount;
    if(l<=j)
    {//printf("%d %d\n",maxcount,count);
        count++;
        min=deepestnode(post,l,j);
    }
    trackcount=0;
/*    if( j+1<=m-1)
    {
        //   printf("%d %d\n",maxcount,count);
        count++;
        deepestnode(post,j+1,m-1);
    }*/

    return min;

}




int main()
{
    long long int post[100000],T,i,j,k,n;
    scanf("%lld",&T);
    while(T--)
    {  maxcount=0;
        count=0;
        min=100001;
        scanf("%lld",&n);
        zz=n-1;
        for(i=0;i<n;i++)
            scanf("%lld",&post[i]);
        k= deepestnode(post,0,n-1);
        printf("%lld %lld\n",k,maxcount);
    }



    return 0;
}
