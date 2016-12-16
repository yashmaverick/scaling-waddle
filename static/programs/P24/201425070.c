#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node*  left;
    struct node*  right;
    int lefth;
    int righth;
    int height;
} node;

node* find( int e, node *t );
node* find_max( node *t );
node* insert( int data, node *t );
node* delete( int data, node *t );
void display_avl(node* t);
int get( node* n );
void updateheight(node* t);

void updateleft(node *t)
{
    int lc , rc;
    if(t->left == NULL)
    {
        t->lefth = 0;
        return;
    }

    if(t->left->left == NULL)
        lc = 0;
    else
        lc = t->left->lefth;

    if(t->left->right == NULL)
        rc = 0;
    else
        rc = t->left->righth;

    t->lefth = lc + rc + 1;
}

void updateright(node *t)
{
    int lc , rc;
    if(t->right == NULL)
    {
        t->righth = 0;
        return;
    }

    if(t->right->left == NULL)
        lc = 0;
    else
        lc = t->right->lefth;

    if(t->right->right == NULL)
        rc = 0;
    else
        rc = t->right->righth;

    t->righth = lc + rc + 1;
}

node* find(int e, node* t )
{
    if( t == NULL )
        return NULL;
    if( e < t->data )
        return find( e, t->left );
    else if( e > t->data )
        return find( e, t->right );
    else
        return t;
}

node* find_max( node* t )
{
    if( t != NULL )
        while( t->right != NULL )
            t = t->right;

    return t;
}

int height( node* n )
{
    if( n == NULL )
        return -1;
    else
        return n->height;
}

int max( int l, int r)
{
    return l > r ? l: r;
}

node *makeNode(int e)
{
    node *t;
    t = (node *)malloc(sizeof(node));
    t->data = e;
    t->lefth = 0;
    t->righth = 0;
    t->height = 0;
    t->left = t->right = NULL;
    return t;
}
node* left_rotate( node* k2 )
{
    node* k1 = NULL;

    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
    k1->height = max( height( k1->left ), k2->height ) + 1;

    updateleft(k2);
    updateright(k2);
    updateleft(k1);
    updateright(k1);
    return k1; /* new root */
}

node* right_rotate( node* k1 )
{
    node* k2;

    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
    k2->height = max( height( k2->right ), k1->height ) + 1;

    updateleft(k1);
    updateright(k1);
    updateleft(k2);
    updateright(k2);
    return k2;  /* New root */
}

node* left_right_rotate( node* k3 )
{
    k3->left = right_rotate( k3->left );

    return left_rotate( k3 );
}

node* right_left_rotate( node* k1 )
{
    k1->right = left_rotate( k1->right );

    return right_rotate( k1 );
}

node* insert(int e, node* t )
{
    if( t == NULL )
    {
        t = makeNode(e);
    }

    else if( e < t->data )
    {
        t->left = insert( e, t->left );
        if( height( t->left ) - height( t->right ) == 2 )
            if( e < t->left->data )
                t = left_rotate( t );
            else
                t = left_right_rotate( t );
    }

    else if( e > t->data )
    {
        t->right = insert( e, t->right );
        if( height( t->right ) - height( t->left ) == 2 )
            if( e > t->right->data )
                t = right_rotate( t );
            else
                t = right_left_rotate( t );
    }

    t->height = max( height( t->left ), height( t->right ) ) + 1;
    updateleft(t);
    updateright(t);
    return t;
}

int get(node* n)
{
    return n->data;
}

void display_avl(node* t)
{
    if (t == NULL)
        return;
    printf("%d",t->data);

    if(t->left != NULL)
        printf("(L:%d)",t->left->data);
    if(t->right != NULL)
        printf("(R:%d)",t->right->data);
    printf("\n");

    display_avl(t->left);
    display_avl(t->right);
}

printinorder(node *t)
{
    if(t==NULL)
        return;
    printf("%d , Left : %d , Right : %d\n",t->data,t->lefth,t->righth);
    printinorder(t->left);
    printinorder(t->right);
}
int found;

void checkhealthy(node *t , int x)
{
    if(t == NULL)
        return;
    
    if(t->data == x)
        found = 1;

    else if(t->data < x)
       checkhealthy(t->right , x);
    else
       checkhealthy(t->left , x);
}

int final;

int healthy(node *t , int k)
{
    if(t==NULL)
        return;

    if(t->lefth == k)
        final = t->data;
    
    if(t->lefth > k)
        healthy(t->left , k);
    else
    {
        healthy(t->right , k-t->lefth-1);
    }
}

void rottenbefore(node *t , int x)
{
    if(t == NULL)
    {
        //final = -1;
        return;
    }
    
    if(t->data == x)
        final = final + t->lefth;

    else if(t->data < x)
    {
        final = final + t->lefth+1;
        rottenbefore(t->right , x);
    }
    else
       rottenbefore(t->left , x);
}
int main()
{
    node *t , *p;
    int i , x;
    int j = 0;
    int l;
    t = NULL;
    char input[100];
    int nodes,key;
    while(1)
    {
        found = final = 0;
        scanf("%s" , input);
        if(input[0] == 'S')
        {
            scanf("%d",&key);
            t = insert(key , t);
        }
        else if (input[0] == 'C')
        {
            scanf("%d",&key);
            checkhealthy(t , key);
            if(found == 1)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else if(input[0] == 'H')
        {
            scanf("%d",&key);
            healthy( t , key - 1);
            if(final == 0)
                printf("NONE\n");
            else
                printf("%d\n",final);
        }
        else if(input[0] == 'R')
        {
            scanf("%d",&key);
            rottenbefore(t , key);
            printf("%d\n",final);
        }
        else if(input[0] == 'Q')
            break;
    }
    return 0;
}
/*
    }
    int nodes;
    
    scanf("%d",&nodes);
    
    for(i=0;i<nodes;i++)
    {
        scanf("%d",&x);
        t = insert(x,t);
        printinorder(t);
        printf("\n\n");
    }
        printinorder(t);

    scanf("%d",&nodes);
    for(i=0;i<nodes;i++)
    {
        found = 0;
        scanf("%d",&x);
        checkhealthy(t , x);
        printf("%d\n",found);
    }
    
    final = 0;
    scanf("%d",&nodes);
    healthy(t , nodes-1);
    printf("%d\n",final);
    final = 0;
    scanf("%d",&nodes);
    rottenbefore(t , nodes);
    printf("%d\n",final);

    return 0;
}
*/
