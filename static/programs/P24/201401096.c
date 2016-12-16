#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int key;
    int sum;
    struct node *lt,*rt;
    int ht;
}node;

int count,el;

int getht(node *root)
{
    if(root==NULL)
        return 0;
    else
        return root->ht;
}
int getsum(node *root)
{
    if(root==NULL)
        return 0;
    else
        return root->sum;
}
int getbf(node *root)
{ int bf;
    if(root==NULL)
        bf=0;
    else
        bf=getht(root->lt)-getht(root->rt);

    return bf;
}
node * getmin(node *root)
{
    node* cur=root;
    while(cur->lt!=NULL)
    {        
        cur=cur->lt;
    }

    return cur;
}


int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
node * newnode(int key)
{
    node * ptr=(node*)malloc(sizeof(node));
    ptr->key=key;
    	ptr->lt=ptr->rt=NULL;
    	ptr->ht=1;//new node @leaf always
   	 ptr->sum=1;
    return ptr;
}
node* rotatert(node *root)
{
    node *q=root;
    node *p=q->lt;
    node *t2=p->rt;
    p->rt=q;
    q->lt=t2;

    q->ht=max(getht(q->lt),getht(q->rt))+1;
    
q->sum=getsum(q->lt)+getsum(q->rt)+1;
    
p->ht=max(getht(p->lt),getht(p->rt))+1;
    p->sum=getsum(p->lt)+getsum(p->rt)+1;

    return p;//ptr to new root
}
node* rotatelt(node *root)
{   
    node *p=root;
    node *q=p->rt;
    node *t2=q->lt;
    q->lt=p;
    p->rt=t2;

    p->ht=max(getht(p->lt),getht(p->rt))+1;
    	p->sum=getsum(p->lt)+getsum(p->rt)+1;
    q->ht=max(getht(q->lt),getht(q->rt))+1;
    q->sum=getsum(q->lt)+getsum(q->rt)+1;

    return q;//ptr to new root
}

node* insert(node *root,int key)
{
    /* 1. Normal BST insertion*/
    if(root==NULL)
        return newnode(key);

    if(key< root->key)
        	root->lt=insert(root->lt,key);
    else
        root->rt=insert(root->rt,key);

    /*2. Update ht of this bloody ancestor :D*/

    int hl,hr;


    	hl=getht(root->lt);
    hr=getht(root->rt);
    	root->ht=max(hl,hr)+1;
    root->sum=getsum(root->lt)+getsum(root->rt)+1; 
    /*3. Calculate balance factor of this ancestor */

    int bf=getbf(root);

    /*4. Determine case*/
    //why -1,1 coz diff can be 0,1,-1 and not exceeding these..
    //lt lt
    if(bf>1 && key<root->lt->key)
        return rotatert(root);
    //rt rt
    if(bf<-1 && key>root->rt->key)
        return rotatelt(root);
    //lt rt
    if(bf>1 && key>root->lt->key)
    {
        root->lt=rotatelt(root->lt);
        return rotatert(root);
    }
    //rt lt
    if(bf<-1 && key<root->rt->key)
    {
        root->rt=rotatert(root->rt);
        return rotatelt(root);
    }
    //return unchanged root
    return root;
}
node* delete(node *root,int key)
{
    /* 1. Normal BST deletion*/
    if(root==NULL)
        return root;
    if(key < root->key)
        		root->lt=delete(root->lt,key);
    else if(key>root->key)
        root->rt=delete(root->rt,key);
    else
        
        if(key==root->key)

        {
            //a-no child
            if (root->lt==NULL&&root->rt==NULL)
            {
                node *temp=root;
                root=NULL;
                free (temp);
            }

            //single child
            else
                if(root->lt==NULL||root->rt==NULL)
                {
                    if(root->lt==NULL)
                        {
                            //only rt child

                            node *temp=root->rt;
                            *root=*temp;
        	                    free(temp);
	
                        }
                        else 
                            if(root->rt==NULL)
                            {
                                //only lt child
                                node *temp=root->lt;
                                *root=*temp;
                                free(temp);

                            }


                }//single child

            else 
                    // 2 children
                {
                    node *temp=getmin(root->rt);
                    root->key=temp->key;
                    root->rt=delete(root->rt,temp->key);   

                }

        }

    //if tree is empty after deletion,return back
    if (root == NULL)
        return root;

    /*2. Update ht of this bloody ancestor :D*/

    int hl,hr;


    hl=getht(root->lt);
    	hr=getht(root->rt);
    root->ht=max(hl,hr)+1;
    root->sum=getsum(root->lt)+getsum(root->rt)+1; 

    /*3. Calculate balance factor of this ancestor */

    int bf=getbf(root);

    /*4. Determine case*/
    //why -1,1 coz diff can be 0,1,-1 and not exceeding these..
    //lt lt
    if(bf>1 && getbf(root->lt)>=0)//remember if bf(y)=0,then it becomes a single rotation case 
        return rotatert(root);
    //rt rt
    if(bf<-1 && getbf(root->rt)<=0)
     	   return rotatelt(root);
    //lt rt
    if(bf>1 && getbf(root->lt)<0)
    {
        root->lt=rotatelt(root->lt);
     	   return rotatert(root);
    }
    //rt lt
    if(bf<-1 && getbf(root->rt)>0)
    {
        root->rt=rotatert(root->rt);
        return rotatelt(root);
    }

    //return unchanged root
    return root;
}

