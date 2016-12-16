#include<stdio.h>
long long a[100001],b[100001];
int merge(int start,int end)
{

	int r=0,k,i,j;
	if(start!=(start+end)/2)
		merge(start,(start+end)/2);
	if(((start+end)/2)+1!=end)
		merge(((start+end)/2)+1,end);
	for(i=start,j=((start+end)/2)+1;i<=(start+end)/2&&j<=end;)
	{
		if(a[i]<a[j])
			b[r++]=a[i++];
		else
			b[r++]=a[j++];
	}
	if(i>(start+end)/2)
		for(k=j;k<=end;)
			b[r++]=a[k++];
	else if(j>end)
		for(k=i;k<=(start+end)/2;)
			b[r++]=a[k++];
	for(i=start,j=0;i<=end;i++)
		a[i]=b[j++];
	return 0;
}
int main()
{
	int t,i;
	scanf("%d",&t);
	char ar[100010];
	while(t--)
	{
		for(i=0;i<100010;i++)
			a[i]=0;
		scanf("%s",ar);
		int len;
		for(len=0;ar[len]!='\0';len++)
		{
			if(len==0)
			{
				switch(ar[len])
				{
					case 'J':a[0]=-100000-2;break;
					case 'M':a[0]=1;break;
					case 'R':a[0]=100001;break;
				}
			}
			else
			{
				switch(ar[len])
				{
					case 'J':a[len]=a[len-1]-100000-2;break;
					case 'M':a[len]=a[len-1]+1;break;
					case 'R':a[len]=a[len-1]+100001;break;
				}
			}
		}
		a[len]=0;
		merge(0,len);
		int count=1,ans=0;
		for(i=1;i<=len;i++)
		{
			if(a[i]==a[i-1])
				count++;
			else
			{
				ans+=(count*(count-1))/2;
				count=1;
			}
		}
		ans+=(count*(count-1))/2;
		printf("%d\n",ans);

	}
	return 0;
}
