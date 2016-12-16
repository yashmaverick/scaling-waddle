#include<stdio.h>
#include<stdlib.h>
#define s(n) scanf("%d",&n)
#define d(n) n=(tp)malloc(1*sizeof(t))
typedef int ll;
typedef struct tree
{
    ll val;
    struct tree *left, *right, *parent;
    ll h;
    ll lno,rno;
}t;
ll co;
ll fag;
ll ans;

typedef t* tp;
tp new;
void setno(tp);
void find(tp,ll);
void search(tp,ll);
void postorder(tp root)
{
    if(root)
    {
	postorder(root->left);
	postorder(root->right);
	printf("%d(%d)\n",root->val,root->h);
    }
    return;

}
ll set(tp groot)
{
    if(groot->left==NULL || groot->right == NULL)
    {
	//printf("should not enter here when 1 is inserted \n");
	if(groot->left==NULL && groot->right)
	    return groot->right->h+1;
	else if(groot->left && groot->right == NULL)
	    return groot->left->h+1;
	else if(groot->left==NULL && groot->right==NULL)
	    return 0;
    }
    else
    {
	//printf("groot-left and groot-right are %d and  %d\n",groot->left->h,groot->right->h);
	if(groot->left->h > groot->right->h)
	    return groot->left->h+1;
	else
	    return groot->right->h+1;
    }
}
tp insert(tp root,ll x)
{
    if(root==NULL)
    {
	new->parent=NULL;
	return new;
    }
    else
    {
	if(x<root->val)
	{
	    root->lno = root->lno + 1;
	    root->left=insert(root->left,x);
	    root->left->parent = root;
	}
	else
	{
	    root->rno = root->rno + 1;
	    root->right=insert(root->right,x);
	    root->right->parent = root;
	}
    }
    root->h = set(root);
    return root;
}
tp rotr(tp node)
{
    tp t2,baap;
    /**/
    baap = node->parent;
    node->parent = node->left;
    node->left->parent = baap;
    /**/
    t2 = node->left->right;
    node->left->right = node;
    node->left = t2;
    if(t2)
	t2->parent = node;
    return node->parent;
}
tp rotl(tp node)
{
    //printf("node value %d\n",node->val);
    tp t2,baap;
    /***/
    baap = node->parent;
    node->right->parent= baap;
    node->parent=node->right;
    /***/
    t2 = node->right->left;
    node->right->left = node;
    node->right = t2;
    if(t2)
	t2->parent = node;
    return node->parent;
}
void inorder(tp,ll);
int main()
{
    tp bst=NULL;
    char c[15];
    ll x,count;
    while(1)
    {
	scanf("%s",c);
	if(c[0]=='S')
	{
	    s(x);
	    d(new);
	    new->val=x;
	    new->left=new->right=NULL;
	    new->h=new->lno=new->rno=0;
	    bst = insert(bst,x);
	    //postorder(bst);
	    //putchar('\n');
	    tp temp;
	    temp = new;
	    count = 0;
	    //printf("just checking what temp/new points to: %d\n",temp->val);
	    if(temp->parent)
	    {
		temp=temp->parent;
		count++;
	    }
	    if(temp->parent)
	    {
		temp=temp->parent;
		count++;
	    }
	    // printf("after doing temp->parent->parent %d count=%d\n",temp->val,count);
	    ll lh=0,rh=0,llh=0,lrh=0,rrh=0,rlh=0;
	    while(temp!=NULL && count==2)
	    {
		/************************************************************************************************************/
		/* set all height variables */
		if(temp->left==NULL)
		    lh=0;
		else
		{
		    lh = temp->left->h+1;
		    if(temp->left->left==NULL)
			llh=0;
		    else
			llh = temp->left->left->h+1;
		    if(temp->left->right==NULL)
			lrh=0;
		    else
			lrh=temp->left->right->h+1;
		}
		if(temp->right==NULL)
		    rh = 0;
		else
		{
		    rh = temp->right->h+1;
		    if(temp->right->right==NULL)
			rrh=0;
		    else
			rrh = temp->right->right->h+1;
		    if(temp->right->left==NULL)
			rlh=0;
		    else
			rlh=temp->right->left->h+1;
		}
		//printf(" LH = %d\nLLH = %d\nLRH = %d\nRH = %d\nRRH = %d\nRLH = %d\n",lh,llh,lrh,rh,rrh,rlh);

		/***********************************************************************************************************/

		//printf("temp->val = %d\n",temp->val);
		if(lh - rh > 1)
		{
		    if(llh > lrh)
		    {
			if(temp->val == bst->val)
			{
			    bst = rotr(temp);

			    tp tmp = temp;
			    while(tmp)
			    {
				tmp->h = set(tmp);
				setno(tmp);
				tmp=tmp->parent;
			    }
			}
			else
			{
			    if(temp->parent->val > temp->val)
			    {
				temp->parent->left = rotr(temp);
				tp tmp = temp;
				while(tmp)
				{
				    tmp->h = set(tmp);
				    setno(tmp);
				    tmp=tmp->parent;
				}
			    }
			    else
			    {
				temp->parent->right = rotr(temp);
				tp tmp = temp;
				while(tmp)
				{
				    tmp->h = set(tmp);
				    setno(tmp);
				    tmp=tmp->parent;
				}
			    }
			}
		    }
		    else if(lrh > llh)
		    {
			temp->left->parent->left = rotl(temp->left);

			tp tmp2 = temp->left->left;
			while(tmp2)
			{
			    tmp2->h = set(tmp2);
			    setno(tmp2);
			    tmp2=tmp2->parent;
			}
			if(temp->val == bst->val)
			{
			    bst = rotr(temp);

			    tp tmp = temp;
			    while(tmp)
			    {
				tmp->h = set(tmp);
				setno(tmp);
				tmp=tmp->parent;
			    }
			}
			else
			{
			    if(temp->parent->val > temp->val)
			    {
				temp->parent->left = rotr(temp);

				tp tmp = temp;
				while(tmp)
				{
				    tmp->h = set(tmp);
				    setno(tmp);
				    tmp=tmp->parent;
				}
			    }
			    else
			    {
				temp->parent->right = rotr(temp);

				tp tmp = temp;
				while(tmp)
				{
				    tmp->h = set(tmp);
				    setno(tmp);
				    tmp=tmp->parent;
				}
			    }
			}

		    }		
		    //printf("NEW temp->val = %d\n",temp->val);
		    break;
		}
		else if(rh - lh > 1)
		{
		    if(rrh > rlh)
		    {
			if(temp->val == bst->val)
			{
			    bst = rotl(temp);
			    tp tmp = temp;
			    while(tmp)
			    {
				tmp->h = set(tmp);
				setno(tmp);
				tmp=tmp->parent;
			    }
			}
			else
			{
			    if(temp->parent->val > temp->val)
			    {
				temp->parent->left = rotl(temp);
				tp tmp = temp;
				while(tmp)
				{
				    tmp->h = set(tmp);
				    setno(tmp);
				    tmp=tmp->parent;
				}
			    }
			    else
			    {
				temp->parent->right = rotl(temp);
				//printf("after return  VAL %d and 6's right %d\n",temp->parent->val,bst->right->val);
				tp tmp = temp;
				while(tmp)
				{
				    tmp->h = set(tmp);
				    setno(tmp);
				    tmp=tmp->parent;
				}
			    }
			}
		    }
		    else if(rlh > rrh)
		    {
			//printf("temp in right tree that is left heavy:   %d\n",temp->right->parent->right->val);
			temp->right->parent->right = rotr(temp->right);

			//printf("temp in right tree that is left heavy:   %d\n",temp->right->val);
			tp tmp1 = temp->right->right;
			while(tmp1)
			{
			    tmp1->h = set(tmp1);
			    setno(tmp1);
			    tmp1=tmp1->parent;
			}
			if(temp->val == bst->val)
			{
			    bst = rotl(temp);
			    tp tmp = temp;
			    while(tmp)
			    {
				tmp->h = set(tmp);
				setno(tmp);
				tmp=tmp->parent;
			    }
			}
			else
			{
			    if(temp->parent->val > temp->val)
			    {
				temp->parent->left = rotl(temp);
				tp tmp = temp;
				while(tmp)
				{
				    tmp->h = set(tmp);
				    setno(tmp);
				    tmp=tmp->parent;
				}
			    }
			    else
			    {
				temp->parent->right = rotl(temp);
				tp tmp = temp;
				while(tmp)
				{
				    tmp->h = set(tmp);
				    setno(tmp);
				    tmp=tmp->parent;
				}

			    }
			}
		    }
		    //printf("NEW temp->val = %d\n",temp->val);
		    break;
		}
		temp=temp->parent;
	    }

	    //printf("BST->val = %d\n",bst->val);
	    //postorder(bst);
	}
	else if(c[0]=='C')
	{
	    s(x);
	    search(bst,x);
	}
	else if(c[0]=='H')
	{
	    s(x);
	    co = fag = 0;
	    inorder(bst,x);
	    if(!fag)
		printf("NONE\n");
	}
	
	   else if(c[0]=='R')
	   {
	   s(x);
	   ans =0;
	   find(bst,x);
	   printf("%d\n",ans);
	   }
	else if(c[0]=='Q')
	    break;
    }
    return 0;
}
/*
void find(tp temp,ll x)
{
  if(temp==NULL)
    return ;
  else
    {
      if(x==temp->val)
	{
	  ans = ans + temp->lno;
	  return;
	}
      else if(x>temp->val)
	{
	  ans+=(temp->lno+1);
	  find(temp->right,x);
	}
      else if(x<temp->val)
	find(temp->left,x);
    }
}
*/
void find( tp froot,ll x)
{
    if(froot!=NULL)
    {
	if(froot->val > x)
	    find(froot->left,x);
	else
	{
	    if(froot->val == x)
	    {
		ans = ans + froot->lno;
		return;
	    }
	    else
	    {
   		ans = ans + froot->lno + 1;
	    	if(froot->val < x)
			find(froot->right,x);
	    }
	}
    }
    else
	return;
}
void setno(tp root)
{
    int a,b,c,d;
    a=0;
    b=0;
    c=0;
    d=0;
    if(root->left)
    {
	a=root->left->lno;
	b=root->left->rno;
    	root->lno=a+b+1;
    }
    else
	root->lno = 0;
    if(root->right)
    {
	c=root->right->rno;
	d=root->right->lno;
    	root->rno=c+d+1;
    }
    else
	root->rno = 0;

}
void inorder(tp root, ll x)
{
    if(root!=NULL)
    {
	inorder(root->left,x);
	co++;
	if(co==x)
	{
	    printf("%d\n",root->val);
	    fag=1;
	    return;
	}
	inorder(root->right,x);
    }
    else
    {
	return;
    }
}

void search(tp root, ll x)
{
    if(root!=NULL)
    {
	while(root!=NULL)
	{
	    if(x==root->val)
	    {
		printf("YES\n");
		return;
	    }
	    else if(x > root->val)
		root=root->right;
	    else
		root=root->left;
	}
	printf("NO\n");
    }
    else
    {
	printf("NO\n");
	return;
    }
}
