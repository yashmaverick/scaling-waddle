#include<stdio.h>
int a[100000],b[100000];
int val=0,dep=-1,las=-1;
void find(int s,int e,int d)
{
	if(s>e)
		return;
	if(s==e)
	{
		if(d>=dep)
		{
			dep=d;
			if(las==d)
			{
				if(a[s]<val)
				{
					val=a[s];
				}
			}
			else
			{
				val=a[s];
			}
			las=d;
		}
		return;
	}
	find(s,b[e],d+1);
	find(b[e]+1,e-1,d+1);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		val=0;
		dep=-1;
		las=-1;
		int i,n,s[100000],p;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		b[0]=-1;
		s[0]=0;
		p=1;
		for(i=1;i<n;i++)
		{
			int state=0;
			while(a[s[p-1]]>a[i])
			{
				p--;
				state=1;
				if(p==0)
				{
					b[i]=-1;
					s[p]=i;
					p++;
					break;
				}
				else if(a[s[p-1]]<a[i])
				{
					b[i]=s[p-1];
					s[p]=i;
					p++;
					break;
				}
			}
			if(state==0)
			{
				b[i]=s[p-1];
				s[p]=i;
				p++;
			}
		}
		//	for(i=0;i<n;i++)
		//		printf("%d ",b[i]);
		find(0,n-1,0);
		printf("%d %d\n",val,dep);
	}
	return 0;
}
