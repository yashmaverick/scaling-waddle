#include<stdio.h>
#include<stdlib.h>

typedef long long int lld;

int sz[1001];
int* a[1001];
int b[1001];

int main()
{
		int n,i,j,temp;
		int mod;
		scanf("%d%d",&n,&mod);
		for(i=0;i<n;i++)
		{
				int m,data;
				scanf("%d",&m);
				sz[i] = m;
				a[i] = (int*)malloc(sizeof(int)*m);
				int as=sizeof(a[i]);
				for(j=0;j<m;j++)
				{
						scanf("%d",&a[i][j]);
						b[i]+=a[i][j]; 
						if(b[i]>=mod)
								b[i]%=mod;
				}
		}
		int *tl;
		for(i=0;i<n-1;i++)
				for(j=i+1;j<n;j++)
				{
						if(b[i]>b[j])
						{
								temp=b[j];
								b[j]=b[i];
								b[i]=temp;
								tl=a[i];
								a[i]=a[j];
								a[j]=tl;
								sz[i] += sz[j]; sz[j] = sz[i]-sz[j]; sz[i]-=sz[j];
						}
				}
		for(i=0;i<n;i++)
		{
				printf("%d\n",b[i]);
				int m = sz[i]; 
				int j;
				for(j=0; j<m; j++)
						printf("%d\n",a[i][j]);
				printf("\n");
		}
		return 0;
}
