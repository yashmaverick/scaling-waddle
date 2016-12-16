#include<stdio.h>
#include<string.h>
char A[100005];
typedef struct list{
    int a;
    int b;
}name;
name B[100005];
#define MAX 1000000
void mergeSort(name arr[],int low,int mid,int high);
void partition(name arr[],int low,int high);
void partition(name arr[],int low,int high){

    int mid;
    if(low<high){
	mid=(low+high)/2;
	partition(arr,low,mid);
	partition(arr,mid+1,high);
	mergeSort(arr,low,mid,high);
    }
}

void mergeSort(name arr[],int low,int mid,int high){

    int i,m,k,l;
    name temp[MAX];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

	if(arr[l].a<arr[m].a){
	    temp[i].a=arr[l].a;
	    temp[i].b=arr[l].b;
	    l++;
	}
	else if(arr[l].a==arr[m].a)
	{
	    if(arr[l].b<=arr[m].b)
	    {
		temp[i].a=arr[l].a;
		temp[i].b=arr[l].b;
		l++;
	    }
	    else
	    {
		temp[i].a=arr[m].a;
		temp[i].b=arr[m].b;
		m++;
	    }
	}
	else{
	    temp[i].a=arr[m].a;
	    temp[i].b=arr[m].b;
	    m++;
	}
	i++;
    }

    if(l>mid){
	for(k=m;k<=high;k++){
	    temp[i].a=arr[k].a;
	    temp[i].b=arr[k].b;
	    i++;
	}
    }
    else{
	for(k=l;k<=mid;k++){
	    temp[i].a=arr[k].a;
	    temp[i].b=arr[k].b;
	    i++;
	}
    }

    for(k=low;k<=high;k++){
	arr[k].a=temp[k].a;
	arr[k].b=temp[k].b;
    }
}
int main()
{
    int t,len,i;
    scanf("%d",&t);
    while(t--)
    {
	int j=0,m=0,r=0,ans=0,count=0;
	scanf("%s",A);
	len=strlen(A);
	for(i=0;i<len;i++)
	{
	    B[i].a=m-j;
	    B[i].b=m-r;
	    if(A[i]=='J')
	    {
		j++;
	    }
	    else if(A[i]=='R')
	    {
		r++;
	    }
	    else
	    {
		m++;
	    }
	}
	B[i].a=m-j;
	B[i].b=m-r;
	partition(B,0,len);
/*	for(i=0;i<=len;i++)
	{
	    printf("%d %d\n",B[i].a,B[i].b);
	}*/
	for(i=0;i<=len;i++)
	{
	    if(B[i].a==B[i+1].a&&B[i].b==B[i+1].b)
	    {
		count++;
	    }
	    else
	    {
		ans=ans+((count+1)*(count))/2;
		count=0;
	    }
	}
	printf("%d\n",ans);
    }
    return 0;
}




