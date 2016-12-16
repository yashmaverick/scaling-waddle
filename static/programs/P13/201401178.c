#include<stdio.h>
int tree[100001],ind,value, lftmin[100001], lftminprev;
void func(int start,int end,int depth){
	int i,j;
	//printf("func runs\n");
	//printf("depth=%d ind=%d\n",depth,ind);
	if(start>end)
		return ;
	if(start==end){
		if(depth>ind){
			value=tree[end];
			ind=depth;
			//printf("dep > ind val%d ind%d\n",value,ind);
			return;
		}
		else if(depth==ind && value>tree[end]){
			value=tree[end];
			//printf("dep == ind val%d  ind%d\n",value,ind);
			return;
		}
	}
	else{
		int flag=0;
		//for(i=end-1;i>=start;i--){	
			//if(tree[i]<tree[end]){
				//flag=1;
				//printf("cut id %d d %d\n",i,depth);
				func(start,lftmin[end],depth+1);
				func(lftmin[end]+1,end-1,depth+1);
				//break;
			//}
		//}
		//if(flag==0)
			//func(start,end-1,depth+1);
	}
	return;
}
int main(){
	int test,z;
	scanf("%d",&test);

	for(z=0;z<test;z++){
		int size,j,i,v, lftminprev=-1;
		value=10000000;
		ind=-1;
		scanf("%d",&size);
		//int tree[size];
		for(j=0;j<size;j++){
			scanf("%d",&tree[j]);
		}
			for(i=0;i<size;i++){
				if(i==0)lftmin[i]=-1;	
				else{
					lftmin[i]=i-1;
					while(lftmin[i]>-1 && tree[lftmin[i]]>tree[i])lftmin[i]=lftmin[lftmin[i]];
					
					
					}
			lftminprev=lftmin[i];

				}
			//for(i=0; i<size; i++)printf("%d ", lftmin[i]);
		
		func(0,size-1,0);
		printf("%d %d\n",value,ind);
	}
	return 0;
}
