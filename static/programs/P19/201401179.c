#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Trie
{
	int no;
	struct Trie *next[11];
}Trie;

Trie *Root[11];
Trie *head;
int main()
{
	int Test,m,n;
	scanf("%d",&Test);	

	while(Test-- > 0)
	{
		int N,prefix;
		scanf("%d",&N);
		prefix=0;
		for(m=0;m<10;m++)
			Root[m]=NULL;

		while(N-- >0)
		{	
			char Temp[11];
			int i,Len,count=0,flag=1,j,vikas=1;
			scanf("%s",Temp);
			Len=strlen(Temp);
			if(prefix==0)
			{
				head=Root[Temp[0]-'0'];
				for(i=0;i<Len;i++)
				{
					if(i==0 && Root[Temp[0]-'0']==NULL)
					{
						Root[Temp[0]-'0']=(Trie*)malloc(sizeof(Trie));
						Root[Temp[0]-'0']->no=Temp[0]-'0';
						head=Root[Temp[0]-'0'];
						flag=1;
					}
					else if(i==0 && Root[Temp[0]-'0']!=NULL)
							flag=0;

					if(i!=0)
					{
						if(head->next[Temp[i]-'0']==NULL)
						{
							flag=1;
							head->next[Temp[i]-'0']=(Trie*)malloc(sizeof(Trie));
							head->next[Temp[i]-'0']->no=Temp[i]-'0';
						}

						head=head->next[Temp[i]-'0'];
					}	
					if(flag==0)
						for(j=0;j<10;j++)
						{
							if(head->next[j]==NULL)
									count++;
						}			
						//printf("flag=%d\n",flag);
					if(count==10)
						vikas=0;	
					count=0;
				}
				if(vikas==0 && flag==1)
					prefix=1;
				else if(flag==0 )
					prefix=1;

			}
		}
		//printf("prefix=%d\n",prefix);
		if(prefix==1)
			printf("NO\n");
		else
			printf("YES\n");		
	}
	return 0;
}