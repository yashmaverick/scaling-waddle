#include<stdio.h>
#include<string.h>
/*int cmpfun(const void *a,const void *b)
{
	return (*(int*)a-*(int*)b);
}*/
void partition(int arr[],int low,int high){

    int mid;

    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}

void mergeSort(int arr[],int low,int mid,int high){

    int i,m,k,l,temp[100000];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }
    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }

    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char jmr[100000];
		scanf("%s",jmr);
		int substr[100000],i,len=strlen(jmr);
		for(i=0;i<len;i++)
		{
			if(jmr[i]=='J')
				substr[i]= -1;
			else if(jmr[i]=='M')
				substr[i]=-999999;
			else if(jmr[i]=='R')
				substr[i]=1000000;
		}
		int zero_count=0;
		for(i=1;i<len;i++)
		{
		    substr[i]+=substr[i-1];
		    if(substr[i]==0)
                zero_count++;
		}
		partition(substr,0,len-1);
		int val=substr[0],count=0,sum=0;
		for(i=0;i<len;i++)
		{
			if(val==substr[i])
				count++;
			if(val!=substr[i]||i==len-1)
			{
				val=substr[i];
				sum += count*(count-1)/2;
				count=1;
			}
		}
		sum += zero_count;
		printf("%d\n",sum);
	}
	return 0;
}
