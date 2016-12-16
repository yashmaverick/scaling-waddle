#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}
int main()
{
    int A[10000];
    int t;
    char st[10000];
    scanf("%d", &t);
    while (t-- )
    {
        int sum = 0,l,h,n,k,i;
      int flag = 0;
      scanf("%d%d", &n, &k);
      for ( i=0; i<n; i++)
      {
          scanf("%s", st);
          scanf("%d", &A[i]);
      }
      qsort(A, n, sizeof(int), cmpfunc);
      //for(i=0;i<n;i++)printf("%d ",A[i]);
      for ( i=0; i<n; i++)
      {
          l = i+1;
          h = n-1;
          while ( l<h )
          {
              sum = A[i] + A[l] + A[h];
              if ( sum>k )
                  h--;
              else if ( sum<k )
                 l++;
              else{ 
                  flag=1;
                  break;
              }
            
            //  printf("YES\n");
          }
          if(flag==1)
              break;
      }

          if (flag==0)
              printf("NO\n");
          else
              printf("YES\n");
    }
    return 0;
}
