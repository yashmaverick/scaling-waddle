
#include<stdio.h>
#include<string.h> 
#define MAX 100010
long long int arr[100010],brr[100010],temp1[100010],temp2[100010];
void mergeSort(long long int low,long long int mid,long long int high);
void partition(long long  int low,long long int high);
int main()
{
long long  int i,n=0,test,j,m,r,l,sum=0,count=1;
char string[100010];
scanf("%lld",&test);    
for(i=0;i<test;i++)
{
    scanf("%s",string);
    n=strlen(string);
    if(n<=2)
    {
	    printf("0\n");
    }
    else if(n==3)
    {
	    if(string[0]!=string[1] && string[1]!=string[2] && string[2]!=string[0])
		  printf("1\n");
	    else
		    printf("0\n");
    }
	    
    
    else if(n>3)
    {
	    
	    arr[0]=0;
            brr[0]=0;
    for(l=0;l<n;l++)
    {
         if(string[l]=='J')
		 j++;
	 if(string[l]=='M')
		 m++;
	 if(string[l]=='R')
		 r++;

	 arr[l+1]=j-m;
	 brr[l+1]=j-r;
    }
    if(j>=n-1 || m>=n-1 || r>=n-1)
    {
	printf("0\n");
    }
    else
    {    
    
    
    partition(0,n);
	long long int count=1;
	long long  int sum=0;
		for(l=0;l<n;l++)
		{
		    if(arr[l]==arr[l+1] && brr[l]==brr[l+1])
		    {
		           count++;
		    }
		    else
		    {
			    sum=sum+(count*(count-1))/2;
	                   	count=1;	   
			
		    }
		}
          sum=sum+(count*(count-1))/2;
		printf("%lld\n",sum);

    }
}
}
return 0;
}

void partition(long long int low,long long int high){

    long long int mid;

    if(low<high){
         mid=(low+high)/2;
         partition(low,mid);
         partition(mid+1,high);
         mergeSort(low,mid,high);
    }
}

void mergeSort(long long int low,long long int mid,long long int high){

   long long  int in,mun,k,eng;

    eng=low;
    in=low;
    mun=mid+1;

    while((eng<=mid)&&(mun<=high))
    {

         if(arr[eng]<arr[mun]){
             temp1[in]=arr[eng];
	     temp2[in]=brr[eng];
             eng++;
         in++;
	 }
         if(arr[eng]==arr[mun])
	 {
		 if(brr[eng]<=brr[mun])
	         {
                temp1[in]=arr[eng];
	        temp2[in]=brr[eng];
                 eng++;
	         in++;
		 }
		 if(brr[eng]>brr[mun])
		 {
			 temp1[in]=arr[mun];
			 temp2[in]=brr[mun];
			 mun++;
		 in++;
		 }
	 }
	 if(arr[eng]>arr[mun])
	 {
             temp1[in]=arr[mun];
             temp2[in]=brr[mun];
	     mun++;
             in++;
	 }
         
     }

    if(eng>mid)
    {
         for(k=mun;k<=high;k++)
	 {
             temp1[in]=arr[k];
             temp2[in]=brr[k];
	     in++;
         }
    }
    else   {
         for(k=eng;k<=mid;k++)
	 {
             temp1[in]=arr[k];
             temp2[in]=brr[k];
	     in++;
         }
           }
   
    for(k=low;k<=high;k++)
    {
         arr[k]=temp1[k];
	 brr[k]=temp2[k];
    }
}
