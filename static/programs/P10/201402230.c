#include<stdio.h>
void append(char s[],int N);
void removes(int N);
void print(int N);
int front=0,rear=-1;
char a[10010][110];
int main()
{ char c,s[100];
	int n,i,N;
	scanf("%d",&N);
	while(1)
	{ scanf("%c",&c);
		if(c=='A')
		{  scanf("%d",&n);
			for(i=0;i<n;i++)
			{  scanf("%s",s);
				append(s,N);
			}
		}
		if(c=='R')
		{ scanf("%d",&n);
			for(i=0;i<n;i++)
			{ removes(N);
			}
		}
		if(c=='L')
			print(N);
		if(c=='Q')
			break;
	}
	return 0;
}
void print(int N)
{ // printf("print\n");
	int i=front,j;
	//	char c;
	if(front==0 && rear==-1)
		return;
	else if(front==rear && a[front-1][0]=='*')
	{
		front=0;
		rear=-1;
		return;
	}	
	else if(front<rear)
	{ 
		i=front;
		//		printf("START:kjf\n");
		while(i<rear && a[i][0]!='*')
		{ //printf("%s\n",a[i]);
			/*for(j=0;a[i][j]!='\0';j++)
			  { printf("%c",a[i][j]);
			  }*/
			printf("%s\n",a[i]);
			//printf("\n");
			i++;
			//   printf("front:%d rear:%d\n",front,rear);
		}
		//printf("kjf\n");
	}
	else if(front>rear)
	{ //printf("print1\n");
		i=front;

		while(i<N)
		{ /*for(j=0;a[i][j]!='\0';j++)
			{ printf("%c",a[i][j]);
			}
			printf("\n");*/
			printf("%s\n",a[i]);
			i++;
			//          printf("front:%d rear:%d\n",front,rear);	
		}

		i=0;
		while(i<=rear && a[i][0]!='*')
		{ /*for(j=0;a[i][j]!='\0';j++)
			{ printf("%c",a[i][j]);
			}
			printf("\n");*/
			printf("%s\n",a[i]);
			i++;
		}

	}
	else if(front==rear && a[front][0]!='*')
	{ i=front;
		while(i<N)
		{ /*for(j=0;a[i][j]!='\0';j++)
			{ printf("%c",a[i][j]);
			}
			printf("\n");*/
			printf("%s\n",a[i]);

			i++;
		}
		i=0;
		while(i<rear)
		{ /*for(j=0;a[i][j]!='\0';j++)
			{ printf("%c",a[i][j]);
			}
			printf("\n");*/
                        printf("%s\n",a[i]);
			i++;
		}
	}
}
void append(char s[],int N)
{ //printf("append\n");
	int j;
	if(rear==N-1)
	{ //rear=0;
		if(rear==front)
			front=0;
		for(j=0;s[j]!='\0';j++)
		{ a[rear][j]=s[j];
		}
		//	rear++;
		a[rear][j]='\0';
		//printf("front:%d rear:%d\n",front,rear);
		rear=0;
	}
	else if(rear==-1)
	{ front=0;
		rear=0;
		for(j=0;s[j]!='\0';j++)
		{ a[rear][j]=s[j];
		}
		a[rear][j]='\0';
		//printf("front:%d rear:%d\n",front,rear);	
		rear++;
	}
	else if(front<rear && rear<N-1)
	{ for(j=0;s[j]!='\0';j++)
		{ a[rear][j]=s[j];
		}
		a[rear][j]='\0';
		//printf("front:%d rear:%d\n",front,rear);
		rear++;
	}
	else if(front==rear)
	{ front++;
		if(front==N)
		{ front=0;
		}
		for(j=0;s[j]!='\0';j++)
		{ a[rear][j]=s[j];
		}
		a[rear][j]='\0';
		//printf("front=%d rear=%d\n",front,rear);
		rear++;
	}
	else if(rear<front)
	{ 

		for(j=0;s[j]!='\0';j++)
		{ a[rear][j]=s[j];
		}
		a[rear][j]='\0';
		//printf("front:%d rear:%d\n",front,rear);
		rear++;


	}
	//if(front==N    
}
void removes(int N)
{ //printf("remove\n");
	if(a[front][0]=='*')
	{ front=0;
		rear=0;
		return;
	}
	else
	{ a[front][0]='*';
		front+=1;
		if(front==N)
			front=0;
	}
	if(front==rear && a[front][0]=='*')
	{
		front=0;
		rear=-1;
	}
	//printf("front:%d rear:%d\n",front,rear);

}
