#include <stdio.h>
int FindJ(int a[],int l,int r,int key){
	int mid=l;
	//mid=(l+r)/2;
	//int r0;
	if (l <= r)
	{
		mid = (l+r)/2;
		//printf("%d %d %d\n",l,r,mid );
		if(a[mid]>key && a[mid-1]<key)
		{
		
			//printf("found mid %d\n",mid);
		
			return mid;


		}
		if(a[mid]>key)
		{
	        //printf("mid greater than key\n");
				return FindJ( a, l, (mid-1), key);
		}
		else if(a[mid]<key)
		{
		//int r;
			//printf("mid less than key\n");
			return FindJ( a,(mid+1),r,key);
		}
	}
	return mid;

}

void process(int a[],int l,int r,int level,int *value,int *depth){
	if(l == r){
		if( *depth < level){
		*value = a[l];
		*depth = level;
		}
		return;
	}
	
	if(l > r){	
		return;
	}
	
	// int j;
	// for(j=l;j<=r-1;j++)
	// {
	// 	if(a[r] < a[j])
	// 	{
	// 		break;
	// 	}
	// }

	int j ;
	j = FindJ(a,l,r-1,a[r]);
	
	

	//printf("* before * %d\n",j);
	process(a,l,j-1,level+1,value,depth);
	//printf("* after first one **\n");
	process(a,j,r-1,level+1,value,depth);
	return;
}
int main(){
	int nt,l;
	scanf("%d",&nt);
	for(l=0;l<nt;l++){
		int n,i;
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int value=0;
		int depth=0;
	//	printf("*\n");	
		process(a,0,n-1,0,&value,&depth);
		printf("%d %d\n",value,depth);
	}
	return 0;
}
