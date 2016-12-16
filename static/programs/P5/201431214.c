#include<stdio.h>
#include<string.h>
void merge(int a[1001],int initial,int middle,int end)
{
	int new[1001];
	int m,n,c,l,p,q,x;
	m=initial;
	n=middle+1;
	c=initial;
	while(m<=middle && n<=end)
	{
		if(a[m]>=a[n])
		{	new[c]=a[n];
			n++;
		}
		else
		{
			new[c]=a[m];
			m++;
		}
		c++;
	}
	if(m>middle)
		for(l=n;l<=end;l++)
		{
			new[c]=a[l];
			c++;
		}
	else
		for(l=m;l<=middle;l++)
		{
			new[c]=a[l];
			c++;
		}
	for(x=initial;x<=end;x++)
	{
		a[x]=new[x];
	}
}

void sort(int a[1001],int leftind,int rightind)
{
	int mid;
	if(leftind<rightind)
	{
		mid=(leftind+rightind)/2;
		sort(a,leftind,mid);
		sort(a,mid+1,rightind);
		merge(a,leftind,mid,rightind);
	}
}
int main()
{
	int t,j;
	scanf("%d",&t);
	char s[10001];
	int night,k,sum,p,flag=0,l,g,i;
	int a[1001];
	for(j=0;j<t;j++)
	{
		flag=0;
		scanf("%d%d",&night,&k);
		for(p=0;p<night;p++)
		{
			scanf("%s ",s);
			scanf("%d",&a[p]);
		}
		sort(a,0,(night-1));
	/*	for(p=0;p<night;p++) printf("%d ",a[p]);
			printf("\n");
*/
		for(i=0;i<night-2;i++)
		{
			g=i+1;
			l=(night-1);
			while(l>g)
			{
				sum=a[i]+a[l]+a[g];
				if(sum>k)
					l--;
				else if(sum<k)
					g++;
				else if(sum==k)
				{
					flag=1;
					printf("YES\n");
					break;
				}
			}
			if(flag==1)
				break;
		}
		if(flag==0)
			printf("NO\n");
	}
	return 0;
}
