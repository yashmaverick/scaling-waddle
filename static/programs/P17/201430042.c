#include<stdio.h>
int a[10000],b[10000];
int n,x,y,j;
int find();
int search();
int main()
{
	int ind,index,t;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
		if(a[0]==b[i])
			index=i;
	}
	ind=index;
	scanf("%d",&t);
	while(t--)
	{
		j=0;
		scanf("%d%d",&x,&y);
		if(x==y)
			printf("%d\n",x);
		else
		{	index=find(0,index);
			printf("%d\n",b[index]);
		}
		index=ind;
	}
	return 0;
}
int find(int start,int index)
{
	//printf("root=%d\n",b[index]);
	int flag=0,i;
	int end;
	if(x==b[index] || y==b[index])
		return index;
	for(i=start;i<index;i++)
		if(b[i]==x || b[i]==y)
		       flag++;
	if(flag==1)
		return index;
	else if(flag==0) // right side
	{
		end=index;
		index=search(index+1,n);	
		find(end+1,index);
	}
	else if(flag==2) // left side
	{
		index=search(start,index-1);
		find(start,index);
	}
	//find(index);
	
}
int search(int l,int m)
{
	//printf("l=%d m=%d\n",b[l],b[m]);
	int i;
	if(l!=m)
		while(1)
		{
			j++;
			//printf("a[j]=%d\n",a[j]);
			for(i=l;i<=m;i++)
			if(a[j]==b[i])
				return i;
		}
	else
		return l;
	
}
