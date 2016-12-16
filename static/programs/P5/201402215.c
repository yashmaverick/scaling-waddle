#include<stdio.h>
#include<string.h>
#include<math.h>
int merge(int A[],int B[],int c[],int m,int n)
{	int i=0,j=0,k=0;
	while(i<m&&j<n)
	{	if(A[i]>B[j])
		{	c[k]=B[j];
			j++;k++;}
			else if(A[i]==B[j])
			{	c[k]=A[i];k++;
				c[k]=A[i];k++;
				i++;
				j++;}
				else
				{	c[k]=A[i];
					i++;
					k++;}
	}
	if(j<n)
	{	while(j<n)
		{	c[k]=B[j];
			k++;
			j++;
		}
	}
	if(i<m)
	{	while(i<m)
		{
			c[k]=A[i];
			k++;
			i++;
		}
	} 

}
void mergesort(int a[],int n)
{	int i;
	int left[n];
	int right[n];
	if(n<=1)
	{	return;}
	for(i=0;i<n/2;i++){
		left[i]=a[i];
	}
	for(i=n/2;i<n;i++)
	{	right[i-n/2]=a[i];}
	mergesort(left,n/2);
	mergesort(right,(n-n/2));
	merge(left,right,a,n/2,(n-n/2)); 
}
int main()
{	int t;
	scanf("%d",&t);
		while(t--)
		{
			int n,k;
			scanf("%d %d\n",&n,&k);
			int i,j,len,b[100000],flag=0;
			char a[100000];
			for(i=0;i<n;i++)
			{	scanf(" %s",a);
		//		printf("%s",a);
			//	printf("1\n");
			scanf("%d",&b[i]);
		//	printf("%d ",b[i]);
			}
		//	printf("23\n");
			mergesort(b,n);
		//	for(i=0;i<n;i++)
		//		printf("%d ",b[i]);
			for(i=0;i<n-2;i++)
			{ int l=i+1,r=n-1;
				while(r>l)
				{//	printf("222\n");
					if(b[i]+b[l]+b[r]==k)
						flag=1;
					if(b[i]+b[l]+b[r]>k)
						r--;
					if(b[i]+b[l]+b[r]<k)
						l++;
					if(flag==1)
						break;
				}
				if(flag==1)
					break;
			}
		//	printf("1\n");
			if(flag==1)
				printf("YES\n");
			else
				printf("NO\n");
		
		}
	return 0;
}

