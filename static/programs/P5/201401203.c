#include<stdio.h>
int a[1000],b[1000];
void divide(int beg,int end)
{
	int mid,i,j,k;
	if(beg==end)
		return;
	else
	{
		mid=(beg+end)/2;
		divide(beg,mid);
		divide(mid+1,end);
		//merge
		i=beg;j=mid+1;k=0;
		while(i<=mid&&j<=end)
			if(a[i]>a[j])
				b[k++]=a[j++];
			else
				b[k++]=a[i++];
		while(i<=mid&&j>end)
			b[k++]=a[i++];
		while(j<=end&&i>mid)
			b[k++]=a[j++];
		for(i=beg,j=0;i<=end&&j<k;i++)
			a[i]=b[j++];
	}
}

/*int search(int x)
{
	int beg,mid,end;
	beg=0;
	end=n-1;
	while(beg<end)
	{
		mid=(beg+end)/2;
		if(a[mid]==x)
			return mid;
		else if(a[mid]>x)
			end=mid-1;
		else 
			beg=mid+1;
	}
	if(a[(beg+end)/2]==x)
		return mid;
	return -1;
}
*/

int main()
{
	int i,j,p,t,n,flag,k,sum;
	char z[1000001];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&p);
		for(i=0;i<n;i++)
			scanf("%s%d",z,&a[i]);
		divide(0,n-1);
		flag=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1,k=n-1;j<k;)
			{
				sum=a[i]+a[j]+a[k];
				if(sum>p)
					k--;
				else if(sum<p)
					j++;
				else if(p==sum)
				{
					printf("YES\n");
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		if(flag!=1)
			printf("NO\n");
	}
	return 0;
}
