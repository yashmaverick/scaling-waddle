#include<stdio.h>
int a[100005];
int max;
int top;
int node;
int n;
int st[100005];
int s[100005];

void small( );
void bst(int low,int high,int depth);

int main()
{
		int t;
		scanf("%d",&t);
		while(t--)
		{
				int i;
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
						scanf("%d",&a[i]);
						st[i]=0;
						s[i]=0;
				}
				max=0;
				node=a[0];
				small();
				//	for(i=0;i<n;i++)
				//			printf("%d\n",s[i]);
				bst(0,n-1,0);
				printf("%d %d\n",node,max);
		}
		return 0;
}

void bst(int low,int high,int depth)
{
		if(high>=low && low>=0)
		{
				int i;
				if(depth>max)
				{
						max=depth;
						node=a[high];
				}
				if(depth==max)
				{
						if(a[high]<node)
								node=a[high];
				}
				/*for(i=high-1;i>=low;i--)
				  {
				  if(a[i]<a[high])
				  break;
				  }*/
				if(s[high]>=low)
				{
						if(low<=s[high])
								bst(low,s[high],depth+1);
						if(s[high]+1<=high)
								bst(s[high]+1,high-1,depth+1);
				}
				else
						if(low<=high)
								bst(low,high-1,depth+1);
		}
}

void small( )
{
		int i;
		top=0;
		for( i=0 ; i<n ; i++ )
		{
				while((top!=0)&&(a[i]<=a[st[top-1]]))
						top--;
				if(top==0)
						s[i]=-1;
				else
				{
						s[i]=st[top-1];
				}
				st[top]=i;
				top++;

		}
}

