#include<stdio.h>
#define gcu getchar_unlocked
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
 int t,n,k,a[10003],c,s,i,j;
 scanf("%d",&t);
 while(t--)
 {
	 int flag=0;
	 scanf("%d %d",&n,&s);
	 for(i=0;i<n;i++)
	 {
		 while(c=gcu()!=' ');
		 scanf("%d",&a[i]);
	 }
	 qsort(a,n,sizeof(int),comparator);
//	 print(a,n);
	 for(i=0;i<n-1;i++)
	 {
      int key=s-a[i];
			j=i+1;k=n-1;
			while(j!=k)
			{
         if(a[j]+a[k]>key)
					 k--;
				 else if(a[j]+a[k]<key)
					 j++;
				 else
				 {flag=1;
					 break;
				 }
			}
	 }
	 if(flag==1)
  printf("YES\n");
	 else
		 printf("NO\n");
 }
 return 0;
}
