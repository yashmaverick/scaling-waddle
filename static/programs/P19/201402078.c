#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int flag=0,temp[1000000],arr[1000000];
char s[15];
typedef struct node
{
	long long int exist;
	struct node *next[10];
}node;
node *root;
void reverse(long long int a)
{
	long long int i=0;
	while(a!=0)
	{
		s[i]=a%10+'0';
		a=a/10;
		i++;
	}
	s[i]='\0';
}
node* insert(long long int a)
{
	node *tmp=root;
	long long int i,j,k;
	char t[15];
	reverse(a);
	j=strlen(s);
//	printf("len %lld\n",j);
	for(k=0;k<j;k++)
	{
		long long int r=s[j-k-1]-'0';
		//printf(" %lld  %lld\n",k,r);
		if(tmp->next[r]==NULL)
		{
			node *new=(node*)malloc(sizeof(node));
			new->exist=1;
			for(i=0;i<10;i++)
				new->next[i]=NULL;
			tmp->next[r]=new;
			//printf("if %lld\n",r);
		}
		else
		{
			if(tmp->next[r]->exist==0)
			{
			//	printf("else %lld\n",r);
				flag=1;
			}

		}
		tmp=tmp->next[r];
	}
	tmp->exist=0;
	return root;
}
void sort(long long int c[],long long int start,long long int mid,long long int end)
{
	long long int i,m,k,l;
	l=start;
	i=start;
	m=mid+1;
	while((l<=mid)&&(m<=end))
	{
		if(c[l]<=c[m])
		{
			temp[i]=c[l];
			l++;
		}
		else
		{
			temp[i]=c[m];
			m++;
		}
		i++;
	}
	if(l>mid)
		for(k=m;k<=end;k++)
		{
			temp[i]=c[k];
			i++;
		}
	else
		for(k=l;k<=mid;k++)
		{
			temp[i]=c[k];
			i++;
		}
	for(k=start;k<=end;k++)
		c[k]=temp[k];
}
void part( long long int c[],long long int start,long long int end)
{
	long long int mid;
	if(start<end)
	{
		mid=(start+end)/2;
		part(c,start,mid);
		part(c,mid+1,end);
		sort(c,start,mid,end);
	}
}
int main()
{
	long long int t,i;
	scanf("%lld",&t);
	while(t--)
	{
		flag=0;
		root=NULL;
		root=malloc(sizeof(node));
		root->exist=0;
		long long int n;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		part(arr,0,n-1);
		for(i=0;i<n;i++)
			insert(arr[i]);
		if (flag==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
