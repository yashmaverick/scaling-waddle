#include<stdio.h>
typedef struct bag{
	int w;int begin;int end;}bag;
int split(bag A[], int left, int right)
{
	int pivot=A[right].w;//like a value

	int wall=left-1;//like a pointer
	int j,i;
	for(j=left;j<=right-1;++j)//till right -1 since right=pivot
	{
		if(A[j].w<=pivot)
		{
			wall++;//move wall forward,wall starts with 0,incremented each time
			//swap
			bag temp;
			temp.w = A[wall].w;temp.begin = A[wall].begin;temp.end = A[wall].end;
			A[wall].w=A[j].w;A[wall].begin=A[j].begin;A[wall].end=A[j].end;
			A[j].w=temp.w;A[j].begin=temp.begin;A[j].end=temp.end;

		}

	}

	//swap wall with pivot,pivot was set to the right most element
	wall++;
	bag temp;
			temp.w = A[wall].w;temp.begin = A[wall].begin;temp.end = A[wall].end;
			A[wall].w=A[right].w;A[wall].begin=A[right].begin;A[wall].end=A[right].end;
			A[right].w=temp.w;A[right].begin=temp.begin;A[right].end=temp.end;

	return wall;
}

void quicksort(bag A[], int l, int r)
{
	if(l<r)//no need for l=h , already sorted
	{
		int pivot=split(A,l,r);
		//notice: p is completely ecxluded from the remaining quick sort calls
		//since we know its position
		quicksort(A,l,pivot-1);
		quicksort(A,pivot+1,r);


	}
}

int main()
{
	int n,mod;int data;
	int input[1000000];  
	bag bag_weight[1000];
	scanf("%d%d",&n,&mod);
	int i,j;int m;
	int buff=0;
	for(i=0;i<n;++i)
	{
		scanf("%d",&m);

		bag_weight[i].w=0;
		bag_weight[i].begin=buff;
		for(j=0;j<m;++j)
		{

			scanf("%d",&data);
			input[buff]=data;
            buff++;
			bag_weight[i].w=((bag_weight[i].w)%mod+(data)%mod)%mod;           


		}
		bag_weight[i].end=buff-1;
	}


	quicksort(bag_weight,0,n-1);
/*for (i=0;i<=buff;++i)
printf ("%d ",input[i]);
*/
	
for(i=0;i<n;++i)
{
	printf("%d\n",bag_weight[i].w);
	j=bag_weight[i].begin;
	while(j<=bag_weight[i].end)
	printf("%d\n",input[j++]);
    printf("\n");
}

	return 0;
}
