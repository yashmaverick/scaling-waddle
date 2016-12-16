#include<stdio.h>

void shortest(int);
void primegen(int);

int prime[1062],z;
int edges[1062][20];
int visit[1062],vi;
int a,b;
int array[2][1000];
int ay[2];int mode;int count;

int main()
{
	z=1;
	int i,k,j,l,m,s;

	for(i=1000;i<=9999;i++)
	{
		if(i%2!=0 && i%3!=0 && i%5!=0 && i%7!=0)
		{primegen(i);}
	}

	for(i=1;i<1062;i++)
	{
		s=0;
		for(j=1;j<1062;j++)
		{
			k=prime[i];
			l=prime[j];

			m=0;
			while(k>0)
			{
				if(k%10==l%10)
				{m++;}
				k=k/10;
				l=l/10;
			}

			if(m==3)
			{
				edges[i][s]=j;
				s++;
			}
		}
	}


	int t;
	scanf("%d",&t);
	while(t--)
	{
		vi=0;
		ay[0]=0;
		ay[1]=0;
		count=0;
		mode=0;

		scanf("%d",&a);
		scanf("%d",&b);

		for(i=1;i<1062;i++)
		{
			if(prime[i]==a)
			{a=i;}

			if(prime[i]==b)
			{b=i;}

			visit[i]=0;
		}

//		printf("a=%d\tb=%d\n",a,b);

		mode=0;
		visit[a]=1;
		array[mode][ay[mode]]=a;
		ay[mode]++;
		
		int use;
		int res=0;

		if(a==b)
		{res=1;}

		while(res==0 && vi<1061)
		{
		count++;

		mode=1-mode;
//		printf("count=%d\n",count);
		k=0;

		for(i=0;i<ay[1-mode] && res==0;i++)
		{

			use=array[1-mode][i];

//			printf("use=%d\t",prime[use]);
			
			for(j=0;edges[use][j]!=0;j++)
			{
				if(visit[edges[use][j]]!=1)
				{
					array[mode][k]=edges[use][j];
					visit[edges[use][j]]=1;
					k++;
					vi++;
//					printf("n=%d  ",prime[edges[use][j]]);

					if(edges[use][j]==b)
					{
						res=1;
						break;
					}
				}
			}

//			printf("\n");
			ay[mode]=k;
		}

		}

		if(res==1)
		{
			printf("%d\n",count);
		}
		else
		{
			printf("Impossible\n");
		}
	}
	return 0;
}

void primegen(int n)
{
	int c=0,i;

	for(i=1;i<=n;i++)
	{
		if(n%i==0)
		{c++;}
	}

	if(c==2)
	{prime[z]=n;z++;}
}
