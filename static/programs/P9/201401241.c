#include<stdio.h>
#include<stdlib.h>
int main()
{
	int k,n,mod,w,t,i,j,a,b,temp,temp1,q,r,no;
//	int mm;
	int **p;
	scanf("%d %d",&n,&mod);
	int m[n];
	p=(int **)malloc(n*sizeof(int *));
		for(i=0;i<n;i++)
		{
//			scanf("%d",&mm);
			scanf("%d",&m[i]);
			*(p +i)=(int *)malloc((m[i]+3)*sizeof(int));
			for(j=2;j<(m[i]+2);j++)
			{
				scanf("%d",(*(p+i)+j));
			}
			p[i][0]=i+1;
			p[i][1]=i+1;
			p[i][m[i]+2]=0;

			for(k=2;k<(m[i]+2);k++)
			{
				p[i][m[i]+2]=((p[i][(m[i])+2])%mod+(p[i][k])%mod)%mod;
			}
		}

	//sort
	for(a=0;a<n-1;a++)
	{
		for(b=0;b<n-a-1;b++)
		{
			if(p[b][m[b]+2]>p[b+1][m[b+1]+2])
			{
				//swap
				temp=p[b][m[b]+2];
				p[b][m[b]+2]=p[b+1][m[b+1]+2];
				p[b+1][m[b+1]+2]=temp;

				//swap p[a][1] p[b][1]
				temp1=p[b][1];
				p[b][1]=p[b+1][1];
				p[b+1][1]=temp1;

			}
		}
	}
	for(q=0;q<n;q++)
	{
		no=p[q][1];
		printf("%d\n",p[q][m[q]+2]);
		for(r=2;r<m[no-1]+2;r++)
		{
			printf("%d\n",p[no-1][r]);
		}
		printf("\n");
	}
	return 0;
}






