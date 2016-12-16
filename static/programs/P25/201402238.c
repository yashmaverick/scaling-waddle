#include<stdio.h>
#include<stdlib.h>

// kruskals algorithm
void mergesort();
void merge();

typedef long long int ll;
typedef struct input{
	long long int source;
	long long int destination;
	long long int weight;

}input;

typedef struct list {
	ll val;
	struct list *next;
}list;

list *arr[100005];

input *a[1000005],*temp;

void insert(list *head,ll i){

	while(head->next!=NULL)
	{
		head=head->next;
	}
	head->next=(list *)malloc(sizeof(list));
	head->next=arr[i];
}

int find(list *head,ll i){
	ll j;

	if(head->val==i)
	{
		return i;

	}
	else
	{
		j=find(arr[head->val],head->val);		
		return j;
	}
}

void merge(int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 =  r - m;

	/* create temp arrays */
	input *L[n1], *R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for(i = 0; i < n1; i++)
	{
		L[i]=(input *)malloc(sizeof(input));   	
		L[i] = a[l + i];
	}
	for(j = 0; j < n2; j++)
	{ 
		R[j]=(input *)malloc(sizeof(input));
		R[j] = a[m + 1+ j];
	}
	/* Merge the temp arrays back into arr[l..r]*/
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i]->weight <= R[j]->weight)
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the sub-array
   of arr to be sorted */
void mergeSort(int l, int r)
{
	if (l < r)
	{
		int m = l+(r-l)/2; 
		//Same as (l+r)/2, but avoids overflow for large l and h
		mergeSort(l, m);
		mergeSort(m+1, r);
		merge(l, m, r);
	}
}

int main()
{	
	long long int n,m,j,i,k=0,v,b;

	scanf("%lld %lld",&n,&m);

	for(j=0;j<m;j++) //taking input in sorting order
	{
		i=j;
		a[i]=(input *)malloc(sizeof(input));
		//	temp=(input *)malloc(sizeof(input));
		scanf("%lld%lld%lld",&a[i]->source,&a[i]->destination,&a[i]->weight);

	//this runs in n*n time so have to use merge sort
		/*while(i>0 && a[i]->weight<a[i-1]->weight)
		  {	
		  temp=a[i-1];
		  a[i-1]=a[i];
		  a[i]=temp;
		  i--;
		  }*/

	}
	j--;
	mergeSort(0,j);

	for(i=1;i<=n;i++)
	{
		arr[i]=(list *)malloc(sizeof(list));
		arr[i]->val=i;	
		arr[i]->next=NULL;
	}

	j=0;i=0;

	while(1)
	{
		v=find(arr[a[i]->source],a[i]->source);
		b=find(arr[a[i]->destination],a[i]->destination);

		if(v!=b)
		{
			insert(arr[v],b);
			arr[b]->val=v;
			arr[b]->next=NULL;
			j+=a[i]->weight;
			k++;
		}
		i++;
		if(i==m || k==(n-1))
			break;
	}
	if(k==(n-1))
		printf("%lld\n",j);
	else
		printf("-1\n");

	return 0;
}		
