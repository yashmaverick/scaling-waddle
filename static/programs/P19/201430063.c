#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct trie
{
	struct trie *children[10];
	int val;
}trie;
int flag=0;
trie* create(trie *head,char ar[])
{flag=0;
int i,j;
int len=strlen(ar);
int a[len];	

if(head==NULL)
	{
		head=(trie*)malloc(sizeof(trie));
		head->val=-1;
		for(i=0;i<10;i++)
			head->children[i]=NULL;
	}


	trie *temp=head;
	for(i=0;i<len;i++)
	{
		if(temp->children[ar[i]-'0']==NULL)
		{
			temp->children[ar[i]-'0']=(trie*)malloc(sizeof(trie));
			temp->children[ar[i]-'0']->val=0;
			temp->children[ar[i]-'0']->val++;
			a[i]=temp->children[ar[i]-'0']->val;
			
        //               printf("%d\n",ar[i]-'0'); 
			for(j=0;j<10;j++)
				temp->children[ar[i]-'0']->children[i]=NULL;
		
                              
}
		else

		{
			//   printf("%d\n",ar[i]-'0');
			temp->children[ar[i]-'0']->val++;
			a[i]=temp->children[ar[i]-'0']->val;
		      
                             }
		temp=temp->children[ar[i]-'0'];

	}


//for(i=0;i<len;i++)	
//printf("array ele %d\n",a[i]);
for(i=0;i<len;i++)	
if(a[i]<=2)
flag=-1;


return head;
}
int main()
{
int t;
scanf("%d",&t);
while(t--)
{

flag=0;
int n,i,j;
	scanf("%d",&n);
	char c[n][12];
	for(i=0;i<n;i++)
		scanf("%s",c[i]);
	trie *temp;
	trie *head=NULL;
	for(i=0;i<n;i++)		
{        head=create(head,c[i]);
if(flag==1)	
break;
}
for(i=0;i<n;i++)
	{	head=create(head,c[i]);
if(flag==0)	
break;
}
int a;
if(flag==0)	
printf("NO\n");
else
printf("YES\n");
}					
return 0;
}










