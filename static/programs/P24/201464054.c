#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define ll long long int
#define sint(n); scanf("%d",&n);
#define pint(n); printf ("%d\n",n);
#define sll(n); scanf("%lld",&n);
#define pll(n); printf("%lld\n",n);
#define sst(n); scanf("%s",n);
#define pst(n); printf ("%s\n",n);
#define TEST ll test;scanf("%lld",&test);while(test--)
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)
#define f1r(i,n) for(i=n;i>=1;i--)
#define f0r(i,n) for(i=n;i>0;i--)
#define set(x,y) memset(x,y,sizeof(x));
#define mod 1000000007
#define SIZE 200005


ll count;


struct node
{
	ll data;
	ll height;	//current node height
	ll nl;	//no of elements in left subtree
	ll nr;	//no of elements in right subtree
	struct node* left;
	struct node* right;
};
struct node* root;
ll rootflag;	// is value assigned to root ??

ll maximum ( ll a, ll b ){	if (a>b)return a;	else return b;	}

ll nodeheight(struct node* xyz){	if (xyz==NULL)return 0;		else return xyz->height;	}
void rotateright ( struct node* curr_root , struct node* ancestor , ll direction )
{
	struct node* curr_left;
	struct node* curr_left_right;
	curr_left=malloc(sizeof(struct node));
	curr_left_right=malloc(sizeof(struct node));

	curr_left=curr_root->left;
	curr_left_right=curr_root->left->right;

	curr_left->right=curr_root;
	curr_root->left=curr_left_right;

	curr_root->height=maximum(nodeheight(curr_root->left),nodeheight(curr_root->right))+1;
	curr_left->height=maximum(nodeheight(curr_left->left),nodeheight(curr_left->right))+1;

	//curr_root->height--;curr_root->height--;


	curr_root->nl=curr_left->nr;
	curr_left->nr = curr_root->nl + curr_root->nr + 1;


	if (ancestor==NULL)
		root=curr_left;
	else
	{
		if (direction == -1)
			ancestor->left=curr_left;
		else if (direction == 1)
			ancestor->right=curr_left;
	}
	return;
}


void rotateleft ( struct node* curr_root , struct node* ancestor , ll direction )
{
//	printf("rotate left\n");
	struct node* curr_right;
	struct node* curr_right_left;
	curr_right=malloc(sizeof(struct node));
	curr_right_left=malloc(sizeof(struct node));

	curr_right=curr_root->right;
	curr_right_left=curr_root->right->left;


	curr_right->left=curr_root;
	curr_root->right=curr_right_left;


	curr_root->height=maximum(nodeheight(curr_root->left),nodeheight(curr_root->right))+1;
	curr_right->height=maximum(nodeheight(curr_right->left),nodeheight(curr_right->right))+1;

	//	curr_root->height--;curr_root->height--;



	curr_root->nr=curr_right->nl;
	curr_right->nl=curr_root->nl + curr_root->nr + 1;

	if (ancestor==NULL)
		root=curr_right;
	else
	{
		if (direction == -1)
			ancestor->left=curr_right;
		else if (direction == 1)
			ancestor->right=curr_right;
	}
	return;
}


void insertintree ( ll x , struct node* curr_root , struct node* ancestor, ll direction)
{
	if (rootflag==0){		root->data=x;		root->nl=0;	root->nr=0;	root->left=NULL;	root->right=NULL;	root->height=1;		rootflag=1;	}
	else
	{
		//		printf ("data visited = %lld\n",curr_root->data);
		if (x > curr_root->data && curr_root->right==NULL)
		{
			struct node* temp;	temp=malloc(sizeof(struct node));
			temp->data=x;	temp->left=NULL;	temp->right=NULL;	temp->height=1;	temp->nl=0;	temp->nr=0;	curr_root->right=temp;
			curr_root->nr++;
			if (curr_root->left==NULL)
				curr_root->height=2;
			else
				curr_root->height=maximum(curr_root->left->height,1)+1;
		}
		else if (x < curr_root->data && curr_root->left==NULL)
		{
			struct node* temp;	temp=malloc(sizeof(struct node));
			temp->data=x;	temp->left=NULL;	temp->right=NULL;	temp->height=1;	temp->nl=0;	temp->nr=0;	curr_root->left=temp;
			curr_root->nl++;
			if (curr_root->right==NULL)

				curr_root->height=2;
			else
				curr_root->height=maximum(curr_root->right->height,1)+1;
		}
		else if ( x < curr_root->data )
		{
			insertintree(x,curr_root->left,curr_root,-1);
			curr_root->nl++;
			if (curr_root->right==NULL)
				curr_root->height=curr_root->left->height+1;
			else
				curr_root->height=maximum(curr_root->left->height,curr_root->right->height)+1;
		}
		else if ( x > curr_root->data )
		{
			insertintree(x,curr_root->right,curr_root,1);
			curr_root->nr++;
			if (curr_root->left==NULL)
				curr_root->height=curr_root->right->height+1;
			else
				curr_root->height=maximum(curr_root->left->height,curr_root->right->height)+1;
		}





		if ( (nodeheight(curr_root->left) - nodeheight(curr_root->right)) > 1 )
		{
			if ( x < curr_root->left->data )
			{	rotateright(curr_root,ancestor,direction);	}
			else if ( x > curr_root->left->data )
			{
				rotateleft(curr_root->left,curr_root,-1);
				rotateright(curr_root,ancestor,direction);
			}
		}
		else if ( (nodeheight(curr_root->right) - nodeheight(curr_root->left)) > 1 )
		{
			if ( x > curr_root->right->data )
			{
				rotateleft(curr_root,ancestor,direction);
			}
			else if ( x < curr_root->right->data )
			{
				rotateright(curr_root->right,curr_root,1);
				rotateleft(curr_root,ancestor,direction);
			}
		}
	}
	return;
}

