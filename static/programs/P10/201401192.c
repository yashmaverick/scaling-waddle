#include<stdio.h>
#include<string.h>
int main()
{
    int start, end, size, nofLines, i;
    char buf[10000][101], ch, line[101];
    start = end = -1;
    scanf("%d", &size);
    do
    {
        scanf("%c", &ch);
        switch(ch)
        {
            case 'A':
                scanf("%d", &nofLines);
                while(nofLines--)
                {
                    scanf("%s", line);
                    if(size)
                    {
                        if((end+1)%size == start)
                        {
                            start = (start+1)%size;
                            end = (end+1)%size;
                        }
                        else
                        {
                            if(start == -1 && end == -1)
                            {
                                start = 0;
                            }
                            end = (end+1)%size;
                        }
                        strcpy(buf[end], line);
                    }
//                    printf("start is %d and end is %d\n", start, end);
                }
                break;
            case 'R':
                //                printf("start is %d and end is %d\n", start, end);
                scanf("%d", &nofLines);
                while(nofLines--)
                {
                    if(size)
                    {
                        start = (start+1)%size;
                        if(start == (end+1)%size)
                        {
                            start = end = -1;
                        }
                    }
                }
                //                printf("start is %d and end is %d\n", start, end);
                break;
            case 'L':
                if(start != -1 || end != -1)
                {
                    for(i = start; i != end; i = (i+1)%size)
                    {
                        printf("%s\n", buf[i]);
                    }
                    printf("%s\n", buf[i]);
                }
        }
    }while(ch != 'Q');
    return 0;
}
