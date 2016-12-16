#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[100000];
void quicksortmk(int a[],int x, int y);
int partition(int A[], int left, int right);
int cmpfunc (const void * a, const void * b);

void find();

int main()
{
	int tt,tb;
	scanf("%d",&tt);
	for(tb=0;tt>tb;tb++){
		find();
	}
	return 0;
}
void find()
{
	int n;
	int k,i;
	for(i=0;i<100000;i++){
		a[i]=0;
	}
	scanf("%d %d", &n, &k);
	
	int j;
	for(i=0;i<n;i++){
		char c;
		c=getchar();
		while(c!=' '){
			c=getchar();
		}
		scanf("%d",&a[i]);
	}
	
	qsort(a, n, sizeof(int), cmpfunc);
	
	int l,r;
	for(i=0;i<n-2;i++){
		l=i+1;
		r=n-1;
		while(l<r){
			if(a[i]+a[l]+a[r] == k){
				printf("YES\n");
				return;
			}
			else if(a[i]+a[l]+a[r] < k){
				l++;
			}
			else if(a[i]+a[l]+a[r] > k){
				r--;
			}
		}
	}
	printf("NO\n");
	return;
}
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int partition(int A[], int left, int right)
{
    int x = A[right];
    int i = (left - 1);
    int j;
 
    for (j = left; j <= right - 1; j++)
    {
        if(A[j] <= x)
        {
            i++;
            int temp;
            temp = A[i];
            A[i] = A[j];
			A[j] = temp;
        }
    }
    int temp;
    temp = A[i+1];
    A[i] = A[right];
	A[right] = temp;
    return (i + 1);
}
 
void quicksortmk(int A[], int left, int right)
{
    int pivot;
    if(left < right)
    {
        pivot = partition(A, left, right);
        quicksortmk(A, left, pivot - 1);
        quicksortmk(A, pivot + 1, right);
    }
}
 
