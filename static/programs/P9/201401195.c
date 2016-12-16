#include<stdio.h>
void enque(int val,int qu[],int last)
{
	qu[last]=val;

}
int main()
{
	int n,mod,qu[1000000],last=0;
	scanf("%d %d",&n,&mod);
	int l,k,a[n],i,j,d,o,c[n],index[n],min,temp,x,y,sum[n],b[n],p;
	for(k=0;k<n;k++)
		sum[k]=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		index[i]=i;
		enque(a[i],qu,last);
		last++;
		for(j=0;j<a[i];j++)
		{
			scanf("%d",&d);
			sum[i]=(sum[i]+d)%mod;
			enque(d,qu,last);
			last++;	
		}
	}
	//int b[n];
	b[0]=0;
	qu[b[0]]=sum[0];
	c[0]=sum[0];
	for(k=1;k<n;k++)
	{		
		b[k]=b[k-1]+a[k-1]+1;
		c[k]=sum[k];
		qu[b[k]]=sum[k];
	}		
//printf("");
//for(i=0;i<n;i++)
//printf("%d ",sum[i]);
//for(i=0;i<n;i++)
//printf("%d ",b[i]);
//int p;
//for(i=0;i<n;i++)
//printf("%d ",c[i]);

	for(p=0;p<n;p++)
	{
		min=p;
		for(y=p;y<n;y++)
		{
			if(c[y]<c[min])
			{
				min=y;
			}

		}
if(min!=p)
{
		temp=index[min];
		index[min]=index[p];
		index[p]=temp;
}
		c[min]=c[p];
	}
//for(i=0;i<n;i++)
//printf("%d ",index[i]);

//	for(y=0;y<last;y++)
//	printf("%d ",qu[y]);


	for(o=0;o<n;o++)
	{
		printf("%d\n",qu[b[index[o]]]);
		if(index[o]==n-1)
		{
			for(j=b[index[o]]+1;j<last;j++)
				printf("%d\n",qu[j]);	
			printf("\n");
		}
		else
		{
			for(j=b[index[o]]+1;j<b[index[o]+1];j++)
				printf("%d\n",qu[j]);
			printf("\n");
		}
	}

	return 0;
}

