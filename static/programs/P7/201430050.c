 #include<stdio.h>
typedef long long int lld;
lld a[1000001],temp[1000001];
void mergeSort(lld arr[],lld low,lld mid,lld high);
void partition(lld arr[],lld low,lld high);
void partition(lld arr[],lld low,lld high)
{

    lld mid;

    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}

void mergeSort(lld arr[],lld low,lld mid,lld high)
{

   lld i,m,k,l;

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
{lld t,n,i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		partition(a,0,n-1);
	//	for(i=0;i<n;i++)
	//		printf("a=%d\n",a[i]);
lld count=1;
	lld j,count1=0;
	for(j=0;j<n-1;j++)
	{if(a[j]==a[j+1])
		{
	    count++;
		}
		else
		{count1=count1+((count)*(count-1))/2;
	           count=1;	 
	
		}
	}
	
		count1=count1+((count)*(count-1))/2;
		printf("%lld\n",count1);
	}
	return 0;
}

