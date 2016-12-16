#include<stdio.h>
int partiton(int a[],int f,int l)
{int pivot,pindex,i,t;
	pivot=a[l];
	pindex=f;
	for(i=f;i<l;i++)
	{
		if(a[i]<=pivot)
		{//	swap(a[i],a[pindex]);
			t=a[i];
			a[i]=a[pindex];
			a[pindex]=t;
			pindex++;
		}
	}
	//	swap(a[l],a[pindex]);
	t=a[l];
	a[l]=a[pindex];
	a[pindex]=t;
	return pindex;
}
void quicksort(int a[],int f,int l)
{int p;

	if(f>=l)
		return;
	else
	{
		p=partiton(a,f,l);
		quicksort(a,f,p-1);
		quicksort(a,p+1,l);
	}

}
int main()
{  int t,j1,n,k,i,a[10000],i1,j,i2,a1,a2,a3,sum,flag;
	char s[10000];
	scanf("%d",&t);
	for(j1=0;j1<t;j1++)
	{scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{	scanf("%s",s); 
			scanf("%d",&a[i]);
		}
		sum=0;
		flag=0;
		quicksort(a,0,n-1);
		for(i1=0;i1<n-1;i1++)
		{j=n-1;
			i2=i1+1;
			while(i2!=j)
			{    
				a1=a[i1];
				a2=a[i2];
				a3=a[j];
				sum=a1+a2+a3;
				if(sum==k)
				{ flag=1;
					break;}
				if(sum>k)
				{     j--;  
					a3=a[j]; 
				} 
				if(sum<k)
				{    	  i2++;
					a3=a[i2];
				}
				flag=0;
			}
			if(flag==1)
				break;
		}
		if(flag==1)  
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
