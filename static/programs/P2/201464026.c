#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        //Scan all arrays
        int p,q,r,i,j;
        scanf("%d",&p);
        int *a = (int *)malloc(4*p);
        for(i=0;i<p;i++)
            scanf("%d",&a[i]);
        scanf("%d",&q);
        int *b = (int *)malloc(4*q);
        for(i=0;i<q;i++)
            scanf("%d",&b[i]);
        scanf("%d",&r);
        int *c = (int *)malloc(4*r);
        for(i=0;i<r;i++)
            scanf("%d",&c[i]);
        //Scanned all arrays;
        //Now start..
        long long int count=0,sum = 0;
        int *bcopy = (int *)malloc(4*q);
        i=0;j=0;
        while(i<q)
        {
            if(b[i]>=a[j] && i>=j && j<p)
            {
                count++;
                j++;
            }
            else
            {
                bcopy[i] = count;
                i++;
            }
        }
        //Right till here
        count=0;
        i=0;
        j=0;
        while(i<r)
        {
            if(c[i]>=b[j] && i>=j && j<q) 
            {
                count+=bcopy[j];
                j++;
            }
            else
            {
                sum += count;
                i++;
            }
        }
        printf("%lld\n",sum);
        //Done counting..
        //Now free the malloc
        free(a);
        free(b);
        free(c);
        free(bcopy);
    }
    return 0;
}
