#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct trie
{
	int end;
	struct trie *next[10];
}trie;
void mergeSort(long long int arr[],long long int low,long long int mid,long long int high);
long long int f,te[100005];
void partition(long long int arr[],long long int low,long long int high)
{
	long long int mid;
	if(low<high)
	{mid=(low+high)/2;partition(arr,low,mid);partition(arr,mid+1,high);mergeSort(arr,low,mid,high);}
}
void mergeSort(long long int arr[],long long int low,long long int mid,long long int high)
{
	long long int i,m,k,l;l=low;i=low;m=mid+1;
	while((l<=mid)&&(m<=high))
	{if(arr[l]<=arr[m])
		{te[i]=arr[l];l++;}
		else
		{te[i]=arr[m];m++;
		}
		i++;
	}
	if(l>mid)
	{for(k=m;k<=high;k++){te[i]=arr[k];i++;}}
	else
	{for(k=l;k<=mid;k++){te[i]=arr[k];i++;}}
	for(k=low;k<=high;k++)arr[k]=te[k];
}
trie* insert(trie *root,long long int v)
{
	long long int i,j,a[25];
	trie *temp=root,*new;
	if(v<0)
		return ;
	if(v==0)
	{
		if(temp->next[0]==NULL)
			temp->next[0]=(trie*)malloc(sizeof(trie));
		temp=temp->next[0];
		for(i=0;i<10;i++)
			temp->next[i]=NULL;
		temp->end=1;
		return root;
	}
	i=0;
	while(v>0)
	{
		a[i++]=v%10;
		v=v/10;
	}
	for(j=i-1;j>=0;j--)
	{
		if(temp!=NULL)
		{
			if(temp->end==1)
			{
				f=1;
				break;
			}
		}
		if(temp->next[a[j]]==NULL)
		{
			temp->next[a[j]]=(trie*)malloc(sizeof(trie));
			temp=temp->next[a[j]];
			for(i=0;i<10;i++)
				temp->next[i]=NULL;
			temp->end=0;
		}
		else
			temp=temp->next[a[j]];
	}
	temp->end=1;
	return root;
}
int main()
{
	long long int i,j,k,l;
	long long int t,n,v,a[100005];
	trie *root=NULL;
	scanf("%lld",&t);
	while(t--)
	{
		f=0;
		root=(trie*)malloc(sizeof(trie));
		for(i=0;i<10;i++)
			root->next[i]=NULL;
		root->end=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		partition(a,0,n-1);
		for(i=0;i<n-1;i++)
			if(a[i]==a[i+1])
				f=1;
		for(i=0;i<n;i++)
		{
			//s=a[i];
			//l=strlen(s);
			root=insert(root,a[i]);
		}
		if(f==1)
			printf("NO\n");
		else
			printf("YES\n");
		free(root);
	}
	return 0;
}
