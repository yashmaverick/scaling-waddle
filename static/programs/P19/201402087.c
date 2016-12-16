#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int in;

typedef struct t
{
		int d;
		struct t* next[10];
}t;

t* root;

void insert( char a[] );
void check(t* head);

int flag=0;

int main()
{
		int test;
		scanf("%d",&test);
		while( test-- )
		{
				int i;
				int n;
				flag=0;
				root=NULL;
				scanf("%d",&n);
				while( n-- )
				{
						char a[11];
						scanf("%s",a);
						int yo=a[0]-'0';
						in=0;
						insert(a);
						//printf("%d",root->next[1]->d);
						/*	if(root->next[1]->d==1)
							{
							int lol;
							for( lol=0 ; lol<10 ; lol++ )
							if(root->next[1]->next[lol]!=NULL)
							break;
							printf("%d\n",lol);
							}*/
				}
				check(root);
				if(flag==1)
						printf("NO\n");
				else
						printf("YES\n");
		}
		return 0;
}

void insert( char a[] )
{
		if( root==NULL)
		{
				root=(t*)malloc(sizeof(t));
				int j=0;
				for( j=0 ; j<10 ; j++ )
						root->next[j]=NULL;
		}
		t* head=root;
		int k;
		int len=strlen(a);
		for( k=0 ; k<len ; k++)
		{
				int temp = a[k]-'0';
				if( head->next[temp]==NULL )
				{
						head->next[temp]=(t*)malloc(sizeof(t));
						int j=0;
						for( j=0 ; j<10 ; j++ )
								head->next[temp]->next[j]=NULL;
				}
				head=head->next[temp];
		}
		if(head->d==1)
				flag=1;
		head->d=1;
		/*int j=0;
		for( j=0 ; j<10 ; j++ )
				head->next[j]=NULL;*/
}			

void check(t* head)
{
		if(head->d==1)
		{
				//printf("in\n");
				int lol;
				for( lol=0 ; lol<10 ; lol++ )
						if(head->next[lol]!=NULL)
						{
								//printf("lol=%d\n",lol);
								break;
						}
				if(lol!=10)
				{
						flag=1;
						return;
				}
		}

		int k;
		for( k=0 ; k<10 ; k++ )
				if(head->next[k]!=NULL)
				{
						//printf("%d\n",k);
						check(head->next[k]);
				}
		return ;
}
