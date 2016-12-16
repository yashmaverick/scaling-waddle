#include<stdio.h>
#include<stdlib.h>
void swap(char **a,int x,int y)
{
	char *temp;
	temp=a[x];
	a[x]=a[y];
	a[y]=temp;
}
int comp(char *a,char *b)
{
	int i=0;
	while(a[i]==b[i] && a[i]!='\0')
		i++;
	if(a[i]=='\0' || b[i]=='\0')
		return 0;
	else if(a[i]>b[i])
		return -1;
	else 
		return 1;
}
int cmp(const void *p,const void *q)
{
	int flag;
	char *l=*(char **)p;
	char *r=*(char **)q;
	flag=comp(l,r);
	if(flag==1)
		return -1;
	else
		return 1;
}
int main()
{
	char **a;
	int i,j,ans,flag,t,n,k;
	a=malloc(sizeof(char*)*100005);
	for(i=0;i<100005;i++)
			a[i]=malloc(sizeof(char)*11);
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%s",a[i]);
		qsort(a,n,sizeof(char *),cmp);
//		for(i=0;i<n;i++)
//			printf("%s\n",a[i]);
		for(i=0;i<n-1;i++)
		{
			if(comp(a[i],a[i+1])==0)
				{
					printf("NO\n");
					ans=1;
					break;
				}
		}
		if(ans==0)
			printf("YES\n");
		}
	return 0;
}
