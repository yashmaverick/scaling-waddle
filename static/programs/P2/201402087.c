#include<stdio.h>
int a[100004],b[100004],c[100004];
int min(int x,int y)
{
		if(x<=y)
				return x;
		return y;
}
int main()
{
		int t,p,q,r,i,j,k,l;
		long long int count;
		scanf("%d",&t);
		while(t--)
		{
				long long int d[100004]={};
				 long long int e[100004]={};
				count=0;
				scanf("%d",&p);
				for(j=0;j<p;j++)
						scanf("%d",&a[j]);
				scanf("%d",&q);
				for(j=0;j<q;j++)
						scanf("%d",&b[j]);
				scanf("%d",&r);
				for(j=0;j<r;j++)
						scanf("%d",&c[j]);
				for(j=k=0;j<min(q,r);j++)
				{
						if(k<j)
								k=j;
						for(;k<r;k++)
								if(b[j]<=c[k])
										break;
						d[j]=r-k;
						
						//printf("%d	",k);
				}
				e[q-1]=d[q-1];
				for(j=q-2;j>=0;j--)
				{
						e[j]=(d[j]+e[j+1]);
						//printf("j=%d	e-1=%d	e=%d	d=%d\n",j,e[j-1],e[j],d[j]);
				}
/*
				for(j=0;j<q;j++)
				{
				printf("%d ",d[j]);
				}
				printf("\n");
				for(j=0;j<q;j++)
				{
				printf("%d ",e[j]);
				}
				*/
				for(j=k=0;j<min(q,p);j++)
				{
						if(k<j)
								k=j;
						for(;k<q;k++)
								if(a[j]<=b[k])
										break;
						count=count+e[k];
						
				//printf("%d	",k);
				}

				printf("%lld\n",count);
		}
		return 0;
}
