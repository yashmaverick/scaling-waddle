#include<stdio.h>
int main()
{
	int n,i,t;
	scanf("%d",&n);
	int c;
	int po[n],in[1000000],in1[n];
	for(i=0;i<n;i++)
		scanf("%d",&po[i]);
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		in[c]=i;
		in1[i]=c;
	}
	scanf("%d",&t);
	int v1,v2,n1,n2,x;
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&n1,&n2);
		v1=in[n1];
		v2=in[n2];
		int j,k,y=n,min,max;
		if(v1<v2)
		{
			min=v1;
			max=v2;
		}
		else
		{
			min=v2;
			max=v1;
		}
//		printf("min=%d max=%d\n",min,max);
		for(j=min;j<=max;j++)
		{
//			printf("j=%d in1[j]=%d\n",j,in1[j]);
			for(k=0;k<n;k++)
			{
//				printf("po[k]=%d\n",po[k]);
				if(po[k]==in1[j])
				{
				//	printf("k=%dy=%d\n",k,y);
					if(y>k)
						y=k;
				}
			}
		}
		printf("%d\n",po[y]);
	}
	return 0;
}
