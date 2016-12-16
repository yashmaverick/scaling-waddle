#include<stdio.h>
#include<stdlib.h>

int x[1000000];

void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));
int cmpfunc(const void *a, const void *b)
{
	return ( *(int*)a - *(int*)b );
}

/*long long int ncr(long long int n,long long int r)
{
    //long long int i,ncr;

    //return (fact(n)/(fact(n-r)*fact(r)));
    return ((n*(n-1))/r);

}*/


int main()
{
    int i,n,min;
    int t;
    long long int tempcount,count;

    scanf("%d",&t);
    while(t-->0)
    {
        count=0;
        scanf("%d",&n);

        //x=(int *)malloc(n*sizeof(int));

        for(i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
            /*if(x[i]>=x[i-1] && i>=1)
                sort=1;
            else 
                sort=0;*/
        }

        //if(sort==0)
            //quicksort(x,0,n-1);
        qsort(x,n,sizeof(int),cmpfunc);;
//for(i=0;i<n;i++)
  //  printf("%lld  ",x[i]);

        min=0;
        tempcount=0;

        for(i=1;i<n;i++)
         {
             if(x[i]==x[min])
             {
                 if(i==(min+1))
                     tempcount+=2;
                 else 
                     tempcount+=1;
             }
             else
             { 
                 min=i;
                 count+=(tempcount*(tempcount-1))/2;
                 tempcount=0;
             }
         }
       // printf("%lld\n",count);

        if((i==n) && (tempcount>0))
        {
            count+=((tempcount*(tempcount-1))/2);
        }

         printf("%lld\n",count);//ncr(count,2)??

        //free(x);

    }

    return 0;
}
