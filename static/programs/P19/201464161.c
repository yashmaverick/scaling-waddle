#include<stdio.h>
#include<stdlib.h>
/*void mergesort(long long int a[],long long int s,long long int e,long long int tmp[])
  {
  if(s==e)
  return;
  long long int mid=(s+e)/2;
  mergesort(a,s,(s+e)/2,tmp);
  mergesort(a,((s+e)/2)+1,e,tmp);
  long long int p1,p2,p;
  p1=s,p2=mid+1;p=0;
  while(p1<=mid||p2<=e){
  if(p1>mid)
  tmp[p++]=a[p2++];
  else if(p2>e)
  tmp[p++]=a[p1++];
  else{
  if(a[p1]<a[p2])
  tmp[p++]=a[p1++];
  else
  tmp[p++]=a[p2++];
  }
  }
  long long int i;
  for(i=0;i<p;i++)
  a[s+i]=tmp[i];
  }*/
int cmp(const void *a,const void *b)
{
	return (*(long long int*)a -*(long long int*)b);
}
void search(long long int a[],long long int b[],int n,int j)
{
	int i;
	int flag=0;
	for(i=0;i<n;i++)
	{
		int num=a[i];
		int f=0,l=j-1;
		int m=(f+l)/2;
		while(f<=l)
		{
			if(num<b[m])
				l=m-1;
			if(num==b[m])
			{
				printf("NO\n");
				flag=1;
				break;
			}
			if(num>b[m])
				f=m+1;
			m=(f+l)/2;
		}
		if(flag==1)
			break;
	}
	if(flag==0)
		printf("YES\n");
}
int main()
{
	int n;
	scanf("%d",&n);
	int i,j,t=0;
	long long int no,num;
	while(t!=n)
	{
		scanf("%lld",&no);
		if(no!=0)
		{
			int k=0;
			long long int a[no],b[9*no];
			for(j=0;j<no;j++)
			{
				scanf("%lld",&num);
				a[j]=num;
				while(1)
				{
					num=num/10;
					if(num==0)
						break;
					b[k]=num;
					k++;
					//		printf("%d->",k);
				}
				//	printf("%d:",k);
			}
			//printf("%d %d ",no,k);
			qsort(a,no,sizeof(long long int),cmp);
			int flag=0;
			i=0;j=1;
			//for(i=0;i<no;i++)
			//	printf("%lld ",a[i]);
			//	printf("\n");
			//	for(i=0;i<k;i++)
			//		printf("%lld ",b[i]);
			//	printf("\n%d\n",k);
			i=0;
			j=1;
			while(j!=no)
			{
				if(a[i]==a[j])
				{
					printf("NO\n");
					flag=1;
					break;
				}
				i++;
				j++;
			}
			qsort(b,k,sizeof(long long int),cmp);
			if(flag==0)
				search(a,b,no,k);
		}
		t++;
	}
	return 0;
}

