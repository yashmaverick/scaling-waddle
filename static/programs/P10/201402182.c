#include<stdio.h>
int main()
{
	int n,t,i,o,p,g,d,T,h;
	char a[10001][101],b[10001][101],c,k;
	scanf("%d",&n);
	//k=getchar();
	g=-1;
	while(1)
	{//c=getchar();
		scanf("%c",&c);
//		printf("===%d==\n",g);
		if(c=='A')
		{//k=getchar();
			scanf("%d",&t);
		//	k=getchar();
	//printf(".......%d.......\n",g+t);
			if(g+t<=n-1)
			{		for(i=g+1;i<g+t+1;i++)
				{d=0;

					{ scanf("%s",a[i]);
					}
					//printf("dr--");
}
g=g+t;}
			else
			{d=g+t-n;
//printf("--%d--",d);
				for(i=g+1;i<g+t+1;i++)
				{if(i>n)
					scanf("%s",a[i-n-1]);
					else
						scanf("%s",a[i]);
				} for(i=d+1;i<=n;i++)
				{T=0;
					while((b[i-d-1][T]=a[i][T])!='\0')
						T++;}
				for(h=n-d;h<=n;h++)
				{T=0;
					while((b[h][T]=a[h-n+d][T])!='\0')
						T++;}
				for(i=0;i<=n;i++)
				{T=0;while((a[i][T]=b[i][T])!='\0')
					{//printf("%s",a[i]);
T++;}
g=n-1;
				}}
			
			}
			else if(c=='L')
			{for(i=0;i<=g;i++)
				printf("%s\n",a[i]);
//printf("sg");
			}
			else if(c=='R')
			{ //k=getchar();
				
				scanf("%d",&o);
				
				{
				for(i=0;i<=g-o;i++)
				{T=0;while((a[i][T]=a[i+o][T])!='\0')
					{T++;}
					//                               printf("%s",a[i]);
				}

				//printf("%d",g);
				g=g-o;}
				//printf("%d",g);
			}
else if(c=='Q')
break;
			//k=getchar();
			//c=getchar();
			
		}
		return 0;
	}
