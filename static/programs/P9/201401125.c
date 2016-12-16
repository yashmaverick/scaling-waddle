#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef long long int lld;

void merge(int arr[][2], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1][2], R[n2][2];
 
    for(i = 0; i < n1; i++)
    {
        	L[i][0] = arr[l + i][0];
        	L[i][1] = arr[l+i][1];
    }

    for(j = 0; j < n2; j++)
    {
       R[j][0] = arr[m + 1+ j][0];
       R[j][1] = arr[m + 1 + j][1];
   	}
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i][0] <= R[j][0])
        {
            arr[k][0] = L[i][0];
            arr[k][1] = L[i][1];
            i++;
        }
        else
        {
            arr[k][0] = R[j][0];
            arr[k][1] = R[j][1];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k][0] = L[i][0];
        arr[k][1] = L[i][1];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k][0] = R[j][0];
        arr[k][1] = R[j][1];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[][2], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
 
int main(){
	int i,j,n,mod;
	scanf("%d %d",&n,&mod);
	int arr[n][2],m;
	int *list[n],item[n];
	for(i=0;i<n;i++){
		scanf("%d",&m);
		item[i]=m;
		list[i]=(int*)malloc(sizeof(int)*m);
		arr[i][0]=0;
		for(j=0;j<m;j++){
			scanf("%d",&list[i][j]);
			arr[i][0]=(arr[i][0]+list[i][j])%mod;
		}
		arr[i][1]=i;
	}
	mergeSort(arr,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i][0]);
		for(j=0;j<item[arr[i][1]];j++)
			printf("%d\n",list[arr[i][1]][j]);
		printf("\n");
	}
	return 0;
}





