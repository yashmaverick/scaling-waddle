#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int flag=0;
typedef struct tri{
	int nc;
	struct tri *p[10];
}tri;

tri * root;

void insert(char s[])
{
	tri * temp=root;
	int i=0,l,z;
	l=strlen(s);
	while(i<l)
	{
		z=(s[i]-'0');
		//		printf("z %d\n",z);
		if(temp->p[z]==NULL)
		{
			temp->p[z]=(tri *)malloc(sizeof(tri));
			temp->p[z]->nc=0;
			//			printf("nukk\n");
		}
		if(i==l-1)
			temp->p[z]->nc=temp->p[z]->nc+1;
		temp=temp->p[z];
		i++;
	}
}


void chk(tri * t,int nv)
{
	int i=0;
	//	printf("nc-%d nv-%d\n",t->nc,nv);
	if(t->nc==0)
		for(i=0;i<10;i++)
		{
			if(t->p[i]!=NULL)
				chk(t->p[i],nv);
		}
	else if(t->nc>1)
		flag=1;
	else
		for(i=0;i<10;i++)
			if(t->p[i]!=NULL)
				flag=1;
}

void check()
{
	int nv,i;
	for(i=0;i<10;i++)
		if(root->p[i]!=NULL)
		{
			nv=root->p[i]->nc;
			chk(root->p[i],nv);
		}

}


int main()
{
	int t,n;
	char s[11];
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		scanf("%d",&n);
		root=(tri *)malloc(sizeof(tri));
		while(n--)
		{
			scanf("%s",s);
			insert(s);
			//		printf("enter\n");
		}
		check();
		//		free(root);
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
