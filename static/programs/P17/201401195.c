#include<stdio.h>
int search1(int val,int in[],int start,int end)
{
	int i;
	for(i=start;i<=end;i++)
	{
		if(in[i]==val)
			return i;
	}
	return -1;
}
int search2(int val,int in[],int root,int start,int end)
{
	int i;
	for(i=start;i<=end;i++)
	{
		if(in[i]==val)
		{
			if(i<root)
				return 1;
			else if(i>root)
				return 2;
			else if(i==root)
				return -1;
		}
	}
	return -1;
}
int main()
{
	int non;
	scanf("%d",&non);
	int pre[non],in[non],i;
	for(i=0;i<non;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<non;i++)
		scanf("%d",&in[i]);
	int t,d;
	scanf("%d",&t);
	for(d=0;d<t;d++)
	{
		int a,b,v;
		scanf("%d%d",&a,&b);
		//if(a!=b)
		
		int start=0,root,end=non-1,v1,v2,ans;
		if(a!=b)
		{
		for(v=0;v<non;v++)
		{
			if(search1(pre[v],in,start,end)==-1)
				continue;
			else
			{
				root=search1(pre[v],in,start,end);		
				v1=search2(a,in,root,start,end);
				v2=search2(b,in,root,start,end);
				if(v1!=v2)
				{
					ans=in[root];
					break;
				}
				else if(v1==1)
					end=root-1;
				else if(v1==2)
					start=root+1;

			}
		}
		}
		else
		ans=a;
		printf("%d\n",ans);
	}
	return 0;
}



