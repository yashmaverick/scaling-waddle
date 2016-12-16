#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*void merge(long long int p,long long int q,long long int r)
  {
  long long int n1,n2,i,j,k,max=1000000005;
  n1=q-p+1;
  n2=r-q;
  for(i=p;i<=r;i++)
  printf("%d ",a[i]);
//printf("\n");
for(i=1;i<=n1;i++)
l[i]=a[p+i-1];
for(i=1;i<=n2;i++)
R[i]=a[q+i];
l[n1+1]=max;
R[n2+1]=max;
i=1;
j=1;
for(k=p;k<=r;k++)
{
if(l[i]<=R[j])
{

a[k]=l[i];
//printf("%d %d\n",a[k],l[i]);
i++;
}
else
{
a[k]=R[j];
//printf("%d %d\n",a[k],R[j]);
j++;
}
//printf("%d ",a[k]);

}
//printf("\n");

}

void merge_sort(long long int p,long long int r)
{
//printf("ok");
long long int q;
//printf("%d %d\n",p,r);
if(p<r)
{
//      printf("ok\n");
q=(p+r)/2;

merge_sort(p,q);
merge_sort(q+1,r);
merge(p,q,r);
}
}*/
typedef struct list{
	 int val;
	struct list *p;
}g;
g *a[1000010];
int u[1000010],v[1000010],p[1000010],w[1000010],count[1000010];;
int quick_sort(int low, int high)
{
	int pivot,j,temp,i;
	if(low<high)
	{
		pivot=high;
		i=low;
		j=high;
		while(i<j)
		{
			while((w[i]<=w[pivot])&&(i<high))
			{
				i++;
			}
			while(w[j]>w[pivot])
			{
				j--;
			}
			if(i<j)
			{
				temp=w[i];
				w[i]=w[j];
				w[j]=temp;
				temp = u[i];
				u[i]=u[j];
				u[j]=temp;
				temp = v[i];
				v[i]=v[j];
				v[j]=temp;

			}
		}
		temp=w[pivot];
		w[pivot]=w[j];
		w[j]=temp;
		temp=u[pivot];
		u[pivot]=u[j];
		u[j]=temp;
		temp=v[pivot];
		v[pivot]=v[j];
		v[j]=temp;
		/*if(j==k)
		  return j;*/
		return quick_sort(low,j-1);
		return quick_sort(j+1,high);
	}
}

int main()
{
	long long int ans;
	 int n,m,i,x,z,s,target,j;
//	 int p[100001],w[100001],count[100001];
	g *travel,*temp,*y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}
	for(i=1;i<=n;i++)
	{
		count[i]=1;
		p[i]=i;
	}
	//memset(count,1,n);
/*	for(i=1;i<=n;i++)
		printf("%d ",count[i]);*/
	for(i=1;i<=n;i++)
	{
		y=malloc(sizeof(g));
		y->val=i;
		y->p=NULL;
		a[i]=y;
	}
	/*for(i=1;i<=n;i++)
	{
		temp  =a [i];
		while(temp!=NULL)
		{
			printf("i->%lld ",temp->val);
			temp =temp->p;

		}
		printf("\n");
	}*/
	quick_sort(1,m);
	ans = 0;
	for(i=1;i<=m;i++)
	{
		x = p[u[i]];
		z = p[v[i]];
		if(x == z)
			continue;
		else
		{
			ans = ans + w[i];
			//printf("ans=%lld\n",ans);

			if( count[x] < count[z] ) // intialise count with 1;make adlist
			{
				travel = a[x];
				s = x;
				target = z;
			}
			else
			{
				travel = a[z];
				s = z;
				target = x;
			}
			//	printf("%d %d")
			j = 0;
			temp = travel;
			while(travel!=NULL)
			{
				//printf("ok\n");
				p[travel->val] = target;
				travel = travel->p;
				if(j!=0)
					temp = temp->p;
				j++;
				count[target]++;
			}
			temp->p = a[target];
			a[target] = a[s];
			a[s] = NULL;
			count[s]=0;
			/*for(j=1;j<=n;j++)
			{
				temp  =a [j];
				while(temp!=NULL)
				{
					printf("j->%lld ",temp->val);
					temp =temp->p;

				}
				printf("\n");
			}*/

		}
	}
	int flag=0;
	for(i=1;i<=n;i++)
		if(count[i]==n)
		{
			printf("%lld\n",ans);
			flag=1;
		}
	if(flag==0)
		printf("-1\n");
	return 0;
}
