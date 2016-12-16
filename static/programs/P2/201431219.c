#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int A[100010], A1[100010], B[100010], B1[100010], C[100010];
long long int B2[100010];
int binary_123(int A[], long long int a, int size, int start){
//Here "a" is the number which we need to search in the given array using binary search
//"start" is used so as we can return the value of start if the very first element is the answer
//size is the normal size, not staring from index 0

	int low, up, mid, index;
	low=start;
	up=size-1;
	int flag=0;
	if(a <= A[low])
		return start;
	else if(a>A[size-1])
	return 100010;
	while((low+1)<up){
		mid=(low+up)/2;
		if(A[mid]>a){
			up=mid;
		}
		else if(A[mid]<a){
			low=mid;
		}
		else{
			index=mid;
			return index;
		}
	}
		return up;//>size-1?up:size-1;
}
int main(){
	int test;
	scanf("%d", &test);
	while(test--){
		
//Check function binary
/*	int i,n, A[1000],a;
	scanf("%d %d",&n,&a);
	for(i=0;i<n;i++){
		scanf("%d", &A[i]);
	}
printf("%d\n",binary(A,a,n));*/
	int a,b,c,l,m,n,i,j,k;
	for(i=0;i<100010;i++){
			A[i]=0;
			B[i]=0;
			B1[i]=0;
			B2[i]=0;
			C[i]=0;

		}
	scanf("%d",&a);
	//int *A=malloc(sizeof(int)*a);
	//int *A1=malloc(sizeof(int)*a);
	//int A[100001], A1[100001];
	for(i=0;i<a;i++){
		scanf("%d", &A[i]);
	}
	scanf("%d",&b);
	//int *B=malloc(sizeof(int)*b);
	//int *B1=malloc(sizeof(int)*b);
	//int B[100001],B1[100001];
	//long long int *B2=malloc(sizeof(int)*b);
	//long long int B2[100001];	
	for(i=0;i<b;i++){
		scanf("%d", &B[i]);
	}	
	scanf("%d",&c);
	//int *C=malloc(sizeof(int)*c);
//int C[100001];
	for(i=0;i<c;i++){
		scanf("%d", &C[i]);
	}
	

	int flag,b1, find;
	b1=b<c?b:c;
	flag=0;
	for(i=0;i<b1;i++){
		if(B[i]<=C[c-1]){
			find=binary_123(C, B[i], c, i);
			//printf("Find = %d\n", find);
			if(c-find>0)  //check whether this is >=0 or >0 only..
				B1[i]=c-find;
		}
		else{
			B1[i]=0;
			for(j=i;j<b;j++){
			B1[i]=0;
			}
			flag=1;
			break;
		}
	}
	if(flag==0){
		for(i=b1;i<b;i++){
			B1[i]=0;
		}
	}
	B2[b-1]=B1[b-1];
for(i=b-2;i>=0;i--){
	B2[i]=B1[i]+B2[i+1];
}
//B2[b-1]=B1[b-1];
long long int count=0;
	int a1;
	a1=a<b?a:b;
	flag=0;
	for(i=0;i<a1;i++){
		if(A[i]<=B[b-1]){
			find=binary_123(B, A[i], b, i);
			//printf("Find = %d\n", find);
			//count=count+B2[i];
			if(b-find>0)  //check whether this is >=0 or >0 only..
				A1[i]=b-find;
		}
		else{
			A1[i]=0;
			for(j=i;j<a;j++){
			A1[i]=0;
			}
			flag=1;
			break;
		}
	}
	if(flag==0){
		for(i=a1;i<a;i++){
			A1[i]=0;
		}
	}
for(i=0;A1[i]!=0;i++){
	count+=B2[b-A1[i]];
}
printf("%lld\n", count);

	/*int a1;
	a1=a<b?a:b;
	a1=a1<c?a1:c;
	find=binary(B, A[a1-1], b, a1-1);
	if(find==100010)
		find=b1-1;
	A1[a1-1]=0;
	for(i=find;i<b1;i++){
			
			A1[a1-1]=B1[i]+A1[a1-1];
	}
	int sum=0;
	if(A[a1-1]<=B[a1-1])
		sum=A1[a1-1];
	for(i=a1-2;i>=0;i--){
		A1[i]=A1[i+1]+B1[i];
		//if(A[i]<=B[i])
		sum+=A1[i];
	}*/
/*	printf("Value\n");
	for(i=0;i<b;i++){
		printf("%d ", B1[i]);
	}
	printf("\n");
	for(i=0;i<a;i++){
		printf("%d ", A1[i]);
	}
	printf("\n");
for(i=0;i<b;i++){
		printf("%d ", B2[i]);
	}
	printf("\n");
printf("count=%d\n",count);*/
//	printf("%d\n", sum);
}
return 0;
}