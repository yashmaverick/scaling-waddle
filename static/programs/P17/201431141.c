#include<stdio.h>
int pre[100000],in[100000],src,des,hash[100000],ans,x=0,instart=0;
int search(int temp)
{
	if(temp>src && temp>des)
		return 0;
	else if(temp<src && temp<des)
		return 1;
	else 
		return -1;

}
void find(int start,int end)
{
	if(start<=end)
	{
		int temp,s=-1;
		temp=hash[pre[start]];
		//if(start==end)
		//{
		//	ans=pre[start];
		//	return ;
		//}
		s=search(temp);
	//	printf("s=%d\n",s);
		if(s==0)
		{
			find(start+1,temp);
		}
		else if(s==1)
		{	
			instart=temp;
			find(temp+start-instart+1,end);
		}
		else
		{
			ans=pre[start];
			return; 
		}
	}
}
int main()
{
	int n,i,a,b,t;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		hash[in[i]]=i;
	}
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&a,&b);
		src=hash[a];
		des=hash[b];
		find(0,n-1);
		printf("%d\n",ans);
	}
	return 0;
}
