#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int a,b,c,d,e,f,n,i,j;
	char p,s[10007][107],t;
	//	printf("scan n\n");
	scanf("%lld",&n);
	a=0;
	d=1;
	e=0;
	f=1;
	getchar();
	while(a!=1)
	{
		//printf("scan Append,List,Quit\n");
		scanf("%c",&p);
		if(p=='A'|| p=='R')
		{	if(p=='A')
			{
				//printf("Append scan\n");
				scanf("%lld",&b);
				for(i=1;i<=b;i++)
				{	e++;
					if(!(e<=n))
						e=n;
					//printf("inside append loop %d\n",d);
					scanf("%s",s[d]);

					if(!(d!=f ||  e==1))
						f++;
					if(f==n+1)
					f=1;					
						d=(d%n)+1;
				}
			}
			else if(p=='R')
			{
				//printf("In Remove, scan\n");
				scanf("%lld",&b);
				e=e-b;
				//printf("Starting the loop\n");
					while(b--)				
				{f++;
				if(f==n+1)
					f=1;
				}
				//printf("i:%d\n",f);
			}
		}
		else if(p=='L'||p=='Q')
		{
			if(p=='L')
			{	
				if(!(f>=d))
					for(i=f;i<d;i=(i%n+1))
					{
						printf("%s\n",s[i]);
					}
				else if(!(f<=d))
				{	
					for(i=f;i<=n;i++)
					{
						printf("%s\n",s[i]);
					}

					for(i=1;i<d;i++)
						printf("%s\n",s[i]);	
				}
				else if(!(e==1)&&e>0)	
				{	for(i=f;i<=n;i++)
					printf("%s\n",s[i]);
					for(i=1;i<f;i++)
						printf("%s\n",s[i]);
				}
				else if(e==1&&e>0)		
					printf("%s\n",s[f]);

			}
			else if(p=='Q')
			{
				a=1;
			}
		}	getchar();
	}
	return 0;
}

