#include<stdio.h>
#include<stdlib.h>
typedef struct bst
{
  int val;
  int height;
  int lfkid;
  int rgkid;
  struct bst *left;
  struct bst *right;
}node;
int update(node *head,int  cnt)
{
  int q,r;
  if(head==NULL)
    return 0;
  else if(cnt==2)
    return head->height;
  node *left,*right;
  left=head->left;
  right=head->right;
  q=update(left,cnt+1);
  r=update(right,cnt+1);
  if(q>r)
    head->height=q+1;
  else
    head->height=r+1;
  return head->height;
}
int updatelf(node *head,int  cnt)
{
  int q,r;
  if(head==NULL)
    return -1;
  else if(cnt==2)
    return (head->lfkid+head->rgkid);
  node *left,*right;
  left=head->left;
  right=head->right;
  q=updatelf(left,cnt+1);
  r=updatelf(right,cnt+1);
  head->lfkid=q+1;
  head->rgkid=r+1;
  return (q+r+2);
}
node* leftrot(node *head)
{
  int t;
  node *temp,*temp2;
  temp=head->right->left;
  head->right->left=head;
  temp2=head->right;
  head->right=temp;
  //head==temp2//
  head=temp2;
  head->height=update(head,0);
  t=updatelf(head,0);
  return head;
}
node* rightrot(node *head)
{
  int t;
  node *temp,*temp2;
  temp=head->left->right;
  head->left->right=head;
  temp2=head->left;
  head->left=temp;
  head=temp2;
  head->height=update(head,0);
  t=updatelf(head,0);
  return head;
}
void preorder(node *head)
{
  if(head==NULL)
    return;
  printf("head->:val:%d lfkid:%d rgkid:%d\n",head->val,head->lfkid,head->rgkid);
  preorder(head->left);
  preorder(head->right);
}
void inorder(node *head)
{
  if(head==NULL)
    return;
  inorder(head->left);
  printf("head->:val:%d head->lfkid:%d \n",head->val,head->lfkid);
  inorder(head->right);
}
node* balance(node *head,int val)
{
  //rintf("balance:%d %d\n",head->val,val);
  node *left,*right;
  left=head->left;
  right=head->right;
  if(right==NULL)
  {	if(left->val>val)
    {
      head=rightrot(head);
    }
    else
    {
      head->left=leftrot(left);
      //			preorder(head);
      //			printf("\n");
      head=rightrot(head);
    }
  }
  else if(left==NULL)
  {
    if(val<right->val)
    {
      head->right=rightrot(right);
      //			preorder(head);
      //			printf("\n");
      head=leftrot(head);
    }
    else
      head=leftrot(head);
  }

  else if(left!=NULL && right!=NULL)
  {
    if(left->height>right->height+1)
    {
      if(left->val>=val)
      {
        head=rightrot(head);
      }
      else
      {
        head->left=leftrot(left);
        //			preorder(head);
        //			printf("\n");
        head=rightrot(head);
      }
    }

    else if(right->height>left->height+1)
    {
      if(val<right->val)
      {
        head->right=rightrot(right);
        //			preorder(head);
        //			printf("\n");
        head=leftrot(head);
      }
      else
        head=leftrot(head);
    }
  }
  return head;
}
node* insert(node *head,int val)
{
  //	printf("insert:\n");
  if(head==NULL)
  {
    head=malloc(sizeof(node));
    head->val=val;
    head->lfkid=0;
    head->rgkid=0;
    head->height=1;
    head->right=NULL;
    head->left=NULL;
  }
  else
  {	
    if(val>=head->val)
    {
      head->rgkid++;
      head->right=insert(head->right,val);
    }
    else
      {
        head->left=insert(head->left,val);
        head->lfkid++;
      }
    if(head->right==NULL)
    {	
      head->height=head->left->height+1;
      if(head->height>2)
        head=balance(head,val);
    }
    else if(head->left==NULL)
    {
      head->height=head->right->height+1;
      if(head->height>2)
        head=balance(head,val);
    }
    else if(head->left->height>head->right->height)
    {
      head->height=head->left->height+1;
      if(head->left->height>head->right->height+1)
        head=balance(head,val);
    }
    else
    {
      head->height=head->right->height+1;
      if(head->right->height>head->left->height+1)
        head=balance(head,val);
    }
  }
  return head;
}
node* search(node *head,int val)
{
  node* q=NULL;
  if(head==NULL)
    return NULL;
  if(head->val==val)
    return head;
  else if(val>head->val)
    q=search(head->right,val);
  else
    q=search(head->left,val);
  return q;
}
int searchxth(node *head,int x)
{
  int q;
  if(head==NULL)
    return 0;
  else if(head->lfkid==x-1)
       return head->val; 
  if(head->lfkid>x-1)
    q=searchxth(head->left,x);
  else
    q=searchxth(head->right,x-(head->lfkid+1));
  return q;
}
int srch(node *head,int val)
{
  int q=0;
  if(head==NULL)
    return 0;
  if(head->val==val)
    return head->lfkid;
  else if(val>head->val)
  {
    q=srch(head->right,val);
    q+=(head->lfkid+1);
  }
  else
    q=srch(head->left,val);
  return q;
}
int main()
{
  int n,i,c,ans,val;
  char t[25];
  node *head;
  node *temp;
  head=NULL;
  scanf("%s",t);
  while(t[0]!='Q')
  {
  scanf("%d",&val);
    if(t[0]=='S')
     head=insert(head,val);
    else if(t[0]=='C')
    {
      temp=search(head,val);
        if(temp==NULL)
          printf("NO\n");
        else
          printf("YES\n");
    }
    else if(t[0]=='H')
    {
      ans=searchxth(head,val);
      if(ans==0)
        printf("NONE\n");
      else
        printf("%d\n",ans);
    }
    else if(t[0]=='R')
    {
      ans=srch(head,val);
      printf("%d\n",ans);
    }
//   preorder(head);
    scanf("%s",t);
  }
  return 0;
}
