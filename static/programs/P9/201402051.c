#include<stdio.h>
struct bag{
	int sum;
	int s;
	int e;
};

int main()
{
	int b[1000001],i,j,n,m,N,sump,y,k,x;
y=0;
k=1;
		struct bag a[1000];
		scanf("%d %d",&n,&N);
	for(i	=0;i<n;i++)
	{
		scanf("%d",&m);
		sump=0;
		for(j=0;j<m;j++)
		{
			scanf("%d",&x);
			b[y]=x;
			y++;
			sump=sump+x;
			sump=sump%N;
		}
		a[i].sum=sump;
		a[0].s=0;
		a[k].s=y;
		k++;
		a[i].e=y-1;
	}
	for(i=1;i<n;i++){
		      struct bag temp=a[i];
		            j=i-1;
			          while((temp.sum<a[j].sum)&&(j>=0)){
					        a[j+1]=a[j];
						          j=j-1;
							        }
				        a[j+1]=temp;
					  }
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i].sum);
		for(j=a[i].s;j<=a[i].e;j++)
		{
			printf("%d\n",b[j]);
		}
		printf("\n");
	}

	return 0;
}


