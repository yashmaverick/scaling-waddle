#include<stdio.h>

long long int n;
long long int a[500004];
long long int wc;
long long int top;
long long int st[500004];

void wrong();

int main()
{
		scanf("%lld",&n);
		while( n!=0 )
		{
				wc=0;
				long long int i;
				for( i=0 ; i<n ; i++ )
				{
						scanf("%lld",&a[i]);
						st[i]=0;
				}
				wrong();
				//printf("%lld\n",wc);
				printf("%lld\n",((n*(n-1))/2-wc));
				scanf("%lld",&n);
		}
		return 0;
}

void wrong()
{

		long long int i;
		wc=0;
		top=0;
		st[0]=0;
		//long long int dups=0;
		top++;

		//		printf("top %lld\n",a[st[top-1]]);
		for( i=1 ; i<n ; i++ )
		{
				//int k;
				//for(k=0;k<4;k++)
				//		printf("a %lld\n",a[k]);
				//	printf("top %lld\n",a[st[top-1]]);
				if( top!=0 && a[i]<a[st[top-1]] )
				{
						st[top]=i;
						wc++;
						//printf("1 tp %lld wc %lld i %lld\n",top,wc,i);
				}
				else if ( top!=0 && a[i]>a[st[top-1]])
				{
						//	printf("yes\n");

						long long int flag=0;
						while( a[i]>a[st[top-1]] && top>0 )
						{
								/*if(a[st[top-1]]==a[st[top-2]])
								  {
								//dups--;
								wc++;
								}*/
								top--;
								wc++;
							//	printf("2 tp %lld wc %lld i %lld\n",top,wc,i);
						}
						long long int j=top;
						while( a[i]==a[st[j-1]] && j>0 )
						{
								/*if(a[st[top-1]]==a[st[top-2]])
								  {
								//dups--;
								wc++;
								}*/
								j--;
								wc++;
								flag=1;
							//	printf("3 tp %lld wc %lld i %lld\n",top,wc,i);
						}
						if(j>0 )
								wc++;

							//	printf("4 tp %lld wc %lld i %lld\n",top,wc,i);
						

						st[top]=i;
				}
				else if( top!=0 && a[i]==a[st[top-1]] )
				{
						//dups++;
						long long int j=top;
						st[top]=i;
						//int k;
						//for(k=0;k<top;k++)
							//	printf("stack %lld\n",a[st[k]]);
						//	if( top>1 )
						while( j>0 && a[st[j-1]]==a[i] )
						{
								wc++;
								//printf("5 tp %lld wc %lld i %lld\n",top,wc,i);
								j--;
								if(j>0 && a[st[j-1]]>a[i])
								{
										wc++;
								//		printf("6 tp %lld wc %lld i %lld\n",top,wc,i);
										break;
								}
						}


				}
				top++;
		}
}
