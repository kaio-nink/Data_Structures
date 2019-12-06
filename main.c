#include <stdio.h>
#include <stdlib.h>

//Include strucutures
#include "stackStruct.c"
#include "queueStruct.c"
#include "count.c"


//Methods initialization
void mainmenu(count *c, stack *st, queue *qeIni);
void stackMenu(stack *ststIni, count *c, int input);
void queueMenu(queue *qe,count *c, int input);



int main()
{
    count c;
    
    initializeCounts(&c);
    
    stack *stIni;
    if (stIni != NULL)
        stIni = NULL;

    queue *qeIni;
    if (qeIni != NULL)
        qeIni = NULL;

    mainmenu(&c,stIni,qeIni);

    return 1;
}


void mainmenu(count *c, stack *stIni, queue *qeIni)
{
    int input = 0;

    
    do
    {
        system("@cls||clear");    
        printf("------------Data Structures Menu------------\n");
        printf("1 - Stack\n2 - Queue\n3 - Singly Linked List\n4 - Doubly Linked List\n5 - Circular Linked List\n");
        printf("0 - Exit\n");

        scanf("%d",&input);

        switch (input)
        {
            case 1: 
                stackMenu(stIni, c, input); break;
            case 2:
                queueMenu(qeIni,c, input); break;
            case 3: 
                break;
            case 4: 
                break;
            case 5: 
                break;
            case 0:
                printf("Succesfully closed\n"); break;
            default: break;
        }

    } while (input != 0);

}

void stackMenu(stack *stIni, count *c, int input)
{
    stack *st;
    st = stIni;
    do
    {
        system("@cls||clear");
        printf("------------Stack Structure Menu------------\n");
        printf("1 - Insert value\n2 - Alter value\n3 - Remove last value\n4 - Print stack\n0 - Back\n");

        scanf("%d",&input);
        switch (input)
        {
            case 1: 
                insertStack(&st, c); break;
            case 2: 
                alterStack(st, c); break;
            case 3: 
                removeStack(&st, c); break;
            case 4: 
                printStack(st); break;
            default: break;
        }        
    } while (input != 0);

}

void queueMenu(queue *qe, count *c, int input)
{

    do
    {
        system("@cls||clear");
        printf("------------Stack Structure Menu------------\n");
        printf("1 - Insert value\n2 - Alter value\n3 - Remove first value\n4 - Print stack\n0 - Back\n");

        scanf("%d",&input);
        switch (input)
        {
            case 1: 
                insertQueue(&qe, c); break;
            case 2: 
                alterQueue(&qe, c); break;
            case 3: 
                removeQueue(&qe, c); break;
            case 4: 
                printQueue(qe); break;
            default: break;
        }        
    } while (input != 0);

}