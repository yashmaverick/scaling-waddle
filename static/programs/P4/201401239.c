#include<stdio.h>
#include<string.h>
void mergesort(int b[],int l,int r)
{
	int mid=l+(r-l)/2;
	if(r-l==1)
		return ;
	mergesort(b,l,mid);
	mergesort(b,mid,r);
	int c[100000],i,j=0,k;
	for(i=l;i<mid;i++)
		c[j++]=b[i];
	i=0;j=mid;k=l;
	while(i<(mid-l) && j<r)
		b[k++]=(c[i]>b[j])?b[j++]:c[i++];
	while(i<(mid-l))
		b[k++]=c[i++];
}
int main()
{
	int c,y;
	scanf("%d ",&y);
	for(c=0;c<y;c++)
	{
		char s[100000];
		scanf("%s",s);
		int i,l,b[100000];
		l=strlen(s);
		for(i=0;i<l;i++)
		{
			if(s[i]=='J')
				b[i]=100001;
			if(s[i]=='M')
				b[i]=-100002;
			if(s[i]=='R')
				b[i]=1;
		}
		for(i=0;i<l-1;i++)
			b[i+1]=b[i]+b[i+1];
		mergesort(b,0,l);
		//for(i=0;i<l;i++)
		//printf("%d ",b[i]);
		int z=0,count=1,zero=0;
		for(i=0;i<l;i++)
		{
			if(b[i]==b[i+1])
				count++;
			else
			{z=z+count*(count-1)/2;
				count=1;
			}
			if(b[i]==0)
				zero++;
		}
		printf("%d\n",zero+z);
	}
	return 0;
}
































































