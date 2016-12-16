#include<stdio.h>
#include<stdlib.h>

char B[100];
int A1[100];
int k;
int flag=0;
struct trie{
	int d;
	struct trie * A[10];
};
typedef struct trie ELEMENT;

void prin(ELEMENT * temp,int level)
{
	int i;
	for(i=0;i<10;i++)
		if(temp->A[i]!=NULL)
		{
			printf("%d l=%d\n",i,level);
			prin(temp->A[i],level+1);
		}


}

int main()
{
	int test,q;
	scanf("%d",&test);
	for(q=0;q<test;q++)
	{
		flag=0;
		int number,i;
		//	printf("Enter number of elements\n");
		scanf("%d",&number);
		ELEMENT *root;
		root=(ELEMENT *)(malloc(sizeof(ELEMENT)));
		for(i=0;i<10;i++)
			root->A[i]=NULL;
		root->d=-1;
		for(i=0;i<number;i++)
		{

			
			int value;
			//	printf("enter the element\n");
			scanf("%s",B);
			int j;
			int count=0;
			for(j=0;B[j]!='\0';j++)
			{
				count++;
			}

			for(j=0;j<count;j++)
			{
				A1[j]=B[j]-'0';
			}
			
                        

			k=-1;


			//		printf("%d\n",k);

			ELEMENT *temp;
			temp=root;
			while(1)
			{
				k=k+1;
				if(k==count)
				{
					temp->d=0;
					break;
				}


				if(temp->A[A1[k]]==NULL)
				{       
					//		printf("1");
					temp->A[A1[k]]=(ELEMENT *)(malloc(sizeof(ELEMENT)));
					temp->A[A1[k]]->d=-1;

				}
				else if(k==count-1 && temp->A[A1[k]]!=NULL)
					flag=1;

				if(temp->A[A1[k]]->d==0)
					flag=1;


				temp->A[A1[k]]->d=-1;
				temp=temp->A[A1[k]];

			}




		}

	//	prin(root,0);      
		if(flag==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;

}
