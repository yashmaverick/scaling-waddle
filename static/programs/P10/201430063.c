#include<stdio.h>
#include<string.h>
typedef struct p2
{
	char a[101];
}p2;
int main()
{

	int n,i;
	int k=0;
	int l=-1;
	scanf("%d",&n);
	p2 b[n];
	char c;
	c='a';
	int m;
	int j=0;
	int track=0;
	while(c!='Q')
	{
		scanf("%c",&c);
		if(n!=0)
		{ if(c=='A')
			{
				scanf("%d",&m);


				for(i=0;i<m;i++)
				{//printf("j is %d\n",j);
					//scanf("%s",b[l].a);
					l++;

					l%=n;
					scanf("%s",b[l].a);
					// l=l%n;



					if(j==n)
						k++;
					if(k==n)
						k=0;
					j++;
					if(j>=n)
						j=n;

				}
				//	printf("%d %d\n",k,l);
			}
			if(c=='R')
			{
				scanf("%d",&m);
				j=j-m;
				if(j<0)
                                  j=0;
                                  if(j==0)
                                  {k=0;  
                                   l=-1;
                                   }
                                   if(k<=l)
				{
					k=k+m;
					if(k>l)
					{k=0;
						l=-1;
					}
				}
				if(l<k&&l!=-1)
				{  int f=0;
					if(k-l==1&&m==n)
					{k=0;
						l=-1;
					}
					if(k+m<n)
					{	k=k+m;
						f=1;
					}    
					if(k+m>=n&&l!=-1&&f==0)
						k=(k+m)%n;
				}
				//	printf("%d %d\n",k,l);

			}

			if(c=='L')
			{
				for(i=k;i<=l;i++)
					printf("%s\n",b[i].a);		
				if(l<k&&l!=-1)
				{
					//	for(i=0;i<=l;i++)
					//		printf("%s\n",b[i].a);
					for(i=k;i<n;i++)
						printf("%s\n",b[i].a);
					for(i=0;i<=l;i++)
						printf("%s\n",b[i].a);

					//		printf("%d %d\n",k,l);	
				}                           
			}
		}
	}
	return 0;
}
