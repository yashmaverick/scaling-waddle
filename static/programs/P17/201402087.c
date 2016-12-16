#include<stdio.h>
#define maxnodes 100000

int n;
int pre[maxnodes];
int in[maxnodes];

int lca( int p1 , int p2 )
{
		int count=0;
		int j=0;
		int temp=j;
		while(count==2 || count==0)
		{
				if(pre[j]==p1)
						return p1;
				if(pre[j]==p2)
						return p2;
				count=0;
				int k;
				for( k=0 ; k<n ; k++ )
						if( in[k] == pre[j] )
								break;
			//	printf("k=%d\n",k);
				int l=k;
				for( k=0 ; k<l ; k++ )
						if(in[k]==p1 || in[k]==p2)
								count++;
			//	printf("count=%d\n",count);
				
				temp=j;
				j++;
		}
		return pre[temp];
}


int main()
{
		scanf("%d",&n);
		int i;
		for( i=0 ; i<n ; i++ )
				scanf("%d",&pre[i]);
		for( i=0 ; i<n ; i++ )
				scanf("%d",&in[i]);
		int test;
		scanf("%d",&test);
		while( test-- )
		{
				int p1,p2;
				scanf("%d%d",&p1,&p2);
				int ans=lca(p1,p2);
				printf("%d\n",ans);
		}
		return 0;
}

