#include<stdio.h>
#include<string.h>
int tmp[100004];
void mergesort(int f[],int s,int e)
{
	if(s==e)
		return ;
	int mid=(s+e)/2;
	mergesort(f,s,mid);
	mergesort(f,mid+1,e);
	int i=s,j=(mid+1),k=0;
	while(i<=mid || j<=e)
	{
		if(i>mid)
			tmp[k++]=f[j++];
		else if(j>e)
			tmp[k++]=f[i++];
		else
		{
			if(f[i]<f[j])
				tmp[k++]=f[i++];
			else
				tmp[k++]=f[j++];
		}
	}
	int p;
	for(p=0;p<k;p++)
		f[s+p]=tmp[p];
}
int main()
{
	char g[100004];
	int f[100004];
	int n,m,t,p,q,r,i,count=1,count1=0,s=0,u=1;
	scanf("%d",&t);
	for(m=0;m<t;m++)
	{
		scanf("%s",g);
		n=strlen(g);
		p=1,q=100001,r=-100002;
		int sum=0,flag=0;
		for(i=0;i<n;i++)
		{
			if(g[i]=='J')
			{
				sum=sum+p;
				f[i]=sum;
			}
			else if(g[i]=='M')
			{
				sum=sum+q;
				f[i]=sum;
			}
			else if(g[i]=='R')
			{
				sum=sum+r;
				f[i]=sum;
			}
		}
		mergesort(f,0,n-1);
//		for(i=0;i<n;i++)
//			printf("%d ",f[i]);
//		printf("\n");
		count=1,u=1,s=0,count1=0,flag=0;
/*		for(i=0;i<n-1;i++)
		{
			if(f[0]!=f[1]&&f[0]==0)
				count1=1;
			if(f[i]==f[i+1] && f[i]==0)
			{
				count++;
				flag=1;
			}
			else if(f[i]!=f[i+1] && flag==1 && f[i]==0)
			{
				count1=count1+count+((count*(count-1))/2);
				count=1;
				flag=0;
			}
			else if(f[i]==f[i+1] && f[i]!=0)
			{
				flag=1;
				u++;
			}
			else if(f[i]!=f[i+1] && flag==1 && f[i]!=0)
			{
				s=s+(u*(u-1))/2;
				u=1;
				flag=0;
			}
			if(f[i]==f[i+1] && i==n-2 && f[i]==0)
				count1=count1+count+(count*(count-1))/2;
			else if(f[i]==f[i+1] && i==n-2 && f[i]!=0)
				s=s+u*(u-1)/2;
		}*/
		for(i=0;i<(n-1);i++)
		{
		    if(f[i]==f[i+1] && f[i]==0)
			count++;
		    else if(f[i]!=f[i+1] && f[i]==0)
		    {
			count1=count1+count+((count*(count-1))/2);
			count=1;
		    }
		    else if(f[i]==f[i+1] && f[i]!=0)
			u++;
		    else if(f[i]!=f[i+1] && f[i]!=0)
		    {
			s=s+((u*(u-1))/2);
			u=1;
		    }
		}
		if(f[n-1]==0)
		    count1=count1+count+((count*(count-1))/2);
		if(f[n-1]!=0)
		    s=s+((u*(u-1))/2);
		printf("%d\n",count1+s);

	}
	return 0;
}
