#include<stdio.h>
int main()
{	int test,max,i,a,j,temp;
	scanf("%d",&test);
	while(test--)
	{
		long long int values,j,new,new1,new2,n;
		scanf("%lld",&values);
		new=new1=new2=values;
		long long int arr[values],arr1[new],arr2[new1],arr3[new2];
		for(i=0;i<values;i++)
		{
			scanf("%lld",&arr[i]);
		}
		arr1[0]=arr[0];
		for(i=1;i<values;i++)
		{	
				if(arr[i]>=arr1[i-1])
				{
					arr1[i]=arr1[i-1];
				}
				else 
					arr1[i]=arr[i];
		}
		arr2[values-1]=arr[values-1];
		for(j=(values-2);j>=0;j--)
		{
				if(arr[j]>=arr2[j+1])
				{
					arr2[j]=arr[j];
				}
				else
					arr2[j]=arr2[j+1];	
		}
long long int temp=arr2[0]-arr1[0];
		for(j=1;j<values;j++)
		{
			if((arr2[j]-arr1[j])>temp)
			temp=arr2[j]-arr1[j];	
		}
		printf("%lld\n",temp);
	}		
     	return 0;
}
