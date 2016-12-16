#include<stdio.h>
#include<stdlib.h>
//long long int arr[100005][3]; 
long long int parent[100005];
int Find(int i)
{
	if(parent[i]==-1)
		return i;
	else
		return parent[i]=Find(parent[i]);
}
long long int sum=0;
/*int conn(int x,int y)
{
	if(Find(x)==Find(y))
		return 1;
	else 
		return 0;
}*/
void Union(int parent1,int parent2) {
	parent[parent1]=parent2;
}
void merge(long long int arr[][3],long long int low,long long int mid,long long int high,long long int c[][3])
{
	long long int i=low,j=mid+1,k=0,x;
	while(i<=mid && j<=high)
	{
		if(arr[i][2] < arr[j][2])
		{
			for(x=0;x<3;x++)
				c[k][x] = arr[i][x];
			k++;
			i++;
		}
		else 
		{
			for(x=0;x<3;x++)
				c[k][x] = arr[j][x];
			k++;
			j++;
		}
	}
	while(i<=mid) 
	{
		for(x=0;x<3;x++)
			c[k][x] = arr[i][x];
		i++;
		k++;
	}
	while(j<=high)
	{
		for(x=0;x<3;x++)
			c[k][x] = arr[j][x];
		k++;
		j++;
	}
}
void mergesort(long long int arr[][3],long long int low,long long int high)
{
	if(high<=low)
		return;
	long long int coo[high-low+1][3];
	long long int mid=(high+low)/2;
	mergesort(arr,low,mid);
	mergesort(arr,mid+1,high);
	merge(arr,low,mid,high,coo);
	long long int x,i;
	for(i=low;i<=high;i++)
	{
		for(x=0;x<3;x++)
			arr[i][x]=coo[i-low][x];
	}
}
int kruskal(long long int arr[][3],int vertices,int edges)
{
	mergesort(arr,0,edges-1);
	int i;
	for(i=0;i<vertices;i++)
	parent[i]=-1;
	int total=0,pos=0,from,to,weight;
	while(total < vertices-1)
	{
		if(pos==edges)
		{	
			printf("-1\n");
			 return 0;
		}
		from=arr[pos][0];
		to=arr[pos][1];
		weight=arr[pos][2];
		pos++;
		int parent1=Find(from);int parent2=Find(to);
		if(parent1!=parent2)
		{ 
			sum=sum+weight;
			Union(parent1,parent2);total++;
		}
	}
	return sum;
}		
int main()
{
	long long int nodes,edges,i,u,v,cost;
	scanf("%lld %lld",&nodes,&edges);
	long long int *hey,*visited;
	//parent=malloc((nodes+1)*sizeof(long long int));
	/*visited=malloc((edges)*sizeof(long long int));
	for(i=0;i<=nodes;i++)
	{
		parent[i]=i;
	}
	for(i=0;i<edges;i++)
	{
		visited[i]=1;
	}*/
	long long int arr[100005][3];
	for(i=0;i<edges;i++)
	{
		scanf("%lld %lld %lld",&u,&v,&cost);
		arr[i][0]=u;
		arr[i][1]=v;
		arr[i][2]=cost;
	}
	long long int t = kruskal(arr,nodes,edges);
	//mergesort(arr,0,edges-1);
	/*long long int x,y,sum=0;
	for(i=0;i<edges;i++)
	{
		x=arr[i][0];
		y=arr[i][1];
		int k=conn(x,y);
		if(k==0)
					lol(x,y);
		else
			visited[i]=0;
	}
	for(i=0;i<edges;i++)
	{
		if(visited[i]==1)
			sum=sum+arr[i][2];
	}*/if(t!=0)
	printf("%lld\n",t);
	return 0;
}
