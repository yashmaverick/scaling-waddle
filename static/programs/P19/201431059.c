#include<stdio.h>
#include<stdlib.h>

#define min(a,b) ((a)<(b)?(a):(b))

int found = 0;
int cmp(const void *a,const void *b)
{
	return *(long long int*)a - *(long long int*)b;
}
long long int A[1000010];
long long int B[1000010];
int len;
int search(int l,int h,long long int elem)	//[l,h)
{
	if(l>=h)
		return 0;
	if(l == h-1)
	{
		if(A[l] == elem) return 1;
		else return 0;
	}
	int mid = (l+h)>>1;
	if(A[mid] == elem)return 1;
	if(A[mid] > elem)
		return search(l,mid,elem);
	else
		return search(mid+1,h,elem);

}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		found = 0;
		int n;
		scanf("%d",&n);
		int i;
		 len=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",B+i);
			long long int temp = B[i];
			while(temp/10!=0)
			{
				A[len++] = temp/10;
				temp = temp/10;
			}
		}
		qsort(A,len,sizeof(long long int),cmp);
		qsort(B,n,sizeof(long long int),cmp);
		for(i=0;i<n-1;i++)
			if(B[i]==B[i+1])
			{
				found=1;
				break;
			}
		if(found)
		{
			printf("NO\n");
			continue;
		}
		for(i=0;i<n;i++)
		{
			long long int elem = B[i];
			if(search(0,len,elem))
			{
				found = 1;
				break;
			}	
		}
		printf("%s\n",found?"NO":"YES");
	}
	return 0;
}
