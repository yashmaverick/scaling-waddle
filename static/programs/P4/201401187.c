#include<stdio.h>
int s[100002],temp[100002];
void merge();
/*int partition(int a[],int l,int h)
  {
  int x,i,temp,j;
  x=a[h];
  i=l-1;
  for(j=l;j<=h-1;j++)
  if(a[j]<=x)
  {
  i++;
  temp=a[i];
  a[i]=a[j];
  a[j]=temp;
  }
  temp=a[i+1];
  a[i+1]=a[h];
  a[h]=temp;
  return (i+1);
  }
  void sort(int a[],int l,int h)
  {
  if(l<h)
  {
  int x=partition(a,l,h);
  sort(a,l,x-1);
  sort(a,x+1,h);
  }
  }*/			
void partition(int arr[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		partition(arr,low,mid);
		partition(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}
void merge(int arr[],int low,int mid,int high){

	int i,m,k,l;
	l=low;
	i=low;
	m=mid+1;
	while((l<=mid)&&(m<=high))
	{
		if(arr[l]<=arr[m]){
			temp[i]=arr[l];
			l++;
		}
		else{
			temp[i]=arr[m];
			m++;
		}
		i++;
	}
	if(l>mid)
	{
		for(k=m;k<=high;k++)
		{
			temp[i]=arr[k];
			i++;
		}
	}
	else
	{
		for(k=l;k<=mid;k++)
		{
			temp[i]=arr[k];
			i++;
		}
	}

	for(k=low;k<=high;k++)
	{
		arr[k]=temp[k];
	}
}
int main()
{	
	int t,i,j,n,cnt,x;
	char a[100002];
	scanf("%d",&t);
	while(t--)
	{	
		int p=-100002;//the values are taken in such a way that that they their sum is 0
		int q=1;
		int r=100001;
		getchar();	//to remove /n
		scanf("%s",a);
		cnt=0;
		if(a[0]=='J')
			s[0]=p;
		else if(a[0]=='M')
			s[0]=q;
		else if(a[0]=='R')
			s[0]=r;
		for(i=1;a[i]!='\0';i++)
		{
			if(a[i]=='J')
				s[i]=s[i-1]+p;
			else if(a[i]=='M')
				s[i]=s[i-1]+q;
			else if(a[i]=='R')
				s[i]=s[i-1]+r;
		}
		n=i;
		partition(s,0,n-1);//sorts the cumulative array using quick sort
//		for(i=0;i<n;i++)
//			printf("%d ",s[i]);
//		printf("\n");
		for(i=0;i<n;i++)//finds the no of similar numbers exist s betweem two similar patterns there exists (n+1)c2 possible ways 
		{
			j=i;
			while(s[j]==s[j+1]&&j!=n-1)
				j++;
			x=j-i;
			cnt+=((x+1)*(x))/2;
			if(s[j]==0)
				cnt+=j-i+1;
			i=j;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
