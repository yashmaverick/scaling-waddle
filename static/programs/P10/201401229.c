#include<stdio.h>
#include<stdlib.h>
int main()
{
	char opt;
	int N,i,first,last,n,j;
	first=last=-1;
	char str[101];
	scanf("%d\n",&N);
	//char **buffer=(char**)malloc(N*sizeof(char*));
	char buffer[N][101];
	scanf("%c",&opt);
	//opt = 'A';
//	printf("%c",opt);
	while(opt!='Q'){
		
		//scanf("%c",&opt);
		switch(opt)
		{
			case 'A': //Add n strings
				{
					scanf("%d",&n);
//					printf("%d\t%d\n", first,last);
				for(i=0;i<n;i++)
				{	
					scanf("%s",str);
				/*	if(first==0 && last==0)
					{
						for(j=0;str[j]!='\0';j++)
							buffer[last][j]=str[j];
						last=0;
					}*/

					if(last==N-1 && first == 0) {
					//	buffer[0]=str;
						last=0;
						for(j=0;str[j]!='\0';j++)
							buffer[0][j]=str[j];
						first++;
					
//					printf("%d\t%d\n",first,last);
					}
					else if(last>=first && last<N) 
					{
						if(last==N-1) last=0;
						else 
							last++;
						for(j=0;str[j]!='\0';j++)
						{
							buffer[last][j]=str[j];
//							printf("%c",buffer[last][j]);
						}
//						printf("\n");
						if(first==-1) first=0;
//					
//						printf("%d\t%d\n",first,last);
					}
					else if(last==first-1)
					{
						if(last==N-1) last=0;
						else	last++;
						for(j=0;str[j]!='\0';j++)
							buffer[first][j]=str[j];
					//	printf("%d\t%d\n",first,last);
						if(first==N-1)
							first=0;
						else
							first++;
					
//					printf("%d\t%d\n",first,last);
					}
					else if(last<first) {
						//buffer[last++]=str;
						if(last==N-1) last=0;
						else	last++;
						for(j=0;str[j]!='\0';j++)
							buffer[last][j]=str[j];
					
//					printf("%d\t%d\n",first,last);
				}
				}
//				printf("%d\t%d\n",first,last);
				break;
				}
			case 'R': //Remove n strings
				{
//					printf("Remove");
					scanf("%d",&n);
				//	if(first!=-1)
					{
				for(i=0;i<n;i++)
				{
					if(first==-1) break;
					//Remove(&first,last);
					{
						for(j=0;buffer[first][j]!='\0';j++)
						{		buffer[first][j]='\0';
		//					printf("%c", buffer[first][j]);
						}
						if(first==last) {first=-1; last=-1;}
						//if(first==0 && last !=0);
						else if(first==N-1) first=0;
						//else if(first==last) first=last=-1;
						else if(first <last) first++;
//						else if(first=last-1) first=last=0;
					}
					if(first==-1) break;
				}
					}
//				printf("%d\t%d\n",first,last);
				break;
				}
			case 'L': //Listing all strings
				if(first==-1)break;
					if(first<=last)
					{
						for(i=first;i<=last;i++)
						{
							for(j=0;buffer[i][j]!='\0';j++)
								printf("%c",buffer[i][j]);
							printf("\n");
						}
					}
					else
					{
						for(i=first;i<N;i++)
						{//	printf("%s\n",buffer[i]);
							for(j=0;buffer[i][j]!='\0';j++)
								printf("%c",buffer[i][j]);
							printf("\n");
						}
						for(i=0;i<=last;i++)
						{//	printf("%s\n",buffer[i]);
							for(j=0;buffer[i][j]!='\0';j++)
								printf("%c",buffer[i][j]);
							printf("\n");
						}
					}
					break;
			}
		opt=getchar();
//		scanf("%c",&opt);
//		printf("%c\n", opt);
		}
	return 0;
}





