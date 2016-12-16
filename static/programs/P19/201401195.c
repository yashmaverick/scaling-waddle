#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct arr
{
	int mark;
	int visited;
	struct arr *next[10];
}arr;
int success=0;
arr *te[10];
void insert(char num[],int cap)
{	
	int i=0;
//	printf("%d\n",num[0]-'0');
	arr *p=te[num[0]-'0'],*r=te[num[0]-'0'];
	for(i=0;i<cap-1;i++)
	{
		if(p==NULL && i==0)
		{
			p=(arr*)(malloc(sizeof(arr)));
			r=p;
//			printf("a");
		}
		else if(i==0)
		r=p;
		else if(p==NULL && i>0)
		{
			r->next[num[i]-'0']=(arr*)(malloc)(sizeof(arr));
			p=r->next[num[i]-'0'];
//			printf("b");
		}
		else
		{
		p=r->next[num[i]-'0'];
		}
		if(p->mark==1)
		{
			success=0;
			return ;
		}
		else
		{
			p->visited=1;
			r=p;
			p=p->next[num[i+1]-'0'];
		}
	}
	if(p==NULL && i==0) 
	{
		p=(arr*)(malloc(sizeof(arr)));
//		printf("DF");
	}
	if(p==NULL && i!=0)
	{
		r->next[num[i]-'0']=(arr*)(malloc)(sizeof(arr));
		p=r->next[num[i]-'0'];
	}
	if(p->visited==1)
	{
		success=0;
	}
	else 
	{
		p->visited=1;
		p->mark=1;
		success=1;
	}

}
int main()
{
	int t,d;
	scanf("%d",&t);
	for(d=0;d<t;d++)
	{
		int n,x,y,ii,j=0,flag=0;
		scanf("%d",&n);
		for(y=0;y<10;y++)
			te[y]=(arr*)(malloc)(sizeof(arr));
//		int num1,num2,num[10],m[10];
		char m[10];
		for(x=0;x<n;x++)
		{
			scanf("%s",m);
//			num2=num1;
//			int f=0;
			if(flag!=1)
			{
/*				while(num2!=0)
				{
					num[f]=num2%10;
					num2=num2/10;
					f++;
				}
				for(ii=0;ii<f;ii++)
					m[ii]=num[f-ii-1];
//				for(ii=0;ii<f;ii++)*/
//					printf("%s\n",m);
				insert(m,strlen(m));
				if(success==0)
				{
					flag=1;

				}
			}

		}
		if(flag==1)
			printf("NO\n");
		else
			printf("YES\n");
		flag=0,success=0;
	}
	return 0;
}


