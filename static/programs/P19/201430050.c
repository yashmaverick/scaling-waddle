#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{       int c;
	struct node* a[11];
}node;
node* insert(node *root,char num[])
{node *head=(node*)malloc(sizeof(node));
	head=root;
	int l,i,j;
	l=strlen(num);
	//printf("1\n");
	int flag=0;
	int g;
        for(i=0;i<l;i++)   
	{//printf("1a\n");
		if(head->a[num[i]-'0']==NULL)
	 	{  head->a[num[i]-'0']=(node*)malloc(sizeof(node));		
		   head->a[num[i]-'0']->c=num[i]-'0';
	//printf("2\n");
		   for(g=0;g<11;g++)
		   {head->a[num[i]-'0']->a[g]=NULL;
		   }
		   head=head->a[num[i]-'0'];
	        }
	    else
	    {      if(head->a[num[i]-'0']->a[10]!=NULL)
		    //printf("NO\n");
		    return NULL;
	//printf("3\n");
		    head=head->a[num[i]-'0'];
		    flag++;
	    } 
	}
	head->a[10]=(node*)malloc(sizeof(node));
         head->a[10]->c=-1;
	 for(j=0;j<11;j++)
		 head->a[10]->a[j]=NULL;
	//printf("4\n");
	 if(flag==l)
	 {	 //printf("NO\n");
	         return NULL;
             }
	 return root;
}
int main()
{int t;
	scanf("%d",&t);
	while(t--)
	{       char num[11];
		node* root=NULL;
		root=(node*)malloc(sizeof(node));
		root->c=-2;
		int i,n;
		for(i=0;i<11;i++)
		  root->a[i]=NULL;
		scanf("%d",&n);
		for(i=0;i<n;i++)
                {      scanf("%s",num);
			if(root!=NULL)
			{      
				root=insert(root,num);
			}
                }
		if(root==NULL)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
