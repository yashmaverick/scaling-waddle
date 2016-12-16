#include<stdio.h>
long long int n;
/*int area()
  {
  int ar=0;
  if(count==-1)
  {
  ar = (i)*top;
  }
  else if(i==n)
  {
  l = stack[count] - stack[count-1] -1;
  r=0;
  ar=top*(l+r);
  }
  else
  {
  l = stack[count] - stack[count-1]-1;
  r = i - stack[count];
  ar = (l+r)*fences[stack[count]];

  }
  return ar;
  }*/
int main()
{
        scanf("%lld",&n);
        while(n)
        {
                long long int fences[100001]; 
                long long int stack[100001];
                long long int i,j,k;
                long long int l=0, r=0;
                long long int top, count=-1;
                for(i=0;i<n;i++)
                {
                        scanf("%lld",&fences[i]);
                }
                long long int max=0;
                long long int ans=0;
                for(i=0;i<n;)
                {
                        if(count!=-1)
                        {
                                if(fences[i] >= top)
                                {
                                        count++;
                                        stack[count]=i;
                                        top=fences[stack[count]];
                                        i++;
                                }
                                else 
                                {
                                        long long int area;
                                        top = fences[stack[count]];
                                        count--;
                                        if(count==-1)
                                                area = top*i;
                                        else
                                        {
                                                area = top*(i-stack[count]-1);
                                                top = fences[stack[count]];
                                        }
                                        //                                      printf("area=%d\n",ans);
                                        if(area>max)
                                                max=area;
                                        //count--;
                                }
                        }
                        else
                        {
                                count++;
                                stack[count]=i;
                                top=fences[stack[count]];
                                i++;
                        }
                }
                while(count!=-1)
                {
                        long long int area;
                        top = fences[stack[count]];
                        count--;
                        if(count==-1)
                                area = top*i;
                        else
                                area = top*(i-stack[count]-1);
                        //                                      printf("area=%d\n",ans);
                        if(area>max)
                                max=area;
                        //count--;
                        //   count--;
                        //  top = fences[stack[count]];
                        // ans=area();
                        // if(ans>max)
                        //       max=ans;
                        //count--;
                }
                printf("%lld\n",max);
                scanf("%lld",&n);
        }

        return 0;
}







