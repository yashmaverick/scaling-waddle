//GABBAR STUDIOWORKS
//27-03-2015
//P-9:ds ASSGN-2
#include<stdio.h>
#include<stdlib.h>
//typedef long long int ll;
/*void swap(int n,int m)
  {
  int temp;
  temp=n;
  n=m;
  m=temp;
  }*/
int main()
{
	int n,mod,m,i,j,d=0,sum=0;
	scanf("%d %d",&n,&mod);
	int**arr=(int**)malloc(sizeof(int*)*n);
	int**sumarr=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
	{
		sumarr[i]=(int*)malloc(sizeof(int)*3);
	}
	for(i=0;i<n;i++)
	{
		sum=0;
		scanf("%d",&m);
		arr[i]=(int*)malloc(sizeof(int)*m);
		for(j=0;j<m;j++)
		{
			scanf("%d",&arr[i][j]);
			sum=(sum+arr[i][j])%mod;
		}
		sumarr[d][0]=sum%mod;
		sumarr[d][1]=i;
		sumarr[d][2]=m;
		d++;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(sumarr[i][0]>sumarr[j][0])
			{
				//swap(sumarr[i][0],sumarr[j][0]);
				int temp=sumarr[i][0];
				sumarr[i][0]=sumarr[j][0];
				sumarr[j][0]=temp;
				//swap(sumarr[i][1],sumarr[j][1]);
				 temp=sumarr[i][1];
				sumarr[i][1]=sumarr[j][1];
				sumarr[j][1]=temp;

				//swap(sumarr[i][2],sumarr[j][2]);
				 temp=sumarr[i][2];
				sumarr[i][2]=sumarr[j][2];
				sumarr[j][2]=temp;

			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",sumarr[i][0]);
		for(j=0;j<sumarr[i][2];j++)
		{
			printf("%d\n",arr[sumarr[i][1]][j]);
		}
		printf("\n");
	}
	return 0;
}
