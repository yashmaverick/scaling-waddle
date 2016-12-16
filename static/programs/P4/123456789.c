#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int val1;
	int val2;
}node;

int cmp(const void *a,const void *b) {
	if((((node *)a)->val1)!=(((node *)b)->val1))
		return ((((node *)a)->val1)-(((node *)b)->val1));
	else
		return ((((node *)a)->val2)-(((node *)b)->val2));
}

int main() {
	int test;
	scanf("%d",&test);
	while(test--)	{
		char string[100000];
		int a[100000],b[100000],c[100000];
		int i,j,l;
		scanf("%s",string);
		l=strlen(string);
		for(i=0;i<l;i++)
			a[i]=b[i]=c[i]=0;
		node arr[100000];
		if(string[0]=='R')                              // a -> R, b -> M, c-> J
			a[0]=1;
		else 
			if(string[0]=='M')
				b[0]=1;
			else c[0]=1;
		arr[1].val1=a[0]-b[0];
		arr[1].val2=a[0]-c[0];
		arr[0].val1=arr[0].val2=0;
		for(i=1;i<l;i++)
		{
			if(string[i]=='R')
				a[i]=a[i-1]+1;
			else 
				a[i]=a[i-1];
			if(string[i]=='M')
				b[i]=b[i-1]+1;
			else
				b[i]=b[i-1];
			if(string[i]=='J')
				c[i]=c[i-1]+1;
			else
				c[i]=c[i-1];
			arr[i+1].val1=a[i]-b[i];
			arr[i+1].val2=a[i]-c[i];
		}
//		for(i=0;i<=l;i++)
//		{
//			printf("%d\n",arr[i].val1);
//			printf("%d\n",arr[i].val2);
//		}
		qsort(arr,l+1,sizeof(node),cmp);
//		for(i=0;i<=l;i++)
//		{
//			printf("%d\n",arr[i].val1);
//			printf("%d\n",arr[i].val2);
//		}
		arr[l+1].val1=arr[l+1].val2=arr[l].val1+1;
		int ans=0,val=0;
		for(i=0;i<=l;i++)
		{
			val++;
			if(arr[i].val1!=arr[i+1].val1 || arr[i].val2!=arr[i+1].val2)
			{
				ans=ans+((val*(val-1))/2);
				val=0;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}