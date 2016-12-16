#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef long long int ll;
typedef struct node
{ 
        char val;
        struct node* arr[10];
        int end;
        
}node;
node*root[10];
int flag;

node* make_node(char x)
{
        node*ptr=malloc(sizeof(node));
        ptr->val=x;
        ptr->end=0;
        return ptr;
}
int YES, NO;
void check(char str[])
{
        node*newnode=make_node(str[0]);
        int i;
        if (root[str[0]-'0']==NULL)
        {
                //printf("Working on root\n");
                node*newnode=make_node(str[0]);
                root[str[0]-'0']=newnode;
                i=1;
                node*ptr=newnode;

                //printf("Putting in %c \n", ptr->val);
                while(str[i]!='\0')
                {
                        node*temp=make_node(str[i]);
                        ptr->arr[str[i]-'0']=temp;
                        ptr=ptr->arr[str[i]-'0'];
                       // printf("Putting in %c \n", ptr->val);        
                        ++i;
                }
                ptr->end=1;
               // printf("Last char is %c and end val is %d\n", ptr->val, ptr->end);
        }           
        else
        { 
               // printf("Found trail\n");
                i=0;
                node*ptr=root[str[0]-'0'];
                node*temp=ptr;
                //ptr=ptr->arr[str[1]-'0'];
                //while(ptr!=NULL && str[i]!='\0')       //if trail exists in the trie
                while(ptr!=NULL && str[i]!='\0')
                {
                        if(ptr->val==str[i])
                        {
                                temp=ptr;
                               // printf("Going down %c\n", ptr->val);
                                if(ptr->end==1)
                                        break;
                                if(str[i+1]!='\0')
                                {
                                        ptr=ptr->arr[str[i+1]-'0'];
                                        i++;
                                }
                                else
                                {
                                        i++;
                                        break;
                                }
                        }
                        else
                                break;

                }

                //temp->end=1;
                //printf("Value of temp is %c and temp->end= %d\n",temp->val, temp->end); 
                if(str[i]!='\0' && temp->end==1)   //if str hasnt ended but trail has ended, trail is prefix
                        flag=1;
                else if(str[i]=='\0')
                {
                        temp->end=1;
                        flag=1;
                }

                ptr=temp;
               // printf("i value is %d\n", i);
                //i++;
                while(str[i]!='\0')
                {
                        node*newnode=make_node(str[i]);
                        ptr->arr[str[i]-'0']=newnode;
                        ptr=newnode;
                 //       printf("Entering new node %c\n", ptr->val);
                        ++i;
                }
                ptr->end=1; 
        }        
}

int main()
{

        ll T,N;
        ll i;
        char arr[11];
        scanf("%lld", &T);
        while(T--)
        {
                flag=0;
                scanf("%lld", &N);
                for(i=0; i<N; i++)
                {
                        scanf("%s", arr);
                        if(flag==0)
                                 check(arr);

                }
                if(flag==1)
                        printf("NO\n");
                else
                        printf("YES\n");
               
                for(i=0; i<10; i++)
                        root[i]=NULL;
        }
        return 0;
                

}
//typedef long long int ll;
//int visited[10];
/*int main()
{
        ll T, N, i;
        char arr[11];
        scanf("%lld", &T);
        while(T--)
        {
                flag=0;
                memset(visited, 0, sizeof(visited));
                for(i=0; i<10; i++)
                        printf("%d ", visited[i]);
                int flag=0;
                scanf("%lld", &N);
                for(i=0; i<N; i++)
                {
                        scanf("%s", arr);
                        if(visited[(int)arr[0]]==0 && flag==0)
                                visited[(int)arr[0]]=1;
                        else
                                flag=1;
                }
                if(flag==1)
                        printf("NO\n");
                else
                        printf("YES\n");
        }
        return 0;
}*/
                
        
