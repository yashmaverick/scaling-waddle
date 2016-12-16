#include<stdio.h>
#include<stdlib.h>
int flag;

typedef struct tri
{
	int end;
	struct tri *child[10];

}tri;

typedef struct tri* tree;

void ins(char s[],tree a,int f)
{
	if(s[0]=='\0') { a->end=1; if(f==0) flag=1; return; }


	int x=s[0]-'0';
//	printf("x:%d\n",x);

	if(a->child[x]==NULL)
	{
		//printf("yes malloc and end: %d\n",a->end);
		if(f==0 && a->end==1) flag=1;
		a->child[x]=(tri *)malloc(sizeof(tri));
		a=a->child[x];
		a->end=0;
		int j;
		for(j=0;j<10;j++) a->child[j]=NULL;
		ins(s+1,a,1);
	}
	else { ins(s+1,a->child[x],0); }
}


int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n,i;
		flag=0;
		scanf("%d",&n);
		getchar();

		tree a;
		a=malloc(sizeof(tri));
		a->end=0;

		for(i=0;i<10;i++) a->child[i]=NULL;

		for(i=0;i<n;i++)
		{
			char s[12],c;
			scanf("%s",s);
			if(flag==0) ins(s,a,0);

		}	

		if(flag==0) printf("YES\n");
		else if(flag==1) printf("NO\n");

	}	
	return 0;
}