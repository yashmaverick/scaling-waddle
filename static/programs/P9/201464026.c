#include<stdio.h>
#include<stdlib.h>
typedef struct arr
{
    int w;
    int m;
    int *a;
}arr;
int cmpfunc(const void *a,const void *b)
{
    arr *x,*y;
    x = (arr *)a;
    y = (arr *)b;
    return (x->w > y->w);
}
int main()
{
    int n,MOD,i;
    scanf("%d %d",&n,&MOD);
    arr *array;
    array = (arr *)malloc(sizeof(arr)*n);
    for(i=0;i<n;i++)
    {
        int j;
        scanf("%d",&array[i].m);
        array[i].a = (int *) malloc(4*array[i].m);
        array[i].w = 0;
        for(j=0;j<array[i].m;j++)
        {
            scanf("%d",&array[i].a[j]);
            array[i].w = (array[i].w + array[i].a[j])%MOD;
        }
    }
    qsort(array,n,sizeof(arr),cmpfunc);
    for(i=0;i<n;i++)
    {
        int j;
        printf("%d\n",array[i].w);
        for(j=0;j<array[i].m;j++)
            printf("%d\n",array[i].a[j]);
        putchar('\n');
    }
    return 0;
}
