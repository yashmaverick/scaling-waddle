#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000000

typedef long long int ll;

typedef struct trie_node
{
    struct trie_node *child[10];
    ll end; // flag to denote the end of a word/string/number in the string
}node;

typedef struct trie
{
    node *root;
}trie;

//trie *t; // Declaring a new "trie". Note that the root is just a node present for holding the trie as it is.
//t->root=create();
//t->count=0;

//ll consecutive[1000000];
//memset(consecutive,0,10);
void merge(ll* left,ll* right,ll* a,ll n);

void msort(ll* a,ll  n)
{

    if(n==1)
        return;

    ll* left=(long long int*)malloc((n/2)*sizeof(long long int));//free the temporary arrays that have been declared dynamically
    ll* right=(long long int*)malloc((n-n/2)*sizeof(long long int));
    ll i,x=0;

    for(i=0;i<n/2;i++)
    {
        left[i]=a[x];
        x++;
    }

   /* printf("\n");

    for(i=0;i<n/2;i++)
        printf("%d ",left[i]);*/
    
    for(i=0;i<n-n/2;i++)
    {
        right[i]=a[x];
        x++;
    }
/*
    printf("\n");
    for(i=0;i<n-n/2;i++)
        printf("%d ",right[i]);
    printf("\n");*/

    msort(left,n/2);
    msort(right,n-n/2);


    merge(left,right,a,n);
}

void merge(ll* left,ll* right,ll* a,ll n)
{
    ll l,x,r;
    l=r=x=0;

    while(l<(n/2) && r<(n-n/2))
    {
        if(left[l]<=right[r])
        {
            a[x]=left[l];
            l++;
            x++;
        }
        else
        {
            a[x]=right[r];
            x++;
            r++;
        }
    }

    if(l==n/2)
        while(r<(n-n/2))
        {
            a[x]=right[r];
            x++;
            r++;
        }
    else
        while(l<(n/2))
        {
            a[x]=left[l];
            x++;
            l++;
        }
/*
    printf("\nmerge: ");;

    for(i=0;i<x;i++)
        printf("%d ",a[i]);
    printf("\n");*/
}

ll no=0;

void create_trie(trie *);
void insert(trie *, char *);
node* create();
//void create_node(node *);

void insert(trie *t, char *key)
{
    node *temp;
    ll length=strlen(key), i;

    temp=t->root;

    ll position;

    /*
    for(i=0;i<10;i++)
    {
        if(i==(key[0]-'0'))
        {
            if(t->root->child[i]!=NULL)
            {
                no=1;
            }
        }
    }
    */

    for(i=0;i<length;i++)
    {
        position=key[i] - '0';

        /*
           if(i==0)
           {
           consecutive[position]++;
           }
           */
        
        /*
        if((i+1==length) && temp->end==1)
        {
            no=1;
        }
        */

        if(temp->child[position]==NULL)
        {
            temp->child[position]=create();
            /*
               node *newnode;

               newnode=(node *)malloc(sizeof(node));

               newnode->end=0;

               for(i=0;i<10;i++)
               {
               newnode->child[i]=NULL;
               }

               temp->child[position]=newnode;
               */
            //create_node(temp->child[position]);
        }
        if(temp->end==1)
        {
            no=1;
        }

        temp=temp->child[position];
    }

    //t->count++;
    if(i==length && temp->end==1)
        no=1;    

    temp->end=1;

    for(i=0;i<10;i++)
    {
        if(temp->child[i]!=NULL)
            no=1;
    }
}


int main()
{
    ll test,n;
    char number[11];
    //char *consecutive[1000000];
    //int flag=0;

    //trie t;

    //create_trie(&t);

    trie *create_trie;
    scanf("%lld",&test);

    ll i;

    while(test-->0)
    {
        trie t;
        create_trie=&t;
        //create_node(create_trie->root);
        create_trie->root=create();
        /*
           node *newnode;

           newnode=(node *)malloc(sizeof(node));

           newnode->end=0;

           for(i=0;i<10;i++)
           {
           newnode->child[i]=NULL;
           }

           create_trie->root=newnode;
           */

        //free newnode;

        //create_trie(&t);

        no=0;
        //flag=0;

        /*
        for(i=0;i<1000000;i++)
        {
            consecutive[i]=0;
        }
        */

        scanf("%lld",&n);

        ll x=0;
        //i=0;

        while(n-->0)
        {
            scanf("%s",number);
            //consecutive[i]=(atoi(number)-'0');
            //printf("%lld\n",consecutive[i]);
            //consecutive[x]=number;
            x++;

            insert(&t, number);
        }

        /*
           for(i=0;i>10;i++)
           {
           if(consecutive[i]>1)
           {
           flag=1;
           }
           }
           */

        //if(flag==1)

	//msort(consecutive,n);
    //printf("\n");

    /*
    for(i=0;i<n;i++)
        printf("%lld ",consecutive[i]);

    printf("\n");
    */

        /*
        for(i=0;i<x;i++)
            printf("%s\n",consecutive[i]);
        */

         if(no==1)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}
 


node* create()
{
    ll i;
    node *newnode;

    newnode=(node *)malloc(sizeof(node));

    newnode->end=0;

    for(i=0;i<10;i++)
    {
        newnode->child[i]=NULL;
    }

    return newnode;
}

/*
void create_node(node* newnode)
{
    ll i;

    newnode=(node *)malloc(sizeof(node));

    newnode->end=0;

    for(i=0;i<10;i++)
    {
        newnode->child[i]=NULL;
    }
}
*/

