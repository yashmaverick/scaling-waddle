#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{
	int val;
	struct bst* left;
	struct bst* right;
	int height;
	int nleft;
	int nright;
}bst;
bst* root;
int visit[1000000];
bst* insert(bst* s,int x)
{
	if(s==NULL)
	{
		bst* new=(bst*)malloc(sizeof(bst));
		new->val=x;
		new->left=NULL;
		new->right=NULL;
		new->height=0;
		new->nleft=0;
		new->nright=0;
		return new;
	}
	if(s->val<x)
	{	
		s->right=insert(s->right,x);
		s->nright++;
	}	
		
	else
	{	
		s->left=insert(s->left,x);
		s->nleft++;
	}	
	int rh,lh;
	if(s->right==NULL)
		rh=-1;
	else
		rh=s->right->height;
	if(s->left==NULL)
		lh=-1;
	else
		lh=s->left->height;
	if(lh>rh)
		s->height=lh+1;
	else
		s->height=rh+1;
	if((lh-rh)<=1 && (lh-rh)>=-1)
		return s;
	else
	{
		//bst* s=p;
		int llh,lrh,rlh,rrh;
		if(lh!=-1 && s->left->right!=NULL)
			lrh=s->left->right->height;
		else if(lh!=-1 && s->left->right==NULL)
			lrh=-1;
		if(lh!=-1 && s->left->left!=NULL)
			llh=s->left->left->height;
		else if(lh!=-1 && s->left->left==NULL)
			llh=-1;
		if(rh!=-1 && s->right->left!=NULL)
			rlh=s->right->left->height;
		else if(rh!=-1 && s->right->left==NULL)
			rlh=-1;
		if(rh!=-1 && s->right->right!=NULL)
			rrh=s->right->right->height;
		else if(rh!=-1 && s->right->right==NULL)
			rrh=-1;
	

		if(lh>rh)
		{
			bst* y=s->left;
			if(lrh>llh)
			{
				bst* z=y->right;
				y->nright=z->nleft;
				z->nleft=y->nleft+y->nright+1;	//updating number of subtrees

				y->right=z->left;
				s->left=z;
				z->left=y;
				int a,b;
				if(y->left==NULL)
					a=-1;
				else
					a=y->left->height;
				if(y->right==NULL)
					b=-1;
				else
					b=y->right->height;
				if(a>b)
					y->height=a+1;
				else
					y->height=b+1;
				z->height=y->height+1;	

			}
			bst* a=s->left;
			int h1,h2,nh1,nh2,nh3,nh4;
			
			if(a->right==NULL)
				h1=-1;
				
			else
				h1=a->right->height;
			if(s->right==NULL)
				h2=-1;
			else
				h2=s->right->height;
			if(h1>h2)
				s->height=h1+1;
			else
				s->height=h2+1;
			s->nleft=a->nright;
			a->nright=s->nleft+s->nright+1;		//updating number of subtrees

			s->left=a->right;
			a->right=s;
				
			int h;
			if(a->left==NULL)
				h=-1;
			else
				h=a->left->height;
			if(h>s->height)	
				a->height=h+1;
			else
				a->height=s->height+1;
			return a;
		}
		else
		{
			bst* y=s->right;
			if(rlh>rrh)
			{
				bst* z=	y->left;
				y->nleft=z->nright;
				z->nright=y->nleft+y->nright+1;		//updating number of subtrees

				y->left=z->right;
				z->right=y;
				s->right=z;
				int a,b;
				if(y->right==NULL)
					b=-1;
				else
					b=y->right->height;
				if(y->left==NULL)
					a=-1;
				else
					a=y->left->height;
				if(a>b)
					y->height=a+1;
				else
					y->height=b+1;
				z->height=y->height+1;	
					
			}
			bst* a=s->right;
			s->nright=a->nleft;
			a->nleft=s->nleft+s->nright+1;	//updating number of subtrees

			int h3,h4;
			if(a->left==NULL)
				h3=-1;
			else
				h3=a->left->height;
			if(s->left==NULL)
				h4=-1;
			else
				h4=s->left->height;
			if(h3>h4)
				s->height=h3+1;
			else
				s->height=h4+1;
			s->right=a->left;
			a->left=s;
			int h;
			if(a->right==NULL)
				h=-1;
			else
				h=a->right->height;
			if(h>s->height)
				a->height=h+1;
			else
				a->height=s->height+1;
			return a;
		}		
		
	}
}
//int hx,flag;		
//bst* node;
/*void inorder(bst* p)
{
	if(p==NULL)
		return ;
	inorder(p->left);
	printf("val is:%d , height is: %d nleft=%d nright=%d\n",p->val,p->height,p->nleft,p->nright);
	inorder(p->right);
}*/
/*void healthy(bst* p,int x)
{
	if(p==NULL)
		return ;
	healthy(p->left,x);
	hx++;
	if(hx==x)
	{	
		node=p;
		return;
	}	
	healthy(p->right,x);
}*/	
int healthy(bst* p, int x)
{
	if(p==NULL)
		return 0;
	int r=p->nleft+1;
	if(r==x)
		return p->val;
	else if(x<r)
		healthy(p->left,x);
	else
		healthy(p->right,x-r);
}		
int hx;
void rotten1(bst* p,int x)
{
	if(p==NULL)
		return;
	rotten1(p->left,x);			//1st version inefficient
	//hx++;
	if(p!=NULL && p->val<x)
		hx++;
	if(p!=NULL && p->val>=x)
		return;
	rotten1(p->right,x);
}

