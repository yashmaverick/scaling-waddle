#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
typedef long long int ll;
ll count;
struct node{
	ll val,height,no;
	struct node* l;
	struct node* r;
};
node* rotateright(node*);
node* rotateleft(node*);
void print(node*,ll);
void inord(node*,ll);
ll is_healthy(node*,ll);
ll rotten(node*, ll);
ll number(node* a)
{
	if(a==NULL)
	{
		return 0;
	}
	else
	{
		return a->no;
	}
}
ll maximum(ll a,ll b)
{
	return a>b?a:b;
}
ll hite(node* a)
{
	if(a==NULL)
	{
		return 0;
	}
	else
	{
		return a->height;
	}
}
node* insert(node* root,ll dat)
{
	ll lh,rh,bal;
	if(root==NULL)
	{
		node* tmp=(node*)malloc(sizeof(node));
		tmp->val=dat;
		tmp->l=NULL;
		tmp->r=NULL;
		tmp->height=1;
		tmp->no=0;
		return tmp;
	}
	if(dat>root->val)
	{
		root->r=insert(root->r,dat);
	}
	else
	{
		root->l=insert(root->l,dat);
		(root->no)++;
	}
	root->height=maximum(hite(root->l),hite(root->r))+1;
	lh=hite(root->l);
	rh=hite(root->r);
	bal=lh-rh;
	//	printf("%d\t%d\t%d\n",lh,rh,bal);
	if(bal<-1&&dat>root->r->val)
	{
		root=rotateleft(root);
	}
	else if(bal<-1&&dat<root->r->val)
	{
		root->r=rotateright(root->r);
		root=rotateleft(root);
	}
	else if(bal>1 && dat<root->l->val)
	{
		root=rotateright(root);
	}
	else if(bal>1&&dat>root->l->val)
	{
		root->l=rotateleft(root->l);
		root=rotateright(root);
	}
	return root;
}
node* rotateleft(node* root)
{
	ll num;
	num=number(root->r);
	node* tmp=root->r;
	node* wen=tmp->l;
	tmp->l=root;
	root->r=wen;
	root->height=maximum(hite(root->l),hite(root->r))+1;
	tmp->height=maximum(hite(tmp->l),hite(tmp->r))+1;
	tmp->no=(number(root))+1;
	//mp->no=(number(root->r));
	tmp->no+=num;
	return tmp;
}
node* rotateright(node* root)
{
	ll num;
	num=number(root);
	num-=number(root->l);
	num--;
	node* tmp=root->l;
	node* wen=tmp->r;
	tmp->r=root;
	root->l=wen;
	root->height=maximum(hite(root->l),hite(root->r))+1;
	tmp->height=maximum(hite(tmp->l),hite(tmp->r))+1;	
	root->no=num;
	return tmp;
}
int main()
{
	node* root=NULL;
	while(1)
	{
		char s[20];
		ll op;
		scanf("%s",s);
		if(s[0]=='Q')
		{
			break;
		}
		scanf("%Ld",&op);
		if(s[0]=='S')
		{
			//		printf("Setting %d\n",op);
			root=insert(root,op);
//			print(root,op);
			//	print(root);
		}
		else if(s[0]=='C')
		{
			//	printf("Checking %d\n",op);
			int re=check(root,op);
			if(re)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
		else if(s[0]=='H')
		{
			ll ans;
			//	printf("HH %d\n",op);
			//	print(root,op);
			ans=is_healthy(root,op);
			if(ans==-1)
			{
				printf("NONE\n");
			}
			else
			{
				printf("%Ld\n",ans);
			}
		}
		else
		{
			ll ans;
			ans=rotten(root,op);
			//	printf("%Ld\n",count);
			printf("%Ld\n",ans);
		}
	}
	return 0;
}
int check(node* root,ll ch)
{
	int tm;
	if(root==NULL)
	{
		return 0;
	}
	if(ch>root->val)
	{
		tm=check(root->r,ch);
	}
	else if(ch<root->val)
	{
		tm=check(root->l,ch);
	}
	else
	{
		return 1;
	}
}
ll is_healthy(node* root,ll op)
{
	ll ans=-1;
//	printf("Count:%Ld\n",op);
	while(root!=NULL)
	{
		if(op<=root->no)
		{
			root=root->l;
		}
		else if(op-1==root->no)
		{
			ans=root->val;
			break;
		}
		else
		{
			op=op-(root->no+1);
			root=root->r;
		}
	}
	return ans;
}
ll rotten(node* root,ll op)
{
	ll ans=0;
	while(root!=NULL)
	{
		if(root->val<op)
		{
			ans+=(root->no)+1;
			root=root->r;
		}
		else
		{
			root=root->l;
		}
	}
	return ans;
}
