#include<stdio.h>
#include<stdlib.h>

typedef struct binary{
     int val;
     int ht;
     int lc; int rc;
     struct binary* pt;
     struct binary* lt;
     struct binary* rt;
}bst;

int ans=0;

void kthsor(int k,bst* root){
     if(root==NULL)
     { ans=0;return ;
     }

     if(k-root->lc==1)
     {
          ans=root->val;
          return ;
     }

     if(k>root->lc)
          kthsor(k-root->lc-1,root->rt);

     if(k<=root->lc)
          kthsor(k,root->lt);
}

int ans2=0;

void  lessk(int k,bst* root)
{  // printf("ans2=%d\n",ans2);
     if(root==NULL)
          return;

     if(root->val ==k)
     {    ans2+=root->lc;
          return;
     }

     if(k > root->val)
     {
          ans2+=root->lc+1;
          lessk(k,root->rt);
     }

     if(k <= root->val)
     {
          lessk(k,root->lt);
     }
}

bst* lr(bst* root)
{
     bst* tmp1,*tmp2;
     tmp1=root->rt;
     //if(tmp1!=NULL)
     tmp2=tmp1->lt;
     // else
     //    return;

     tmp1->lt=root;
     root->rt=tmp2;
     int hl=0,hr=0,lch=0,rch=0;
     if(root->lt==NULL){hl=0; lch=0;}
     else 
     {    hl=root->lt->ht;
          lch=root->lt->lc+root->lt->rc+1;
     }

     if(root->rt==NULL){ hr=0; rch=0;}

     else
     {    hr=root->rt->ht;
          rch=root->rt->lc+root->rt->rc+1;
     }

     if(hl>hr)
          root->ht=hl+1;
     else
          root->ht=hr+1;

     root->lc=lch;
     root->rc=rch;
     hl=0; hr=0,lch=0,rch=0;
     if(tmp1->lt==NULL){ hl=0; lch=0;}
     else
     {
          hl=tmp1->lt->ht;
          lch=tmp1->lt->rc + tmp1->lt->lc+1;
     }
     if(tmp1->rt==NULL){ hr=0; rch=0;}
     else
     {      hr=tmp1->rt->ht;
          rch=tmp1->rt->rc+tmp1->rt->lc+1;
     }

     if(hl>hr)
          tmp1->ht=hl+1;
     else
          tmp1->ht=hr+1;
     tmp1->rc=rch; tmp1->lc=lch;

     return tmp1;
}

bst* search(bst* root,int p)
{
     if(root==NULL)
          return NULL;
     while(root!=NULL)
     {
          if(root->val==p)
          {
               return root;
          }
          if(root->val > p)
               root=root->lt;
          else
               root=root->rt;
     }

     return NULL;
}


bst* rr(bst* root)
{
     bst *tmp1,*tmp2;

     tmp1=root->lt;
     //  if(tmp1!=NULL)
     tmp2=tmp1->rt;
     //else
     // return ;   

     tmp1->rt=root;
     root->lt=tmp2;
     //printf("root->lt=%p\n",root->lt);
     int hl=0,hr=0,lch=0,rch=0;

     if(root->lt==NULL){ hl=0;lch=0;}

     else
     {  hl=root->lt->ht;
          lch=root->lt->lc+root->lt->rc+1;
     }

     if(root->rt==NULL){ hr=0; rch=0;}

     else
     {     hr=root->rt->ht;
          rch=root->rt->lc+root->rt->rc+1;
     }

     if(hl>hr)
          root->ht=hl+1;
     else
          root->ht=hr+1;
     root->lc=lch;
     root->rc=rch;
//printf("val=%d hl=%d hr=%d lch=%d rch=%d\n",root->val,hl,hr,lch,rch);
     hl=0; lch=0;hr=0;rch=0;
     if(tmp1->lt==NULL){ hl=0; lch=0;}
     else
     {    hl=tmp1->lt->ht;
          lch=tmp1->lt->lc+tmp1->lt->rc+1;
     }

     if(tmp1->rt==NULL){ hr=0; rch=0;}

     else
     {     hr=tmp1->rt->ht;
          rch=tmp1->rt->lc+tmp1->rt->rc+1;
     }

     if(hl>hr)
          tmp1->ht=hl+1;
     else
          tmp1->ht=hr+1;
     tmp1->lc=lch;
     tmp1->rc=rch;

//printf("val=%d hl=%d hr=%d lch=%d rch=%d\n",tmp1->val,hl,hr,lch,rch);
     return tmp1;
}

