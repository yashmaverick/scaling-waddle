#include<stdio.h>
//#include<string.h>
void merge(int a[],int low,int mid,int high)
{
	int i=low,k=0,j=mid+1,t[1000009];
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
			t[k++]=a[i++];
		else if(a[j]<a[i])
			t[k++]=a[j++];
		else
		{
			t[k++]=a[i++];
			t[k++]=a[j++];
		}
	}
	while(i<=mid)
	{
		t[k++]=a[i++];
	}
	while(j<=high)
	{
		t[k++]=a[j++];
	}
	for(k=0,i=low;i<=high;i++,k++)
	{
		a[i]=t[k];
	}
}
void mergesort(int a[],int low,int high)
{
	if(low>high)
		return;

	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
int main()
{
	int w,n,i;

	scanf("%d",&w);
	while(w--)
	{
		int n,i,r=0;
		int q[100004];	
		char s[100004];
		scanf("%s",s);
	
		n=strlen(s);
		for(i=0;i<n;i++)
		{ 
			if(s[i]=='J')
				q[i]=-1;
			if(s[i]=='M')
				q[i]=-99;
			if(s[i]=='R')
				q[i]=100;
	if(i!=0)
		q[i]+=q[i-1];
		if(q[i]==0)
			r++;
		//printf("%d",q[i]);
	}



		mergesort(q,0,n-1);
		//printf("%d",q[i]);
	int k=0,v;   
	int c=0;
		for(i=0;i<n-1;i++)
		{
			c=1;
	                //k=0;
	
			while(q[i]==q[i+1])
			{
				c++;
				i++;

			}

			k+=(c*(c-1))/2;
		}
	//	k=k+(c*(c-1))/2;
		v=r+k;
		printf("%d\n",v);
	}
	return 0;
}
