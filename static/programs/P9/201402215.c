#include<stdio.h>
#include<stdlib.h>
struct node{
	int *a;
	int index;
	int w;
	int no;
};
typedef struct node node;
void print(node head)
{
	int j;
	//printf("%d\n",(head.w)%mod);
	for(j=0;j<(head.no);j++)
	{
		printf("%d\n",(head.a[j]));
	}
}
void merge(node A[],node B[],node c[],int m,int n)
{	int i=0,j=0,k=0;
	while(i<m&&j<n)
	{	if(A[i].w>B[j].w)
		{	c[k]=B[j];
			j++;k++;}
			else if(A[i].w==B[j].w)
			{	if(A[i].index<B[j].index)
				{	c[k]=A[i];k++;
				c[k]=B[j];k++;
				i++;
				j++;}
				else
				{	c[k]=B[j];k++;
					c[k]=A[i];k++;
					i++;
					j++;
				}
			}
				
				else
				{	c[k]=A[i];
					i++;
					k++;}
	}
	if(j<n)
	{	while(j<n)
		{	c[k]=B[j];
			k++;
			j++;
		}
	}
	if(i<m)
	{	while(i<m)
		{
			c[k]=A[i];
			k++;
			i++;
		}
	} 

}
void mergesort(node a[],int n)
{	int i;
	node left[n];
	node right[n];
	if(n<=1)
	{	return;}
	for(i=0;i<n/2;i++){
		left[i]=a[i];
	}
	for(i=n/2;i<n;i++)
	{	right[i-n/2]=a[i];}
	mergesort(left,n/2);
	mergesort(right,(n-n/2));
	merge(left,right,a,n/2,(n-n/2)); 
}
int main()
{
	int n,m,i,j;
	int mod;
	node head[1001];
	scanf("%d %d",&n,&mod);
	for(i=0;i<n;i++)
	{
	//	head[i]=(node)malloc(sizeof(node));
		head[i].index=i;
		head[i].w=0;
		scanf("%d",&(head[i].no));
//		printf("%d\n",head[i].no);
		m=head[i].no;
		head[i].a=(int *)malloc(m*sizeof(int));
		for(j=0;j<head[i].no;j++)
		{	//printf("1\n");

			scanf("%d",&(head[i].a[j]));
		//	printf("2\n");
				head[i].w+=(head[i].a[j])%mod;
				head[i].w%=mod;
		//	printf("3\n");
		}
	}
//	for(i=0;i<n;i++)
//		printf("%d %d\n",head[i].w,head[i].no);
	mergesort(head,n);
//	printf("\n");
//	for(i=0;i<n;i++)
//		printf("%d",head[i].w,head[i].index)
	for(i=0;i<n;i++)
	{	printf("%d\n",(head[i].w)%mod);
		print(head[i]);
		printf("\n");
	}
	return 0;
}