ll check ( ll x , struct node* curr_root ){
	if (rootflag==0)
		return 0;
	else{
		if ( x==curr_root->data )return 1;
		else if ( x > curr_root->data && curr_root->right==NULL )return 0;
		else if ( x < curr_root->data && curr_root->left==NULL )return 0;
		else if ( x > curr_root->data )return (check(x,curr_root->right));
		else if ( x < curr_root->data )return (check(x,curr_root->left));
	}
}

void printpreorder(struct node* curr_root)
{
	if (curr_root!=NULL)
	{
		printf ("data = %lld height = %lld nl = %lld nr = %lld\n",curr_root->data,curr_root->height,curr_root->nl,curr_root->nr);
		printpreorder(curr_root->left);
		printpreorder(curr_root->right);
	}
	return;
}
void printinorder(struct node* curr_root)
{
	if (curr_root!=NULL)
	{
		printinorder(curr_root->left);
		printf ("data = %lld height = %lld nl = %lld nr = %lld\n",curr_root->data,curr_root->height,curr_root->nl,curr_root->nr);
		printinorder(curr_root->right);
	}
	return;
}

void setx ( ll input , struct node* curr_root )
{
	insertintree(input,curr_root,NULL,0);
	return;
}

//check default height values


void rotten ( ll x , struct node* curr_root ){
	struct node* temp;	temp=malloc(sizeof(struct node));
	temp=curr_root;
	while (1){
		if ( temp->data == x ){		count+=temp->nl;	return;		}
		else if ( x < temp->data ){	
			if (temp->left==NULL){	return;		}
			else	temp=temp->left;
		}
		else if ( x > temp->data ){
			if (temp->right==NULL){		count+=(temp->nl)+1;	return;			}
			else{	count+=((temp->nl)+1);		temp=temp->right;			}
		}
	}
	return;
}


void healthy(ll x){
	struct node* temp;	temp=malloc(sizeof(struct node));
	temp=root;
	ll ct;	ct=0;
	while (1){
		if ( temp->nl + 1 == x ){	pll(temp->data);	return;		}
		else if ( temp->nl < x ){	x-=(temp->nl+1);	temp=temp->right;		}
		else{	temp=temp->left;	}
	}
	return;
}



int main()
{
	root=malloc(sizeof(struct node));
	rootflag=0;
	ll totalnodes;
	totalnodes=0;
/*#ifdef DEBUG
	setx(10,root);
	printinorder(root);
	printf ("--------------------------\n");
	setx(20,root);
	printinorder(root);
	printf ("--------------------------\n");
	setx(30,root);
	printinorder(root);
	printf ("--------------------------\n");
	setx(40,root);
	printinorder(root);
	printf ("--------------------------\n");
	setx(50,root);
	printinorder(root);
	printf ("--------------------------\n");
	setx(25,root);
	printinorder(root);
	printf ("--------------------------\n");
#endif
*/		while (1){
		ll ip;
		char str[20];
		sst(str);
		if (str[0]=='Q'){break;}
		sll(ip);
		if (str[0]=='S'){if(check(ip,root)==0){setx(ip,root);totalnodes++;/*printinorder(root);printf("--------------------------\n");*/}}
		else if (str[0]=='C'){if (check(ip,root)==0)printf("NO\n");	else printf("YES\n");}
		else if (str[0]=='H'){if (ip>totalnodes)printf("NONE\n");	else {count=0;	healthy(ip);}	}
		else if (str[0]=='R'){count=0;	rotten(ip,root);	pll(count);}
		}
	return 0;
}
