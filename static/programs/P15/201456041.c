#include<stdio.h>
#include<stdlib.h>
#define gi(x) scanf("%d",&x)
#define pi(x) printf("%d",x)
#define ps(x) printf("%dg",x)
#define MAX 10005


int min[MAX];
int main()
{
	int testcases;
	gi(testcases);
	while(testcases--)
	{
		int N,k,i;
		int mini,in,v;
		gi(N);
		gi(k);
		int m,f;
		for(i=1;i<=N;i++)
		{
			gi(min[i]);
		}

		for(i=1;;i++)
		{

			f=i+k-1;


			if(i==1)
			{       

				mini=min[1];
				in=1;
				while(1)
				{
					i++;
					if(i>k)
						break;
					if(min[i]<mini)
					{
						mini=min[i];
						in=i;
					}

				}	 

				if(i>N)
				{
					pi(mini);
					break;
				}
				else
					pi(mini);
				i=1;
			}

			else
			{
				if(min[f]<mini)
				{
					mini=min[f];
					in=f;
					pi(mini);

				}

				else if(mini<min[f] && in>=i)
				{
					pi(mini);


				}
				else
				{
					int q;
					mini=min[i];
					in=i;
					for(q=i+1;q<=(i+k-1);q++)
					{

						if(min[q]<mini)
						{
							mini=min[q];
							in=q;
						}
					}
					pi(mini);

				}
			}
			if(f!=N)
				printf(" ");
			if(f==N)
				break;
		}
		printf("\n");
	}
	return 0;
}



