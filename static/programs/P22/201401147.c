#include<stdio.h>
#include<limits.h>
int MOD=1000000007;
int minheap[100005];
int minsize=0,maxsize=0;
int maxheap[100005];
int a,b,c,n;
int med;
unsigned long long int sum=0;
/*void print(int *heap,int size){
  int i=1;
  for(i=1;i<=size;i++)
  printf("%d\t",heap[i]);
  printf("\n");
  return ;
  }*/
void balancemax(){
	int i=maxsize,temp;
	while(i>1){
		if(maxheap[i]>maxheap[i/2]){
			temp=maxheap[i/2];
			maxheap[i/2]=maxheap[i];
			maxheap[i]=temp;
			i=i/2;
		}
		else
			break;//i=i/2;
	}
	return ;
}
void balancemin(){
	int i=minsize,temp;
	while(i>1){
		if(minheap[i]<minheap[i/2]){
			temp=minheap[i/2];
			minheap[i/2]=minheap[i];
			minheap[i]=temp;
			i=i/2;
		}
		else
			break;//i=i/2;
	}
	return ;
}
void shufflemin(){
	//printf("minsize is %d and max size is%d\n",minsize,maxsize);
	minheap[1]=minheap[minsize];
	minsize--;
	//printf("minsize is %d and max size is%d\n",minsize,maxsize);
	int i=1,temp;
	while(i<=minsize/2 && (minheap[i]>minheap[2*i]||minheap[i]>minheap[2*i+1])){//made changes in while loop after getting seg fault
		if(minheap[2*i] <  minheap[2*i+1]){
			temp=minheap[i];
			minheap[i]=minheap[2*i];
			minheap[2*i]=temp;
			i=2*i;
		}
		else{
			temp=minheap[i];
			minheap[i]=minheap[2*i+1];
			minheap[2*i+1]=temp;
			i=2*i+1;
		}
	}
	return ;
}
void shufflemax(){
	//printf("minsize is %d and max size is%d\n",minsize,maxsize);
	maxheap[1]=maxheap[maxsize];
	maxsize--;
	//printf("minsize is %d and max size is%d\n",minsize,maxsize);
	int i=1,temp;
	while(i<=maxsize/2 && (maxheap[i]<maxheap[2*i]||maxheap[i]<maxheap[2*i+1])){
		if(maxheap[2*i] >  maxheap[2*i+1]){
			temp=maxheap[i];
			maxheap[i]=maxheap[2*i];
			maxheap[2*i]=temp;
			i=2*i;
		}
		else{
			temp=maxheap[i];
			maxheap[i]=maxheap[2*i+1];
			maxheap[2*i+1]=temp;
			i=2*i+1;
		}
	}
	return ;
}

int median(){
	if(minsize>maxsize || maxheap[1] > minheap[1])
		return minheap[1];
	else
		return maxheap[1];
}
void generate(int i){
	med=median();
	unsigned long long int temp=((((long long)med*a)%MOD+((long long)b*i)%MOD)%MOD+(long long)c)%MOD;
	sum+=temp;
	if(temp<=med){
		maxheap[++maxsize]=temp;
		if(maxsize>1)
			balancemax();
		while(maxsize-minsize >1){
			minheap[++minsize]=maxheap[1];
			balancemin();
			shufflemax();
			balancemax();
		}
	}
	else{
		minheap[++minsize]=temp;
		if(minsize>1)
			balancemin();
		while(minsize-maxsize>1){
			maxheap[++maxsize]=minheap[1];
			balancemax();
			shufflemin();
			balancemin();
		}
	}
	return ;
}
int main(){
	int t,temp;
	//printf("%d\n",INT_MAX);
	scanf("%d",&t);
	while(t--){
		minsize=0;
		maxsize=0;
		sum=1;
		int i;
		scanf("%d%d%d%d",&a,&b,&c,&n);
		if(n>=2){
			temp=(int)(((a+(2*(long long)b)%MOD)%MOD+c)%MOD);
			sum=temp+1;
			minheap[++minsize]=(temp<1)?1:temp;
			maxheap[++maxsize]=(temp>1)?1:temp;
			//printf("minheap[1] is %d\nmaxheap[1] is %d\n",minheap[1],maxheap[1]);
			if(n>=3){
				for(i=3;i<=n;i++)
					generate(i);
			}
		}
		printf("%llu\n",sum);
	}
	return 0;
}
