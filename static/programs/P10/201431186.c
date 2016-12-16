#include<stdio.h>
#include<stdlib.h>
int a;
void shift(char **s,int t,int *A)
{
	int i;
	for(i=0;i<t;i++)
	{
		free(s[i]);
		*(A+i)=0;
	}a=a-t;
	for(i=0;i<a;i++)
	{
		*(s+i)=*(s+i+t);
		*(A+i)=1;
		*(A+i+t)=0;
	}
}
int main()
{
	int N,i,j;
	scanf("%d",&N);
	getchar();
	char c,r;char *t;
	char *s[N];
	int A[N];
	for(i=0;i<N;i++)
		A[i]=0;
	t=(char *)malloc(105*sizeof(char *));
	while(1)
	{
		c=getchar();
		if(c=='A')
		{
			r=getchar();
			scanf("%d",&j);
			if(j<=N-a)
			{
				for(i=a;i<a+j;i++)
				{
					s[i]=(char *)malloc(105*sizeof(char *));
					scanf("%s",s[i]);
					A[i]=1;
				}
				a=i;
			}
			else
			{
				if(j<N)
				{
					shift(s,j-(N-a),A);
					for(i=a;i<N;i++)
						{   
							s[i]=(char *)malloc(105*sizeof(char *));
							scanf("%s",s[i]);
						}
				}a=N;
			   if(j>=N)
			{
			    for(i=0;i<j-N;i++)
				scanf("%s",t);
				for(i=0;i<N;i++)
				{
				  if(A[i]==1)
				  free(s[i]);
				  s[i]=(char *)malloc(105*sizeof(char *));
				  scanf("%s",s[i]);
				  A[i]=1;
				}
			       	a=N;
			}
			}
			continue;
		}
		if(c=='R')
		{
			r=getchar();
			scanf("%d",&j);
		        shift(s,j,A);
			//a=a-j;
			continue;
		}
		if(c=='L')
		{ i=0;
			while(i<a)
			{
				printf("%s\n",s[i]);
				i++;
			}
			continue;
		}
		if(c=='Q')
			break;
	}
	return 0;
}
				





