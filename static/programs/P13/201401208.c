#include<stdio.h>

struct node{
	int data;
	int level;
}leaf[100005];

struct node leaf[100005];
int a[100005];
void max_node_depth(int n);
int max_min(int i,int n);
int main(){
	int t,i,j,k,l,m,n,p,min;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=n-1;i>=0;i--){
			scanf("%d",&(leaf[i].data));
			leaf[i].level=0;
		}

		a[leaf[0].data]=0;
		//		printf("The value of a[%d] is %d\n",leaf[0].data,a[leaf[0].data]);
		for(j=1;j<n;j++){
			a[leaf[j].data]=j;
			//		printf("The value of a[%d] is %d\n",leaf[j].data,a[leaf[j].data]);
		}

		j=1;
		while(j<n){
			if(leaf[j].data > leaf[j-1].data){
				leaf[j].level=leaf[j-1].level + 1;
				//				printf("level of %d is %d\n",leaf[j].data,leaf[j].level);

			}
			else{

				leaf[j].level = leaf[(max_min(j,n))].level + 1;
				//				printf("j is:%d leaf[j].data is %d leaf[j].level is %d\n",j,leaf[j].data,leaf[j].level);

			}	
			//	min=100005;
			//	for(k=1;k<j;k++){
			//		if(a[k] > a[j] && a[k] < min){
			//			min=a[k];
			//			l=k;
			//		}
			//	}
			//	leaf[n-j-1].level=leaf[n-l-1].level+1;

			j++;

		}

		max_node_depth(n);
	}

	return 0;
}

void max_node_depth(int n){
	int l_depth=0,r_depth=0,l_node,r_node,max_depth=0,max_node;
	int l,r,i;
	for(i=1;i<n;i++){
		if(leaf[i].data < leaf[0].data){
			if(l_depth < leaf[i].level){
				l_depth=leaf[i].level;
				l_node=leaf[i].data;
				//				printf("(left)level is:%d\n",leaf[i].level);
				//				printf("(left depth)level is:%d\n",l_depth);
			}
			else if(l_depth == leaf[i].level && leaf[i].data < l_node)
				l_node=leaf[i].data;
		}
		else if(leaf[i].data > leaf[0].data){
			if(r_depth < leaf[i].level){
				r_depth=leaf[i].level;
				r_node=leaf[i].data;
				//				printf("(right)level is:%d\n",leaf[i].level);
				//				printf("(right depth)level is:%d\n",r_depth);
			}
			else if(r_depth == leaf[i].level && leaf[i].data < r_node)
				r_node=leaf[i].data;
		}
	}



	if(l_depth >=r_depth){
		max_depth=l_depth;
		max_node=l_node;
	}
	else{
		max_depth=r_depth;
		max_node=r_node;
	}
	printf("%d %d\n",max_node,max_depth);
}


int max_min(int i,int n){
	int val,ans,k;
	val=leaf[i].data;
	//	printf("val is %d a[val] is %d\n",leaf[i].data,a[val]);
	if(val > leaf[0].data){
		for(k=val+1;k<=n;k++){
			if(a[k] < a[val]){
				ans=a[k];
				break;
			}
		}
	}
	else{
		for(k=val+1;k<=leaf[0].data;k++){
			if(a[k] < a[val]){
				ans=a[k];
				break;
			}
		}
	}
	return ans;
}
