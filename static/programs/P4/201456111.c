#include<stdio.h>
#include<string.h>
void mergesort(int arr[],int l,int r);
void merge(int arr[],int l,int m,int r);
void mergesort(int arr[100000],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;

		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}
void merge(int arr[100000],int l,int m,int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int L[100000],R[100000];
	for(i=0;i<n1;i++)
		L[i]=arr[l+i];
	for(j=0;j<n2;j++)
		R[j]=arr[m+1+j];
	i=0;
	j=0;
	k=l;
	while((i<n1)&&(j<n2))
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}

}

int main()
{
	int t=0,n,k,l,m,p,q,arr_size,v,count,ans=0,zero;
	char a[100000];
	int b[100000];
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		zero=0;
		count=1;
		ans=0;
		for(p=0;p<100000;p++)
		{
			b[p]=0;
		}
		//scanf("%d",&n);
		scanf("%s",a);
		n=strlen(a);
		arr_size=n;
			for(l=0;l<n;l++)
			{

			if(a[l]=='M')
			{
		//printf("entered the if\n");
		b[l]=1000;
		}
		if(a[l]=='R')
		{
		b[l]=-999;
		}
		if(a[l]=='J')
		{
		b[l]=-1;
		}
		}
//printf("n value is %d\n",n);
		for(m=0;m<n;m++)
		{
		//printf("the valuse in a is %c\n",a[m]);
		//printf("b[%d] has %d\n",m,b[m]);
		}
		for(q=1;q<n;q++)
		{
		b[q]=b[q]+b[q-1];
		//printf("b[%d] has %d\n",q,b[q]);
		}
		//printf("befor merge sort\n");
		/*for(v=0;v<n;v++)
		{
		printf("b[%d] has %d\n",v,b[v]);
		}*/
		mergesort(b,0,arr_size-1);
		//printf("after merge sort\n");
		//printf("a[0] is %d\n",b[0]);
		for(l=1;l<n;l++)
		{
		//printf("b[%d] has %d\n",l,b[l]);
			if(b[l]==b[l-1])
		{
		count++;

		}
		if(b[l]!=b[l-1])
		{
		ans=ans+((count)*(count-1))/2;
		count=1;
		}
		if(b[l]==0)
		zero++;}
		ans=ans+(count)*(count-1)/2;
		if(b[0]==0)
			zero++;
		//printf("sero is %d\n",zero);
		ans=ans+zero;
		printf("%d\n",ans);
//	printf("%s\n",a);
	}
	return 0;
}
