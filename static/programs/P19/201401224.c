#include<stdio.h>
#include<stdlib.h>
struct trie{
	int val;
	struct trie* a[10];
}trie;
int main()
{
	int t,i,f,j,k,n,p,q,z=0,s,ins;
	char c;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		struct trie* head;
		struct trie* temp;
		scanf("%d",&n);
		s=10;
		head=(struct trie *)malloc(sizeof(struct trie));
		for(q=0;q<10;q++)
			head->a[q]=NULL;
		if(n!=0)
		{
			for(j=0;j<n;j++)
			{
				temp=head;
				ins=0,z=0;
				char b[11];
				scanf("%s",b);
				k=0;
				while(b[k]!='\0')
				{
					if(s!=2)
					{
						for(p=0;(p<10)&&(z==1)&&(ins==0);p++)
						{
							if(head->a[p]!=NULL)
								break;
						}
						if(p==10)
							break;	
						if(z==0)
							z=1;
						if(head->a[b[k]-48]==NULL)
						{
							head->a[b[k]-48]=(struct trie *)malloc(sizeof(struct trie));
							head=head->a[b[k]-48];
							head->val=b[k]-48;
							ins=1;
							for(q=0;q<10;q++)
								head->a[q]=NULL;
						}
						else
							head=head->a[b[k]-48];
					}
					k++;
				}
				if(p==10||ins==0)
					s=2;
				head=temp;
			}
			if(s==2)
				printf("NO\n");
			else
				printf("YES\n");
		}
		else
			printf("YES\n");
	}
	return 0;
}
