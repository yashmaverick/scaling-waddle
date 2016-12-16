#include<stdio.h>
#include<stdlib.h>
long long int MOD;
int main ()
{
	long long int *bags[1004],k,i,n,j,wtemp,weight,small,smalli;
	long long int temp[1004][2],retemp,size[1004],li,ln;
	scanf("%lld%lld",&n,&MOD);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		size[i]=k+2;
		wtemp=0;
		bags[i]=(long long int *)malloc((sizeof(long long int)*(k+2)));
		for(j=2;j<k+2;j++)
		{
			scanf("%lld",&weight);
			bags[i][j]=weight;
			wtemp=((wtemp)%MOD+(weight)%MOD)%MOD;
		}
		bags[i][0]=wtemp;
		bags[i][1]=i;


	//	for(j=0;j<k+2;j++)
	//		printf("%lld\n",bags[i][j]);

	}
	
	
		
	
	//SORTING//
	for(i=0;i<n;i++)
	{
		temp[i][0]=bags[i][0];
		temp[i][1]=bags[i][1];
	}
	for(i=1;i<n;i++)
	{
		
			
		ln=temp[i][0];
		li=temp[i][1];
		j=i-1;
		while((temp[j][0]>ln)&&(j>=0))
		{
			temp[j+1][0]=temp[j][0];
			temp[j+1][1]=temp[j][1];
			j=j-1;


		}
		temp[j+1][0]=ln;
		temp[j+1][1]=li;


		
		}

	      

	
/*	for(i=0;i<n;i++)
	{
		small=temp[i][0];
		smalli=i;
		for(j=i+1;j<n;j++)
		{
			if(temp[j][0]<small)
			{
				small=temp[j][0];
				smalli=j;
			}

		}
		retemp=temp[i][0];
		temp[i][0]=temp[smalli][0];
		temp[smalli][0]=retemp;
		
		retemp=temp[i][1];
                temp[i][1]=temp[smalli][1];
		temp[smalli][1]=retemp;



	}
*/

	//PRINTNG//
	for(i=0;i<n;i++)
	{
		for(j=0;j<size[temp[i][1]];j++)
		{
			if(j!=1)
				printf("%lld\n",bags[temp[i][1]][j]);
		}
		printf("\n");

	}

	return 0;


}
