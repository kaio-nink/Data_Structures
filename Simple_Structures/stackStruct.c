#ifndef stackStruct_c
#define stackStruct_c

#include <stdio.h>
#include <stdlib.h>

#include "count.c"

typedef struct stack
{
    int value;
    struct stack *next;
} stack;


//-----------Stack functions-----------//

void insertStack(stack **st, count *c)
{
    int value;
    int  ex;
    stack *new, *aux;
    new = (stack *) malloc(sizeof (stack) * 1);

    printf("\nValue: ");
    scanf("%d",&value);
    
    if (new == NULL)
        printf("Insertion error");
    else
    {
        new->value = value;
        new->next = NULL;  
        if (*st == NULL)
        { 
            *st = new;
        }
        else 
        {
            aux = *st;
            while (aux->next != NULL)
                aux = aux->next;
            aux->next = new;
        }  
        c->stCount++;    
    }
    
    printf("\nType to exit: ");
    scanf("%d",&ex);  
}

void alterStack (stack *st, count *c)
{
    int i, pos;
    int ex;
    printf("\nSet position: ");
    scanf("%d", &pos);
    if(pos > c->stCount - 1)
        printf("Unvalid position");
    else
    {
        stack *aux;
        aux = st;
        for (i = 0; i < pos; i++)
            aux = aux->next;
        printf("New value: ");
        scanf("%d",&aux->value);
    }
    printf("\nType to exit: ");
    scanf("%d",&ex);  
}

stack removeStack(stack **st, count *c)
{
    stack *aux, *temp, copy;
    int value;
    if ((*st) == NULL)
    {
        char ex;
        printf("Empty List\nType to exit: ");
        scanf("%c",&ex);
        aux = *st;
        return (*aux);
    }
    else if ((*st)->next == NULL)
    {
        copy = **st;
        value = (*st)->value;
        free(*st);
        (*st) = NULL;
    }
    else
    {
        temp = *st;
        while (temp->next != NULL)
        {
            aux = temp;
            temp = temp->next;
        }
        copy = *temp;
        free(temp);
        aux->next = NULL;
    }
    c->stCount--;
}

void printStack(stack *st)
{
    int ex;
    if (st == NULL)
        printf("Empty stack");
    else
    {
        stack *aux;
        aux = st;
        printf("\nPrinted stack: ");
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