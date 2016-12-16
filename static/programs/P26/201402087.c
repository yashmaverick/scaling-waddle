#include<stdio.h>

int main()
{
		int i,j,k,m;
		int a[11111]={0};
		a[1]=1;
		for(i=2;i<=100;i++)
		{	j=2;
				k=i;
				m=0;		
				if(a[i]==0)
				{
						while(m<=10000)
						{
								m=j*k;
								a[m]=1;
								j++;
						}
				}
		}

		/*	int count=0;
			for(i=1000;i<=10000;i++)
			if(a[i]==0)
			{
			count++;
			printf("%d\n",i);
			}
			printf("total=%d\n",count);*/

		int test;
		scanf("%d",&test);
		while(test--)
		{
				int flag=0;
				int source,dest;
				scanf("%d%d",&source,&dest);
				if(a[source]==0 && a[dest]==0)
				{
						int d[11111]={0};
						//printf("%d\n",d[13]);
						int i;
						int q[11111];
						int start=0;
						int end=0;

						//for( i=0 ; i<=10000 ; i++)
						//		d[i]=-1;

						d[source]=1;
						q[end]=source;
						end++;
						while( end > start)
						{
								int n=q[start];
								int num=n;
								int nn;
								//printf("\n%d\n",n);
								for( i=3 ; i>=0 ; i--)
								{
										int no[4];
										int temp[4];
										int j;
										for( j=3 ; num != 0 ; j-- )
										{
												temp[j]=num%10;
												num=num/10;
										}
										//for( j=0 ; j<4 ; j++)
										//		printf("%d",no[j]);
										//printf("\n");
										no[0]=temp[0];
										no[1]=temp[1];
										no[2]=temp[2];
										no[3]=temp[3];
										for( j=0 ; j<10 ; j++)
										{
												nn=0;
												int k;
												no[i]=j;
												for( k=0 ; k<=3 ; k++ )
														nn=nn*10+no[k];
												//printf("nn=%d	a[nn]=%d d[nn]=%d\n",nn,a[nn],d[nn]);
												if( a[nn]==0 && nn>999 && nn<10000 && d[nn]==0 )
												{

														q[end]=nn;
														//	printf("push=%d\n",q[end]);
														end++;
														d[nn]=d[n]+1;
														if( nn == dest )
														{
																flag=1;
																break;
														}
												}
										}
										if( flag ==1 )
												break;
								}
								if( flag==1 )
										break;
								//printf("pop=%d\n",q[start]);
								q[start]=0;
								start++;
						}
						if(d[dest]==0)
								printf("Impossible\n");
						else
								printf("%d\n",d[dest]-1);
				}
				else
						printf("Impossible\n");
		}
		return 0;
}
