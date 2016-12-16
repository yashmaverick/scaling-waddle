#include<stdio.h>
#include<stdlib.h>

struct bag
{
	int size;
	long long int weight;
	int* list;
};

typedef struct bag bag;

void sort(bag* bags,int n)	//Merge sort function
{

	int i,j,k;
	int mid=n/2;
	if(n<2)				//Base case
		return;
	bag* left=(bag*)malloc(mid*sizeof(bag));  //Divide the parent array into two subarrays
	bag* right=(bag*)malloc((n-mid)*sizeof(bag));
	for(i=0;i<mid;i++)
	{
		left[i]=bags[i];
	}
	for(j=mid;j<n;j++)
	{
		right[j-mid]=bags[j];
	}
	sort(left,mid);			//Sort the left sub-array
	sort(right,n-mid);		//Sort the right sub-array
	i=j=k=0;
	while(i<mid && j<(n-mid))		//Compare elements of sorted subarrays and place in the parent array
	{
		if(left[i].weight<=right[j].weight)
		{
			bags[k]=left[i];
			i++;
		}
		else
		{
			bags[k]=right[j];
			j++;
		}
		k++;		
	}
	while(i<mid)				//Place the leftover elements of both subarrays in parent array
	{
		bags[k]=left[i];
		i++;
		k++;	
	}
	while(j<(n-mid))
	{
		bags[k]=right[j];
		j++;
		k++;
	}
	free(left);
	free(right);
}

int main()
{
	int n,mod,m;
	int i,j,k=1;
	scanf("%d%d",&n,&mod);
	bag temp;
	bag* bags=(bag*)malloc(n*sizeof(bag));
	for(i=0;i<n;i++)
	{
		scanf("%d",&bags[i].size);
		bags[i].weight=0;
		bags[i].list=(int*)malloc(bags[i].size*sizeof(int));
		for(j=0;j<bags[i].size;j++)
		{
			scanf("%d",&bags[i].list[j]);
			bags[i].weight+=(long long int)(bags[i].list[j]);
		}
		bags[i].weight=bags[i].weight%mod;
	}
	sort(bags,n);	//Merge sort function call to sort the bags according to individual total weights
	for(i=0;i<n;i++)
	{
		printf("%d\n",bags[i].weight);
		for(j=0;j<bags[i].size;j++)
			printf("%d\n",bags[i].list[j]);
		printf("\n");
	}
	free(bags);
	return 0;
}