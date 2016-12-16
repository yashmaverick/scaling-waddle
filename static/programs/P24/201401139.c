#include <stdio.h>
#include <stdlib.h>
#define sc(n) scanf("%d",&n);

typedef struct dabba
{
  int num,hght;
  int nol,nor;
  struct dabba *lp,*rp,*par;
}node;

node *root=NULL;
int count;

void checkcount(node *temp)
{
  int nl=0,rl=0;
  if(temp->lp!=NULL)
    nl=temp->lp->nol + temp->lp->nor + 1;
  if(temp->rp!=NULL)
    rl=temp->rp->nol + temp->rp->nor + 1;
  
  temp->nol=nl;
  temp->nor=rl;
}

void inorder(node* temp,int pos)
{
  if(temp==NULL)
    return;
  else
    {
      inorder(temp->lp,pos);
      count++;
      if(count==pos)
	{
	  printf("%d\n",temp->num);
	  return;
	}
      inorder(temp->rp,pos);
    }
}

void nodesinorder(node* temp)
{
  if(temp==NULL)
    return;
  else
    {
      nodesinorder(temp->lp);
      printf("%d%d%d\n",temp->num,temp->nol,temp->nor);
      nodesinorder(temp->rp);
    }
}

void setheight(node* temp)
{
  //printf("99999999999999999999999\n");
  
  int lth,rth;
  if(temp->lp==NULL)
    lth=0;
  else
    lth=temp->lp->hght;
      
  if(temp->rp==NULL)
    rth=0;
  else
    rth=temp->rp->hght;
      
  temp->hght=(lth>rth?lth:rth)+1;
  //printf("1233244357834658734568\n");
  
}

  
void rightrot(node *temp)
{
  node *temp2=temp->par;
  node *temp3=temp->lp;
  if(temp2==NULL)
    root=temp3;
  else if(temp==temp2->lp)
    temp2->lp=temp3;
  else
    temp2->rp=temp3;
  if(temp3->rp!=NULL)
    temp3->rp->par=temp;
  temp->lp=temp3->rp;
  temp3->rp=temp3->par;
  temp3->par=temp2;
  temp->par=temp3;
  
  setheight(temp);
  checkcount(temp);
  setheight(temp3);
  checkcount(temp3);
  
} 

void leftrot(node *temp)
{
  node *temp2=temp->par;
  node *temp3=temp->rp;
  int lth,rth;
  if(temp2==NULL)
    root=temp3;
  else if(temp==temp2->rp)
    temp2->rp=temp3;
  else
    temp2->lp=temp3;
  if(temp3->lp!=NULL)
    temp3->lp->par=temp;
  temp->rp=temp3->lp;
  temp3->lp=temp3->par;
  temp3->par=temp2;
  temp->par=temp3;

  setheight(temp);
  checkcount(temp);
  setheight(temp3);
  checkcount(temp3);
  
}

void checkleft(node *temp)
{
  node *newnode=temp->rp;
  int lth,rth;
  if(newnode->lp==NULL)
    lth=0;
  else
    lth=newnode->lp->hght;
  
  if(newnode->rp==NULL)
    rth=0;
  else
    rth=newnode->rp->hght;

  if(lth-rth==1)
    rightrot(newnode);
  leftrot(temp);
}
    
void checkright(node* temp)
{
  node *newnode=temp->lp;
  int lth,rth;
  if(newnode->lp==NULL)
    lth=0;
  else
    lth=newnode->lp->hght;
  
  if(newnode->rp==NULL)
    rth=0;
  else
    rth=newnode->rp->hght;

  if(lth-rth==-1)
    leftrot(newnode);
  rightrot(temp);
}

void insert(node* temp,int val)
{
  if(root==NULL)
    {
      root=(node*)malloc(sizeof(node));
      root->num=val;
      root->hght=1;
      root->par=NULL;
      root->lp=NULL;
      root->rp=NULL;
      root->nol=root->nor=0;
      temp=root;
    }
  else if(val>temp->num)
    {
      if(temp->rp==NULL)
	{
	  temp->rp=(node*)malloc(sizeof(node));
	  temp->rp->num=val;
	  temp->rp->hght=1;
	  temp->rp->par=temp;
	  temp->rp->rp=NULL;
	  temp->rp->lp=NULL;
	  temp->rp->nol=temp->rp->nor=0;
	  temp->nor++;
	}
      else
	{
	  temp->nor++;
	  insert(temp->rp,val);
	}
    }
  else if(val<=temp->num)
    {
      if(temp->lp==NULL)
	{
	  temp->lp=(node*)malloc(sizeof(node));
	  temp->lp->num=val;
	  temp->lp->hght=1;
	  temp->lp->par=temp;
	  temp->lp->rp=NULL;
	  temp->lp->lp=NULL;
	  temp->lp->nol=temp->lp->nor=0;
	  temp->nol++;
	}
      else
	{
	  temp->nol++;
	  insert(temp->lp,val);
	}
    }
  
  setheight(temp);
  
  int lth,rth;
  if(temp->lp==NULL)
    lth=0;
  else
    lth=temp->lp->hght;

  if(temp->rp==NULL)
    rth=0;
  else
    rth=temp->rp->hght;

  if(lth-rth == -2)
    checkleft(temp);
  else if(lth-rth == 2)
    checkright(temp);

  return;
}

int search(node *temp,int item)
{
  if(temp==NULL)
    return 0;
  else
    {
      if(temp->num==item)
	return 1;
      else if(item>temp->num)
	return search(temp->rp,item);
      else if(item<temp->num)
	return search(temp->lp,item);
    }
}

int sum;
void nodesonleft(node *temp,int item)
{
  if(temp==NULL)
    return ;
  else
    {
      if(item==temp->num)
	{
	  sum+=temp->nol;
	  return;
	}
      else if(item>temp->num)
	{
	  sum+=(temp->nol+1);
	  nodesonleft(temp->rp,item);
	}
      else if(item<temp->num)
	nodesonleft(temp->lp,item);
    }
}

//avl part above
//
//
//
//



int main()
{
  int n,t,node,number;
  int a,b,c,choice=-1;
  char word[50];

  scanf("%s",word);
  
  while(word[0]!='Q')
    {
      sc(number);
      if(word[0]=='S')
	insert(root,number);
      else if(word[0]=='C')
	{
	  if(search(root,number)==1)
	    printf("YES\n");
	  else
	    printf("NO\n");
	}
      else if(word[0]=='H')
	{
	  count=0;
	  if(number>(root->nol+root->nor+1) || number<=0)
	    printf("NONE\n");
	  else
	    inorder(root,number);
	}
      else if(word[0]=='R')
	{
	  sum=0;
	  nodesonleft(root,number);
	  printf("%d\n",sum);
	}
      /*else if(word[0]=='P')
	{
	  nodesinorder(root);
	  }*/
      scanf("%s",word);
    }
  
  
  return 0;
}
  
