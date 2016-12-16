#include<stdio.h>
#include<stdlib.h>
struct list{
     int data;
     struct list *lft,*rt;
     int ht;
     int less;
};
typedef struct list element;
typedef element *link;
//link head;
int count=0,st;
int d[500000];
void postorder(link (root),int value){
  if((root)==NULL)
    return;
  //count++;
  postorder((root)->lft,value);
 // d[count]=root->data;
  //count++;
  //if(root->data<value)
  //{
    //st++;
  //}
  postorder((root)->rt,value);
  printf("Po node%d less%d\n",(root)->data,root->less);
  //printf("%d\n",(root)->data);
}
void inorder(link (root),int value){
	if((root)==NULL)
		return;
  //count++;
	inorder((root)->lft,value);
  printf("In node%d %d\n",(root)->data,root->less);
 // d[count]=root->data;
  //count++;
  //if(root->data<value)
  //{
    //st++;
  //}
	inorder((root)->rt,value);
	//printf("%d\n",(root)->data);
}
int height(link node){
  if(node==NULL)
    return 0;
  return node->ht;
}
int max(int a, int b)
{
    if(a>=b)
      return a;
    else
      return b;
}
int lessthan(link node)
{
  if(node==NULL)
    return 0;
  else
    return (node->less);
}
/*int gettotal(link node)
{
  if(node==NULL)
    return 0;
  else return node->total;
}*/
link avl(link (root))
{
      /*  if((root)->rt==NULL){                   //1
           link temp=((root)->lft)->rt;
           link temp2=(root)->lft;
            //if(head==(*root))
              //link head=((root)->lft);         // rotate right
            ((root)->lft)->rt=(root);
            (root)->lft=temp;
            (root)->ht=max(height((root)->lft),height((root)->rt))+1;//(*root)->ht-2;
            (root)->less=(lessthan(root));
            temp2->ht=max(height(temp2->lft),height(temp2->rt))+1;
            temp2->less=lessthan(temp2);
            return temp2;
         }
        else if((root)->lft==NULL){              //2
            link temp=((root)->rt)->lft;
            link temp2=(root)->rt;
            //head=((root)->rt);
            ((root)->rt)->lft=(root);
            (root)->rt=temp;
            (root)->less=(lessthan(root));
            (root)->ht=max(height((root)->lft),height((root)->rt))+1;//(*root)->ht-2;
            temp2->ht=max(height(temp2->lft),height(temp2->rt))+1;
            temp2->less=lessthan(temp2);
            return temp2;
         }  */
      //  else 
        //{

         	  if((height((root)->lft))>height((root)->rt))
            {  // lft case
               // if(((root)->lft)->lft!=NULL)
                //{
                	  /*if(((root)->lft)->rt==NULL)      //3

                	  {
                        link temp=((root)->lft)->rt;
                        link temp2=((root)->lft);
                       // if(head==(*root))
                         //  head=((*root)->lft);
                        ((*root)->lft)->rt=(*root);
                        (*root)->lft=temp;
                        (*root)->ht=max(height((*root)->lft),height((*root)->rt))+1;//(*root)->ht-2;
                        temp2->ht=max(height(temp2->lft),height(temp2->rt))+1;                                                // lft lft case
                	  }*/
                	   if(/*((*root)->lft)->rt!=NULL&&*/(height(((root)->lft)->lft))>height(((root)->lft)->rt))

                	  {
                        link temp=((root)->lft)->rt;
                        link temp2=((root)->lft);
                        //if(head==(*root))
                          // head=((*root)->lft);
                        ((root)->lft)->rt=(root);
                        (root)->lft=temp;
                        //(root)->total=((root)->total)-gettotal(temp2)+gettotal(temp);
                     //   printf("!!!%d %d\n",root->data,root->less);
                        (root)->less=(lessthan(root))-lessthan(temp2)-1;
                        (root)->ht=max(height((root)->lft),height((root)->rt))+1;//(*root)->ht-2;
                        //(temp2)->total=(temp2)->total+gettotal(root)-gettotal(temp);
                        temp2->ht=max(height(temp2->lft),height(temp2->rt))+1;
                        //temp2->less=lessthan(temp2);
                        return temp2;
                	  }
                    else if(/*((*root)->lft)->lft!=NULL&&*/((height(((root)->lft)->lft))<(height(((root)->lft)->rt))))
                   {
                      link temp=(root->lft)->rt;
                      link p=root->lft;
                      link q=temp->lft;
                      //p->total=p->total-gettotal(temp)+gettotal(q);
                      //temp->total=temp->total-gettotal(q)+gettotal(p);
                      root->lft=temp;
                      temp->lft=p;
                      p->rt=q;
                      p->ht=max(height(p->lft),height(p->rt))+1;
                      temp->ht=max(height(temp->lft),height(temp->rt))+1;
                      root->ht=max(height(root->lft),height(root->rt))+1;
                      //(p)->less=(lessthan(p));
                      (temp)->less=(lessthan(temp))+lessthan(p)+1;
                      //(root)->less=(lessthan(root));
                      link temp1=((root)->lft)->rt;
                        link temp2=((root)->lft);
                        //if(head==(*root))
                          // head=((*root)->lft);
                        ((root)->lft)->rt=(root);
                        (root)->lft=temp1;
                        //(root)->total=((root)->total)-gettotal(temp2)+gettotal(temp);
                        (root)->less=(lessthan(root))-lessthan(temp2)-1;  // temp2 bhi subs
                        (root)->ht=max(height((root)->lft),height((root)->rt))+1;//(*root)->ht-2;
                        //(temp2)->total=(temp2)->total+gettotal(root)-gettotal(temp);
                        temp2->ht=max(height(temp2->lft),height(temp2->rt))+1;
                        //temp2->less=lessthan(temp2);
                        return temp2;
                      //root=avl((root));
                      //return root;
                    }

            //    }
               	
         	  }
         	  else                          // rt case
            {
                 
                  //if(((root)->rt)->rt!=NULL)
                  //{
                	    /*if(((root)->rt)->lft==NULL)
                	    {
                          link temp=((root)->rt)->lft;
                          link temp2=((root)->rt);
                          //if(head==(root))
                            // head=((root)->rt);
                          ((root)->rt)->lft=(*root);
                          (root)->rt=temp;
                          (root)->ht=max(height((*root)->lft),height((*root)->rt))+1;//(*root)->ht-2;
                          temp2->ht=max(height(temp2->lft),height(temp2->rt))+1;
                          return temp2;                                                // rt rt case
                	    }*/
                	    if(/*((*root)->lft)->rt!=NULL&&*/((height(((root)->rt)->rt))>(height(((root)->rt)->lft))))
                	    {
                          link temp=((root)->rt)->lft;
                          link temp2=((root)->rt);
                          //if(head==(root))
                            // head=((root)->rt);
                          ((root)->rt)->lft=(root);        // checked karrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr!!!!!!!!!!
                          (root)->rt=temp;
                          //(root)->total=((root)->total)-gettotal(temp2)+gettotal(temp);
                          (root)->ht=max(height((root)->lft),height((root)->rt))+1;//(*root)->ht-2;
                          //(root)->less=(lessthan(root))-lessthan(temp2)-1;
                          //(temp2)->total=(temp2)->total+gettotal(root)-gettotal(temp);
                          temp2->ht=max(height(temp2->lft),height(temp2->rt))+1;
                          (temp2)->less=(lessthan(temp2))+lessthan(root)+1;
                          return temp2;
                	    }
                      else if(/*((*root)->rt)->rt!=NULL&&*/(height(((root)->rt)->rt))<height(((root)->rt)->lft))
                      {
                          link temp=(root->rt)->lft;
                          link p=root->rt;
                          link q=temp->rt;
                          //p->total=p->total-gettotal(temp)+gettotal(q);
                          //temp->total=temp->total-gettotal(q)+gettotal(p);
                         root->rt=temp;
                          temp->rt=p;
                          p->lft=q;
                          p->ht=max(height(p->lft),height(p->rt))+1;
                          temp->ht=max(height(temp->lft),height(temp->rt))+1;
                          root->ht=max(height(root->lft),height(root->rt))+1;
                          (p)->less=(lessthan(p))-lessthan(temp)-1;
                          //(temp)->less=(lessthan(temp));
                          //(root)->less=(lessthan(root));
                          link temp1=((root)->rt)->lft;
                          link temp2=((root)->rt);
                          //if(head==(root))
                            // head=((root)->rt);
                          ((root)->rt)->lft=(root);        // checked karrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr!!!!!!!!!!
                          (root)->rt=temp1;
                          //(root)->total=((root)->total)-gettotal(temp2)+gettotal(temp);
                          (root)->ht=max(height((root)->lft),height((root)->rt))+1;//(*root)->ht-2;
                          //(root)->less=(lessthan(root))-lessthan(temp2)-1;
                          //(temp2)->total=(temp2)->total+gettotal(root)-gettotal(temp);
                          temp2->ht=max(height(temp2->lft),height(temp2->rt))+1;
                          //(temp2)->less=(lessthan(temp2));
                          (temp2)->less=(lessthan(temp2))+lessthan(root)+1;
                          return temp2;
                          //root=avl((root));
                          //return root;
                      }

                //}
         	}

        //}

}
link insert(link root,int value){
          if((root)==NULL){
          	   (root)=malloc(sizeof(element));
          	   (root)->data=value;
          	   (root)->lft=NULL;
          	   (root)->rt=NULL;
          	   (root)->ht=1;
               (root)->less=0;
               //(root)->total=0;
          	   return root;
          }
          else if(((root)->data)<value)
          {
                //root->total++;
          	   root->rt=insert((root)->rt,value); 
          }
          else
          {
              //root->total++;
              root->less++;
          	  root->lft=insert((root)->lft,value);
          }
          (root)->ht=max(height((root)->lft),height((root)->rt))+1;
          int bfact=height((root)->lft)-height((root)->rt);
          //printf("bfact=%d\n",bfact);
          if(bfact>1 || bfact< -1)
          {
            return avl(root);
          }
          return root;
        /*  if((root)->lft==NULL){
          	//   (root)->ht=(((root)->rt)->ht)+1;
          	   if(((root)->ht)>=2)
          		   avl((root));
          	   return root;
          }
          else if((root)->rt==NULL){
          	  // (root)->ht=(((root)->lft)->ht)+1;
          	   if(((root)->ht)>=2)
          		  root=avl((root));
          	  return root;
          }
          else{
          	   if((((root)->rt)->ht)>=((root)->lft)->ht){
                  // (root)->ht=(((root)->rt)->ht)+1;
                   if((((root)->rt)->ht)-(((root)->lft)->ht)>1)
               	       root=avl((root));
                     return root;
                   
               }
              else{
            	   // (root)->ht=(((root)->lft)->ht)+1;
            	   if((((root)->lft)->ht)-(((root)->rt)->ht)>1)
               	      root=avl((root));
            	   return root;
            }
          } */
}
int check(int value,link root)
{
	if(root==NULL)
	{
		return -1;
	}
	else if(root->data==value)
		return 1;
	else if(root->data > value)
		return check(value,root->lft);
	else
		return check(value,root->rt);
}
int min(int value,link root)
{
  if(root==NULL)
  {
    return 0;
  }
  else if(root->data==value)
    return root->less;
  else if(root->data > value)
  {
    return min(value,root->lft);
  }
  else
  {
    
      return root->less+min(value,root->rt)+1;
  }
}
int ksmallest(link node,int k)
{
  if(k==(node->less)+1)
  {
    return node->data;
  }
  else if(k>(node->less))
  {
    return ksmallest(node->rt,k-((node->less)+1));
  }
  else 
  {
    return ksmallest(node->lft,k);
  }
}
int main()
{
	char a[100];
	int sw,x;
	scanf("%s",a);
	link root=NULL;
	int state=0;
  count=0;
	while(a[0]!='Q')
	{
		scanf("%d",&x);
		if(a[0]=='S')
		{
      count++;
			root=insert(root,x);
      //inorder(root,x);
      //postorder(root,x);
		}
		else if(a[0]=='C')
		{
      state=0;
			state=check(x,root);
   //   printf("state=%d\n",state);
			if(state==1)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else if(a[0]=='R')
		{
      //count=0;
      st=0;
      st=min(x,root);
      //printf("!@##$\n");
      //if(a[0]=='R')
      printf("%d\n",st);
      /*else
      {
        if(x<count)
        {
          printf("%d\n",d[x-1]);
        }
        else
        {
          printf("NONE\n");
        }
      }*/
		}
    else  // a[0]==h
    {
      //count=0;
      //st=0;
      //st=inorder(root,x);
      if(x<=count)
      {
       // printf("root= %d\n",root->data);
        st=ksmallest(root,x);
        printf("%d\n",st);

      }
      else
      {
        printf("NONE\n");
      }
    }
    scanf("%s",a);
	}
	return 0;
}