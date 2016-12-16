//Program to implement a buffer to store a max of 10000 strings of max length 100 in queue like configuration
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int start,end,current;
	char opcode,d;
	int n,i,k,size,len=0;
	start=end=current=0;
	char buffer[10000][100];
	scanf("%d",&size);
	/*char** buffer=(char**)malloc(size*sizeof(char*));
	for(i=0;i<size;i++)
		buffer[i]=(char*)malloc(100*sizeof(char));*/
	while(1)
	{
		scanf("%c",&opcode);
		//if(opcode=='\n')scanf("%c",&opcode);
		//scanf("%c%c",&d,&opcode);
		//printf("%c %c",d,opcode);
		switch(opcode)
		{
			case 'A'://Operation to append 'n' new strings at end of buffer
			{
				scanf("%d",&n);
				if(n>=size)len=size;
				else{
					if(len+n>size)len=size;
					else{len+=n;}
				}
				for(i=0;i<n;i++)
				{
					scanf("%s",buffer[current]);
					current++;
					if(current>size-1)
						current=0;
				}
				if(current!=0)end=current-1;
				else{end=size-1;}
				if(len==size)start=(end+1);
				//if(end==start)start=(start+1)%size;
				
				//printf("\nStart-%d End-%d Current-%d Length-%d\n",start,end,current,len);
				break;
			}
			case 'R'://Operation to remove 'n' strings from beginning of buffer
			{
				scanf("%d",&n);
				if(len>=n)len-=n;
				else{
					len=0;
				}
				start=(start+n)%size;
				if(len==0||len==1)end=start;
				if(len==0)current=start;
				if(len>0)current=(end+1)%size;
				//printf("\nStart-%d End-%d Current-%d Length-%d\n",start,end,current,len);
				break;
			}
			case 'L'://Operation to print the buffer
			{
				if(start!=current){
					if(start<end){
						for(i=start;i<=end;i++)
							printf("%s\n",buffer[i]);
					}
					else if(start==end){
						printf("%s\n",buffer[end]);
					}
					else{
						for(i=start;i<size;i++)
							printf("%s\n",buffer[i]);
						for (i=0;i<=end;i++)
							printf("%s\n",buffer[i]);
					}
					//printf("\nStart-%d End-%d Current-%d Length-%d\n",start,end,current,len);
				}
				else{
					if(start>end){
						for(i=start;i<size;i++)
							printf("%s\n",buffer[i]);
						for (i=0;i<=end;i++)
							printf("%s\n",buffer[i]);
					}
					//printf("\nStart-%d End-%d Current-%d Length-%d\n",start,end,current,len);
				}
				break;
			}
			case 'Q'://Quit the program
			{
				//printf("\nStart-%d End-%d Current-%d Length-%d\n",start,end,current,len);
				return 0;
			}
		}
	}
	return 0;
}