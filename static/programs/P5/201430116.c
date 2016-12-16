#include<stdio.h>
#include<stdlib.h>
int binarySearch(int a[], int l, int r, int x)
{
  while (l <= r)
  {
    int m = l + (r-l)/2;
 
    if (a[m] == x) return m;  
 
    if (a[m] < x) l = m + 1; 
    else r = m - 1; 
 }
 return 0;
}
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main(){
    int tc,s;
    scanf("%d",&tc);
    for(s=0;s<tc;s++){
	int n,sum,i,state,j;
	char c;
	scanf("%d %d",&n,&sum);
	int a[n+1];
    for(i=0;i<n;i++){
        while((c=getchar())!=' ');
        scanf("%d",&a[i]);
    }
    qsort(a, n, sizeof(int), cmpfunc);
    state=0;
    for(i=0;i<n;i++){
        for(j=i+1;j<n-1;j++){
            state=binarySearch(a,j+1,n-1,sum-(a[i]+a[j]));
            if(state)
                break;
        }
        if(state)
            break;
    }
    if(state)
        printf("YES\n");
    else
        printf("NO\n");
    }
	return 0;
}