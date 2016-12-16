#include<stdio.h>
#include<stdlib.h>
int sz=1,n,a[1000000],b[1000000],c[1000000],d[1000000],flagc=0,flagd=0,szc=0,szd=0;
typedef struct node
{
	int val;
	struct node *left;
	struct node *right;
}node;
node *head=NULL;
int tree(int lind,int rind,int index,node *cur)
{
	int ind,ele,i;
	ele=a[sz];
	sz++;
        node *new=malloc(sizeof(node));
	new->val=ele;
	if(index==0)
		cur->left=new;
	if(index==1)
		cur->right=new;
	if(lind!=rind)
	{
	for(i=lind;i<=rind;i++)
		if(b[i]==ele)
		{
			ind=i;
			break;
		}
	if(ind!=lind)
	//	cur->left=new;
	//else
		tree(lind,ind-1,0,new);
	if(ind!=rind)
//		cur->right=new;
//	else
		tree(ind+1,rind,1,new);
	}
	return;
}
/*void print(node *root)
{
	if(root==NULL)
		return;
	print(root->left);
	printf("%d ",root->val);
	print(root->right);
}*/
void searchc(node *temp,int ele)
{
	if(temp==NULL)
		return;
	if(temp->val==ele)
	{
		c[0]=ele;
		szc=1;
		flagc=1;
		return;
	}
	if(flagc!=1)
		searchc(temp->left,ele);
	if(flagc!=1)
		searchc(temp->right,ele);
	if(flagc==1)
	{
		c[szc]=temp->val;
		szc++;
	}
}
void searchd(node *temp,int ele)
{
	if(temp==NULL)
		return;
	if(temp->val==ele)
	{
		d[0]=ele;
		szd=1;
		flagd=1;
		return;
	}
	if(flagd!=1)
		searchd(temp->left,ele);
	if(flagd!=1)
		searchd(temp->right,ele);
	if(flagd==1)
	{
		d[szd]=temp->val;
		szd++;
	}
}
int main()
{
	int i,t,v1,v2,x,ind;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	x=a[0];
	for(i=0;i<n;i++)
		if(b[i]==x)
		{
			ind=i;
			break;
		}
	head=malloc(sizeof(node));
	head->val=x;
	if(ind!=0)
		tree(0,ind-1,0,head);
	if(ind!=n-1)
		tree(ind+1,n-1,1,head);
	//print(head);
	scanf("%d",&t);
	while(t--)
	{
		flagc=0;
		flagd=0;
		szd=0;
		szc=0;
		scanf("%d%d",&v1,&v2);
		searchc(head,v1);
		searchd(head,v2);
		if(szc==szd)
		{
		for(i=szc;i>0;i--)
			if(c[i-1]!=d[i-1])
				break;
		printf("%d\n",c[i]);
		}
		else if(szc>szd)
		{
			for(i=1;i<=szd;i++)
				if(c[szc-i]!=d[szd-i])
					break;
			printf("%d\n",c[szc-i+1]);
		}
		else if(szd>szc)
		{
			for(i=1;i<=szc;i++)
				if(c[szc-i]!=d[szd-i])
					break;
			printf("%d\n",c[szc-i+1]);
		}
		for(i=0;i<szc;i++)
			c[i]=0;
		for(i=0;i<szd;i++)
			d[i]=0;

	}
	return 0;
}

