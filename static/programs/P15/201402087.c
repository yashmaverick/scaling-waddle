#include<stdio.h>

int top;
int n;
int a[100004];
int st[100004];
int s[100004];

void small();

int main()
{
		int t,k,i;
		scanf("%d",&t);
		while(t--)
		{
			//	printf("test done\n");
				scanf("%d%d",&n,&k);
				for(i=0;i<n;i++)
				{
						scanf("%d",&a[i]);
				}
			//	printf("scan done\n");
				small();
			//	printf("small done\n");
				for(i=0;i<=(n-k);i++)
				{
					//	printf("for\n");
						int min;
						int j=i;
						min=a[i];
						while( s[j]<(i+k) && s[j]>=0)
						{
								int l=j;
								min=a[s[l]];
								j=s[l];
						}
						printf("%d",min);
						if(i!=n-k)
								printf(" ");
				}
				printf("\n");
		}
		//printf("test out\n");
		return 0;
}

void small( )
{
		int i;
		top=0;
		for( i=n-1 ; i>=0 ; i-- )
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

