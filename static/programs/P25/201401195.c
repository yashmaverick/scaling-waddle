#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int n1;
	int n2;
	int wt;
}node;
int sum=0;
node b[1000000];
void quicksort(int first,int last)
{
	int pivot,j,i;
	node temp;

	if(first<last)
	{
		//	pivot=first;
		i=first;
		j=last;
		pivot=first;
		while(i<j)
		{
			while(b[i].wt<=b[pivot].wt)
			{
				if(i<last)
					i++;
				else
					break;
			}
			while(b[j].wt>b[pivot].wt)
				j--;
			if(i<j){
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}

		temp=b[pivot];
		b[pivot]=b[j];
		b[j]=temp;
		quicksort(first,j-1);
		quicksort(j+1,last);

	}
}
int find(int x, int y,int u[]);
void merge(int x,int y,int wt,int u[])
{
	//	printf("DG");
	if(find(x,y,u)==1)
		return;
	else
	{
		int a=x,b=y;
		while(u[a]!=a)
		{
			a=u[a];
		}
		//		printf("GD");
		while(u[b]!=b)
		{		
			b=u[b];
		}
		u[a]=b;
		sum=sum+wt;
	}

}

int find(int x,int y,int u[])
{
	int a=x,b=y;
	//printf("QW");
	while(u[a]!=a)
	{
		//	printf("GHG");
		a=u[a];
	}
	//		printf("%d----",u[b]);
	while(u[b]!=b)
	{
		//		printf("FDH");
		b=u[b];
	}
	if(a==b)
		return 1;
	else
		return 0;
}

int main()
{
	int n,m,x,y,w,i;
	scanf("%d%d",&n,&m);
	int a[n];
	//	node b[m],k[m];
	for(i=0;i<n;i++)
	{
		a[i]=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&b[i].n1,&b[i].n2,&b[i].wt);
		//		printf("%d%d%d",b[i].n1,b[i].n2,b[i].wt);
	}
	//return 0;
	//	quicksort(b,0,m-1);
	/*	int ii,jj,max=0,kk;
		for(ii=0;ii<m;ii++)
		{
	//		kk=b[ii].wt;
	for(jj=ii;jj<m;jj++)
	{
	if(b[jj].wt<b[ii].wt)
	{
	//			kk=b[jj].wt;
	//			max=jj;
	b[ii]=b[jj];			
	//k[ii]=b[ii];
	}
	k[ii]=b[ii];

	}
	//	k[ii]=b[max];
	}*/
	//	for(i=0;i<m;i++)
	//		printf("%d %d %d \n",k[i].n1,k[i].n2,k[i].wt)0;
	//	printf("BC");
	quicksort(0,m-1);
	//	printf("%d%d",b[1].n2,b[0].wt);
	for(i=0;i<m;i++)
	{
		//		printf("GDvv");
		merge((b[i].n1)-1,(b[i].n2)-1,b[i].wt,a);
	}
	for(i=0;i<n-1;i++)
	{
	if(find(i,i+1,a)==0)
	{
	printf("-1\n");
	//break;
	return 0;
	}
	}		
	printf("%d\n",sum);
	return 0;
}
