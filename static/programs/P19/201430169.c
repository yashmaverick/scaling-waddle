#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int leaf;
	struct node* child[10];
}node;	
node* create()
{
	node* new=(node*)malloc(sizeof(node));
	new->leaf=0;
	int i;
	for(i=0;i<10;i++)
		new->child[i]=NULL;
	return new;
}	
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char C[11];
		long long int n,S[11],i,j,l,flag,ans;
		scanf("%lld",&n);
		ans=0;
		node* root=create();
		for(j=0;j<n;j++)
		{
			scanf("%s",C);
			if(ans==0)
			{
				l=0;
				for(i=0;C[i]!='\0';i++)
					S[i]=C[i]-'0';
				flag=0;
				node* p=root;
				l=i;
				for(i=0;i<l;i++)
				{
					if(p->child[S[i]]==NULL)
					{
						node* new=create();
						p->child[S[i]]=new;
						//if(i==l-1)
						//	p->leaf=1;
						//if(flag==1)
						//	flag=0;
						p=new;
						//printf("Create leaf %d\n",p->leaf);
						//printf("for %lld Created\n",S[i]);
					}
					else
					{
						if(p->child[S[i]]->leaf==1)
						{
							flag=1;
							//printf("made flag 1\n");
							}
						//if(p->leaf==1)
						//	break;
						//printf("for %lld Not Created\n",S[i]);
						if(i==l-1)
						{
							flag=1;
							p->leaf=1;
						}
						p=p->child[S[i]];
					}
				}
				if(i==l)
				{
					p->leaf=1;
					//printf("Leaf %d\n",p->leaf);
				}
				if(flag==1)
					ans=1;
			}	
		}
		if(ans==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}

