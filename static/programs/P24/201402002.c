#include<stdio.h>
#include<stdlib.h>

int ANS=0;

struct node{
    int key;
    int h;
    int no_of_nodes_left;
    int no_of_nodes_right;
    struct node *l;
    struct node *r;
};

int max_height(struct node *t)
{
    int X=0,Y=0;
    if(t->l !=NULL)
        X=t->l->h;
    if(t->r !=NULL)
        X=t->r->h;
    return ((X<Y)?Y:X) ;
}

struct node* single_rotate(struct node *root)
{
    if (h_diff(root) == 1)
    {
        struct node *t=root->l;
        root->l=t->r;
        t->r=root;
        root->no_of_nodes_left=t->no_of_nodes_right;
        t->no_of_nodes_right+=root->no_of_nodes_right + 1;

        t->r->h=max_height(t->r) + 1;
        t->h = max_height(t) + 1;
        return t;
    }
    else if (h_diff(root) == -1)
    {
        struct node *t=root->r;
        root->r=t->l;
        t->l=root;
        root->no_of_nodes_right=t->no_of_nodes_left;
        t->no_of_nodes_left+=root->no_of_nodes_left + 1;

        t->l->h=max_height(t->l) + 1;
        t->h = max_height(t) + 1;
        return t;
    }
    else if (h_diff(root) > 1)
    {
        struct node *t=root->l;
        root->l=t->r;
        t->r=root;
        root->no_of_nodes_left=t->no_of_nodes_right;
        t->no_of_nodes_right+=root->no_of_nodes_right + 1;
       
        t->r->h=max_height(t->r) + 1;
        t->h = max_height(t) + 1;
        return t;
    }
    else
    {
        struct node *t=root->r;
        root->r=t->l;
        t->l=root;
        root->no_of_nodes_right=t->no_of_nodes_left;
        t->no_of_nodes_left+=root->no_of_nodes_left + 1;

        t->l->h=max_height(t->l) + 1;
        t->h = max_height(t) + 1;
        return t;
    }
}

int h_diff(struct node *root)
{
    if(root==NULL)
        return 0;

    int A=0,B=0;
    if(root->l != NULL)
        A=root->l->h;
    if(root->r != NULL)
        B=root->r->h;
    return A-B;
}

struct node* insert(struct node *root, int data)
{
    if (root==NULL)
    {
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->key=data;
        temp->r=NULL;
        temp->l=NULL;
        temp->no_of_nodes_left=0;
        temp->no_of_nodes_right=0;
        temp->h=1;
        return temp;
    }
    else if (root->key < data)
    {
        root->r=insert(root->r,data);
        root->no_of_nodes_right++;
        int P=0;
        if(root->l != NULL)
            P=root->l->h;
        root->h = (root->r->h > P)?(root->r->h + 1):(P+1);
        //max_height(root->l,0) - max_height(root->r,0);
        //cout<<"root's h = "<<root->h<<endl;

        if (h_diff(root) > 1 || h_diff(root) < -1)
        {
            //  cout<<"If Executed:Balancing...(1)"<<endl;
            if (h_diff(root) > 1)
            {
                // Left is bigger

                if (h_diff(root->l)>0)
                    root=single_rotate(root);
                else
                {
                    //        cout<<"If Executed:Double-Balancing...(1)"<<endl;
                    root->l=single_rotate(root->l);
                    root=single_rotate(root);
                    //         cout<<"PREORDER: ";
                    //print_preorder(root);
                    //         cout<<endl;
                }
            }
            else if (h_diff(root) < -1)
            {
                // Right is bigger

                if (h_diff(root->r) < 0)
                    root=single_rotate(root);
                else
                {
                    //       cout<<"If Executed:Double-Balancing...(2)"<<endl;
                    root->r=single_rotate(root->r);
                    root=single_rotate(root);
                    //      cout<<"PREORDER: ";
                    //print_preorder(root);
                    //      cout<<endl;
                }
            }
        }
        return root;
    }
    else
    {

        root->l=insert(root->l,data);
        root->no_of_nodes_left++;
        int P=0;
        if(root->r != NULL)
            P=root->r->h;
        root->h = (root->l->h > P)?(root->l->h + 1):(P + 1);
        //root->h=max_height(root->l,0) - max_height(root->r,0);
        //   cout<<"root's h = "<<root->h<<endl;
        if (h_diff(root) > 1 || h_diff(root) < -1)
        {
            //     cout<<"If Executed:Balancing...(1)"<<endl;
            if (h_diff(root) > 1)
            {
                // Left is bigger

                if (h_diff(root->l) > 0)
                    root=single_rotate(root);
                else
                {
                    //         cout<<"If Executed:Double-Balancing...(1)"<<endl;
                    root->l=single_rotate(root->l);
                    root=single_rotate(root);
                    //           cout<<"PREORDER: ";
                    //print_preorder(root);
                    //           cout<<endl;
                }
            }
            else if (h_diff(root) < -1)
            {
                // Right is bigger

                if (h_diff(root->r) < 0)
                    root=single_rotate(root);
                else
                {
                    //      cout<<"If Executed:Double-Balancing...(2)"<<endl;
                    root->r=single_rotate(root->r);
                    root=single_rotate(root);
                    //       cout<<"PREORDER: ";
                    //print_preorder(root);
                    //        cout<<endl;
                }
            }
        }
        return root;

    }
}

