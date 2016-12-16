#include<stdio.h>
#include<limits.h>
int a[100000];
int stack[100000];
int marks[100000];
int maxdepth=-1;
int node=INT_MAX;
void func(int start,int end,int depth){
	int i;
	if(start==end){
		if(depth > maxdepth){
			maxdepth=depth;
			node=a[start];
		}
		else if(depth==maxdepth && a[start] < node){
			node=a[start];
		}
		return ;
	}
	else{
		i=marks[end];
		if(i==-1 || i < start){
			func(start,end-1,depth+1);
		}
		else{
			func(start,i,depth+1);//left subtree
			if(i < end-1 && i >=start){
				func(i+1,end-1,depth+1);
			}
		}
	}
}
int N;
void pack(int *a,int start,int end){
	int i,m;
	int rear=-1;
	i=end;
	while(i>=0){
		if(rear==-1 || a[i]>=a[stack[rear]])
			stack[++rear]=i--;
		else{
			m=stack[rear--];
			marks[m]=i;
		}
	}
	while(rear!=-1){
		marks[stack[rear]]=-1;
		rear--;
	}
}	
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&N);
		int i;
		for(i=0;i<N;i++)
			scanf("%d",&a[i]);
		pack(a,0,N-1);
		func(0,N-1,0);
		printf("%d %d\n",node,maxdepth);
		maxdepth=-1;
		node=INT_MAX;
	}
	return 0;
}
