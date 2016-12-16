// #Authored : Jaipal Singh Goud
// Part of : DS - Assignment
// Date : 28/2/2015
// Sem I-II
// Implementation with 2-D wordsay. :)


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

void append_list(int n);
void print_list();
void remove_items(int n);
void create_list();

int head , current , pointer;
int len , n;
char words[10101][101];                               // 2 - D wordsay to save the words . 10101 Words max and each of 100 characters

int main()
{	
    int i,j,k;
    int pee;
    char choice;

    current  =  head  =  pointer  =  0;
    scanf("%d",&len);
    scanf("%s",&choice);

    if(choice != 'L' || choice != 'Q')
        scanf("%d",&n);
    while(choice != 'Q')
    {
        switch(choice)                           // Beautiful Switch Statement
        {
            case 'A' : append_list(n);
                       break;
            case 'R' : remove_items(n);
                       break;
            case 'L' : print_list();
                       break;
            case 'Q' : pee  =  1;
                       return 0;
                       break;
            default : ;
        }
        if(pee == 1)                        // Pee is the control variable to quit when user inputs Q as his choice
            break;
        scanf("%s",&choice);
        if (choice != 'L' && choice != 'Q' )
            scanf("%d",&n);
    }
    return 0;
}

void append_list(int n)                     // Add New elements to the list
{
    int i,temp;
    i = 0;
    while( i<n )
    {
        if(pointer >= len)
            head++;

        if(pointer < len)
            pointer++;

        scanf("%s",words[current]);
        current +=1;
        current %= len;
        head = head%len;
        i++;
    }
    return;
}

void remove_items(int n)
{
    int i,temp;
    i = 0;
    while( i<n )
    {
        i++;
        head++;
        head = head%len;
        pointer--;
        pointer = pointer%len;
    }
    return ;
}

void print_list()
{
    int i,temp;
    i = 0;
    if(current>head)                                  // If the current position where elements are to be added is ahead of head.
        for(i=head ; i<current ; i++)
            printf("%s\n",words[i]);

    else if(pointer != 0)                             // If The head is ahead of the current position or at the current position and the pointer in not Zero
    {
        for(i=head ; i<len ; i++)                     // Prints from head to the end of the list (len)
            printf("%s\n",words[i]);            

        for(i=0; i<current ; i++)                     // Prints from the initial position to the current adder variable
            printf("%s\n",words[i]);
    }// Is this a right approach?
    return;
}	
