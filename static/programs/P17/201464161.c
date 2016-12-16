#include<stdio.h>
#include <stdlib.h>
int s,d,is,id,arr[1000],z,f=0,i,n,j;
int main()
{
	int in[1000],pre[1000],j,t,z;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
	}
	for(j=0;j<n;j++)
	{
		scanf("%d",&in[j]);
	}	
	scanf("%d",&t);
	for (z=0;z<t;z++)
	{
		int s,d;
		scanf("%d%d",&s,&d);
		if (s == d)
		{
		 printf("%d\n",s);
		}
		else
		{
		lca(in,pre,s,d);
		}
	}
	return 0;
}
int lca(int in[],int pre[],int s, int d)
{
	f=0;
	for(i=0;i<n;i++)
	{
		if(in[i]==s)
		{
			is=i;
		}
		if(in[i]==d)
		{	
			id=i;
		}
	}         
	if(is<id && (is-id)!=1)
	{
		for (z=is;z<=id;z++)
		{
			arr[f]=in[z];
			f++;
		}
		for(i=0;i<n;i++)
		{
			for(f=0;f<=(id-is);f++)
			{
				if(pre[i]==arr[f])
				{
					printf("%d\n",pre[i]);
					return 0;
				}
			}
		}
	} 
	if(id<is && (id-is)!=1)
	{
		for (z=id;z<=is;z++)
		{
			arr[f]=in[z];
			f++;
		}
		for(i=0;i<n;i++)
		{
			for(f=0;f<=(is-id);f++)
			{
				if(pre[i]==arr[f])
				{
					printf("%d\n",pre[i]);
					return 0;
				}
			}
		}
	}
}

