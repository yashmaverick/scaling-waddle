
/*
   _____________________________________________

PURPOSE : 

created by -ABHINAV AGGARWAL
_____________________________________________ 

*/

#include <stdio.h>

long long int less_eq(long long int *A,long long int n,long long int l,long long int h)
  {
  long long int mid;

  while(l<h)
  {
  mid=l+(h-l)/2;
  
  if(l==h-1)
  {
      if(A[h]<=n)
          return h;
      else if(A[l]<=n)
          return l;
      else return -1;
  }

  if(A[mid]<=n)
  l=mid;
  else if(A[mid]>n)
  h=mid-1;
  }
   
  if(A[l]<=n)
  return l;
  else return -1;
  
  }


 long long int great_eq(long long int *A,long long int n,long long int l,long long int h)
  {
  long long int mid;

  while(l<h)
  {
  mid=l+(h-l)/2;

  if(l==h-1)
  {
      if(A[l]>=n)
          return l;
      else if(A[h]>=n)
          return h;
      else return -1;
  }
  if(A[mid]>=n)
  h=mid;
  else
  l=mid+1;
  }
  if(A[l]>=n)
  return l;
  else return -1;
  
  }


long long int P[100001],Q[100001],R[100001];
int main()
{
    long long int t,i,j,k;
    long long count_p,count_r,count,less,more;
    scanf("%lld",&t);
    long long int p,q,r;
    int np,nr;

    while(t--)
    {
        count_p=count_r=count=0;
        scanf("%lld",&p);
        for(i=0;i<p;i++)
        {
            scanf("%lld",&P[i]);
        }

        scanf("%lld",&q);
        for(i=0;i<q;i++)
        {
            scanf("%lld",&Q[i]);
        }

        scanf("%lld",&r);
        for(i=0;i<r;i++)
        {
            scanf("%lld",&R[i]);
        }

       /* j=0;
        i=0;
        while(P[0]>Q[j] && j<q)
            j++;
        if(j==q)
        {
            printf("0\n");
            continue;
        }
        k=j;
        */

      /*  for(;j<q;j++)
        {  
            //        printf("J: %d\n",j);
            while(i+1<p && P[i+1]<=Q[j] && (i+1)<=j)
                i++;
            count_p=i+1;

            k=k>j?k:j;
            //   k=j;
            while(k+1<r && R[k+1]<Q[j])
                k++;
            if(R[k]<Q[j])
            {
                if(k+1<r)
                    k++;
                else break;
            }
            //        printf("%d is k\n",k);
            count_r=r-k;

            //      printf("%lld\n",count_p*count_r);

            count=count+count_p*count_r;
        }
        */

      for(j=0;j<q;j++)
      {	
         //printf("j is %lld\n",j);
          if(j<=p-1)
          less= less_eq(P,Q[j],0,j);
          else
              less=less_eq(P,Q[j],0,p-1);
    //      printf("less\n");
         if(j>r-1)
             break;
          more= great_eq(R,Q[j],j,r-1);
  //        printf("more\n");
          count_p=(less>=0?less:-1)+1;
          count_r=r-(more>=0?more:r);
//       printf("%lld %lld\n",count_p,count_r);
          count=count+count_p*count_r;
      }

        printf("%lld\n",count);
    }
    return 0;
}
