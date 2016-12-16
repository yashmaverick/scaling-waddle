#include<stdio.h>
#include<stdlib.h>

#define maxN 1000005

typedef struct abd
{
    int rank,m,weight;
}abd;

int cmpfunc(const void *p1, const void *p2)
{
    const struct abd *a=p1;
    const struct abd *b=p2;
    if(a->weight!=b->weight)
        return ( a->weight - b->weight);
    return ( a->rank - b->rank);
}

int arr[maxN],arr1[maxN];

int main()
{
    int n;
    int MOD;
    scanf("%d %d",&n,&MOD);
    abd *abc=(abd*)malloc(n*sizeof(abd));
    int i;
    for(i=0;i<n;i++)
    {
        //printf("%d %d\n",i,arr1[i]);
        abc[i].rank=i;
        int m;
        abc[i].weight=0;
        scanf("%d",&m);
        abc[i].m=m;
        if (i!=n-1 && i!=0)
            arr1[i+1]=arr1[i]+m; 
        if (i==0)
        {
            arr1[i]=0;
            arr1[i+1]=m;
        }
        int j;
        for(j=0;j<abc[i].m;j++)
        {
            scanf("%d",&arr[j+arr1[abc[i].rank]]);
            abc[i].weight=(abc[i].weight+arr[j+arr1[i]])%MOD;
        }
    }   
    qsort(abc,n,sizeof(abd),cmpfunc); 
    for(i=0;i<n;i++)
    {
        printf("%d\n",abc[i].weight);
        int j;
        for(j=0;j<abc[i].m;j++)
        {
            printf("%d\n",arr[j+arr1[abc[i].rank]]);
        }
        printf("\n");
    } 
    return (0);
}
