#include<stdio.h>
int a,b,x,y,hash[100005],pre[100005];
int find(int st,int en)
{
	int temp,ans;
	temp=hash[pre[st]];
	if(temp>a&&temp>b)
		ans=find(st+1,temp);
	else if(temp<a&&temp<b)
	{
		y=x;
		x+=temp-y+1;
		ans=find(temp+st-y+1,en);
	}
	else 
		return pre[st];
	return ans;
}
int main()
{
	int i,j,k,w,ans;
	int in[100005],t,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		hash[in[i]]=i;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&j,&w);
		x=0;
		y=0;
		a=hash[j];
		b=hash[w];
		ans=find(0,n-1);
		printf("%d\n",ans);
	}
	return 0;
}
