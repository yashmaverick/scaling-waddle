
/*
_____________________________________________
PROBLEM STATEMENT: 
TEST CASES:
COMMENTS:

		SOLVED BY - YOGESH SHARMA
______________________________________________ 
*/
#include <stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
//global
int queue[10001];
int start,end,minindex;
void insert(int element){end++;queue[end]=element;}
void delete(int element){start++;}
void min_find(){ int i=start; minindex=i; for(i=start; i<=end; i++) if(queue[i]<=queue[minindex]) minindex=i;}
int is_sorted(int arr[],int n) {int i; for(i=2;i<=n;i++) if(arr[i]<arr[i-1]) return 0;  return 1;}
void init(){int i; for(i=0;i<=end;i++) queue[i]=0;}

int main()
{ 
    int t,n,k,i;
    int arr[10001];
    
    scanf("%d",&t);
    while(t--)
    {
        start=1;end=0;
        scanf("%d %d",&n,&k);
        for(i=1;i<=n;i++) scanf("%d",&arr[i]);
        if(is_sorted(arr,n)) {for(i=1;i<=n-k+1;i++) if(i==n-k+1) printf("%d",arr[i]); else printf("%d ",arr[i]); printf("\n"); continue;}
        for(i=1;i<=k;i++) insert(arr[i]);
        min_find();
        for(i=1;i<=n-k+1;i++)
        {
            if(i==n-k+1) {printf("%d",arr[minindex]);break;}
            else printf("%d ",arr[minindex]);
            delete(arr[i]);
            insert(arr[i+k]);
            if(arr[minindex]>=arr[i+k]) minindex=i+k;
            if(minindex<start) min_find();
        }
        printf("\n");
        init();
    }
    return 0;
}
