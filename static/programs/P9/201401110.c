#include<stdio.h>
#include<stdlib.h>

typedef struct b
{
  long long int sum;
  long long int m;
  long long int* array;

}b;

/* void swap(int *a,int *b)
{
  int temp=*a;
  *a=*b;
  *b=*a;
}

int partition(int A[],int start,int end)
{
  int pivot=start;
  int i,j=start+1;
  for(i=start+1;i<=end;i++)
  {
    if(A[i]<A[pivot])
    {
      swap(&A[i],&A[j]);
      j++;
    }
    swap(&A[pivot],&A[j-1]);
    pivot=j-1;
    return pivot;
    //printf("PIVOT : %d ELE: %d\n",pivot,A[pivot]);
  }
}

  void sort(int start,int end,int k,int A[])
  {
    int pivot;
    if(start<end)
    {
      pivot=partition(A,start,end);
      if(pivot==k-1)
      {
        printf("%d\n",A[pivot]);
      }
      else if(pivot>k-1)
        sort(start,pivot-1,k,A);
      else 
        sort(pivot+1,end,k,A);
    }
    return;
  } */


int main()
{
	long long int i,j;
	long long int n,m,mod;
  b temp;
 
  //struct bag *ptr = &b;
	scanf("%lld",&n);
	scanf("%lld",&mod);
  struct b *bag=malloc(n*sizeof(struct b));
		/*for(i=0;i<=n;i++)
	{
		scanf("%lld",&m);
		a[i]=(long long int *)malloc((m+2)*sizeof(long long int));
		a[i][0]=m;
		for(j=2;j<m+2;j++)
		{
			scanf("%lld",&a[i][j]);
			a[i][1]+=a[i][j];
		}
	}*/
for (i = 0; i < n; i++)
{
 	scanf("%lld",&bag[i].m);
  bag[i].array=malloc((bag[i].m)*sizeof(long long int));
 // printf("M: %lld\n",bag[i].m);
  for(j=0;j<bag[i].m;j++)
  {
    scanf("%lld",&bag[i].array[j]);
   // printf("ARRAY ELE%lld\n",bag[i].array[j]);
    bag[i].sum=(bag[i].sum+(bag[i].array[j]%mod))%mod;

  }
  bag[i].sum=bag[i].sum%mod;
 // printf("BAG SUM WHILE IO: %lld\n",bag[i].sum );
}

/**ptr = &b;  //bring the pointer back
struct bag *temp=b;
for(i=0;i<n;i++)
{
  for(j=0;j<n-1-i;j++)
  {
    if(bag[j].sum>bag[j+1].sum)
    {
      temp=ptr;
      ptr=ptr+1;
      ptr+1=temp;
      
    }
    ptr++;
  }
}*/

for(i=0;i<n;i++)
{
  for(j=0;j<n-1-i;j++)
  {
    if(bag[j].sum>bag[j+1].sum)
    {
      temp=bag[j];
      bag[j]=bag[j+1];
      bag[j+1]=temp;
      
    }
  }
}


/*printf("TEMP ARR AFTER\n");
for(i=0;i<n;i++)
{
  printf("%d : ",temparr1[i]);
}
printf("\n");*/
	for(i=0;i<n;i++)
  {
    printf("%lld\n",bag[i].sum);
		for(j=0;j<bag[i].m;j++)
		{
			printf("%lld\n",bag[i].array[j]);

		}
		printf("\n");
	}

return 0;
}