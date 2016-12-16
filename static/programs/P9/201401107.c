#include<stdio.h>
#include<stdlib.h>

long long int num;

int *n[1000];

//long long int m[1000000];

long long int mod;

long long int weight;

long long int sortingArray[1000][3];



int main()
{
	scanf("%lld%lld",&num,&mod);
	long long int i,m,index=0;
	
	for(i=0;i<num;i++)
	{
		
		scanf("%lld",&m);
		n[i]=(int*)malloc((m+3)*sizeof(int));
		long long int size=m,weight=0,j;
		for(j=1;j<=m;j++)
		{
			scanf("%d",&n[i][j]);
			weight=(weight+n[i][j])%mod;
		}
		
		n[i][0]=size;
		n[i][j]=index;
		n[i][j+1]=weight;
		long long int z;
		
		
	/*	for(z=0;z<m+3;z++)
		{
			printf("%lld",n[i][z]);
		}
		printf("\n");
	*/	
		
		sortingArray[i][0]=weight;
		sortingArray[i][1]=index;
		//printf("%lld ",sortingArray[i][0]);
		//printf("%lld\n",sortingArray[i][1]);
		
		index++;
	}
	long long int y;
	for(y=0;y<num;y++)
	{
		sortingArray[y][2]=0;
	}
	
	//for sorting the sorting array
	long long int k,min,impt,l,index2,temp;
	for(l=0;l<num;l++)
	{
		min=1000000011;
	for(k=0;k<num;k++)
	{
		//if(k==0)
		//{
		//max=sortingArray[0][0];
		//temp=0;
		//index2=sortingArray[0][1];
		//}
		//if(sortingArray[k][0]==-1)
		//continue;
		if(sortingArray[k][0]<min&&sortingArray[k][2]!=1)
		{
		min=sortingArray[k][0];
		index2=sortingArray[k][1];
		temp=k;
		//index2=k;
		//index2=sortingArray[k][1];
		}
	
	}
	sortingArray[temp][2]=1;	
	printf("%lld\n",min);
	//sortingArray[temp][0]=-1;
	long long int p;
	
	for(p=1;p<=n[index2][0];p++)
	{
		printf("%lld\n",n[index2][p]);
	}
	printf("\n");
	}
	return 0;
}
