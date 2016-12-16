#include <stdio.h>
int sort_kar();
int search_kar();
int B[1010];
int main(){
	int test;
	scanf("%d", &test);
	while(test--){
	int n,i,j,k,l,a,b,c;
	char C[100000];
	int arr[1010];
	int total;
	scanf("%d%d",&n,&total);
	for(i=0;i<n;i++){
		scanf("%s %d",C,&arr[i]);
		//printf("%s %d\n", A,arr[i]);
	}
	sort_kar(arr,0,n-1);
		/*printf("Array\n");
		for (i = 0; i < n; ++i)
		{
			printf("%d ",arr[i]);
		}
		printf("\n");*/
		a=0;
		for ( i = 0; i < n-2; i++)
		{
			for (j = i+1; j < n-1; j++)
			{
			k=total-arr[i]-arr[j];		
			l=search_kar(arr,k,j+1,n-1);
			//printf("k=%d and search_kar=%d\n",k,l);
			if(l==1){
				printf("YES\n");
			a=1;
			break;
				}
			}
			if(a==1)
			break;
		}
if(a==0)
	printf("NO\n");

}
		return 0;
}
int search_kar(int arr[], int find,int low, int up){
	int mid;
	if(low==up){
		if(arr[low]==find)
			return 1;
		else
			return 0;
	}
	else if(low+1==up){
		if(find==arr[low] || find==arr[up])
			return 1;
		else
			return 0;
	}
	while(low+1<up){
		mid=(low+up)/2;
		if(arr[mid]<find){
			low=mid;
		}
		else if(arr[mid]>find){
			up=mid;
		}
		else
			return 1;
	}
	if(low+1==up){
		if(find==arr[low] || find==arr[up])
			return 1;
		else
			return 0;
	}
	return 0;
}
int sort_kar(int A[], int low, int up){
	if(low==up)
		return 0;
	if(low+1==up){
		if(A[low]>A[up]){
			A[low]=A[low]^A[up];
			A[up]=A[low]^A[up];
			A[low]=A[low]^A[up];
			}
	return 0;
	}
int mid;
mid=(low+up)/2;
	sort_kar(A,low,mid);
	sort_kar(A,mid+1,up);
	int a,b;
	a=low;
	b=(mid+1);
	int c;
	c=low;
	while(a<=mid&&b<=up){
		if(A[a]<A[b]){
			B[c++]=A[a++];
		}
		else{
			B[c++]=A[b++];
		}
	}
	if(a>mid && b<=up){
		while(b<=up){
		B[c++]=A[b++];
		}
	}
	else if(b>up && a<=mid){
		while(a<=mid){
			B[c++]=A[a++];
		}
	}
	a=low;
	b=low;
	while(a<=up){
		A[a++]=B[b++];
	}
return 0;
}