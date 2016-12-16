#include<stdio.h>
#include<string.h>
char s[10010][110];
int main()
{
	int n,val;
	int old=-1,new=-1,i,nu,ol,index,intfl;
	scanf("%d",&n);
	char c;
	scanf("%c",&c);
	while(1)
	{	
		scanf("%c",&c);
		if(c=='A')
		{
			scanf("%d",&val);
			if(val>0)
			{
				nu=new;
				ol=old;	
				if(old==-1)
				{
					old=0;
					intfl=1;
				}
				index=nu;
				for(i=nu+1;i<=nu+val;i++)
				{
					if(index==n-1)
						index=0;
					else 
						index++;
					scanf("%s",s[index]);
					new=index;
					if(index==old)
					{
						if(intfl==0)
						{
							old++;
							if(old==n)
								old=0;
						}
						else 
							intfl=0;
					}
				}
			}
		}
		else if(c=='R')
		{
			nu=new;
			ol=old;
			scanf("%d",&val);
			index=ol-1;
			for(i=ol;i<ol+val;i++)
			{
				if(index==n-1)
					index=0;
				else
					index++;
				strcpy(s[index],"\0");
				old=index+1;
				if(old==n)
					old=0;
				if(index==new)
				{
					old=-1;
					new=-1;
				}
		//		printf("%d----%d",old,new);
			}
		}
		else if(c=='L')
		{
			i=old;
			while(i!=new)
			{
				printf("%s\n",s[i]);
				i++;
				if(i==n)
					i=0;
			}
			if(new>=0)
				printf("%s\n",s[new]);
		}
		else 
			break;
		scanf("%c",&c);
	}
	return 0;
}
