#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a>b)? a:b)
#define ll long long int
/*1 x insert
 * 2 x find
 * 3 inorder
 * 4 preorder
 * 5 postorder
 * 6. delete
 */
ll stack[1000000];
int top=-1;
int flag=0;
int chocolate;
int count=0;

int binary_search(int l,int h,int key)
{
        if(key<=stack[0])
                return 0;
        else if(key>stack[top])
                return top+1;

        if(l<=h)
        {
                int mid=(l+h)/2;
                if(mid+1<=top&&stack[mid+1]>=key&&stack[mid]<key)
                        return mid+1;
                else if(stack[mid]>key)
                        return binary_search(l,mid-1,key);
                else if(stack[mid]<key)
                        return binary_search(mid+1,h,key);
                else
                        return binary_search(l,mid,key);
        }
        return -1; 
}
struct node
{
        ll data;
        struct node* left;
        struct node* right;
        int height;       
        struct node* parent;
        //int lessnum;
        int child_count;

};
typedef struct node node;
//node* queue[1000000];
//int f=0,r=-1;
//node* stack[1000000];
//int top=0;
node* new_node(ll data)
{
        node* temp=(node* )malloc(sizeof(node));
        temp->data=data;
        temp->right=NULL;
        temp->left=NULL;
        temp->height=1;
        temp->child_count=0;
        
        //temp->rightnum=0;
        //temp->lessnum=0;
        return temp;
}
int height(node* root)
{

        if(!root)
                return 0;
        else
                return root->height;
}
/*int getleftnum(node* root)
{
        if(!root)
                return -1;
        else if(root->left==NULL)
                return 0;
        else return root->leftnum;
}*/
/*int getlessnum(node* root)
{
        if(!root)
                return 0;
        else if(root->left==NULL)
                return 0;
        else return root->lessnum;
}*/
int getchild_count(node* root)
{
        if(!root/*||(!root->left&&!root->right)*/)
                return -1;
        //else if(!root->left&&!root->right)
          //      return 0;
        //else if(!root->left||!root->right)
          //      return 1;       
        else
                return root->child_count;
}
int getvolume(node* root)
{
        if(!root)
                return ;
  //      else
                //return root->volume;
}

