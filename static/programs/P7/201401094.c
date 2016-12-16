#include<stdio.h>
int comparator(const void *a,const void *b)
{
	return (*(int*)a-*(int*)b);
}
void print(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d:  %d\n",i,a[i]);
}
int main()
{
 int t,n,a[1000005],i,prev;
 scanf("%d",&t);
 while(t--)
 {
	 scanf("%d",&n);
	 for(i=0;i<n;i++)
	 {
		
		 scanf("%d",&a[i]);
	 }
	 qsort(a,n,sizeof(int),comparator);
//	 print(a,n);
	 prev=a[0];
	 a[n++]=100000007;
	long long int cnt=1,sum=0;
	 for(i=1;i<n;i++)
	 {
		 if(prev!=a[i])
		 {
			 prev=a[i];
			    sum=sum+((cnt*(cnt-1))/2);
			   cnt=1;
			 }
			 else
				 cnt++;
		 }
	 printf("%lld\n",sum);
	 

//	 print(a,n);
	
 }
 return 0;
}
