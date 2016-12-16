#include<stdio.h>
#include<stdlib.h>
int flag;
struct node {
	int data;
	struct node* next[10];
};
long long int a[1000003];
struct node* root;
struct node*  make()
{
	int x;
	struct node *b;
	b=(struct node*)malloc(sizeof(struct node));
	b->data = 99;
	for(x=0;x<10;x++)
		b->next[x] = NULL;
	return b;
}
void insert(long long int n) {
	int in;
	long long int lev;
	long long int p;
	long long int k=0;
	int stat=0;
	if(n==0)
	{
		k=1;
		a[0]=0;
	}
	while(n)
	{
		a[k]=n%10;
		n=n/10;
		k++;
	}
	if(root==NULL)
		root=make();
	struct node *b=root;  
	for(lev=0,p=k-1;lev<k,p>=0;lev++,p--)
	{
		in=a[p];
	//	printf("%d\n",in);
		if(b->next[in] == NULL) {
			if(flag==1)
			{
				if(b->data==99)
				{
					flag=0;
					stat=0;
				//	b->data=lev;
				}
				else
					stat=1;

		//		else
		//			flag=0;
			}
			b->next[in] = make();  
			
		}
		else
			flag=1;
		b=b->next[in];
		if(stat==1)
			b->data=lev;
//		printf("%d\n",flag);
	}
	b->data=lev;      
}

int main() {
	long long int n,j,k,m;
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		root=NULL;
		flag=0;
		scanf("%lld",&n);
		for(j=0;j<n;j++)
		{
			scanf("%lld",&m);
			if(flag==1)
				continue;
			insert(m);
		}
		if(flag==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}

