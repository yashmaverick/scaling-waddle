#include<stdio.h>
#include<stdlib.h>
typedef struct nod
{
	int da;
	int fa;
	int ma;
}nod;
nod sum[1007];
int main()
{
	int g,n,mod,i,j,c,p[1000007],t,k;
	nod tem;
	scanf("%d%d",&n,&mod);
	int **arr=(int **)malloc(n * sizeof(*arr));
	for(i=0;i<n;i++)
	{
	        sum[i].ma=i;
		sum[i].da=0;
		scanf("%d",&c);
		 arr[i]=(int *)malloc(c * sizeof(int *));

		for(j=0;j<c;j++)
                {
			scanf("%d",&arr[i][j]);
			(sum[i].da)=((sum[i].da)%mod+arr[i][j]%mod)%mod;

		}
		sum[i].fa=c;
		p[i]=sum[i].da;
	}
	int temp,tg;
/*	for(i=0;i<n-1;i++)
	{
		for(j=i;j<n-i-1;j++)
		{  
			if(sum[j].da>sum[j+1].da)
			{       
				tem=sum[j+1].da;
				sum[j+1].da=sum[j].da;
				sum[j].da=tem;
				temp=sum[j].fa;
				sum[j].fa=sum[j+1].fa;
				sum[j+1].fa=temp;
				tg=sum[j].ma;
				sum[j].ma=sum[j+1].ma;
				sum[j+1].ma=tg;

			}
		}
	}
	*/
	for(i=0;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			if(sum[j].da<sum[j-1].da)
			{
				tem=sum[j];
				sum[j]=sum[j-1];
				sum[j-1]=tem;
			}
		}
	}
	int o,m;
	for(o=0;o<n;o++)
	{	
		printf("%d\n",sum[o].da);
		m=sum[o].ma;
		for(i=0;i<sum[o].fa;i++)
		{
			printf("%d\n",arr[m][i]);
		}
		printf("\n");
	}


	return 0;
}
