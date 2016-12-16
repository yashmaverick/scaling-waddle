#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct trie
{
	int end;
	struct trie *next[10];
}trie;

trie* initialize()
{
	trie *newtrie;
	newtrie = (trie *)malloc(sizeof(trie));
	newtrie->end = 0;
	int i;
	for(i = 0;i < 10;i++)
		newtrie->next[i] = NULL;
	return newtrie;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		
		trie *head, *tail;
		head = initialize();
		int flag = 1;
		int arr[11] = {0};

		while(n--)
		{
			char s[10];
			scanf("%s",s);
			int i;
			if(flag)
			{
				tail = head;
				for(i = 0;i < strlen(s);i++)
				{
					if(tail->end == 1)
					{
						flag = 0;
						break;
					}
					
					int temp = s[i]-'0';
					if(tail->next[temp] == NULL)
						tail->next[temp] = initialize();
					tail = tail->next[temp];
				}
				if(tail->end == 0)
					tail->end = 1;
				else flag=0;
				for(i = 0;i < 10;i++) 
				{
					if(tail->next[i]) 
					{
						flag = 0;
						break;
					}
				}
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}