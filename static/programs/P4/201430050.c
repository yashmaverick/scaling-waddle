#include<stdio.h>
#include<math.h>
#include<string.h>
int a[1000010],b[1000010];
void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);
void partition(int arr[],int low,int high)
{
    int mid;

    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}

void mergeSort(int arr[],int low,int mid,int high){

  int i,m,k,l,tempa[100000],tempb[100000];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high))
    {

         if(arr[l]<=arr[m])
	 {
		 if(arr[l]<arr[m])
		 {    tempa[i]=arr[l];
			 tempb[i]=b[l];
             l++;
         }
		 else
			 if(arr[l]==arr[m])
			 {
				 if(b[l]<=b[m])
				 {tempb[i]=b[l];
					 tempa[i]=arr[l];
					 l++;
				 }
				 else
					 if(b[m]<b[l])
					 { tempb[i]=b[m];
						 tempa[i]=arr[m];
						 m++;
					 }
			 }
	 }
         else{
             tempa[i]=arr[m];
	     tempb[i]=b[m];
             m++;
         }
         i++;
    
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             tempa[i]=arr[k];
              tempb[i]=b[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             tempa[i]=arr[k];
             tempb[i]=b[k];
             i++;
         }
    }
       
    for(k=low;k<=high;k++){
         arr[k]=tempa[k];
          b[k]=tempb[k];
    }
}


int main()
{	int t;
	char s[100000];
	int i;
	scanf("%d",&t);
	while(t--)
	{ scanf("%s",s);
		int j=0,m=0,r=0;
		int a1=1,b1=1;
                 int i1=0;
		 int n;
		n=strlen(s);
		  a[0]=0;
	         b[0]=0;	  
		 for(i=0;i<n;i++)
		{

			if(s[i]=='J')
			j++;
		if(s[i]=='M')
                    m++;
		if(s[i]=='R')
			r++;
		  a[a1++]=m-r;
		    b[b1++]=m-j;
                      		
        }
		int t5,t6;
		 t5=a1;
		 t6=b1;
		 //for(i=0;i<t5;i++)
		//	 printf("a=%d b=%d\n",a[i],b[i]);
partition(a,0,t5-1);
/*printf("aftersort\n");
		 for(i=0;i<t5;i++)
			 printf("a=%d b=%d\n",a[i],b[i]);*/
	    int k,k1;
             k=a[0];
             k1=b[0];
         int count=1,flag=0;
         int count1=0;
             for(i=0;i<t5-1;i++)
               {
                 if(a[i]==a[i+1]&&b[i]==b[i+1])
                     {count++;}
		 else
		 
		 { // printf("count=%d\n",count);
			 count1=count1+((count*(count-1))/2);
		          count=1;
	       }
       }
                    
           count1=count1+(count*(count-1))/2;
           printf("%d\n",count1);
        }
return 0;
}
