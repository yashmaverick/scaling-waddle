#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int flag;
	struct node* next[10];
};
int ans;
int main()
{
	int len,t,l,k,n,m,p,j,u;
	char a[100];
	scanf("%d",&t);
	//struct node* head;
	struct node* top;
	struct node* aid;
	for(l=0;l<t;l++)
	{
		ans=0;
		struct node* head;
		head=malloc(sizeof(struct node));
		head->flag=0;
		for(j=0;j<10;j++)
		{
			head->next[j]=NULL;
		}
		scanf("%d",&n);
		for(k=0;k<n;k++)
		{
			scanf("%s",a);
			len=strlen(a);
			//printf("len is%d\n",len);
			top=head;
			if(ans==0)
			{
			for(m=0;m<len;m++)
			{
				p=a[m]-'0';
				//printf("p is %d\n",p);
				if(top->next[p]==NULL)
				{
					//printf("enterd if null\n");
					struct node* temp;
					temp=malloc(sizeof(struct node));
					if(m==len-1)
					{
						temp->flag=1;
					}
					else
					{
						temp->flag=0;
					}
					for(u=0;u<10;u++)
					{
						temp->next[u]=NULL;
					}
					top->next[p]=temp;
					top=temp;
				}
				else
				{

					//printf("etrd else\n");
					if(m==len-1)
					{
						ans=1;
						//printf("breaking at end cond\n");
						break;
					}
					aid=top->next[p];
					if((aid->flag==1)&&(m<len))
					{
						ans=1;
						//printf("breaking at string parent\n");
						break;
					}
					top=top->next[p];

				}


			}
			}
		}
	
	if(ans==1)
		printf("NO\n");
	else
		printf("YES\n");
	}

return 0;
}
