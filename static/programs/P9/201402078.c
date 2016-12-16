#include<stdio.h>
typedef struct num
{
	int val,left,right;
}num;
int main()
{
	num new[1000];
	int n,t,mod,i,a[1000001],j=0,m,k=0;
	scanf("%d %d",&n,&mod);
	for(i=0;i<n;i++)
	{
		int ans=0;
		scanf("%d",&m);
		scanf("%d",&a[k]);
		new[i].left=k;
		ans=(ans+a[k])%mod;
		k++;
		for(j=0;j<m-2;j++)
		{
			scanf("%d",&a[k]);
			ans=(ans+a[k])%mod;
			k++;
		}
		if(m>=2)
		{
			scanf("%d",&a[k]);
			ans=(ans+a[k])%mod;
			k++;
		}
		new[i].right=k;
		new[i].val=ans;
		//printf("finished one\n");
	}
	for(i=1;i<=n-1;i++)
	{
		j=i;
		while (j>0&& new[j].val<new[j-1].val)
		{

			t=new[j].val;
			new[j].val=new[j-1].val;
			new[j-1].val=t;

			t=new[j].right;
			new[j].right=new[j-1].right;
			new[j-1].right=t;

			t=new[j].left;
			new[j].left=new[j-1].left;
			new[j-1].left=t;
			j--;

		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",new[i].val);
		for(j=new[i].left;j<new[i].right;j++)
			printf("%d\n",a[j]);
		printf("\n");
	}
	/*for(i=0;i<n;i++)
	  {
	  for(j=new[i].left;j<new[i].right;j++)
	  printf("%d\n",a[j]);
	  printf("\n");
	  }*/
	return 0;
}
