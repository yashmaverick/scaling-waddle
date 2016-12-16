#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
long long int pre[1000009],in[1000009],a[1000009],b[1000009];
/*typedef struct bt
{
	long long int val;
	struct bt *left,*right;
}bt;
bt *root;
long long int search(long long int x)
{
	long long int i;
	for(i=0;i<n;i++)
	{
		if(in[i]==x)
			return i;
	}
}
bt* build(bt *root,long long start,long long end)
{
		root=(bt *)malloc(sizeof(bt));
		root->val=pre[start];
		root->left=NULL;
		root->right=NULL;
		ind=search(pre[start]);
		root->left=build(root->left,start+1,ind);
		root->right=build(root->right,ind+1,end);
}*/
int main()
{
	long long int n,i,r,s,temp,u,v,start,q,min;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&pre[i]);
		b[pre[i]]=i;
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&in[i]);
		a[in[i]]=i;
	}
//	build(root,0,n-1);
	scanf("%lld",&q);
	while(q--)
	{
		min=LLONG_MAX;
		scanf("%lld %lld",&u,&v);
		r=a[u];
		s=a[v];
		if(r<s)
		{
			temp=r;
			r=s;
			s=temp;
		}
//		printf("%lld %lld\n",r,s);
		for(i=s;i<=r;i++)
		{
	//		printf("%lld %lld\n",in[i],b[in[i]]);
			if(b[in[i]]<min)
			{
				min=b[in[i]];
			}
		}
		printf("%lld\n",pre[min]);
	}
	return 0;
}
