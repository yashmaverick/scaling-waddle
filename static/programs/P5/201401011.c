#include<stdio.h>
#include<stdlib.h>

//int *merge_sort(int *a,int l,int r);
//int *merge(int *left,int len_left,int *right,int len_right);
int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
int main()
{
	int T,n,k,i,j,sum,flag=0;
	int *ar;
	ar =(int*) malloc( 2000 * sizeof(int));
	char night[1000];

	scanf("%d",&T);
	while(T--)
	{
		flag = 0;
		scanf("%d %d",&n,&sum);
		for(i=0;i<n;i++)
		{
			scanf("%s",night);
			scanf("%d",&ar[i]);
		}
		qsort(ar,n,sizeof(int),cmpfunc);
		for(i=0;i<n-2;i++)
		{
			j=i+1,k=n-1;
			while(j<k)
			{		
				if(ar[i]+ar[j]+ar[k] == sum)
				{
					printf("YES\n");
					flag=1;
					break;
				}
				else if(ar[i]+ar[j]+ar[k] > sum)
					k--;
				else
					j++;
			}
			if(flag==1)
				break;
		}
		if(flag!=1)
			printf("NO\n");
	}
	return 0;
}
/*
   int *merge_sort(int *a,int l,int r)
   {
   if(l == r)
   return (a + l);

   int mid;
   int *left_arr,*right_arr;

   left_arr = (int*) malloc( 2000 * sizeof(int));
   right_arr = (int*) malloc( 2000 * sizeof(int));

   mid = l + (r - l)/2 ;
   left_arr = merge_sort(a,l,mid);
   right_arr = merge_sort(a,mid+1,r);

   return merge(left_arr,mid-l+1,right_arr,r-(mid+1)+1);
   }

   int *merge(int *left,int len_left,int *right,int len_right)
   {
   int i=0,j=0,k=0;

   int *temp;
   temp = (int*) malloc( 10099 * sizeof(int));

   while(i<len_left && j<len_right)
   {
   if(*(left+i) <= *(right+j))
   {
 *(temp+k) = *(left+i);
 k++,i++;
 }
 else
 {
 *(temp+k) = *(right+j);
 k++;j++;
 }
 }

 for(;j<len_right;j++,k++)
 *(temp+k) = *(right+j);
 for(;i<len_left;i++,k++)
 *(temp+k) = *(left+i);

 return temp;
 }
 */
