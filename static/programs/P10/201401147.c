#include<stdio.h>
int main()
{
	int N,num,i,start=-1,end=-1,temp=0,count=0;
	char ch;
	scanf("%d",&N);
	char a[10000][100];
RETURN:
	while(1){//printf("Waiting for choice.........\n");
		//printf("right now the end is at %d and start is at %d\n",end,start);
		scanf("%c",&ch);
		switch(ch){
			case 'A':
				scanf("%d",&num);
				count=count + num;
				if(count>N)
					count=N;
				for(i=0;i<num;i++){
					if(start==-1 && end!=-1)
					{start++;}
					end++;
					if(end>N-1)
						end=0;
					if(start==end)
					{start++;}
					if(start>N-1)
						start=0;	
					scanf("%s",a[end]);

				}
				break;
			case 'R':
				scanf("%d",&num);
				if(count==num){
					count=0;
					start=-1;
					end=-1;
					goto RETURN;
				}
				for(i=0;i!=num;i++){
					start++;
					//printf("start at %d\n",start);
					if(start>N-1)
						start=0;
				}
				count=count-num;
				break;
			case 'L':

				temp=end;
				if(start==temp && start==-1)
					goto RETURN;

				if(start>temp){
					for(i=start;i<N;i++)
						printf("%s\n",a[i]);
					for(i=0;i<=temp;i++)
						printf("%s\n",a[i]);
				}
				else{

					for(i=start;i<=temp;i++)
						printf("%s\n",a[i]);
				}
				break;
			case 'Q':
				goto EXIT;

		}
		if(start==-1 && end!=-1)
		{start++;}//printf("increasing start since start==-1 and end!=-1\n");}
}
EXIT:
return 0;
}

