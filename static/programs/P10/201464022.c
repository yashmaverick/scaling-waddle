#include<stdio.h>
#include<stdlib.h>
typedef struct string
{
	char s[102];
}string;
string *buffer;
int main()
{
	int n,size=0,front=0,i,numop,tempsize;
	char option,dummy;
	scanf("%d",&n);
	scanf("%c",&dummy);
	buffer=malloc(sizeof(string)*n);
	//	scanf("%c",&dummy);
	while(1)
	{
		scanf("%c",&option);
//		printf("option =%c\n",option);
		scanf("%c",&dummy);
		switch(option)
		{
			case('A'):
				{
					scanf("%d",&numop);
				//	if(numop<n)
					//	size=size+numop;
					//else size=n;
				//	if(size>n)
				//		size=n;
				//	size=size%n;
					//if(size>n)
					//	size=n;
					tempsize=numop;
					for(i=(front+size)%n;tempsize>0;i=(i+1)%n,tempsize--)
					{
						scanf("%s",buffer[i].s);
					}
					if(size+numop<=n)
						size=(size+numop);
					else
					{
						//size=n;
						front=(front+size+numop)%n;
						size=n;
					}
				//	else size=n;
				//	if(size>n)
				///		size=n;
				//	if(size+numop>n)
				//		front=(size+numop)%n;
				//	if(size>n)
				//		size=n;
					scanf("%c",&dummy);
//					printf("front=%d\n size=%d\n",front,size);
					break;
				}
			case('L'):
				{
					tempsize=size-1;
					for(i=front;tempsize>=0;i=(i+1)%n,tempsize--)
						printf("%s\n",buffer[i].s);
//					scanf("%c",&dummy);
					break;
				}
			case('R'):
				{
					scanf("%d",&numop);
					//size=size-numop;
					//if(size<0)
					//	size=0;
					//for(i=0;i<numop;i++)
					if(numop!=size)
						front=(front+numop)%n;
					else front=0;
					size=size-numop;
					if(size<0)
						size=0;

					scanf("%c",&dummy);
//					printf("front=%d\nsize=%d\n",front,size);
					break;
				}
			case('Q'):
				{
					free(buffer);
					return 0;
				}

		}
	}
}




