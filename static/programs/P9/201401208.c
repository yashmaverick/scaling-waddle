#include<stdio.h>

struct BAG{
	int weight;
	int start;
	int finish;
}packet[1001];

struct BAG packet[1001];

//void quicksort(int left,int right);
void swap(int i,int j);
void bubblesort(int n);

int a[1000001];
//int b[1000001];

int main(){
	int N,mod,i,j,k,num,b;

	scanf("%d %d",&N,&mod);
	((packet[0]).start)=0;
	for(i=0;i<N;i++)
	{
		scanf("%d",&num);
		((packet[i]).finish)=((packet[i]).start)+num;
		((packet[i+1]).start)=((packet[i]).finish)+1;
		for(j=0;j<num;j++){
			scanf("%d",&b);
			a[((packet[i]).start)+j]=b;
			(packet[i].weight)=((((packet[i].weight)%mod)+(b%mod))%mod);
		}
	}

	bubblesort(N);
//	quicksort(0,N-1);
	for(i=0;i<N;i++){
		printf("%d\n",((packet[i]).weight));
		for(j=((packet[i]).start);j<((packet[i]).finish);j++){
			printf("%d\n",a[j]);
		}
		printf("\n");
	}	

return 0;
}

/*void quicksort(int left,int right)
{
	int last,i,temp;

	last=left;

	if(left>=right)
		return;

	for(i=left+1;i<=right;i++){
		if(((packet[left]).weight) > ((packet[i]).weight))
		{
			last++;
			swap(last,i);
		}
	}

	swap(left,last);

	quicksort(left,last-1);
	quicksort(last+1,right);
}*/

void swap(int i,int j){
	int temp,temp1,temp2;
	temp=((packet[i]).weight);
	temp1=((packet[i].start));
	temp2=((packet[i].finish));
	((packet[i].weight))=((packet[j].weight));
	((packet[i].start))=((packet[j].start));
	((packet[i].finish))=((packet[j].finish));
	((packet[j].weight))=temp;
	((packet[j].start))=temp1;
	((packet[j].finish))=temp2;
}
void bubblesort(int n){
	int i,j;

	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(packet[j].weight > packet[j+1].weight)
				swap(j,j+1);
			
		}
	}
}
	
