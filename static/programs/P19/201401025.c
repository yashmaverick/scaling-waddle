#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tree
{
	int val;
	struct tree *next[10];
};

struct tree *root=NULL;

int ans=0;

void xyz()
{
	int i;
	struct tree *tmp = (struct tree *)malloc(sizeof(struct tree));
	tmp->val=0;
	for(i=0;i<10;i++)
	{
		tmp->next[i]=NULL;
	}
	root = tmp;
}

void insert(int a[],int j)
{
	int i=0,x;

	struct tree *temp=root;
	for(i=0;i<j;i++)
	{
		if(temp->next[a[i]]==NULL)
		{
			struct tree *tmp = (struct tree *)malloc(sizeof(struct tree));
			tmp->val=0;
			for(x=0;x<10;x++)
			{
				tmp->next[x]=NULL;
			}
			temp->next[a[i]]=tmp;
			if(temp->val==1)
				ans=1;
			temp=temp->next[a[i]];
		}
		else
		{
			if(i==j-1)
				ans=1;
			temp=temp->next[a[i]];
		}

		if(i==j-1)
			temp->val=1;
		//cout<<i<<"sgd "<<temp->val<<endl;
	}
}


int main()
{
	int test,n,i,len,p[100],j,k,a[100];
	char c[100];
	scanf("%d",&test);
	while(test>0)
	{
		scanf("%d",&n);
		xyz();
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",c);
			
			len=strlen(c);
			
			//printf("%s\n",c);
			/*j=0;
			while(len>0)
			{
				p[j]=c[len-1];
				j++;
				len--;
			}*/
			for(k=0;k<len;k++)
			{
				a[k]=c[k]-'0';
				//printf("%d ",a[k]);
			}

			insert(a,len);
		}
		if(ans==0)
			printf("YES\n");
		else
			printf("NO\n");
		test--;
	}

	return 0;
}
