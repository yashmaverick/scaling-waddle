#include<stdio.h>
#include<stdlib.h>
int root[100005];
int val[100005];
void serge(int a[][3],int low,int mid,int high,int c[][3],int par)
{
	int i=low,j=mid+1,k=0,x;
	while(i<=mid && j<=high)
	{
		if(a[i][par] < a[j][par])
		{
			for(x=0;x<3;x++)
				c[k][x] = a[i][x];
			k++;
			i++;
		}
		else {
			for(x=0;x<3;x++)
				c[k][x] = a[j][x];
			k++;
			j++;
		}
	}
	while(i<=mid) {
		for(x=0;x<3;x++)
			c[k][x] = a[i][x];
		i++;
		k++;
	}
	while(j<=high){
		for(x=0;x<3;x++)
			c[k][x] = a[j][x];
		k++;
		j++;
	}
}
void sergemort(int a[][3],int low,int high,int par)
{
	if(high<=low)
		return;
	int i=0,x;
	int c[high-low+1][3];
	int mid = (low+high)/2;
	sergemort(a,low,mid,par);
	sergemort(a,mid+1,high,par);
	serge(a,low,mid,high,c,par);
	for(i=low;i<=high;i++)
	{
		for(x=0;x<3;x++)
			a[i][x] = c[i-low][x];
	}
}
int serch(int i)
{
	if(root[i]==i)
		return i;
	else
		return serch(root[i]);
}
int icon(int x,int y)
{
	if(serch(x)==serch(y))
		return 1;
	else 
		return 0;
}
int uet(int a,int b) 
{
	int k;
	k=serch(b);
	root[k]=a;
	return 0;
}
int main()
{
	int n,q,x,y,test,i,A[100005][3],ed,sum=0,nod,ned;
	scanf("%d %d",&nod,&ed);
	for(i=0;i<=nod;i++)
		root[i]=i;
	for(i=0;i<ed;i++)
	{
		val[i]=1;
		scanf("%d",&A[i][0]);
		scanf("%d",&A[i][1]);
		scanf("%d",&A[i][2]);
	}
	if(ed<nod-1)
	{
		printf("-1\n");
		return 0;
	}
	sergemort(A,0,ed-1,2);
	ned=0;
	for(i=0;i<ed;i++)
	{
		x=A[i][0];
		y=A[i][1];
		if(icon(x,y)==0)
		{
			uet(x,y);
			ned++;
		}
		else
			val[i]=0;
	}
	for(i=0;i<ed;i++)
	{
		if(val[i]==1)
			sum+=A[i][2];
	}
	if(ned<nod-1)
		printf("-1\n");
	else
		printf("%d\n",sum);
	return 0;
}
