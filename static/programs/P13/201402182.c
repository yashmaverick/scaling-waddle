#include<stdio.h>
long long int node,a[100007],b[100007],c[100007],maxd=0,node=0,lpg=-1;
void push(int val)
{
	lpg++;
	c[lpg]=val;
	return ;
}
void pop()
{
	if(lpg==-1)
		return ;
	lpg--;
	return ;
}

void maxnd(long long int j,long long int index,long long int dep);
int main()
{
	long long int t,i,n,hu,y,o,fl,h;
	scanf("%lld",&t);
	for(o=1;o<=t;o++)
	{
		node=1000009;maxd=0,fl=1;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		c[0]=-1;
		i=n-1;
		while(i>=0)
		{
			if(lpg==-1 || a[i]>=a[c[lpg]])
			{push(i);
				i--;
			}
			else
			{
				b[c[lpg]]=i;
				pop();
			}

		}
		while(lpg!=-1)
		{
			b[c[lpg]]=c[lpg]-1;
			pop();
		}

		maxnd(0,n-1,0);
		printf("%lld %lld\n",node,maxd);
	}
	return 0;
}
void maxnd(long long int stat,long long int index,long long int dep)
{
	if(stat>index)
		return;
	if(stat==index)
	{
		if(dep>maxd)
		{
			node=a[index];
			maxd=dep;
		}
		else if(dep==maxd && a[index]<node)
			node=a[index];
	}
	maxnd(stat,b[index],dep+1);
	maxnd(b[index]+1,index-1,dep+1);
	return;
}
