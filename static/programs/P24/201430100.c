#include<stdio.h>
#include<stdlib.h>

typedef struct nod
{
	int number; //number of nodes including itself
	int height; //height of tree from that node
	int val;
	struct nod *left;
	struct nod *right;
	/* data */
}nod;

typedef struct nod *node;


node insert(int x,node head)
{
	if(head==NULL)
	{
		node temp;
		temp=malloc(sizeof(nod));
		temp->val=x;
		temp->height=1;
		temp->number=1;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}

	node temp;
	if(x<head->val)	head->left=insert(x,head->left);
	else head->right=insert(x,head->right);
		
	head->number++;



	int left=0,right=0;

	if(head->left==NULL && head->right==NULL) return head;
	else if(head->left==NULL)
	{
		node t1=head->right;
		if(t1->left==NULL && t1->right==NULL) return head;
	}
	else if(head->right==NULL)
	{
		node t1=head->left;
		if(t1->left==NULL && t1->right==NULL) return head;
	

	}





	if(head->left!=NULL) left=head->left->height;
	if(head->right!=NULL) right=head->right->height;

	if(left>=right) head->height=left+1;
	else head->height=right+1;

	temp=head;


	if(left>right+1)
	{
		int na=0,nb=0,nc=0,nd=0;

		int le=0,ri=0;
		node temp1=head->left;

		if(head->right!=NULL) nd=head->right->number;


		if(temp1->left!=NULL)
		 le=temp1->left->height; 
		if(temp1->right!=NULL)
		ri=temp1->right->height;

		if(le>=ri) //left left
		{
			node temp3,temp4;
			temp4=temp1->left;
	
			temp3=temp1->right;
			temp1->right=temp;
			temp->left=temp3;

			if(temp3!=NULL) nc=temp3->number;
			if(temp4->left!=NULL) na=temp4->left->number;
			if(temp4->right!=NULL) nb=temp4->right->number;


			int p=0,q=0;

			if(temp->left!=NULL) p=temp->left->height;
			if(temp->right!=NULL) q=temp->right->height;


			if(p>=q) temp->height=p+1;
			else temp->height=q+1;



			temp=temp1;
		}
		else
		{
			if(temp1->left!=NULL) na=temp1->left->number;

			node t1=temp1->right;
			if(t1->left!=NULL) nb=t1->left->number;
			if(t1->right!=NULL) nc=t1->right->number;


			temp->left=temp1->right;
			node temp3=temp1->right->left;
			temp1->right->left=temp1;
			temp1->right=temp3;

			temp1=temp->left;
			temp3=temp1->left;

			int p=0,q=0;

			if(temp3->left!=NULL) p=temp3->left->height;
			if(temp3->right!=NULL) q=temp3->right->height;


			if(p>=q) temp3->height=p+1;
			else temp3->height=q+1;

			p=0; q=0;

			if(temp1->left!=NULL) p=temp1->left->height;
			if(temp1->right!=NULL) q=temp1->right->height;


			if(p>=q) temp1->height=p+1;
			else temp1->height=q+1;


			p=0,q=0;

			if(temp->left!=NULL) p=temp->left->height;
			if(temp->right!=NULL) q=temp->right->height;


			if(p>=q) temp->height=p+1;
			else temp->height=q+1;



			
			temp3=temp1->right;
			temp1->right=temp;
			temp->left=temp3;

			p=0,q=0;

			if(temp->left!=NULL) p=temp->left->height;
			if(temp->right!=NULL) q=temp->right->height;


			if(p>=q) temp->height=p+1;
			else temp->height=q+1;

		
			temp=temp1;
		}
			temp->left->number=na+nb+1;
			temp->right->number=nc+nd+1;
			temp->number=na+nb+nc+nd+3;

			

	}
	else if(right>left+1)
	{
		int le=0,ri=0;
		node temp1=head->right;

		int na=0,nb=0,nc=0,nd=0;


		if(head->left!=NULL) na=head->left->number;




		if(temp1->left!=NULL)
		le=temp1->left->height;
		if(temp1->right!=NULL)
		ri=temp1->right->height;

		if(le<ri)
		{
			if(temp1->left!=NULL) nb=temp1->left->number;

			node te; te=temp1->right;
			
			if(te->left!=NULL) nc=te->left->number;
			if(te->right!=NULL) nd=te->right->number;

			node temp3;
			temp3=temp1->left;
			temp1->left=temp;
			temp->right=temp3;

			int p=0,q=0;

			if(temp->left!=NULL) p=temp->left->height;
			if(temp->right!=NULL) q=temp->right->height;


			if(p>=q) temp->height=p+1;
			else temp->height=q+1;

			temp=temp1;

		}
		else
		{
			if(temp1->right!=NULL) nd=temp1->right->number;

			node te=temp1->left;

			if(te->left!=NULL) nb=te->left->number;
			if(te->right!=NULL) nc=te->right->number;


			temp->right=temp1->left;
			node temp3=temp1->left->right;
			temp1->left->right=temp1;
			temp1->left=temp3;

			temp1=temp->right;
			temp3=temp1->right;

			int p=0,q=0;

			if(temp3->left!=NULL) p=temp3->left->height;
			if(temp3->right!=NULL) q=temp3->right->height;


			if(p>=q) temp3->height=p+1;
			else temp3->height=q+1;

			p=0; q=0;

			if(temp1->left!=NULL) p=temp1->left->height;
			if(temp1->right!=NULL) q=temp1->right->height;


			if(p>=q) temp1->height=p+1;
			else temp1->height=q+1;


			p=0,q=0;

			if(temp->left!=NULL) p=temp->left->height;
			if(temp->right!=NULL) q=temp->right->height;


			if(p>=q) temp->height=p+1;
			else temp->height=q+1;



			
			temp3=temp1->left;
			temp1->left=temp;
			temp->right=temp3;

			p=0,q=0;

			if(temp->left!=NULL) p=temp->left->height;
			if(temp->right!=NULL) q=temp->right->height;


			if(p>=q) temp->height=p+1;
			else temp->height=q+1;


			temp=temp1;
		}	
			temp->left->number=na+nb+1;
			temp->right->number=nc+nd+1;
			temp->number=na+nb+nc+nd+3;
			

	}	

	return temp;
}

