#include<stdio.h>
#include<string.h>
void merge(long int A[],long int B[],long int c[],int m,int n)
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
void mergesort(long int a[],int n)
{	int i;
	long int left[n];
//	printf("1\n");
	long int right[n];
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
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{		char s[100000];
			long int b[100001]={0};
			    int i,count=0,sum=0,flag=0;
		scanf(" %s",s);
		int len=strlen(s);
			for(i=1;i<=len;i++)
			{		
				if(s[i-1]=='J')
					b[i]=b[i-1]+-100000-2;
				if(s[i-1]=='M')
					b[i]=b[i-1]+1;
				if(s[i-1]=='R')
					b[i]=b[i-1]+100000+1;
			}
			//	for(i=0;i<=strlen(s);i++)
			//	printf("%ld ",b[i]);
			mergesort(b,len+1);
//			for(i=0;i<=strlen(s);i++)
//				printf("%ld\n",b[i]);
			for(i=1;i<=len;i++)
				{
					if(b[i]==b[i-1])
					{	count++;
						if(i==len)
							flag=1;
					}
					//printf("%ld ",count);
					if(b[i]!=b[i-1]||flag==1)
					{//	printf("\n%ld",i);
						if(count+1>=2)
						sum+=((count+1)*(count))/2;
						count=0;
				//		printf(" %ld ",sum);
					}
				
				}

			printf("%d\n",sum);
		}
		return 0;
}
				
