#include<stdio.h>
#include<stdlib.h>

struct node{
    int vertex;
    struct node *next;
};

struct edge{
    int A;
    int B;
    int weight;
};

int compa(const void * A, const void * B)
{
    return (((struct edge*)A)->weight - ((struct edge*)B)->weight);
}

struct node* insert_node(struct node *root, int data)
{
    if(root==NULL)
    {
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->vertex = data;
        temp->next=NULL;
        return temp;
    }
    else
    {
        root->next = insert_node(root->next,data);
        return root;
    }
}

int CParent(int v, int cp[])
{
    if(cp[v]==v)
        return v;
    cp[v]=CParent(cp[v], cp);
    return cp[v];
}

int main()
{
    int v,e,i=0;
    scanf("%d %d",&v ,&e);
    int cp[v+2];    // component parent
    int csize[v+2];
    struct node *comp[v+1];
    struct edge a[e];
    long long int sum=0;

    for(i=1;i<=v;i++)
    {
        csize[i]=1;
        cp[i]=i;
        comp[i]=NULL;
        comp[i]=insert_node(comp[i],i);
    }

    for(i=0;i<e;i++)
    {
        int x,y,W;
        scanf("%d %d %d",&x ,&y ,&W);
        (a[i]).A=x;
        (a[i]).B=y;
        (a[i]).weight=W;
    }

    qsort(a, e, sizeof(a[0]), compa);

    int p=0,found=0;
    while(p!=e && found!=(v-1))
    {
        int Cp1=CParent(a[p].A, cp);
        int Cp2=CParent(a[p].B, cp);

        if(Cp1 != Cp2)
        {
            if(csize[Cp1] < csize[Cp2])
                cp[Cp1]=Cp2;
            else
                cp[Cp2]=Cp1;

            sum+=a[p].weight;
            found++;
        }
        p++;
    }

    if(found!=(v-1))
        printf("-1\n");
    else
        printf("%lld\n",sum);
    return 0;
}
