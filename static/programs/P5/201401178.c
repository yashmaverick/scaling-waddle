#include<stdio.h>
#include<stdlib.h>
int arr[1000000];
int cmpfunc(const void *a,const void *b)
{
	return (*(int *)a-*(int *)b);
}
int main(){
	int test,i;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		int size,sum,n;
		scanf("%d%d",&size,&sum);
		for(n=0;n<size;n++)
		{
			char str[20];
			//      int arr[size];
			scanf("%s %d",str,&arr[n]);
		}
		qsort( arr, size, sizeof(int), cmpfunc);
		//      for(n=0;n<size;n++){
		//              printf("%d\n",arr[n]);
		//      }
		int p,q,r,flag=0;
		for(p=0;p<size;p++)
		{
			q=p+1;
			r=size-1;
			while(q<r){
				//      q=p+1;
				//      r=size-1; 
				if(arr[p]+arr[q]+arr[r]==sum)
				{
					printf("YES\n");
					flag=1;
					break;
				}
				if(arr[p]+arr[q]+arr[r]>sum)
					r--;
				if(arr[p]+arr[q]+arr[r]<sum)
					q++;
			}
			if(flag==1)
				break;


		}
		if(flag==0)
			printf("NO\n");
	}
	return 0;
}

