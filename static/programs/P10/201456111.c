#include<stdio.h>

struct uniq
{
	char a[120];
};
int main()
{
	int k,n,s,l,v,i,e,flag,z,h,f;
	char c;
	int start,end,present;
	start=0;
	end=-1;
	struct uniq b[10000];
	scanf("%d",&z);
	scanf("%c",&c);
	h=0;
	f=0;
	present=0;
	while(1)
	{
		f=0;

		flag=0;
		if(c=='A')
		{
			scanf("%d",&n);
		}
		if(c=='R')
		{
			scanf("%d",&s);
		}
		if(c=='Q')
			return 0;
		if(c=='A')
		{
			for(i=0;i<n;i++)
			{
				if(present==z)
					start=(start+1)%z;
				else
					present++;
				end=(end+1)%z;
				scanf("%s",b[end].a);
			}
		}
		if(c=='R')
		{
			present-=s;
			for(v=0;v<s;v++)
			{
				if(start==end)
				{
					start=0;
					end=-1;
					h=0;
					break;
				}
				if(start==(z-1))
				{
					h=0;
				}
				if(start<(z-1))
				{
					start=start+1;
				}
				else{
					if((start+1)>=z)
					{
						start=(start+1)%z;
					}
				}
			}
		}
		if(c=='L')
		{
			if(end!=-1){
				if(start<end)
				{
					for(i=start;i<=end;i++)
					{
						printf("%s\n",b[i].a);
					}
				}
				if(start>end)
				{
					for(i=start;i<z;i++)
					{
						printf("%s\n",b[i].a);
					}
					for(i=0;i<=end;i++)
					{
						printf("%s\n",b[i].a);
					}

				}
				if(start==end)
				{
					printf("%s\n",b[start].a);
				}
			}
		}
		scanf("%c",&c);
	}
	return 0;
}
