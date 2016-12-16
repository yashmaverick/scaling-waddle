#include<stdio.h>
typedef struct node
{
	int weight;
	int left;
	int right;
}node;
node a[1001];
int b[1000001];
int sort(node a[],int l,int r)
{
	int pos;
	if(l<r)
	{
	pos=partition(a,l,r);
	sort(a,l,pos-1);
	sort(a,pos+1,r);
	}
}
int partition(node a[],int l,int r)
{
//	printf("aaa%d %d\n",l,r);
	int p=a[r].weight,i=l-1,j,t1,t2,t3;
	for(j=l;j<=r-1;j++)
	{
		if(a[j].weight<=p)
		{
			i++;
			t1=a[j].weight;
			a[j].weight=a[i].weight;
			a[i].weight=t1;

			t2=a[j].left;
			a[j].left=a[i].left;
			a[i].left=t2;

			t3=a[j].right;
			a[j].right=a[i].right;
			a[i].right=t3;

		}
	}
	t1=a[i+1].weight;
	a[i+1].weight=a[r].weight;
	a[r].weight=t1;

	t2=a[i+1].left;
	a[i+1].left=a[r].left;
	a[r].left=t2;

	t3=a[i+1].right;
	a[i+1].right=a[r].right;
	a[r].right=t3;

	return i+1;
}
int main()
{
	int sum,i,j,n,mod,m,l,w,x,st,end;
	scanf("%d%d",&n,&mod);
	l=0;
	for(i=0;i<n;i++)
	{
		sum=0;
		st=l;
		scanf("%d",&m);
		for(j=l;j<l+m;j++)
		{
			scanf("%d",&x);
			sum=(sum%mod+x%mod)%mod;
			b[j]=x;
		}
		l=l+m;
		end=l-1;
		a[i].weight=sum;
		a[i].left=st;
		a[i].right=end;
	}
	sort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i].weight);
		st=a[i].left;
		end=a[i].right;
		for(j=st;j<=end;++j)
			printf("%d\n",b[j]);
		printf("\n");
	}
	//for(i=0;i<n;i++)
	//	printf("%d  %d  %d  \n",a[i].weight,a[i].left,a[i].right);
	return 0;
}






