#include<stdio.h>
struct node
{

	int wb;
	int fi;
	int li;
};
int w[1000000];
int main()
{
	int n,mod,i,j,sum,m;
	scanf("%d%d",&n,&mod);
	struct node bag[n];
	for(i=0;i<n;i++)
	{
		sum=0;
		//	int w[100000];
		scanf("%d",&m);
		//		if(i==0)
		//			bag[0].fi=m-1;
			if(i==0)
			{
				bag[0].li=m-1;
				bag[0].fi=0;
			}
		if(i!=0)
		{
			//bag[i].li=bag[i].fi+m-1;
			//  if(i!=0)
			bag[i].fi=(bag[i-1].li)+1;
			bag[i].li=bag[i].fi+m-1;
		}
		for(j=bag[i].fi;j<=bag[i].li;j++)
		{

			scanf("%d",&w[j]);
			sum=(sum%mod+w[j])%mod;
		}
		bag[i].wb=sum;



	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(bag[i].wb>bag[j].wb)
			{
				struct node temp;
				temp=bag[i];
				bag[i]=bag[j];
				bag[j]=temp;
			}
		}

	}

	for(i=0;i<n;i++)
	{
		printf("%d\n",bag[i].wb);
		for(j=bag[i].fi;j<=bag[i].li;j++)
		{
			printf("%d\n",w[j]);
		}
			printf("\n");
	}
	return 0;
}





