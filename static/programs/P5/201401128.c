
/*
_____________________________________________

PURPOSE : 

		created by -ABHINAV AGGARWAL
_____________________________________________ 

*/

#include <stdio.h>

int cmp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int t;
    scanf("%d",&t);

    int n,k,i,j,l,h,m,finish;
    long long sum,req;
    int A[1000005];
    char str[1000];

    while(t--)
    {
        scanf("%d%d",&n,&k);

        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            scanf("%d",&A[i]);
        }
      //  printf("hello\n");
        qsort(A,n,sizeof(int),cmp);

        for(l=0;l<n-2;l++)
       {    
           finish=0;
   //        printf("l is %d\n",l);
            h=n-1;
            m=l+1;
            req=k-A[l];
            while(m<h)
            {   
 //              printf("%lld %d\n",req,A[m]+A[h]);
               if(A[m]+A[h]==req)
               {  
                   printf("YES\n");
                   finish=1;
                   break;
               }
               else if(A[m]+A[h]>req)
                   h--;
               else m++;
               
            }

            if(finish==1)
                break;
        }
        if(finish==0)
            printf("NO\n");
           
    }



return 0;
}