bst* newnode(int p)
{
     bst* temp;
     temp=(bst*)malloc(sizeof(bst));
     temp->val=p;
     temp->lc=0;
     temp->lt=NULL;
     temp->rt=NULL;
     return temp;
}


bst* insert(bst* root,int p)
{                       
     if(root==NULL)
     {
          root=newnode(p);
     }

     else if(root->val > p)
          root->lt=insert(root->lt,p);
     else
          root->rt=insert(root->rt,p);

     int hl,hr,bal,lch,rch;

     if(root->lt==NULL)
     {   hl=0; lch=0; }

     else
     {  hl=root->lt->ht;
          lch=root->lt->lc+root->lt->rc+1;
     }

     if(root->rt==NULL)
     {   hr=0; rch=0;} 
     else
     {    hr=root->rt->ht;
          rch=root->rt->rc+1+root->rt->lc;
     }

     if(hl>hr)
          root->ht=hl+1;
     else
          root->ht=hr+1;
     root->lc=lch;
     root->rc=rch;

     if(root==NULL) bal=0;
     else
     {
          if(root->lt==NULL)
               hl=0;
          else
               hl=root->lt->ht;
          if(root->rt==NULL)
               hr=0;
          else
               hr=root->rt->ht;
          bal=hl-hr;
     }
  //   printf("val=%d bal=%d,lc=%d rc=%d\n",root->val,bal,root->lc,root->rc);
     if(root->rt!=NULL)
     {                       
          if(p < root->rt->val && bal < -1)
          {
              // printf("case 1\n");
               root->rt=rr(root->rt);
    // printf("val=%d bal=%d,lc=%d rc=%d\n",root->val,bal,root->lc,root->rc);

//printf("rt val=%d bal=%d,lc=%d rc=%d\n",root->rt->val,bal,root->rt->lc,root->rt->rc);
               return lr(root);
          }
     }


     if(root->rt!=NULL)      
          if(bal < -1 && p > root->rt->val)
          {                      //  printf("case 2\n");
               return lr(root);
          }

     if(root->lt!=NULL)
          if(p < root->lt->val && bal>1)
          {                  //    printf("case 3\n");
               return rr(root);
          }


     if(root->lt!=NULL)
          if(p > root->lt->val && bal>1)
          {                  //     printf("case 4\n");
               root->lt=lr(root->lt);
               return rr(root);
          }

     return root;
}

void inorder(bst* root)
{
     if(root==NULL)
          return;

     if(root->lt!=NULL)
          inorder(root->lt); 

     printf("%d %d %d\n",root->val,root->lc,root->rc);

     if(root->rt!=NULL)
          inorder(root->rt);

}

int main (){
     bst* root,*temp;
     int i,j,a,q,p,i1,t;
     char s[200];
     scanf("%d",&q);
     root=NULL;
     while(1)
     {

           scanf("%s",s);
          //scanf("%d",&t);
           if(strcmp(s,"Quit")==0)
              break;
          //if(t==1)
              if(strcmp(s,"SetHealthy")==0)
          {
               scanf(" %d",&a);
               root=insert(root,a);
          }

          //if(t==2)
             if(strcmp(s,"CheckHealthy")==0)
          {
               scanf(" %d",&a);

               temp=search(root,a);

               if(temp!=NULL)
                    printf("YES\n");
               else
                    printf("NO\n");
          }


   /*       if(t==5)
          {
               inorder(root); 
               printf("\n");
          } */

         // if(t==3)
            if(strcmp(s,"Healthy")==0)
          {     scanf(" %d",&a);
               ans=0;
               kthsor(a,root);
               if(ans!=0)
                    printf("%d\n",ans);
               else
                    printf("NONE\n");

          }

         // if(t==4)
           if(strcmp(s,"RottenBefore")==0)
          {    ans2=0;         
               scanf(" %d",&a);
               lessk(a,root);
               printf("%d\n",ans2);
          }

     }
     return 0;
}
