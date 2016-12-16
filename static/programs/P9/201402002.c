#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int data[1000000];

struct begin{
    int weight;
    int index;
    int size;
};

int compare(const void *ele1, const void *ele2)
{
    struct begin *A=*(struct begin **)ele1;
    struct begin *B=*(struct begin **)ele2;
    return A->weight - B->weight;
}

int main()
{
    int n,MOD,m,i=0,j=0;
    scanf("%d %d",&n ,&MOD);

    struct begin *arr[n];
    int IN=0;
    for(i=0;i<n;i++)
    {
        arr[i]=(struct begin*)malloc(sizeof(struct begin));

        scanf("%d",&m);
        arr[i]->size=m;
        arr[i]->index=IN;

        int w=0;
        for(j=0;j<m;j++)
        {
            scanf("%d",&data[IN]);
            w=(w+data[IN])%MOD;
            IN++;
        }
        arr[i]->weight=w;
    }
    qsort(arr,n,sizeof(arr[0]),compare);

    for (i=0;i<n;i++)
    {
        printf("%d\n",arr[i]->weight);
        int k,another;
        for(k=arr[i]->index,another=0 ; another<arr[i]->size ; another++,k++)
            printf("%d\n",data[k]);
        printf("\n");
    }

    return 0;
}
