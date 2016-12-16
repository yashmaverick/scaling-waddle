#include<stdio.h>
#include<stdlib.h>

#define gu getchar_unlocked 
#define pu putchar_unlocked
#define lli long long int
#define ulli unsigned long long int
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define test() int t; din(t); while(t--)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
#define loop(n) for(i=0;i<n;i++)

int find(int *pre,int num1,int num2,int *inorder)
  {
  int flag_root,flag_num1,flag_num2;
  flag_root=flag_num1=flag_num2=0;
  int i=0;
  int target=pre[0];
  if(num1==target || num2==target)
  return 0;
  while(!flag_root)
  {
  if(inorder[i]==target)
  flag_root=1;
  else if(inorder[i]==num1)
  flag_num1=1;
  else if(inorder[i]==num2)
  flag_num2=1;
  if(flag_num1==1 && flag_num2==1)
      return -1;

  i++;
  }

  if(flag_num1 && flag_num2)
  return -1;
  if(!flag_num1 && !flag_num2)
  return i;
  else
  return 0;
  }


int main()
{
    int n,inorder[1000005],preorder[1000005],i;
    din(n);
    loop(n)
        din(preorder[i]);
    loop(n)
        din(inorder[i]);
    test()
    {
        int num1,num2;
        din(num1);
        din(num2);
        if(num1==num2)
        {
            dout(num1);
            continue;
        }
        int breakflag=1;
        int *x=preorder;
        while(breakflag)
        {
            int result=find(x,num1,num2,inorder);
           /* int flag_root,flag_num1,flag_num2;
            flag_root=flag_num1=flag_num2=0;
            int i=0;
            int target=x[0];
            if(num1==target || num2==target)
                result=0;
            else
            {
                while(!flag_root)
                {
                    if(inorder[i]==target)
                        flag_root=1;
                    else if(inorder[i]==num1)
                        flag_num1=1;
                    else if(inorder[i]==num2)
                        flag_num2=1;
                    i++;
                }

                if(flag_num1 && flag_num2)
                    result=-1;
                if(!flag_num1 && !flag_num2)
                    result=i;
                else
                    result=0;
            }*/
            if(result==0)
            {
                dout(x[0]);
                break;
            }
            if(result<0)
                x+=1;
            if(result>0)
            {
                //int count=0;



                x=x+result-1;
            }
        }
    }
    return 0;
}
