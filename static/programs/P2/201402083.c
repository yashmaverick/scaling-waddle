#include<stdio.h>
long long int searchbig(long long int arr[],long long int num,long long int start,long long int end,long long int size);
long long int searchsmall(long long int arr[],long long int num,long long int start,long long int end,long long int size);
int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		 long long int count=0;
		long long int lena,lenb,lenc;
		scanf("%lld",&lena);
		long long int arr[lena],i;
		for(i=0;i<lena;i++)
			scanf("%lld",&arr[i]);
		scanf("%lld",&lenb);
		long long int brr[lenb];
		for(i=0;i<lenb;i++)
			scanf("%lld",&brr[i]);
		scanf("%lld",&lenc);
		long long int crr[lenc];
		for(i=0;i<lenc;i++)
			scanf("%lld",&crr[i]);
	/*		//start
		for(i=0;i<lena;i++)
			printf(" %d ",arr[i]);
		printf("\n");
		for(i=0;i<lenb;i++)
			printf(" %d ",brr[i]);
		printf("\n");
		for(i=0;i<lenc;i++)
			printf(" %d ",crr[i]);
		printf("\n");
	*/	//finish
		for(i=0;i<lenb;i++)
		{
			long long int index1=-1;
			long long int index2=-1;
	/*		//start
			printf("ELEMENTS SENT FOR SEARCH is %d \n",brr[i]);
	*/		//finish
			if(i<lena)
			{
				if(brr[i]>arr[i])
					index1=i;
				else
				 	index1=searchsmall(arr,brr[i],0,i,lena);
			}
			else
				 index1=searchsmall(arr,brr[i],0,lena-1,lena);
			if(i<lenc)
			{
				if(brr[i]<crr[i])
					index2=i;
				else
				 	index2=searchbig(crr,brr[i],i,lenc-1,lenc);
			}
	/*		//start
			printf("VALUES RESTURNED index1:%d index2:%d \n",index1,index2);
	*/		//finish
			
			if(index1!=-1 && index2!=-1)
			         count+=( (index1+1)*(lenc-index2));
	/*		//start
			printf("count is %lld \n\n",count);
	*/		//finish
		}
		printf("%lld\n",count);
	}

	return 0;
}

long long int searchbig(long long int arr[],long long int num,long long int start,long long int end,long long int size)
{
	//start
/*	printf("IN FUNC. searchbig \n");
	printf("%d-start %d-end %d-size %d-num\n",start,end,size,num);
*/	//finish
	if(end<=start)
	{
		if(num<=arr[start])
			return start;
		else
			return -1;
	}
	long long int mid=(start+end)/2,found1;
	//start
/*	printf("%d-mid %d-arr[mid]\n",mid,arr[mid]);
	printf("\n\n");
*/	//finish
	if(arr[mid]>=num && num>arr[mid-1])
		return mid;
	else if(arr[mid]>num)
	{
		found1=searchbig(arr,num,start,mid,size);
	}
	else
		found1=searchbig(arr,num,mid+1,end,size);
	return found1;
}


long long int searchsmall(long long int arr[],long long int num,long long int start,long long int end,long long int size)
{
	if(end<=start)
	{

		if(num<arr[start])
			return -1;
		else
			return start;
	}
	long long int mid=(start+end)/2,found1;
	if(arr[mid]<=num && num<arr[mid+1])
		return mid;
	else if(arr[mid]>num)
	{
		found1=searchsmall(arr,num,start,mid,size);
	}
	else
		found1=searchsmall(arr,num,mid+1,end,size);
	return found1;
}

