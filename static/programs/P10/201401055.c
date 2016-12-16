#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int e=1;
int f=-1;
int r=-1;
char c[10000][105];
char in[105];
int N;
void append(int n)
{
	//	char s[100];

	//	printf("%d %d\n",f,r);
	//	printf("\n append\n");
	//	return;
	int i;
	//	for(i=0;i<n;i++)
	//	{
	/*		if(f==-1)
			{
			r=0;f=0;
			printf("%d %d\n",f,r);

			scanf("\n%s",&c[r][100]);
	//			printf("\n%d %d\n",f,r);
	//			printf("\n%s",c[r]);
	}
	else
	if(f==r+1)
	{
	r=f;
	f=f+1;
	//				printf("\n%d %d\n",f,r);
	scanf("\n%s",&c[r][100]);
	//				printf("\%d %d\n",f,r);
	}
	else
	if(r==N-1&&f<r)
	{
	r=0;
	f++;
	//					printf("\n%d %d\n",f,r);
	scanf("\n%s",&c[r][100]);
	//					printf("\n%d %d\n",f,r);
	}
	else
	if(f==N-1)
	{
	f=0;
	r++;
	//						printf("\n%d %d\n",f,r);
	scanf("\n%s",&c[r][100]);
	//						printf("\n%d %d\n",f,r);
	}
	else
	if(r==N-1)
	{
	r=0;
	//							printf("\n%d %d\n",f,r);
	scanf("\n%s",&c[r][100]);
	//							printf("\n%d %d\n",f,r);
	}
	else
	{
	r++;
	//							printf("\n%d %d\n",f,r);
	scanf("\n%s",&c[r][100]);
	//							printf("\n%d %d\n",f,r);
	}
	//		scanf("\n%s",&c[r][100]);
	//		printf("\n%s",c[r]);
	//		printf("\n%d",r);
	//		printf("\n%s",c[r]);
	}*/

/*	if(f<r&& (N-1-r)<=n)
	{
		//		r++;
		for(i=0;i<n;i++)
		{
			r++;
			scanf("%s",in);
			//			printf("\t%s",in);
			strcpy(c[r],in);
			//			printf("\t%s",c[r]);
			e=0;
		}
	}
	else
	{
*/		//		int j;

		for(i=0;i<n;i++)
		{
			scanf("%s",in);
			/*			if(f<r&&r!=N-1)
						{

						printf("check1:%d %d\n",f,r);
						strcpy(c[r],in);
						printf("%d %d\n",f,r);
			//				printf("\t%s",c[r]);
			r++;
			e=0;
			}
			else
			{
			 */				if(r==N-1)
			{
				if(f==0)
					f++;
				r=0;
				//	printf("check2:%d %d\n",f,r);
				strcpy(c[r],in);
				//	printf("%d %d\n",f,r);
				e=0;
			}
			//			}


			else
				if(f>r)
				{

					        if(f-r==1)
						{
							if(f==N-1)
								f=0;
							else f++;
						}
						r++;
					//	printf("check3:%d %d\n",f,r);
					strcpy(c[r],in);
					//	printf("%d %d\n",f,r);
					e=0;
				}	


				else if(e==1)
					{
						f=r=e=0;
						//	printf("check4:%d %d\n",f,r);
						strcpy(c[0],in);
						//	printf("%d %d\n",f,r);
					}
				else
					{
							r++;
						//	printf("check5:%d %d\n",f,r);
						strcpy(c[r],in);
						//	printf("%d %d\n",f,r);
						e=0;
					}
		
   //                                    printf("%d %d\n",f,r);
	//}
	//return;
}
}
void rem(int n)
{	int i;
	//	printf("\n remove\n");
	//	i=c[f];

		/*		if(f<=r&(r-f+1<=n))
				{
				r=r-n;
				if(r<f)
				{
				f++;
				e=1;
				}
				}
				else
				{
		 */			for(i=0;i<n&&e!=1;i++)
		{
			if(f<r)
			{
				f++;
			}
			else if (f==r)
			{
				f=r=-1;
				e=1;
			}
			else
			{
				if(f>r)
				{
					if(f==N-1)
						f=0;
					else 	
						f++;
				}


			//		printf("\n%d",f);
		}
//	printf("%d %d\n",f,r);
		
	//	}
	//	return ;

}
}
void list()
{
	//	printf("\nr=%df=%d\n",r,f);
	//	printf("\nf=%s",c[f]);
	//	printf("\nr=%s\n",c[r]);

	int i;
	//	printf("\n list\n");
	//	return ;
	if(e!=1)
	{if(f<=r)
		{
			for(i=f;i<=r;i++)
			{
				printf("%s",c[i]);
				//			printf("\n%d %d %d\n",f,r,i);
				printf("\n");
			}
		}
		/*	else

			if(f==0&&r==0)
			{
			printf("%s",c[f]);
		//		printf("\n%d %d\n",f,r);
		}
		 */	else
		if(f>r)
		{
			for(i=f;i<N;i++)
			{	
				printf("%s\n",c[i]);
				//			printf("\n%d %d %d\n",f,r,i);
			}
			for(i=0;i<r+1;i++)
			{	
				printf("%s\n",c[i]);
				//			printf("\n%d %d %d\n",f,r,i);
			}
		}
	}
	/*	else
		if(f==r)
		{
		printf("%s",c[r]);
		}
		printf("\n");
		return;
	 */
}


int main()
{
	int i;//flag=0;
	//	int N;
	scanf("%d",&N);
	//	char c[N][100];
	int n;
	char opt;
	while(1)
	{
		scanf(" %c",&opt);
		if(opt=='A'||opt=='R')
			scanf("%d",&n);
		if(opt=='A')
		{
			
			append(n);
		}
		else if(opt=='R')
			{
				rem(n);
			}
		else if(opt=='L')
			{
				list();
			}
		else
			{
				break;
			}
		//		scanf("%s",&opt);
	}


	return 0;
}
