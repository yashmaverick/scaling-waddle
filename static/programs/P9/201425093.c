#include<stdio.h>
#include<stdlib.h>
#define pr(n) printf("%d",n)
#define pn() printf("\n")
int *w[100000];
int m[100000];
int tw[100000][2];
int main()
{
	 int s,t,i,j,n,k,min,mi;
	 long long int mod;
	scanf("%d%lld",&n,&mod);
	for(i=0;i<n;i++)
	{
		tw[i][1]=i;
		scanf("%d",&m[i]);
		s=0;
		w[i] = malloc(sizeof(int) * m[i]);
		for(j=0;j<m[i];j++)
		{
			int temp;
			scanf("%d",&temp);
			s = (s%mod+temp%mod)%mod;
			s %= mod;
			w[i][j]=temp;
		}
		tw[i][0]=s;

	}
	//sorting
	for(k=0;k<n;k++)
	{
		min=tw[k][0];
		mi=k;
		for(i=k;i<n;i++)
			if(tw[i][0]<min)
			{
				min=tw[i][0];
				mi=i;
			}

		//swap;
		int temp1,temp2;

		temp1=tw[k][0];
		temp2=tw[k][1];
		tw[k][0]=tw[mi][0];
		tw[k][1]=tw[mi][1];
		tw[mi][0]=temp1;
		tw[mi][1]=temp2;
	}
/*	for(k=0;k<n;k++)
		printf("k %d\n",tw[k][0]);*/

	//printing

	for(i=0;i<n;i++)
	{
		pr(tw[i][0]);
		pn();
		for(j=0;j<m[tw[i][1]];j++)
		{
			pr(w[tw[i][1]][j]);
			pn();
		}
		pn();
	}
	return 0;
}
