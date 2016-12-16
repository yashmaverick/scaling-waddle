#include<stdio.h>
#include<stdlib.h>
typedef struct vertex{
	int val;
	struct vertex *down;
}node;
node *list[100000];
int p,front=0,rear=-1,visited[10009],queue[10009],level[10009],ans;
void enq(int a, int arr[]){
	rear++;
	arr[rear]=a;
}
void deq(int arr[]){
	front++;
}
void bfs(int i,int j){
	enq(i,queue);
	level[i]=0;
	visited[i]=1;
	while(front<=rear)
	{
		int parent=queue[front];
		//printf("Front of queue is %d\n",queue[front]);
		node *tmp = list[queue[front]]->down;
		deq(queue);
	//printf("Visited %d\n",i);
		while(tmp!=NULL){
			if(visited[tmp->val]!=1){
				enq(tmp->val,queue);
				level[tmp->val]=level[parent] + 1;
			    //printf("Level of %d is %d\n",tmp->val,level[tmp->val]);
				visited[tmp->val]=1;
				if(tmp->val==j){
					ans = level[j];
					return;
				//printf("Answer %d\n",ans);
				}
			}
			tmp = tmp->down;
		}
	}
}

int main(){
	int test;
	int sieve[10005],i,j;
	sieve[1] = 0;
	sieve[0] = 0;
	for(i=2;i<10005;i++){
		sieve[i] = 1;
	}
	for(i=2;i<10005;i++){
		if(sieve[i]!=0){
			for(j=i*i;j<10005;j+=i){
				sieve[j] = 0;
			}
		}
	}
	for(i=999;i<=9999;i++){
		if(sieve[i]==1){
			for(j=999;j<=9999;j++){
				if(sieve[j]==1){
					int j1,j2,j3,j4;
					j1 = j/1000;
					j2 = j/100;
					j2 = j2%10;
					j3 = j/10;
					j3 = j3%10;
					j4 = j%10;
					int i1,i2,i3,i4;
					i1 = i/1000;
					i2 = i/100;
					i2 = i2%10;
					i3 = i/10;
					i3 = i3%10;
					i4 = i%10;
					if((j1==i1 && j2==i2 && j3==i3 && j4!=i4) || (j1==i1 && j2==i2 && j3!=i3 && j4==i4) || (j1==i1 && j2!=i2 && j3==i3 && j4==i4) || (j1!=i1 && j2==i2 && j3==i3 && j4==i4)){
						//node *x = (node *)malloc(sizeof(node));
						node *y = (node *)malloc(sizeof(node));
						/*if(list[j]==NULL){
							list[j]=(node *)malloc(sizeof(node));
						}*/
						if(list[i]==NULL){
							list[i]=(node *)malloc(sizeof(node));
						}
						/*if(list[j]->down==NULL){
							x->val=i;
							list[j]->down=x;
							list[j]->val = 1;
						}
						else{
							x->val=i;
							x->down=list[j]->down;
							list[j]->down=x;
							list[j]->val += 1;
						}*/
						if(list[i]->down==NULL){
							list[i]->down=y;
							y->val=j;
							list[i]->val = 1;
						}
						else{
							y->val=j;
							y->down=list[i]->down;
							list[i]->down=y;
							list[i]->val += 1;
						}
					}			
				}
			}
		}
	}
	scanf("%d",&test);
	while(test--){
		front = 0;
		rear = -1;
		int k;
		for(k=999;k<=10000;k++){
			visited[k]=0;
			//queue[k]=0;
		}
		int a,b;
		scanf("%d%d",&a,&b);
		visited[a]=1;
		if(a==b){
			printf("0\n");
		}
		else{
			level[a]=0;
			bfs(a,b);
			//printf("Front %d Rear %d\n",front,rear);
			printf("%d\n",ans);
		}
	}
	/*for(i=1000;i<=9999;i++){
		if(list[i]!=NULL){
			node *temp;
			temp = list[i]->down;
			printf("%d ",i);
			while(temp!=NULL){
				printf("%d ",temp->val);
				temp=temp->down;
			}
			printf("\n");
		}
	}*/
	/*int k,count=0;
	for(k=1000;k<10000;k++){
		if(sieve[k]==1){
			count++;
			printf("%d\n",k);
		}
	}*/
	//printf("Count %d\n",count);
	return 0;
}