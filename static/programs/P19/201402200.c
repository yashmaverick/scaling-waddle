#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int check=0;
struct trie_node{
	int flag;
	struct trie_node *arr[10];
};
struct trie_head{
	struct trie_node *head;
};
struct trie_node *newnode(){
    	struct trie_node *node=NULL;
	node=(struct trie_node*)malloc(sizeof(struct trie_node));
	if(node!=NULL)
	{
//	node->flag=0;printf("inside!!\n");
	int c;
	for(c=0 ; c<10 ; c++)
	 {
		node->arr[c]=NULL;
	 } 
	}
	return node;
}
void insert(struct trie_head *tr_head , char s[])
{
	int digits,len,count=0,val;
	len=strlen(s);
	struct trie_node* tnode;
	    tnode=tr_head->head;
	for(digits=0 ; digits<len ; digits++)
	{
	    	val=((int)s[digits]-(int)'0');
	    	if(tnode->arr[val]==NULL)
		{	
		    
		    count++;
//		    printf("%c==\n",s[digits]);
		    tnode->arr[val]=newnode();
		}
		
		if(tnode->flag==1)
		{
		    check=1;
		} 
		
	    //if(tnode->arr[s[digits]]!=NULL)
		tnode=tnode->arr[val];
	}
//	printf("%d===",count);
	if(count==0 )
	{
	    	   check=1;
	}
	tnode->flag=1;
}
void initalize(struct trie_head *t_h)
{
t_h->head=newnode();
}
int main()
{
    int c,i,test_cases,count_no;
    scanf("%d",&test_cases);
	struct trie_head t_head; 
    	char no[11];

    while(test_cases--)
    {
	initalize(&t_head);
//	tnode=NULL;
	scanf("%d",&count_no);
	check=0;
	for(i=0 ; i<count_no ; i++)
	{
	scanf("%s",no);
	insert(&t_head,no);
	}
	if(check==0 && count_no>=0)
	    printf("YES\n");
	if(check==1)
	    printf("NO\n");
	//free(t_head);
    }
return 0;
}