void print_tree(struct node *root)
{
    printf("%d(%d, %d, h=%d)",root->key, root->no_of_nodes_left, root->no_of_nodes_right, root->h);
    printf(" -> ");
    if(root->l!=NULL)
        printf("%d, ",root->l->key);
    if(root->r!=NULL)
        printf("%d",root->r->key);
    printf("\n");

    //    if(root->l!=NULL && root!=NULL)
    //        printf("Parent of %d = %d\n",root->l->key, root->key);
    //    if(root->r!=NULL && root!=NULL)
    //        printf("Parent of %d = %d\n",root->r->key, root->key);

    if(root->l!=NULL)
        print_tree(root->l);
    if(root->r!=NULL)
        print_tree(root->r);

}

void find(struct node *root, int data)
{
    while(root!=NULL)
    {
        if (root->key == data)
        {
            printf("YES\n");
            return;
        }
        if (root->key < data)
            root=root->r;
        else
            root=root->l;
    }
    printf("NO\n");
    return;
}

void printXth(struct node *root, int X)
{
    if(root==NULL)
        return;

    int NODES_LEFT = root->no_of_nodes_left;
    if( NODES_LEFT + 1 == X)
    {
        printf("%d\n",root->key);
        return;
    }
    else if( NODES_LEFT + 1 < X )
    {
        printXth(root->r, X-NODES_LEFT-1);
        return;
    }
    else if( NODES_LEFT + 1 > X )
    {
        printXth(root->l, X);
        return;
    }
}

void print_elements_on_left(struct node *root, int data)
{
    if(root==NULL)
        return;

    if(root->key == data)
    {
        ANS+=root->no_of_nodes_left;
        return;
    }
    else if(root->key < data)
    {
        ANS+=root->no_of_nodes_left;
        ANS+=1;
        print_elements_on_left(root->r,data);
    }
    else if(root->key > data)
        print_elements_on_left(root->l,data);
}

int main()
{
    int data;
   // long long int count=0;
    struct node *root=NULL;

    char s[100];
    while(1)
    {
 //       count++;
//        printf("count=%lld\n",count);
        scanf("%s",s);
        if (!strcmp(s,"SetHealthy"))
        {
            scanf("%d",&data);
            root=insert(root,data);
  //          print_tree(root);
        }
        else if (!strcmp(s,"CheckHealthy"))
        {
            scanf("%d",&data);
            find(root,data);
        }
        else if (!strcmp(s,"Healthy"))
        {
            scanf("%d",&data);
            if(root==NULL || (root->no_of_nodes_left + root->no_of_nodes_right + 1) < data)
                printf("NONE\n");
            else
                printXth(root,data);
        }
        else if(!strcmp(s,"RottenBefore"))
        {
            scanf("%d",&data);
            ANS=0;
            print_elements_on_left(root,data);
            printf("%d\n",ANS);
        }
        else if(!strcmp(s,"Quit"))
            break;
        else
            printf("PROBLEM\n");

//        printf("#################################### %d\n",count);
    }

    return 0;
}