node* search(node *root,int key)
{	
    if (root==NULL)
        return NULL;
    if(root->key<key)
        return search(root->rt,key);
    if(root->key>key)
     	   return search(root->lt,key);
    else
        return root;
}

/*void inorder(node * root)
{
    if (root==NULL)
        return;
    if(root->lt)
     		   preorder(root->lt);
    if(root->data==el)
        return;
    else
        count++;
    if(root->rt)
     	   preorder(root->rt);

}
*/
int val_at_kth(node* root,int idx)
{
    if(!root)
        return 0;
    int ltsize=getsum(root->lt);
    if(ltsize==idx)
     		   return root->key;
    else if(ltsize>idx)
     	   return val_at_kth(root->lt,idx);
    else
        return val_at_kth(root->rt,idx-ltsize-1);

}

int less_than_x(node * root,int el)
{
    if(!root)
        return 0;//key doesn't exist or a leaf is encountered
//since its less than we are only concerned with the lt subtrees
    //function accounts for count as well binary search
    if(el<root->key)
        return less_than_x(root->lt,el);
    if(el==root->key)
    {
        if(root->lt!=NULL)
            return getsum(root->lt)+1;

        else
            return 1;

    }
    if(el>root->key)
    {
        if(root->lt!=NULL)
            return getsum(root->lt)+1+less_than_x(root->rt,el);
        else
            return 1+less_than_x(root->rt,el);

    }

}
int main()
{
    char ch,ch2;
    char str[100];
    int data,test,ans;
    node *myroot=NULL;int temp;

    while(1)
    {
        //printf("%d===\n ",test);
        scanf("%s%d",str,&data);getchar();
        
        switch(str[0])
        {
            case 'S':
                if(!search(myroot,data))
                myroot=insert(myroot,data);//no duplicates
                break;
            case 'R':
                     ans=less_than_x(myroot,data);
                     if(search(myroot,data))
                     printf("%d\n",ans-1);
                     else
                     printf("%d\n",ans);
                     break;
            case 'C':
                    if(search(myroot,data))
                     printf("YES\n");
                    else
                     printf("NO\n");
                        break;
            case 'H':
                     data--;
                     temp=val_at_kth(myroot,data);
                     if(myroot==NULL)
                         printf("NONE\n");
                     else if(myroot->sum<=data)
                         printf("NONE\n");
                     else
                         printf("%d\n",temp);
                     break;
        }

        if(str[0]=='Q')
            break;

        
    }
    return 0;
}
