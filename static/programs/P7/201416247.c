#include<stdio.h>
long long int a[1000100],b[1000100]={0};
/*void quicksort(long long int first,long long int last){
  long long int pivot,j,temp,i;

  if(first<last){
  pivot=first;
  i=first;
  j=last;

  while(i<j){
  while(a[i]<=a[pivot]&&i<last)
  i++;
  while(a[j]>a[pivot])
  j--;
  if(i<j){
  temp=a[i];
  a[i]=a[j];
  a[j]=temp;
  }
  }

  temp=a[pivot];
  a[pivot]=a[j];
  a[j]=temp;
  quicksort(first,j-1);
  quicksort(j+1,last);

  }
  }*/
void print(long long int *A,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%lld\n",A[i]);
	printf("\n");

}
int main()
{
	long long int i,j,p,k,m,t,d,n,c;
	int min;
	scanf("%lld",&m);
	for(t=0;t<m;t++)
	{
		p=0;
		scanf("%lld",&n);
		scanf("%d",&min);
		a[0]=min;
		for(i=1;i<n;i++){
			scanf("%lld",&a[i]);
			if(a[i]<min)
				min=a[i];
		}
		for(i=0;i<1000100;i++)
			b[i]=0;
//		print(a,n);
//		printf("%d\n",min);
//		quicksort(0,n-1);
		for(i=0;i<n;i++){
			a[i]=a[i]-min;
			d=a[i];
			b[d]++;
		}
//		print(b,1000100);
		for(k=0;k<1000001;k++){
			if(b[k]>0)
				p=p+((b[k]*(b[k]-1))/2);}
		printf("%lld\n",p);
	}
	return 0;
}
