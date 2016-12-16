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

void mergesort(int arr[],int start,int end,int wrr[]);
void merge(int arr[],int start1,int end1,int start2,int end2,int wrr[]);
int main()
{
    //declaration
    int *arr[1000];
    int wrr[1000],irr[1000];

    int n,mod,i,j,m,row_weight=0,k=0;
    //end declaration

    scanf("%d %d",&n,&mod);
    if(n==0 || n>1000)while(1);
    //arr=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        if(m==0)while(1);
        arr[i]=(int *)malloc((m+1)*sizeof(int ));
        for(j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
            row_weight=(row_weight + arr[i][j])%mod;
        }
        arr[i][j]=-1;
        wrr[i]=row_weight;
        irr[i]=i;
        row_weight=0;
    }


//    mergesort(irr,0,n-1,wrr);
    for(i=0; i<n;i++)
    {
        int mn = i;
        for(j=i+1; j<n;j++)
        {
          if(wrr[irr[j]] < wrr[irr[mn]]) mn = j;
        }
        if(mn!=i)
        {
           irr[i] += irr[mn]; irr[mn] = irr[i] - irr[mn]; irr[i] -= irr[mn];
        }
    }

    for(i=0;i<n;i++)
    {
        j=0;
        printf("%d\n",wrr[irr[i]]);
        while(arr[irr[i]][j]!=-1)
            printf("%d\n",arr[irr[i]][j++]);
        printf("\n");
    }
return 0;
}


void mergesort(int arr[],int start,int end,int wrr[])
{
    if(end<=start)
        return ;

    int mid=(start+end)/2;

    mergesort(arr,0,mid,wrr);
    mergesort(arr,mid+1,end,wrr);

    merge(arr,0,mid,mid+1,end,wrr);
}


void merge(int arr[],int start1,int end1,int start2,int end2,int wrr[])
{
    int  i=start1,k=start2;
    int j=end1,l=end2;
    int res=0,q=0;
    int fin[end2-start1+1];

    while(i<=end1 && k<=end2)
        if(wrr[arr[i]]<wrr[arr[l]])
            fin[res++]=arr[i++];
        else
            fin[res++]=arr[k++];
    while(i<=end1)
        fin[res++]=arr[i++];
    while(k<=end2)
        fin[res++]=arr[l++];

    int z=0;
    for(q=start1;q<=end2;q++)
        arr[q]=fin[z++];
}

