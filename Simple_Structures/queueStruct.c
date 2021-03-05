#ifndef queue_c
#define queue_c

#include <stdio.h>
#include <stdlib.h>

#include "count.c"
typedef struct queue
{
    int value;
    struct queue *next;
} queue;

void insertQueue(queue **qe, count *c)
{
    int value;
    int ex;
    queue *new, *aux;
    new = (queue *) malloc (sizeof (queue) * 1);    
    
    printf("\nValue: ");
    scanf("%d",&value);

    if (new == NULL)
        printf("Memory allocation error");
    else
    {
        new->value = value;
        new->next = NULL;

        if ((*qe) == NULL)
            (*qe) = new;
        else
        {
            aux = (*qe);
            while (aux->next != NULL)
                aux = aux->next;
            aux->next = new;
        }
        c->qeCount++;
    }

    printf("\nType to exit: ");
    scanf("%d",&ex);      
}

void alterQueue(queue **qe, count *c)
{
    int pos, i;
    int ex;

    printf("\nSet position: ");
    scanf("%d", &pos);

    if (pos > c->qeCount - 1)
        printf("Unvalid position");
    else
    {
        queue *aux;
        aux = (*qe);

        for (i = 0; i < pos; i++)
            aux = aux->next;
        printf("New value: ");
        scanf("%d",&aux->value);
    }
    printf("\nType to exit: ");
    scanf("%d",&ex);     

}

queue removeQueue(queue **qe, count *c)
{
    queue *aux, temp, copy;
    int value;
    int ex;

    if ((*qe) == NULL)
    {
        char ex;
        printf("Empty queue\nType to exit: ");
        scanf("%c", &ex);

        copy = **qe;
        return copy;
    }
    else if ((*qe)->next == NULL)
    {
        copy = **qe;
        value = (*qe)->value;
        free(*qe);
        (*qe) = NULL;

        return copy;
    }
    else
    {
        aux = *qe;
        (*qe) = (*qe)->next;
        free(aux);
        
    }
    c->qeCount--;
    
    printf("\nType to exit: ");
    scanf("%d",&ex);  
}

void printQueue(queue *qe)
{
    int ex;
    if (qe == NULL)
        printf("Empty queue");
    else
    {
        queue *aux;
        aux = qe;

        printf("\nPrinted queue: ");        
        do
        {
            printf("%d\t",aux->value);
            aux = aux->next;

        } while (aux != NULL);
    }

    printf("\nType to exit: ");
    scanf("%d",&ex);     
}



#endif