int getbalance(node* root)
{
        if(!root)
                return 0;
        else
                return height(root->left)-height(root->right);
}
node* right_rotate(node* root)
{
        node* p=root->left;
        node* q=p->right;
        p->right=root;
        root->left=q;
        root->height=max(height(root->left), height(root->right))+1;
        //p->leftnum=getleftnum(root->left)+1;
        p->height=max(height(p->left), height(p->right))+1;
        //root->leftnum=getleftnum(p->left)+1;
        root->child_count=getchild_count(root->left)+getchild_count(root->right)+2;
        p->child_count=getchild_count(p->left)+getchild_count(p->right)+2;


        //root->volume=getvolume(root->left)+getvolume(root->right)+1;
        //p->volume=getvolume(root->left)+getvolume(root->right)+1;
        return p;
}
node* left_rotate(node* root)
{
        node* p=root->right;
        node* q=p->left;
        p->left=root;
        root->right=q;
        root->height=max(height(root->left), height(root->right))+1;
        root->child_count=getchild_count(root->left)+getchild_count(root->right)+2;
        p->child_count=getchild_count(p->left)+getchild_count(p->right)+2;

        //root->leftnum=getleftnum(root->left)+1;
        //p->leftnum=getleftnum(p->left)+1;
        p->height=max(height(p->left), height(p->right))+1;
        //root->volume=getvolume(root->left)+getvolume(root->right)+1;
        //p->volume=getvolume(root->left)+getvolume(root->right)+1;
        return p;
}
ll sum=0;
int count_less(node* root)
{
        if(root->left==NULL)
                return 0;
        else
        {
                sum=0;
                node* temp=root->left;
                while(temp!=NULL)
                {
                        sum+=count_less(temp->left)+1;
                        temp=temp->right;
                }
                return sum+1;
        }
}
node* insert(node* root, ll key)
{       
        if(!root)
        {                
                root=new_node(key);
        }
        else if(key<root->data)
        {                
                root->left=insert(root->left,key);
                root->left->parent=root;
                //if(root->parent->right==root)
                  //      root->lessnum+=parent->lessnum+1;
                //else
               
        }
        else
        {

                root->right=insert(root->right,key);   
                root->right->parent=root;
        }
        root->height=max(height(root->left),height(root->right))+1;
        //root->leftnum=getleftnum(root->left)+1;
        //root->lessnum=getlessnum(root->left)+1;
        //root->volume=getvolume(root->left)+getvolume(root->right)+1;
        root->child_count=getchild_count(root->left)+getchild_count(root->right)+2;
        int balance=getbalance(root);
        if(balance>1&&key<root->left->data)
                return right_rotate(root);
        if(balance<-1&&key>root->right->data)
                return left_rotate(root);
        if(balance>1&&key>root->left->data)
        {
                root->left=left_rotate(root->left);
                return right_rotate(root);
        }
        if(balance<-1&&key<root->right->data)
        {
                root->right=right_rotate(root->right);
                return left_rotate(root);
        }
        return root;
}
int search(node* root,ll key)
{
        if(root==NULL)
        {
                printf("NO\n");
                return -1;
        }
        else if(key==root->data)
        {
                printf("YES\n");
                return 1;
        }
        else if(key<root->data)
                return search(root->left,key);
        else
                return search(root->right,key);
}
void inorder(node* root,int key)
{
        if(flag==1)
                return;
        if(root)
        {
                inorder(root->left,key);
                stack[++top]=root->data;
                if(stack[top]>=key)
                        flag=1;
                inorder(root->right,key);
        }
}
/*void inorder2(node* root,int key)
  {
  if(flag==1)
  return;
  if(root)
  {
  inorder2(root->left,key);
  stack[++top]=root->data;
  if(top==key-1)
  flag=1;
  inorder2(root->right,key);
  }
  }*/


int inorder4(node* root,int key)
{
        /*   int count=0;
             while(root!=NULL)
             {
             int temp=getleftnum(root);
             if(root->data<key)
             {
             count+=temp+1;
        //                        printf("%d\n",count);
        root=root->right;
        }
        else if(root->data>key)
        {
        root=root->left;
        }
        else if(root->data==key)
        {
        printf("%d\n",count+temp);
        return temp;
        }
        }
        printf("%d\n",count);
        return count;*/
        /*if(root==NULL)
        {
                printf("NO\n");
                return -1;
        }*/
//       printf("%d\n",getlessnum(root));
        if(root==NULL)
        {
                printf("%d\n",count);
                return;
        }

        
        //if(key==root->data)
        //{
          //      printf("%d\n",count);
                
        //}
        //else if(key<root->data&&(root->left==NULL||key>root->left->data))
        //{
          //      printf("%d\n",getleftnum(root->left)+1);
                //return inorder4(root->left,key);
        //else if(key>root->data&&(root->right==NULL||key<=root->right->data))
        //        printf("%d\n",getleftnum(root)+1+count);
        else if(key>root->data)
        {
                count+=getchild_count(root->left)+2;
                //printf("%d\n",count);
                inorder4(root->right,key);
        }
        else
                return inorder4(root->left,key);

}
/*int getvolume(node* root)
  {
  if(root==NULL)
  return 0;
  else return root->volume;
  }*/
