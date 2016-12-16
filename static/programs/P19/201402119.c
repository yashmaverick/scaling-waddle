#include<stdio.h>
#include<stdlib.h>

long long int c[100000],b[100000],n;

typedef struct tries{	
	struct tries*a[10];
	int cnt;
	int flag;
}tries;

long long int g=0;
int convert(long long int a)
{
	if(a == 0)
		return 0;
	else
	{
		convert(a/10);
		c[g]=a%10;
		g++;
	}
	return 0;
}


int  functries()
{
	tries *head,*tmp;
	head=(tries *)malloc(sizeof(tries));
	tmp=head;
	long long int i,x,k,j;
	for(i=0;i<10;i++)
	{
		head->a[i]=NULL;
		head->flag=0;
		head->cnt=0;
	}
	tmp=head;
	for(j=0;j<n;j++)
	{
		g=0;
		convert(b[j]);
		for(i=0;i<g;i++)
		{
			x=c[i];
			if(head->a[x] == NULL)
			{
		//		if(head->flag|| head->cnt>0)
		//		{
		//			printf("NO\n");
		//			return 0;
		//		}
				head->a[x]=(tries *)malloc(sizeof(tries));
				head=head->a[x];
				for(k=0;k<10;k++)
				{
					head->a[k]=NULL;
					head->flag=0;
					head->cnt=0;
				}
				head->cnt=head->cnt + 1;
				if(head->flag)
				{
					printf("NO\n");
					return 0;
				}
			}
			else
			{
				head=head->a[x];
				if((head->cnt)>0 && head->flag == 1)
				{
					printf("NO\n");
					return 0;
				}
				head->cnt=head->cnt + 1;
				if(head->flag)
				{
					printf("NO\n");
					return 0;
				}
			}
			if(head->cnt >0 && head->flag == 1)
			{
				printf("NO\n");
				return 0;
			}
		}
		if(head->cnt >1)
		{
			printf("NO\n");
			return 0;
		}
		head->flag=1;
		head=tmp;
	}
	printf("YES\n");
	return 0;	
}

int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int i;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&b[i]);
			if(n == 1)
			{
				printf("NO\n");
			}
		}
		if(n >1)
		functries();
	}
	return 0;
}
