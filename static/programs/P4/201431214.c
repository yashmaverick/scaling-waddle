#include<stdio.h>
#include<string.h>
void merge(long long int a[100001],long long int initial,long long int middle,long long int end)
{
	//printf("d\n");
	int new[100001];
	int m,n,c,l,p,q,x;
	m=initial;
	n=middle+1;
	c=initial;
	while(m<=middle && n<=end)
	{
		if(a[m]>=a[n])
		{	new[c]=a[n];
			n++;
		}
		else
		{
			new[c]=a[m];
			m++;
		}
		c++;
	}
	if(m>middle)
		for(l=n;l<=end;l++)
		{
			new[c]=a[l];
			c++;
		}
	else
		for(l=m;l<=middle;l++)
		{
			new[c]=a[l];
			c++;
		}
	for(x=initial;x<=end;x++)
	{
		a[x]=new[x];
	}
}

void  sort(long long int a[100001],long long int leftind,long long int rightind)
{
	int mid;
	if(leftind<rightind)
	{
		mid=(leftind+rightind)/2;
		sort(a,leftind,mid);
		sort(a,mid+1,rightind);
		merge(a,leftind,mid,rightind);

	}
}

int main()
{
	int t,j;
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		char s[100001];
	long long int a[100001],len,p=0,count[100001],cp=0,word=0,sum=0,ans,i,m,o;
		scanf("%s",s);
//printf("%d\n",count[0]);
for(o=0;o<100000;o++)
{
count[o]=1;
}

len=strlen(s);
if(s[0]=='J')
{
a[0]=-999999;
}
else if(s[0]=='M')
{a[0]=-1;}
else
{a[0]=1000000;}
		for(i=0;i<len-1;i++)
		{
if(s[i+1]=='J')
		{	a[i+1]=a[i]-999999;}
else if(s[i+1]=='M')
{a[i+1]=a[i]-1;}
else
{a[i+1]=a[i]+1000000;}
//printf("%d ",a[i]);
		}
//printf("\n");
		sort(a,0,(len-1));
//for(i=0;i<len;i++)
//{
//printf("%d ",a[i]);
//}
//printf("\n");
		for(i=1;i<=(len-1);i++)
		{
			if(a[i-1]==a[i] && a[i]!=0)
			{count[p]++;}
			else if(a[i]!=0 && a[i-1]!=a[i]) 
			{
				p++;
				cp=p;
			}
			if(a[i]==0)
			{
				word++;
			}
		}
//printf("%d\n",cp);
		for(m=0;m<=cp;m++)
		{
//printf("%d ",count[m]);
if(count[m]>1)
			sum=sum+((count[m]-1)*count[m])/2;
		}
//printf("\n");
//printf("%d\n",word);
		ans=sum+word+(word*(word-1))/2;
		printf("%lld\n",ans);
	}
	return 0;
}
