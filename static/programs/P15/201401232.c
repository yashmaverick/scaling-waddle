#include<stdio.h>
int segment[1000000];
int mini(int x,int y)
{
        if(x<y)
                return x;
        else
                return y;
}
int segmentmin(int start,int end,int qstart,int qend,int pointer)
{
        if(qstart<=start && qend>=end)
        {
                return segment[pointer];
        }
        if(end<qstart || start>qend)
                return 1000000000;
        int mid=(start+end)/2;
        return mini(segmentmin(start,mid,qstart,qend,2*pointer+1),segmentmin(mid+1,end,qstart,qend,2*pointer+2));
}
int segmentrange(int *p,int start,int end,int currentindex)
{
        if(start==end)
        {
                segment[currentindex]=p[start];
                return segment[currentindex];
        }
        int mid=(start+end)/2;
        segment[currentindex]=mini(segmentrange(p,start,mid,((2*currentindex)+1)),segmentrange(p,mid+1,end,2*currentindex+2));
        return segment[currentindex];
}
int main()
{
        int test,inputnumber,specifier,i,j,k;
        scanf("%d",&test);
        while(test--)
        {
                scanf("%d %d",&inputnumber,&specifier);
                int dataget[inputnumber];
                for(k=0;k<inputnumber;k++)
                {
                        scanf("%d",&dataget[k]);
                }
                k=segmentrange(dataget,0,inputnumber-1,0);
                for(i=0;i<inputnumber-specifier;i++)
                        printf("%d ",segmentmin(0,inputnumber-1,i,i+specifier-1,0));
                        printf("%d",segmentmin(0,inputnumber-1,i,i+specifier-1,0));
                        printf("\n");
        }
        return 0;
}
