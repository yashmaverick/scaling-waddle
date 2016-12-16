#include<stdio.h>
int a[100005],b,c;

int binary(int key,int low,int high)
{       int m=(high+low)/2;
	if(low<high)
	{       if(key>a[m]&&key<a[m+1])
		return m;
		if(key>a[m]&&key>a[m+1])
			binary(key,m+1,high);
		else if(key<a[m])
			binary(key,low,m-1);
	}

	else if(low==high&&a[low]<key)
		return low;
	else if(low>=high)
		return -1;

}

int partition(int key,int low,int high,int j,int l)
{       int k;
	j++;
	if(l==low)
	{if(b<=j)
		{//printf("y-%d-%d ",key,j);
			if((b==j&&key<c)||(b<j))
			{b=j;
				c=key;      
			}
		}return;
	}
	if(low>high)
		return;
	k=binary(key,low,high);
	//printf("o-%d-%d-%d ",k,a[k],key);
	if(k==-1)
	{       
		partition(a[l-1],low,l-2,j,l-1);
	}
	else                         
	{    partition(a[high],k+1,high-1,j,high);
		partition(a[k],low,k-1,j,k);
	}
	return;
}

int main()
{	int t,i,m,n,z,key,j;
	scanf("%d",&t);
	while(t--)
	{	scanf("%d",&n);
		i=0;
		while(n--)
			scanf("%d",&a[i++]);        
		i--;
		key=a[i];b=-1;c=i+5;

		partition(key,0,i-1,-1,i);        
		printf("%d %d\n",c,b);
	}
	return 0;
}
