#include <stdio.h>
#include <stdlib.h>

typedef struct bag 
{
	int size;
	int *data;
	int weight;
	struct bag *nextbag; 
}bag;

bag *head;

void insert(int size, int arr[], int val)
{
    
    bag *p = (bag*)malloc(sizeof(bag));  
	p -> size = size;
	p -> data = (int*)malloc(sizeof(int)*size);
	p -> weight = val;
	p -> nextbag = NULL;
	int i;
	for(i = 0; i < size; i++)
		p->data[i] = arr[i];

	if(head==NULL){
		head = p;
		return;
	}

    if(head -> weight > val){
		p -> nextbag = head;
		head = p;
		return;
	}
	
	bag *q = head;
	bag *r;
	while(q != NULL && q -> weight <= val)
	{
		r = q;
		q = q -> nextbag;   
	}

	r -> nextbag = p;
	p -> nextbag = q;
	return;
}

void print()
{
    bag *p = head;
	while(p != NULL)
	{
		printf("%d",p->weight);
		printf("\n");
		int i;
		
		for(i = 0; i < p -> size; i++){
			printf("%d\n",p -> data[i]);
		}
		printf("\n");
		p = p -> nextbag;
	}
}

int main()
{
	int N,mod;
	scanf("%d %d",&N,&mod);
	int size,arr[1000001],i,
	head=NULL;

	while(N--)
	{
		int weight=0;
		scanf("%d",&size);
		for(i = 0; i < size; i++){
			scanf("%d", &arr[i]);
			weight = (weight % mod + arr[i] % mod) % mod;
		}
		insert(size,arr,weight);
	}
	print();
	return 0;
}