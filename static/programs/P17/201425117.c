#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	int Pre[10000];
	int In[10000];
	int Mid[10000];
	for(i=0;i<10000;i++)
		Pre[i]=0;
	for(i=0;i<10000;i++)
		In[i]=0;
	for(i=0;i<n;i++)
		scanf("%d",&Pre[i]);
	for(i=0;i<n;i++)
		scanf("%d",&In[i]);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int john,white,j=0,fl=0;
		scanf("%d %d",&john,&white);
		for(i=0;i<n;i++)
		{
			if(j!=0 && (In[i]!=john && In[i]!=white))
			{
				Mid[j]=In[i];
				j++;
			}
			else if(In[i]==john || In[i]==white)
			{
				if(fl==0)
				{
					Mid[j]=In[i];
					j++;
					fl=1;
				}
				else if(fl==1)
				{
					Mid[j]=In[i];
					break;
				}
			}
		}
		int l,flag=0,ans;
		l=j+1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<l;j++)
			{
				if(Pre[i]==Mid[j])
				{
					ans=Pre[i];
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
