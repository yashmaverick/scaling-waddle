#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*void freefun(node *root)
{
int i;
if(root!=NULL)
{
free(root);
for(i=0;i<11;i++)
freefun(root->b[i]);
}
}*/
typedef struct node
{
	char c;
	struct node *b[11];
	int count;
	int flag;
}node;
typedef struct head
{
	struct node *cr[11];
}head;
int i=0;
node *insert(node *root,char *l)
{
	//	printf("%p\n",root);
	char fr=l[i];
	int j;
	//	printf("Printing:%c\n",fr);
	if(l[i]!='\0')
	{
		if(root==NULL)
		{
			root=(node *)malloc(sizeof(node));
			root->count=1;
			//	printf("null: %d\n",root->count);
			root->c=l[i];
			for(j=0;j<11;j++)
				root->b[j]=NULL;
			//l++;
			i++;
			if(i<strlen(l))
				fr=l[i];
			if(l[i]=='\0')
				root->flag=1;
			//if(l[i]!='\0')	

			//	{
			//	fr=l[i];
			//	printf("Printing in NULL:%c\n",fr);
			
		//for(j=0;j<11;j++)
		//	root->b[j]=NULL;

				root->b[fr-'0']=insert((root->b[fr-'0']),l);
		}

			else
			{
				(root->count)++;
				i++;
				if(i<strlen(l))
					fr=l[i];
				//	printf("%d\n",root->count);
				//l++;


				//if(l[i]!='\0')
				//	fr=l[i];
				//	printf("Printing in NULL:%c\n",fr);
				if(l[i]=='\0')
					root->flag=1;
				root->b[fr-'0']=insert((root->b[fr-'0']),l);

			}
			return root;
		}
	//	root=(node *)malloc(sizeof(root));
		//	root->flag=1;
	//	root->count=0;
		return 	NULL;
	}
	node *r,*temp=NULL;
	head g;
	int main()
	{
		int test,n,yy,len;
		char s[15];
		scanf("%d",&test);
		while(test--)
		{
			
			for(yy=0;yy<11;yy++)
				g.cr[yy]=NULL;
			scanf("%d",&n);
			int st=1;
			while(n--)
			{
				
				scanf("%s",s);	
				//printf("%c\n",hy);
				i=0;
				//	printf("First:%c\n",s[0]);
				(g.cr[s[0]-'0'])=insert((g.cr[s[0]-'0']),s);
				//	printf("Final:%p\t%c\n",g.cr[s[0]-'0'],g.cr[s[0]-'0']->c);
				int hyu=s[0];
				int irr=0;
				temp=g.cr[hyu-'0'];
				//while(s[irr]!='\0')
				while(s[irr]!='\0')
				{
					len=strlen(s);
					//	r=temp;
					//	printf("%d %d %d \n",temp->count,temp->b[hyu-'0']->count,temp->flag);
					//	if((temp->count!=(temp->b[hyu-'0'])->count)&&temp->count>1)	
					//	st=0;
					if(temp->flag==1&&temp->count>1)
						st=0;


					//	printf("%d\n",r->count);
					//irr++;
					//if(irr<len)
					//	hyui=s[irr++];
					//temp=g.cr[hyu-'0'];

					irr++;
					//	if(s[irr]=='\0')
					//		{
					//	if(s[irr-1]


					//			}

					if(irr<len)
						hyu=s[irr];

					temp=temp->b[hyu-'0'];

				}
				//	printf("%d\n",r->count);
				//	if(r->count>1)
				//	st=0;
				//	printf("YES\n");

			} 
			if(st==0)
				printf("NO\n");
			else
				printf("YES\n");  
			
		
		
		
		
		
		
		}


		return 0;
	}
