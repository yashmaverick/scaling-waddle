#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    long long int no;
    struct node * left;
    struct node * right;
    long long int height;
    long long int lcount;
    long long int rcount;

}node;
node * head;
long long int gheight,flag,flag2,flag3,totcount;
node* rr(node *temp)
{
        node *temp2,*temp3;
        long long int llheight,lheight,rheight,lrheight,rcount,lrcount;
       if(temp->left->right==NULL)
       {
           lrheight=0;
           lrcount=0;
       }
       else
       {
           lrheight=temp->left->right->height;
           lrcount=temp->left->rcount;
       }
       if(temp->left->left!=NULL)
       llheight=temp->left->left->height;
       else
           llheight=0;
       if(temp->right!=NULL)
       {
           rheight=temp->right->height;
           rcount=temp->rcount;//was 0
       }
       else
       {
           rheight=0;
           rcount=0;//wastemp->count
       }
       lheight=temp->left->height;

       if(rheight>lrheight)
       {
           temp->height=rheight+1;

       }
       else
       {
           temp->height=lrheight+1;
       }
       if(llheight>temp->height)
       {
           temp->left->height=llheight+1;

       }
       else
           temp->left->height=temp->height+1;
       if(temp==head)
           head=temp->left;

       temp->lcount=lrcount;
       temp->left->rcount=rcount+temp->lcount+1;


       temp3=temp->left;
        
       temp2=temp->left->right;
       temp->left->right=temp;
       
       temp->left=temp2;
       return temp3;
                 
        
}
node* ll(node *temp)
{
        node *temp2,*temp3;
        long long int rrheight,rheight,lheight,rlheight,lcount,rlcount;
       if(temp->right->left==NULL)
       {
           rlheight=0;
           rlcount=0;
       }
       else
       {
           rlheight=temp->right->left->height;
           rlcount=temp->right->lcount;
       }
       if(temp->right->right!=NULL)
       {
           rrheight=temp->right->right->height;

       }
       else
       {
           rrheight=0;
       }

       if(temp->left!=NULL)
       {
           lheight=temp->left->height;
           lcount=temp->lcount;
       }
       else
       {
           lcount=0;
           lheight=0;
       }

       rheight=temp->right->height;

       if(lheight>rlheight)
       {
           temp->height=lheight+1;

       }
       else
       {
           temp->height=rlheight+1;
       }
       if(rrheight>temp->height)
       {
           temp->right->height=rrheight+1;

       }
       else
           temp->right->height=temp->height+1;
       if(temp==head)
           head=temp->right;  
       
       temp->rcount=rlcount;
       temp->right->lcount=lcount+temp->rcount+1;


       temp3=temp->right;
       temp2=temp->right->left;
       temp->right->left=temp;
       
       temp->right=temp2;
       return temp3;
                 
        
}
node * insert(node *temp,long long int num)
{
    long long int lheight,rheight,llheight,lrheight,rrheight,rlheight,trheight,tlheight;
    
    if(temp==NULL)
    {
        node * temp2=(node *)malloc(sizeof(node));
        temp2->no=num;
        temp2->left=NULL;
        temp2->right=NULL;
        temp2->lcount=0; 
        temp2->height=1;
        return temp2;

    }
    else if(num<=temp->no)
    {
        temp->left=insert(temp->left,num);
        temp->lcount=temp->lcount+1;
        if(temp->right==NULL)
            trheight=0;
        else
            trheight=temp->right->height;
        if(trheight>temp->left->height)
        {
            temp->height=trheight+1;
           
        }
        else
            temp->height=temp->left->height+1;
     
  
    }
    else if(num>temp->no)
    {
        
        temp->right=insert(temp->right,num);
        temp->rcount=temp->rcount+1;
        if(temp->left==NULL)
            tlheight=0;
        else
            tlheight=temp->left->height;
        if(tlheight>temp->right->height)
        {
            temp->height=tlheight+1;
           
        }
        else
            temp->height=temp->right->height+1;
    }



     if((temp->left!=NULL)||(temp->right!=NULL))
    {
        if(temp->left==NULL)
        {
            lheight=0;
            rheight=temp->right->height;

        }
        if(temp->right==NULL)
        {
            rheight=0;
            lheight=temp->left->height;
        }
        if((temp->left!=NULL)&&(temp->right!=NULL))
        {
            lheight=temp->left->height;
            rheight=temp->right->height;

        }


        if(lheight-rheight==2)
        {

            if(temp->left->left==NULL)
            {
                llheight=0;
                lrheight=temp->left->right->height;

            }
            if(temp->left->right==NULL)
            {
                lrheight=0;
                llheight=temp->left->left->height;
            }
            if((temp->left->left!=NULL)&&(temp->left->right!=NULL))
            {
                llheight=temp->left->left->height;
                lrheight=temp->left->right->height;


            }



            if(llheight-lrheight==1)
            {
                temp=rr(temp);


            }
            else if(lrheight-llheight==1)
            {
               temp->left=ll(temp->left);
               temp=rr(temp);

            }

        }
        else if(rheight-lheight==2)
        {

            if(temp->right->right==NULL)
            {
                rrheight=0;
                rlheight=temp->right->left->height;

            }
            if(temp->right->left==NULL)
            {
                rlheight=0;
                rrheight=temp->right->right->height;
            }
            if((temp->right->right!=NULL)&&(temp->right->left!=NULL))
            {
                rrheight=temp->right->right->height;
                rlheight=temp->right->left->height;


            }



            if(rrheight-rlheight==1)
            {

                temp=ll(temp);

            }
            else if(rlheight-rrheight==1)
            {
               temp->right=rr(temp->right);
               temp=ll(temp);

            }

        }

    }
    return temp;

}

