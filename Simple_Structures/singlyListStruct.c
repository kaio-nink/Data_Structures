#ifndef singlyListStruct_c
#define singlyListStruct_c

#include <stdio.h>
#include <stdlib.h>

#include "count.c"
typedef struct list
{
    int value;
    struct list *next;
} sList;


int emptyList(sList **ls)
{
    if ((*ls) == NULL)
        return 1;
    else 
        return 0;
}

sList *listAlloc(int value)
{
    sList *alloc;
    alloc = (sList *) malloc(sizeof(sList));
    if (alloc == NULL)
        printf("Memory allocation error");
    else
    {
        alloc->value = value;
        alloc->next = NULL;
    }
    
    return (alloc);
}

void insertFirst(sList **sl, count *c)
{
    int value;

    sList *aux, *new;
    
    printf("\nValue: ");
    scanf("%d",&value);

    new = listAlloc(value);

    if (emptyList(sl))
        (*sl) = new;
    else
    {
        aux = (*sl);
        new->next = aux;
        (*sl) = new;
    }
    c->snCount++;            
}

void insertLast(sList **sl, count *c)
{
    int value;

    sList *aux, *new;
    
    printf("\nValue: ");
    scanf("%d",&value);

    new = listAlloc(value);
    
    if (emptyList(sl))
        (*sl) = new;
    else
    {
        aux = (*sl);
        while (aux->next != NULL)
            aux = aux->next;
        aux->next = new;
    }
    c->snCount++;

}

void insertPosition(sList **sl,count *c)
{
    int value, pos;

    sList *aux1, *aux2, *new;
    
    printf("\nPosition: ");
    scanf("%d",&pos);

    if (pos > c->snCount - 1)
        printf("\nUnvalid position\n");
    else
    {
        int i = 0;
        printf("\nValue: ");
        scanf("%d",&value);

        new = listAlloc(value);

        if (emptyList(sl))
            (*sl) = new;
        else
        {
            aux1 = (*sl);
            while (i < pos)
            {
                aux2 = aux1;
                aux1 = aux1->next;
                i++;
            }

            aux2->next = new;
            new->next = aux1;

            c->snCount++;
        }
    }
}

void alterList(sList **sl,count *c)
{
    int pos, i;
    int ex;

    printf("\nSet position: ");
    scanf("%d", &pos);

    if (pos > c->snCount - 1)
        printf("Unvalid position");
    else
    {
        sList *aux;
        aux = (*sl);

        for (i = 0; i < pos; i++)
            aux = aux->next;
        printf("New value: ");
        scanf("%d",&aux->value);
    }
    printf("\nType to exit: ");
    scanf("%d",&ex);   

}

void removeFirst()
{

}

void removeLast()
{

}

void removePosition()
{

}

#endif