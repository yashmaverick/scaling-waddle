#include<stdio.h>
#include<string.h>
int main()
{
	int N,start=0,end=-1,r,k,count,size=0,jpo;
	scanf("%d",&N);
	int a,e;
	char s[N][100],ins;
	while(1)
	{
		//char l;
		scanf("%c",&ins);
		scanf("%c",&ins);
		//ins=getchar()
		if(ins=='A')
		{
			scanf("%d",&a);
			while(a--)
			{
			if(size<N)
			{
				end=(end+1)%N;
				size++;
				scanf("%s",s[end]);
			}
			else
			{
				end=(end+1)%N;
				start=(start+1)%N;
				scanf("%s",s[end]);
			}
			}

		}
		else if(ins=='R')
		{
			scanf("%d",&r);
			while(r--)
			{
				if(size==0)
				{
					jpo=0;
				}
				else
				{
					start=(start+1)%N;
					size--;
				}
			}
			//e=start;
			/*while(r--)
			  {
			  s[e%N]='\0';
			  e++;
			  }*/
			//start=e%N;
		}
		else if(ins=='L')
		{
			if(size==0)
			{
				jpo=0;
			}
			else if(start<=end)
			{
				for(e=start;e<=end;e++)
					//while(N--)
				{
					k=e%N;
					printf("%s\n",s[k]);
				}
			}
			else if(end<start)
			{
				for(e=start;e<N;e++)
					printf("%s\n",s[e]);
				for(e=0;e<=end;e++)
					printf("%s\n",s[e]);
			}
		}
		else if(ins=='Q')
		{
			return 0;
		}
		if(start<=end)
			count=end-start+1;
		else if(end<start)
			count=end+N-start+1;
	//	printf("count=%d",count);
	}
return 0;
}
