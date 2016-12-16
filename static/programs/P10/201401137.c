#include<stdio.h>
int main()
{
	int n,i,j,k,poi=0,early=-1;
	scanf("%d ",&n);
	char a[n][107],c;
//	int start=0,end=n-1;
	int flag=0;
	while(1)
	{
		scanf("%c",&c);
		if(c=='A')
		{
			scanf("%d ",&k);
			while(k--)
			{
				j=0;
				while((c=getchar())!='\n')
				{
					a[poi][j]=c;
					j++;
				}
				a[poi][j]='\0';

				if(poi==early)
				{
				//	printf("Hi\n");
					if(flag==1)
					{
				//		printf("Hi\n");
						if(a[poi+1][0]!='\0')
						{
							early++;
						}
					}
				}
				if(poi==n-1)
				{
					poi=0;
					flag=1;
					if(a[poi][0]!='\0')
						early=0;        // MISTAKE
				}
				else
				{
					poi++;
				}
			}
		}
		if(c=='Q')
			break;
		if(c=='L')
		{
			if(early==-1 && flag==0)
			{
				for(i=0;i<poi;i++)
				{
					for(j=0;a[i][j]!='\0';j++)
					{
						printf("%c",a[i][j]);
					}
					if(a[i][0]!='\0')
						printf("\n");
				}
			}
			else
			{
				int l=early;
				i=early;
				int p,w=0;
				if(early==poi && flag==1)
				{
					p=n+early;
					w=n;
				}
				else
				{
					p=poi;
					if(poi>early)
					{
						w=poi-early;
					}
					if(early>poi)
					{
						w=n-early+poi;
					}
				}
				
				while(w--)
				{
//					printf("%d\n\n",w);
					for(j=0;a[i][j]!='\0';j++)
					{
						printf("%c",a[i][j]);
					}
					if(a[i][0]!='\0')
						printf("\n");
					if(i==n-1)
						i=0;
					else
						i++;					
//					if(a[i][0]!='\0')
//						printf("\n");
				}
			}
		}
		if(c=='R')
		{
			int u,aa=early;
			if(early==-1)
				aa=0;
			scanf("%d",&u);
			while(u--)
			{
				a[aa][0]='\0';
			if(aa==n-1)
				aa=0;
			else
				aa++;
			}
			if(early==poi)
			{
				early=-1;
			}
			early=aa;
		}
		if(c=='E')
		{
			printf("%d\n",early);
		}
		if(c=='P')
		{
			printf("%d\n",poi);
		}
		if(c=='F')
		{
			printf("%d\n",flag);
		}


	}
	return 0;
}
