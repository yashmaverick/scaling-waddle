#include<stdio.h>
#include<stdlib.h>
typedef struct rav
{
	struct rav* a[10];
	int v;
}rav;
int insert(rav* head,char* s)
{
	int i,j;
	i=0;
	while(s[i]!='\0')
	{
		if(head->a[s[i]-'0']==NULL)
		{
			head->a[s[i]-'0']=malloc(sizeof(rav));
			if(s[i+1]=='\0')
			{
		        head->a[s[i]-'0']->v=1;
			}
			else
			{
		        head->a[s[i]-'0']->v=0;
			}
			j=0;
			while(j<10)
			{
				head->a[s[i]-'0']->a[j]=NULL;
				j++;
			}

		}
		else
		{
			if(head->a[s[i]-'0']->v==1)
			{
				return 1;
			}
			else if(s[i+1]=='\0') 
			{  
				return 1;
			}
		}
		head=head->a[s[i]-'0'];
		i++;
	}
	return 0;
}
int main()
{
	long long int m,n,i,j,k,l,t;
	char s[10];
	int o,p;
	scanf("%lld",&n);
	for(t=n;t>0;t--)
	{
		o=0;
		p=0;
		rav* head;
		head=malloc(sizeof(rav));
		j=0;
		head->v=0;
		while(j<10)
		{
			head->a[j]=NULL;
			j++;
		}
		scanf("%lld",&m);
		if(m==0)
			continue;
		i=0;
		while(i<m)
		{
			scanf("%s",s);
			if(p==0)
			{
			o=insert(head,s);
			}
			if(o==1)
			{
				p=1;
			}

			i++;
		}
		if(p==1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	return 0;
}
