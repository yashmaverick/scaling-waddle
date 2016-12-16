#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int state=0;
struct node{
	int flag;
	struct node *a;
};
typedef struct node node;
void insert(char s[],node k[],int i)
{
	int j;
	//for(j=0;j<10;j++)
	//	printf("%d ",k[j].flag);
	//printf("\n");
	//printf("%d %d %d\n",k[s[i]-'0'].flag,i,k[s[i]-'0'].flag);
	if(k[s[i]-'0'].flag==1&&i==strlen(s)-1||k[s[i]-'0'].flag==2)
	{	state=1;
		return ;
	}
	if(i==strlen(s)-1)
	{
		k[s[i]-'0'].flag=2;
		
		return ;
	}
	else
	{
		//k[s[i]-'0'].flag=1;
	//	k[s[i]-'0'].a=(node*)malloc(10*sizeof(node));
	//	k[s[i]-'0'].flag=0;
//		for(j=0;j<10;j++)
//		{
//			printf("%d ",k[j].flag);
//		}
//		printf("\n");
		if(k[s[i]-'0'].flag==0)
		{
			k[s[i]-'0'].a=(node*)malloc(10*sizeof(node));
			for(j=0;j<10;j++)
				k[s[i]-'0'].a[j].flag=0;
			k[s[i]-'0'].flag=1;
		}
		insert(s,k[s[i]-'0'].a,i+1);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		state=0;
		int n,i;
		scanf("%d",&n);
		node k[10];
		for(i=0;i<10;i++)
		{	k[i].flag=0;
		//	k[i].flag=0;
		//	k[i].end=0;
		}
		char s[11];
		while(n--)
		{
		//	char s[10];
	//		node k[10];
			scanf(" %s",s);
			insert(s,k,0);
		}
		if(state==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}

				


