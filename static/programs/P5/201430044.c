#include<stdio.h>
#include<string.h>
#include<math.h>
#define purna 100000
void search(int a[],int k,int first,int last)
{
	if(first<=last)
	{
		int ref=pivot(a,first,last);
		//      if(ref>k-1)
		search(a,k,first,ref-1);
		//      else if(ref<k-1)
		search(a,k,ref+1,last);
		//      else 
		//              printf("%d\n",a[k-1]);
	}
	return;
}
int pivot(int a[],int first,int last)
{
	int L,index,fix,i=first;
	index=first;
	fix=a[last];
		while(i!=last)
		{
			if(a[i]<=fix)
			{
				L=a[i];
				a[i]=a[index];
				a[index]=L;
				index++;
			}
			i++;
		}
	L=a[index];
	a[index]=a[last];
	a[last]=L;
	return index;
}

int main()
{
	int t;
	scanf("%d",&t);

	char z[purna];
	int i,count,k,x,a[purna],j,sum,f,l,mid,flag;
	while(t--)
	{
		flag=0;
		scanf("%d%d",&count,&k);
		for(i=0;i<count;i++)
		{
			scanf("%s",z);
			scanf("%d",&a[i]);
		}
		search (a,1,0,count-1);
		for(i=0;i<count-2;i++)
		{
			for(j=i+1;j<count-1;j++)
			{
				sum=k-a[i]-a[j];
				f=j+1;
				l=count-1;
				while(f<=l)
				{
					mid=(f+l)/2;
					if(sum==a[mid])
					{
						flag=1;
						break;
					}
					else if(sum>a[mid])
					{
						f=mid+1;
					}
					else
					{
						l=mid-1;
					}
				}
				if(flag==1)
					break;
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			printf("YES\n");
		else if(flag==0)
			printf("NO\n");
	}
	return 0;
}
