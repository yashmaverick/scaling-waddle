#include<stdio.h>
void qs(int cumsum[],int left,int right);
int partition(int cumsum[],int left,int right);
int main()
{
	char a[100010];
	int cumsum[100010];
	int assn[100];
	assn[74]=100001;assn[77]=1;assn[82]=-100002;
	int t,n,i;
	long long int add,cnt,ans;ans=0;i=1;add=0;
	scanf("%d",&t);
	while(t>0)
	{
	scanf("%s",a);
	cumsum[0]=assn[a[0]];
	//printf("%d",cumsum[0]);
	while(a[i]!='\0')
	{
		cumsum[i]=cumsum[i-1]+assn[a[i]];
		if(cumsum[i]==0)
		{
			add++;
		}
		i++;
	}
	qs(cumsum,0,i-1);//cumsum is now sorted
	cnt=1;
	for(n=0;n<i;n++)
	{
		if(cumsum[n+1]==cumsum[n])
		{
			cnt++;
		}
		else
		{
			ans=ans+((cnt)*(cnt-1))/2;
			cnt=1;
		}
	}
	printf("%lld\n",ans+add);
	t--;
	add=0;cnt=0;ans=0;i=1;
	}
	return 0;
}
void qs(int a[],int left,int right)
{
	int z;
	if(left>=right)
	{
		return;
	}
	else
	{
		//printf("%d",i);
		//mid=(i+j)/2;
		z=partition(a,left,right);
		qs(a,left,z-1);
		qs(a,z+1,right);
	}
}
int partition(int a[],int left,int right)
{
	int pivot,s,e,temp,p;
	//printf("%d\n",i);
	pivot=a[left];
	e=right;
	for(p=left+1;p<=e;p++)
	{
		//printf("i=%d e=%d\n",i,e);
		if(a[p]>=pivot)
		{
			temp=a[e];
			a[e]=a[p];
			a[p]=temp;
			e--;
			p--;
		}
	}
	temp=a[e];
	a[e]=a[left];
	a[left]=temp;
	return e;
}








