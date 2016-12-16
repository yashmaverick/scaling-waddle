#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

#define gu getchar_unlocked 
#define pu putchar_unlocked
#define lli long long int
#define ulli unsigned long long int
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define test() int t;din(t); while(t--)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
#define loop(n) for(i=0;i<n;i++)
int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}
typedef struct node{
	int flag;
	struct node* numbers[10];
}node;
node* head;
int ansflag=0;

void insert()
{
	node* temphead=head;
	int tempflag=0;
	int createflag=0;
	char c=getchar();
	char tempchar;

	while(c!='\n')
	{
		tempchar=c;

		if(ansflag)
		{
			c=getchar();
			continue;
		}
		int j;
		if(temphead->numbers[c-'0']==NULL)
		{
			createflag=1;
			temphead->numbers[c-'0']=(node*)malloc(sizeof(node));
			temphead->numbers[c-'0']->flag=0;
			for(j=0;j<10;j++)
				temphead->numbers[c-'0']->numbers[j]=NULL;
			//printf("Executing 2 \n");
			tempchar=c;
			c=getchar();
			tempflag=1;
			//printf("Executing 3\n");
			//printf("temporary varaiable is %c\n",tempchar);
			if(c=='\n')
			{

				temphead->numbers[tempchar-'0']->flag=1;
				//printf("Executing  loop \n");
				break;
			}
		}

		//printf("Executing statement \n");
		if(temphead->numbers[(tempflag?tempchar:c)-'0']->flag==1)
			ansflag=1;
		//pu(c);
		//printf("Executing statement \n");
		temphead=temphead->numbers[tempchar-'0'];
		//printf("Executing statement \n");
		if(!tempflag)
		{
			c=getchar();
			tempflag=0;
		}
	}
	if(!createflag)
		ansflag=1;
}
int main()
{
	test()
	{
		head=NULL;
		int n,i,j;
		din(n);
		gu();
		loop(n)
		{
			if(!i)
			{
				head=(node*)malloc(sizeof(node));
				head->flag=0;
				for(j=0;j<10;j++)
					head->numbers[j]=NULL;
			}
			insert();
		}
		if(ansflag)
			printf("NO\n");
		else
			printf("YES\n");
		ansflag=0;
	}
	return 0;
}
