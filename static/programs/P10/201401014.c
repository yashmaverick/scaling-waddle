#include<stdio.h>
#include<string.h>
void append(int val);
void remmove(int val);
void list();
char S[10001][101],ch,input[101];
int n,start,end,empty;
int main()
{
	char c,d;
	int x;
	start=0;
	end=0;
	empty=1;
	scanf("%d",&n);
	if(n==0)
		return 0;
	else
	{
//	scanf("%c",&c);
	while(1)
	{
		scanf("%c",&c);
//		printf("%c ----c main char\n",c);
//		scanf("%c",&d);
//		printf("%c ---d after main\n",d);
		if(c=='A')
		{
			scanf("%d",&x);
//			printf("%d x\n",x);
//			scanf("%c",&d);
//			printf("%c ----x char\n",d);
			append(x);
		}
		else if(c=='R')
		{
			scanf("%d",&x);
//			scanf("%c",&d);
//			printf("%d start %d end\n",start,end);
			remmove(x);
		}
		else if(c=='L')
		{
//			scanf("%c",&d);
//			printf("list called\n");
			list();
		}
		else if(c=='Q')
			break;
		else
			continue;
	}
	return 0;
	}
}
void append(int val)
{
	int i;
	char q;
//	printf("entered append\n");
//	printf("%d start %d end\n",start,end);
	if((n-1-end)>=val && start<end)
	{
//		printf("if\n");
//		printf("%d start %d end\n",start,end);
		for(i=end+1;i<=end+val;i++)
		{
//			printf("about to scan input\n");
			scanf("%s",input);
//			printf("%s",input);
//			printf("string scanned\n");
			strcpy(S[i],input);
			empty=0;
		}
		end=end+val;
	}
	else
	{
//		printf("else\n");
		while(val!=0)
		{
			scanf("%s",input);
//			printf("%s",input);
//			printf("string scanned\n");
	//		printf("\n");
			if(start<end)
			{
				if(end!=n-1)
				{
					strcpy(S[end+1],input);
//					printf("----");
//					printf("%s",S[end+1]);
//					printf(" \n if \n");
					empty=0;
					end++;
				}
				else
				{
					if(start==0)
						start++;
					end=0;
					empty=0;
					strcpy(S[0],input);
//					printf("%s  hey\n",S[0]);
				}
			//	empty=0;
			}
			else if(start>end)
			{
	/*			if(start!=n-1)
					start++;
				else
					start=0;
				strcpy(S[start],input);
	*/	                
				if(start-end>1)
				{	
					end++;
					strcpy(S[end],input);
				}
				else
				{
					if(start!=n-1)
					{
						end++;
						start++;
						strcpy(S[end],input);
					}
					else
					{
						start=0;
						end=n-1;
						strcpy(S[end],input);
					}
				}
				empty=0;
			}
			else
			{
				if(empty==1)
				{
					start=0;
					end=0;
					empty=0;
					strcpy(S[0],input);
//					printf("%s",S[0]);
//					printf("\n");
				}
				else
				{
					if(end!=n-1)
						end++;
					else 
						end=0;
					strcpy(S[end],input);
//					printf("%s",S[end]);
//					printf("\n");
					empty=0;
				}
			}
			val--;
		}
	}
//	scanf("%c",&q);
//	printf("%c ----q append\n",q);
//	printf("%d start %d end\n",start,end);
}
void remmove(int val)
{
//	char w;
	if(empty!=1)
	{
		if(start<end && (end-start+1)>=val)
		{
		//	end=end-val;
			start=start+val;
			if(end<start)
			{
				start=end;
				empty=1;
			}
		}
		else
		{
			while(val--)
			{
				if(start<end)
					start++;
				else if(start>end)
				{
			//		if(end==0)
			//			end=n-1;
			//		else
			//			end--;
					if(start!=n-1)
						start++;
					else
						start=0;
				}
				else
				{
					start=0;
					end=0;
					empty=1;
				}
			}
		}
	}
//	printf(" %d start %d end\n",start,end);
//	scanf("%c",&w);
//	printf("%c ---w",w);
}
void list()
{
	int i;
//	printf("list\n");
//	printf("%d emptyy\n",empty);
//	printf("inside list\n");
	if(empty!=1)
	{
//		printf("%d start %d end\n",start,end);
	//	printf("not empty\n");
		if(start<=end)
		{
			for(i=start;i<end+1;i++)
			{
				printf("%s",S[i]);
				printf("\n");
			}
		}
		else
		{
			for(i=start;i<n;i++)
			{
				printf("%s",S[i]);
				printf("\n");
			}
			for(i=0;i<end+1;i++)
			{
				printf("%s",S[i]);
				printf("\n");
			}
		}
	}
//	printf("%d start %d end\n",start,end);
}		
