#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[100001];
int z[100001];
/*int merge(int array[], int start, int mid, int end) {
  int * left_array=(int *)malloc(sizeof(int));
  int * right_array=(int *)malloc(sizeof(int));
  int i, j, k;
  int inversions=0;
  for(i=0; i<mid-start+1; i++) {
    left_array[i]=array[start+i];
  }
  for(j=0; j<end-mid; j++) {
    right_array[j]=array[mid+1+j];
  }
  i=0;
  j=0;
  for(k=start; k<=end; k++) {
    if(i<mid-start+1 && j<end-mid && left_array[i]>right_array[j]) {
        inversions=inversions+mid-start-i+1;      
    }
    if((i<mid-start+1 && j<end-mid && left_array[i]<=right_array[j]) || j>=end-mid) {
      array[k]=left_array[i];
      i++;
    } else if((i<mid-start+1 && j<end-mid && left_array[i]>right_array[j]) || i>=mid-start+1) {
      array[k]=right_array[j];
      j++;
    }
  }
  return inversions;
}

int mergesort(int array[], int start, int end) {
  int mid;
  int i=0;
  if(start<end) {
    mid=(start+end)/2;
    i=i+mergesort(array, start, mid);
    i=i+mergesort(array, mid+1, end);
    i=i+merge(array, start, mid, end);
  }
  return i;
}*/
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		
		int sum=0,count=1,j=0,i;
		scanf("%s",a);
		if(a[0]=='J')
			z[0]=1234;
		else if(a[0]=='M')
			z[0]=1;
		else
			z[0]=-1235;
		for(i=1;i<strlen(a);i++)
		{
			if(a[i]=='J')
			{
				z[i]=z[i-1]+1234;
				
			}
			else if(a[i]=='M')
			{
				z[i]=z[i-1]+1;
			}
			else
			{
				z[i]=z[i-1]-1235;
			}
			j++;
		}
		//mergesort(z,0,j);
		for(i=0;i<j+1;i++)
		{
			if(z[i]==0)
				count++;
			/*else if(count>1)
			{
				sum=sum+((count)*(count-1))/2;
				count=1;
			}
			if(z[i]>0)
				break;*/
		}
		sum=sum+((count)*(count-1))/2;
		printf("%d\n",sum);
	}
	return 0;
}