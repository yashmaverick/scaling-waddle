
/*
_____________________________________________

PURPOSE : 

		created by -ABHINAV AGGARWAL
_____________________________________________ 

*/

#include <stdio.h>
#include <stdlib.h>


/*struct node 
{
    int d;
    struct node *next;
};*/

//typedef struct node WEIGHT;

struct bag
{
    int m;
    int total;
    int *head;
};

typedef struct bag BAG;

BAG *bags[1005];

int cmp(const void *a,const void *b)
{
    return (*(BAG **)a)->total-(*(BAG **)b)->total;
}

int main()
{
    int n,mod;
    scanf("%d%d",&n,&mod);

    int i,j;
    for(i=0;i<n;i++)
    {
        bags[i]=(BAG *)malloc(sizeof(BAG));
        scanf("%d",&bags[i]->m);
        
        bags[i]->head=(int *)malloc(bags[i]->m*sizeof(int));

        scanf("%d",&bags[i]->head[0]);
        bags[i]->total=(bags[i]->head[0])%mod;

        for(j=1;j<bags[i]->m;j++)
        {
            scanf("%d",&bags[i]->head[j]);
            bags[i]->total=(bags[i]->total+(bags[i]->head[j])%mod)%mod;
        }
    }


    qsort(bags,n,sizeof(BAG *),cmp);
    for(i=0;i<n;i++)
    {
        printf("%d\n",bags[i]->total);
        for(j=0;j<bags[i]->m;j++)
        {
            printf("%d\n",bags[i]->head[j]);
        }
       printf("\n");
    }

  //  printf("bag:%lu\n",sizeof(BAG));

    


return 0;
}
