#include <stdio.h>
int id[100000];
int size[100000];
typedef struct kr{
	int u,v;
	int w;
}kr;
void qusort(int a[],int b[],int first,int last);

//Initializing id, size
void init(int n)
{
	int i;
	for(i=0;i<=n;i++)
		id[i]=i;
	for(i=0;i<=n;i++)
		size[i]=1;
}
int root(int i)
{
	while(i!=id[i])
	{   id[i]=id[id[i]];
		i=id[i];
	}
	return i;
}
int find(int p,int q)
{
	if(root(p)==root(q))
		return 1;
	else
		return 0;
}
void unionx(int p,int q)
{
	int i=root(p);
	int j=root(q);
	if(size[i]<size[j])
	{
		id[i]=j;
		size[j]+=size[i];
	}
	else
	{
		id[j]=i;
		size[i]+=size[j];
	}

}
int main()
{
	kr arr[100000];
	int weight[100000];
	int index[100000];
	int n,m;
	int x,y,wt;
	scanf("%d%d",&n,&m);
	init(n);
	int t=m;
	int i=0;
	while(t--)
	{
		scanf("%d%d%d",&x,&y,&wt);
		arr[i].u=x;
		arr[i].v=y;
		arr[i].w=wt;
		index[i]=i;
		weight[i]=wt;
		i++;
	}
	qusort(weight,index,0,m-1);
	int count=0;
	int minsum=0;
	i=0;
//unionx(1,2);
//	printf("%d %d\n",find(1,2),find(2,3));
//	printf("%d %d %d\n",arr[index[i]].u,arr[index[i]].v,find(arr[index[i]].u,arr[index[i]].v));
	while(1)
	{
		//printf("Running\n");
		if(find(arr[index[i]].u,arr[index[i]].v)==0)
		{
			//printf("Join\n");
			unionx(arr[index[i]].u,arr[index[i]].v);
			minsum+=arr[index[i]].w;
			count++;
			i++;
		}
		else
			i++;
		if(count==n-1)
			break;
		if(i==m-1)
			break;
	}

   if(count==n-1)
	printf("%d\n",minsum);
   else if(i==m-1)
	   printf("-1\n");




	
	   /*int n,q;
	   int a,x,y;
	   int ans;
	   scanf("%d%d",&n,&q);
	   init(n);
	   int temp=q;
	   while(temp--)
	   {
	   scanf("%d%d%d",&a,&x,&y);
	   switch(a)
	   {
	   case 1:
	   unionx(x,y);
	   break;
	   case 2:

	   ans=find(x,y);
	   if(ans)
	   printf("YES\n");
	   else
	   printf("NO\n");
	   break;
	   case 3:
	   printf("%d\n",size[x]);
	   default:
	   break;
	   }
	   }                                                                                       
*/

	return 0;
}
void qusort(int a[],int b[],int first,int last)
{
	int pivot,i,j,temp;
	int temp2;
	if(first<last)
	{    
		pivot=first;
		i=first;
		j=last;

		while(i<j)
		{
			while(a[i]<=a[pivot]&&i<last)
				i++;
			while(a[j]>a[pivot])
				j--;
			if(i<j)
			{
				temp=a[i];
				temp2=b[i];
				b[i]=b[j];
				b[j]=temp2;
				a[i]=a[j];
				a[j]=temp;
			}
		}
		temp=a[pivot];
		a[pivot]=a[j];
		a[j]=temp;
		temp2=b[pivot];
		b[pivot]=b[j];
		b[j]=temp2;
		qusort(a,b,first,j-1);
		qusort(a,b,j+1,last);
	}    
}
