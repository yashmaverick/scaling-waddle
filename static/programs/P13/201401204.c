#include<stdio.h>
int a[100005],b[100005];
int count=0;
int value=100000000;
void depth(int start,int root,int d){
	int l=0;
	int r=0;
	//	printf("start=%d root=%d count=%d d=%d\n",start,root,count,d);
	if(start>root) 
		return;	
	/*if(count<=d){
	  count=d;
	  if(value>a[root])
	  value=a[root];
	  }*/
	if(b[root]>=0 && b[root]>=start){
		l=1;
	}		//	left exists
	if(root!=0 && a[root-1]>a[root]){
		r=1;
	}		//	right exists
	if(l==0 && r==0){		//	i.e. it is a leaf
		if(count==d)
			if(value>a[root])
				value=a[root];
		if(count<d){
			count=d;
			value=a[root];
		}
		//	printf("done\n");
		return;
	}
	if(r==1 && l==1){		 
		//		printf("both called after %d\n",a[root]);
		depth(b[root]+1,root-1,d+1);	//	calling right
		depth(start,b[root],d+1);	//	calling left
	}
	else if(r==1 ){			
		//		printf("right called after %d\n",a[root]);
		depth(start,root-1,d+1);	//	calling right only if left doesn't exist
	}
	else if(l==1){
		//		printf("left called after %d\n",a[root]);
		depth(start,root-1,d+1);	//	calling left only if right doesn't exist
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int min,j,i,n;
		count=0;
		value=100000000;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		b[0]=-1;
		int root=a[n-1];
		for(i=1;i<n;i++){
			if(b[i-1]==-1){
				if(a[i-1]>a[i])
					b[i]=-1;
				else if(a[i-1]<a[i])
					b[i]=i-1;
			}	
			else{
				if(a[i-1]<a[i]){
					b[i]=i-1;
				}
				else{
					j=i-1;
					while(j>=0){
						if(b[j]==-1){
							b[i]=-1;
							break;
						}
						if(a[b[j]]<a[i]){
							b[i]=b[j];
							break;
						}
						if(a[b[j]]>a[i])
							j=b[j];
					}
				}
			}
		}
		/*		for(i=0;i<n;i++){
				printf("%d ",b[i]);
				}
				printf("\n");*/
		depth(0,n-1,0);
		printf("%d %d\n",value,count);
	}
	return 0;
}