int check(node head,int x)
{
	if(head==NULL) return 0;

	if(head->val==x) return 1;

	if(x<head->val) return check(head->left,x);
	else return check(head->right,x);
}

int healthy(node head,int x)
{
	int l=0,r=0;

	if(head->left!=NULL) l=head->left->number;
	if(head->right!=NULL) r=head->right->number;

	if(x==l+1) return head->val;
	else if(x<l+1) return healthy(head->left,x);
	else return healthy(head->right,x-l-1); 

}

int rotten(node head,int x)
{
	if(head==NULL) return 0;

	int t=0;
	if(head->left!=NULL) t=head->left->number;
	
	if(head->val==x) return t;
	else if(head->val<x) return t+1+rotten(head->right,x);
	else return rotten(head->left,x);
}


int main()
{
	node head=NULL;

	char c;
	int count=0;

	while((c=getchar())!='Q')
	{
		if(c=='S')
		{
			while((c=getchar())!=' ') {;}
			int x;
			scanf("%d",&x); getchar();
			
			head=insert(x,head);
			count++;
		}
		else if(c=='C')
		{
			while((c=getchar())!=' ') {;}
			int x;
			scanf("%d",&x); getchar();
			
			int t=check(head,x);
			if(t==1) printf("YES\n");
			else printf("NO\n");
		}
		else if(c=='H')
		{
			while((c=getchar())!=' ') {;}
			int x;
			scanf("%d",&x); getchar();
			
			if(x<=count)
			{	
				printf("%d\n",healthy(head,x));
			}
			else printf("NONE\n");	

		}
		else if(c=='R')
		{
			while((c=getchar())!=' ') {;}
			int x;
			scanf("%d",&x); getchar();
			
			printf("%d\n",rotten(head,x));
		}
	}

	while((c=getchar())!=EOF) {;}
	return 0;
}