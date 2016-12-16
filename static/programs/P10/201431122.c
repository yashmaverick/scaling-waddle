#include<stdio.h>
typedef struct node{
	char a[101];
}node;
int main()
{
	node p[10001];
	int s=0,e=-1,n,m,temp,i,FL=1;
	int x=0;
	char c[2];
	scanf("%d",&n);
int nm=n;
if(n==0)
	n=1;
	while(1)
	{
		
		scanf("%s",c);
		if(c[0]=='A')
		{
			scanf("%d",&m);
			for(i=0;i<m;i++){
				if(x<n)
				x++;
				e=(e+1)%n;
				if(x==n) 
				FL=0;
				scanf("%s",p[(e)%n].a);		
			}	
			if(FL==0)
			{s=(e+1)%n;
				FL=1;
			}
		}
		else if(c[0]=='L')
		{
			int I=s;
			int J=x;
			while(J--)
			{
				printf("%s\n",p[I].a);
				I=(I+1)%n;
			}
		}
		else if(c[0]=='R')
		{       
			scanf("%d",&m);
			x=x-m;
			if(x<0)
				x=0;
			s=(s+m)%n;
		if(x==0)
			{
				s=0;
				e=-1;
			}
		}

		else if(c[0]=='Q')
			break;
	/*printf("e %d s %d\n",e,s);
		for(i=0;i<5;i++)
			printf("i %s\n",p[i].a);*/
	}
return 0;
}