void inorder(node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%lld-lcount%lld-rcount%lld\n ",temp->no,temp->lcount,temp->rcount);
        inorder(temp->right);

    }
}

void check(node *temp, long long int num)
{
   
   
   if(temp==NULL)
   {
       return;
   }
   if(temp->no==num)
   {
       flag=1;
       printf("YES\n");
   }
   else if(temp->no<num)
   {
       check(temp->right,num);

   }
   else
   {
       check(temp->left,num);
   }
   return;
}
void healthy(node *temp,long long int x)
{
    node *last;
    

    if(temp==NULL)
    {
        return;
    }
    if(temp->lcount+1==x)
    {
       flag2=1;
              
       
               printf("%lld\n",temp->no);


    }
    else if(temp->lcount+1>x)
    {
        
        healthy(temp->left,x);

    }
    else if (temp->lcount+1<x)
    {
       
        healthy(temp->right,x-temp->lcount-1);
    }
    
}
void rotten(node *temp,long long int num)
{
     if(temp==NULL)
     {
         return;
     
     }
          
      if(temp->no<num)
     {
         totcount=totcount+temp->lcount+1;
         rotten(temp->right,num);
     }
     else 
     {

         rotten(temp->left,num);
        
     }
}
int main ()
{
    long long int i,j,a,l,k,m,n,num;
    char str[50];
  /*  scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&num);
        head=insert(head,num);
    
    } 
    inorder(head);
    healthy(head,3);*/
   str[0]='a';
    while(str[0]!='Q')
    {
        scanf("%s",str);
        scanf ("%lld",&num);
            if(str[0]=='C')
            {
                check(head,num);
                if(flag==0)
                    printf("NO\n");
                else
                    flag=0;
            }
            else if(str[0]=='S')
            {
              
                head=insert(head,num);
    
                  
            }
            else if(str[0]=='H')
            {
                
                healthy(head,num);
                if(flag2!=1)
                    printf("NONE\n");
                else
                    flag2=0;

                     
            }
            else if(str[0]=='R')
            {
                totcount=0;
                rotten(head,num);
                printf("%lld\n",totcount);

            }
            


    }
 //   printf("lola");

    return 0;
}