int inorder3(node* root,int key)
{
        /*if(getvolume(root)<key)
          {
        //printf("NONE\n");
        return;
        }
        if(getvolume(root)==1)
        return root->data;
        if(getvolume(root->left)>key-1)
        return inorder3(root->left,key);
        else if(getvolume(root->left)<key)
        return inorder3(root->right,key-(getvolume(root->left)+1));
        else if(getvolume(root->left)==key-1)
        return root->data;*/
        //if(root==NULL)
        //      return;
        /* if(key==0)
           {
           printf("%lld\n",root->data);
           return;
           }*/
        /* if(key==0)
           {
           while(root->left!=NULL)
           root=root->left;
           printf("%lld\n",root->data);
           return;
           }*/

        while(root!=NULL)
        {
                                //printf("%d  %lld  %d\n", root->child_count, root->data, key);
                                
                // int leftnum=getleftnum(root);

            int temp=getchild_count(root->left)+1;
                if(temp==key-1)
                {
                        printf("%lld\n",root->data);
                        flag=1;
                        root=NULL;
                        break;
                }

                else if(temp>=key)        
                        root=root->left;
                else
                {
                        root=root->right;
                        key=key-(temp+1);
                }
        }
        if(flag!=1)
                printf("NONE\n");
        return;
}
/*void preorder(node* root)
{
        if(root)
        {
                printf("%lld %d",root->data,root->leftnum);
                preorder(root->left);
                preorder(root->right);
        }
}*/
void postorder(node* root)
{
        if(root)        
        {
                postorder(root->left);
                postorder(root->right);
                printf("%lld %d\n",root->data,root->child_count);
        }
}
node* delete(node* root,int key)
{
        if(root==NULL)
                return NULL;
        if(root->data>key)        
                root->left=delete(root->left,key);
        else if(root->data<key)
                root->right=delete(root->right,key);
        else if(root->left==NULL||root->right==NULL)
        {
                node* temp=root->left;
                if(temp==NULL)
                        temp=root->right;
                free(root);
                root=temp;
        }
        else
        {
                node* temp=root->left;
                while(temp->right!=NULL)
                        temp=temp->right;
                root->data=temp->data;
                root->left=delete(root->left,temp->data);
        }
        if(root==NULL)
                return NULL;
        root->height=max(height(root->left), height(root->right))+1;
        int balance=getbalance(root);
        if(balance>1&&getbalance(root->left)>=0)
                return right_rotate(root);
        else if(balance<-1&&getbalance(root->right)<=0)
                return left_rotate(root);
        else if(balance>1&&getbalance(root->left)<0)
        {
                root->left=left_rotate(root->left);
                return right_rotate(root);
        }
        else if(balance<-1&&getbalance(root->right)>0)
        {
                root->right=right_rotate(root->right);
                return left_rotate(root);
        }
        return root;
}
int main()
{
        int n,sum,y,t;
        ll key;
        char s[20];
        node* root=NULL;        
        while(1)
        {       scanf("%s",s);
                if(s[0]=='Q')
                        break;
                else if(s[0]=='S')
                        n=1;
                else if(s[0]=='C')
                        n=2;
                else if(s[0]=='H')
                        n=3;
                else if(s[0]=='R')
                        n=4;
                
                if(n==1)
                {
                        scanf("%lld",&key);
                        root=insert(root,key);
                        //                     preorder(root);
//postorder(root);
                }
                else if(n==2)
                {
                        scanf("%lld",&key);
                        search(root,key);

                }
                else if(n==3)
                {
                        scanf("%lld",&key);
                        //            preorder(root);
                        inorder3(root,key);
                        //if(key>top+1)
                        //      printf("NONE\n");
                        //else
                        //printf("%d\n",ans);

                        top=-1;
                        flag=0;
                }
                else if(n==4)
                {
                        count=0;
                        scanf("%lld",&key);
                        inorder4(root,key);
                        //                        preorder(root);
                        //int temp=binary_search(0,top,key);
                        //if(temp==-1&&key>stack[top])
                        //      printf("%d\n",top+1);
                        //else if(temp==-1&&key<=stack[0])
                        //     printf("0\n");
                        //el/se
                        //printf("%d\n",binary_search(0,top,key));
                        //printf("%d\n",top);

                        top=-1;
                        flag=0;

                }
        }
        return 0;
}
