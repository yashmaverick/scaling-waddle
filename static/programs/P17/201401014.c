#include<stdio.h>
int min_ind(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
int main()
{
	int in[100001],pre[100001],pre_ind[100001],in_ind[100001];
	int n,i,j,a,num1,num2,k,q,min,min_val;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
		pre_ind[pre[i]]=i;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		in_ind[in[i]]=i;
	}
	scanf("%d",&q);
	for(k=0;k<q;k++)
	{
		min=n+1;
		min_val=n+1;
		scanf("%d%d",&num1,&num2);
		i=min_ind(in_ind[num1],in_ind[num2]);
		j=in_ind[num1];
		if(i==j)
			j=in_ind[num2];
		for(a=i;a<=j;a++)
		{

			if(min>pre_ind[in[a]])
			{
				min=pre_ind[in[a]];
				min_val=pre[min];
			}
		}
		printf("%d\n",min_val);
	}
return 0;
}