#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct tries
{
	int value;
	struct tries *p[11];
}node;
struct buffer
{
	char s[15];
};
int main()
{
	int t,n,i,j,k,z;
	scanf("%d",&t);
	struct buffer a[10000];
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i].s);
		}
		int fl=0;

		node* start;
		start=(node*)malloc(sizeof(node));
		start->value=-2;
		node* root;
		root=(node*)malloc(sizeof(node));
		for(i=0;i<n;i++)
		{ 

		     root=start;	 

                     for(j=0;j<strlen(a[i].s);j++)
		     {
			     if(root->p[a[i].s[j]-'0']==NULL)
			     {
				     root->p[a[i].s[j]-'0']=(node*)malloc(sizeof(node));
				     root->p[a[i].s[j]-'0']->value=a[i].s[j]-'0';
				     root=root->p[a[i].s[j]-'0'];
			     }
			     else
			     {
				 //    printf("%d\n",root->p[a[i].s[j]-'0']->value);
				     root=root->p[a[i].s[j]-'0'];
				    // printf("%d\n",root->p[10]->value);
				     if(root->p[10]!=NULL)
				     {
					     fl=1;
					     break;
				     }
			     }
			  //   printf("%d\n",root->value);
                                     

			 
                                 			    
		     }
		     
		     if(fl==1)
			  break;
		     else
		     {
                           for(z=0;z<9;z++)
			   {
				   if(root->p[z]!=NULL)
				   {  fl=1;
				   break;
				   }
			   }

		     }

			    
		     
		     root->p[10]=(node*)malloc(sizeof(node));
		     root->p[10]->value=-1;


		}
		if(fl==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
}