int rotten2(bst* p,int x,int c)
{
	if(p!=NULL && p==root && p->val==x)		//2nd version better
		return p->nleft;
	//else if(p!=NULL && p->val==x)
	//	return c;
	else if(p==NULL) //||  p->val>=x)
		return c;
	else if(p->val==x)	
		return c;
	if(x>p->val)	
		rotten2(p->right,x,c+p->nleft+1);
	else if(x<p->val)	
		rotten2(p->left,x,c);
}	
		

/*void check(bst* p, int x)
{
	if(p==NULL)
		return;
	check(p->left,x);
	if(p!=NULL && p->val==x)
	{	
		flag=1;
		return;
	}
	check(p->right,x);
}*/	
		
int check(bst* p,int x)
{
	//if(p!=NULL && p->val==x)
	//	return 1;
	if(p==NULL)
		return 0;
	else if(p->val==x)
		return 1;
	else if(x<p->val)
		check(p->left,x);
	else if(x>p->val)
		check(p->right,x);
}		
int main()
{
	int q,n,x,i,count=0;
	char s[50];root=NULL;
	while(1)
	{
		scanf("%s",s);
		if(strcmp(s,"Quit")==0)
			return 0;
		else if(strcmp(s,"SetHealthy")==0)
		{
			scanf("%d",&x);count++;
			if(x<1000000)
				visit[x]=1;
			root=insert(root,x);
				
			
			//inorder(root);
		}
		else if(strcmp(s,"Healthy")==0)
		{
			scanf("%d",&x);//hx=0;node=NULL;
			int ans;
			//if(x!=0 && x<=count)
				ans=healthy(root,x);
			//if(count==0 || x==0 || count<x)
			if(ans==0)	
				printf("NONE\n");
			else
				printf("%d\n",ans);
		}
		else if(strcmp(s,"RottenBefore")==0)
		{
			scanf("%d",&x);hx=0;
			if(check(root,x)==0)
				hx=rotten2(root,x,0);
			else
				rotten1(root,x);
			//if(hy>0)
			//	printf("%d\n",r);
			//else
				printf("%d\n",hx);
		}
		else if(strcmp(s,"CheckHealthy")==0)
		{
			scanf("%d",&x);int flag;
			if(x<1000000)
			{	
				if(visit[x]==1)
					flag=1;
				else
					flag=0;
			}			
			flag=check(root,x);
			if(flag==1)
				printf("YES\n");
			else
				printf("NO\n");
		}		
	}
	//return 0;
}	

	
