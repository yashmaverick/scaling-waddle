#include<stdio.h>
void print(char **a,int n)
{
	int i;
	for(i=0;i<n;i++)
	  printf("%s",a[i]);
	}
int main()
{
  char a[10000][105];
	char b[2];
	int j,i,st,end,n,con,m;
	st=0;
	end=0;
	con=0;
	scanf("%d",&n);
	scanf("%s",b);
	while(b[0]!='Q')
	{
		if(b[0]=='A')
		{
      scanf("%d",&m);
			for(i=0;i<m;i++)
			{
			  scanf("%s",a[end]);	
				end=(end+1)%n;
			}
			con=con+m;
			if(con>n)
			{ st=(st+con-n)%n;
				con=n;
			}
		}
		else if(b[0]=='R')
		{
			scanf("%d",&m);
			st=(st+m)%n;
			con-=m;
		}
     	//printf("st:%d end:%d\n",st,end);
	 if(b[0]=='L')
		{

			for(i=st;i<st+con;i++)
			{
				j=i%n;
				printf("%s\n",a[j]);
			}
		}
		scanf("%s",b);
	}
return 0;
}
