#include <stdio.h>
#include <string.h>
char A[10010][110];
char str[110];
int size_now=0,head=-1,tail=-1;
int buff_size;
void my_str(char *a , char *b)
{
int i=0;
for(;b[i]!='\0';i++)	
	a[i] = b[i];
b[i] = '\0';
return;
}
int main()
{
	int qty;
	char flag[100];
	char x[210];
	scanf("%d", &buff_size);
	int i = 0;
	while(flag[0]!='Q')
	{       
 		scanf("%s", flag);
 		//printf("%s\n",flag );
 		if(flag[0] == 'Q')
 			return 0;

 		if(flag[0] == 'L')
 		{
 			
 			int temp_head = head;
 			int temp_size = size_now;
			while(temp_size--)
			{
				printf("%s\n", A[temp_head]); 
				temp_head=(temp_head+1)%buff_size;
			}

		}

		else if(flag[0] == 'R')
		{
			//printf("__________R\n");
			scanf("%d",&qty);
			while(qty--)
			{
		
			
			if(size_now == 0)
				head = tail;	

			else if(size_now!=0)
			{
			head=(head+1)%buff_size; 
			size_now -= 1;	
			}


			}
			
		}


		else if(flag[0] == 'A')
		{
			//printf("__________A\n");
			scanf("%d",&qty);
			

			for(i=0;i<qty;i++)
			{
			scanf("%s",x);
			

			if(size_now == 0)
			{
			tail=0; 	
			head=0; 
			my_str(A[tail],x); 
			size_now++;
			}

			else if(size_now!=0)
			{
			tail=(tail+1)%buff_size; 
			my_str(A[tail],x);
			
			if(size_now<buff_size) 
				size_now++;
        	else if(size_now==buff_size) 
        		head=(head+1)%buff_size;

			}
	
		}


		}

	}
        return 0;
}










