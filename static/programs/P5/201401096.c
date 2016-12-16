#include<stdio.h>
void merge(int l,int r, int A[])
{
     int mid=(l+r)/2;
     int C[10000];
     int i, j,k=0;
    for(i=l,j=mid+1;i<=mid&&j<=r;)
        if(A[i]>A[j])
        {
            C[k++]=A[j++];
        }
        else if (A[j]>A[i])
        {
            C[k++]=A[i++];

        }
        else
        {
            C[k++]=A[i++];
        }
    while(j>r&&i<=mid){C[k++]=A[i++];}
    while(i>mid&&j<=r){C[k++]=A[j++];}

    int size =k-1;
    for(i=l,k=0;k<=size;++i,++k)
        A[i]=C[k];    
        

}

void  mergesort( int A[], int l,  int r)
{
    if(l==r)
        return; 
    int mid=(l+r)/2;
    mergesort(A,l,mid);

    mergesort(A,mid+1,r);
    merge (l,r,A);



}
void compute();
int a[100000];
int n,k;

int main()
{
	int t,i;
	char c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			while(1)
			{
				scanf("%c",&c);
				if(c==' ')
					break;
			}
			scanf("%d",&a[i]);
		}
		compute();
	}
	return 0;
}
void compute()
{
	int i,end,beg;
	mergesort(a,0,n-1);
	for(i=0;i<n-2;i++)
	{
		beg=i+1;
		end=n-1;
		while(beg<end)
		{
			if(a[i]+a[beg]+a[end]==k)
			{
				printf("YES\n");
				return;
			}
			else if(a[i]+a[beg]+a[end]>k)
				end--;
			else
				beg++;
		}
	}
	printf("NO\n");
	return;
}
