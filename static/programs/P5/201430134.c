#include<stdio.h>
void qs(int a[],int i,int j);
int partition(int a[],int i,int j);
int main()
{
	int v[1010];
	int flag;
	int t,n,k,i,j,m;
	char c;
	char word[1010];
	scanf("%d",&t);
	while(t>0)
	{
		flag=0;
		scanf("%d %d",&n,&k);
		scanf("%c",&c);
	for(i=0;i<n;i++)
	{
		scanf("%s %d",word,&v[i]);
		scanf("%c",&c);
	}
	qs(v,0,n-1);
/*	for(i=0;i<n;i++)
	{
		printf("%d",v[i]);
	}
	printf("\n");*/
	for(i=0;i<n-2;i++)
	{
		m=i+1;
		//printf("m=%d\n",m);
		for(j=n-1;j>m;j--)
		{
			//printf("j=%d\n",j);
			if((v[i]+v[m]+v[j])==k)
			{
				flag=1;break;
				//printf("flag=%d\n",flag);
			}
			else if((v[i]+v[m]+v[j])<k)
			{
				m++;j++;
				//printf("m=%d j=%d\n",m,j);
			}
			else
			{;}
		}
		if(flag==1)
		{
			printf("YES\n");
			break;
		}
		else
		{
			j=n-1;
		}
	}
	if(flag==0)
	{
		printf("NO\n");
	}
	t--;
	}
	return 0;
}
void qs(int a[],int i,int j)
{
	int z;
	if(i>=j)
	{
		return;
	}
	else
	{
		//printf("%d",i);
		//mid=(i+j)/2;
		z=partition(a,i,j);
		qs(a,i,z-1);
		qs(a,z+1,j);
	}
}
int partition(int a[],int i,int j)
{
	int pivot,s,e,temp,p;
	//printf("%d\n",i);
	pivot=a[i];
	e=j;
	for(p=i+1;p<=e;p++)
	{
		//printf("i=%d e=%d\n",i,e);
		if(a[p]>=pivot)
		{
			temp=a[e];
			a[e]=a[p];
			a[p]=temp;
			e--;
			p--;
		}
	}
	temp=a[e];
	a[e]=a[i];
	a[i]=temp;
	return e;
}








