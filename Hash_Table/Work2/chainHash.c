/*Etapa 2:
Implemente uma tabela Hash, uma que trate as colisões com encadeamento externo. 
Desenvolva todas as funções necessárias para manipulação da estrutura (inserção, busca, etc).*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct studentData
{
    int code;
    float gpa;

    struct student *next;
} stdData;

typedef stdData* hashTable;

// Hashtable functions
void startHashTable(hashTable *table, int size)
{
    for(int i = 0; i < size; i++)
        table[i] = NULL;
}

int getHash(int code, int size)
{
    float words = 64, primeNum = 19;

    int hashNum = code * (primeNum/words);

    if(hashNum >= size)
        return size - 1;
    else
        return hashNum;
}


//Struct functions
stdData *allocData(int code, float gpa)
{
    stdData *new = (stdData*) malloc(sizeof(stdData));
    new->code = code;
    new->gpa = gpa;
    new->next = NULL;

    return new;
}

stdData *searchData(hashTable *table, int code, int size)
{
    int hashNum = getHash(code, size);

    stdData *temp = table[hashNum];

    while(temp && (temp->code != code))
        temp = temp->next;
    
    return temp;
}

void checkSearch(stdData *temp)
{   
    if(temp)
        printf("\nCode = %d\tGPA = %.2f\n", temp->code, temp->gpa);
    else
        printf("Code not found\n");

}

void insertData(hashTable *table, int code, float gpa, int size)
{
    int hashNum = getHash(code, size);

    stdData *temp = table[hashNum];
    stdData *back = NULL;

    while ((temp != NULL) && (temp->code != code))
    {
        back = temp;
        temp = temp->next;
    }
    
    if(temp)
    {
        temp->gpa = gpa;
        return;
    }

    stdData *new = allocData(code, gpa);

    if(!back)
        table[hashNum] = new;
    else
        back->next = new;

}

void deleteData(hashTable *table, int code, int size)
{
    int hashNum = getHash(code, size);

    if(table[hashNum] == NULL)
        return;
    
    stdData *temp = table[hashNum];
    stdData *back = NULL;

    while((temp != NULL) && (temp->code != code))
    {
        back = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("\nCode not found\n");
        return;
    }

    if(back == NULL)
        table[hashNum] = temp->next;
    else
        back->next = temp->next;
    free(temp);

    printf("\nCode %d deleted\n", code);
}

void printData(hashTable *table, int size)
{   
    printf("\nIndex    Code     GPA     Next\n");

    for(int i = 0; i < size; i++)
    {
        printf("%d", i);
        if (table[i])
        {
            stdData *temp = table[i];
            printf("\n");
            while(temp)
            {
                printf("\t| %d |\t| %.2f |\t| %p |\n", temp->code, temp->gpa, temp->next);
                temp = temp->next;
            }
        }
        else
            printf("\nNULL DATA\n");     
    }
    printf("---------------------------\n");
}

void freeData(hashTable *table, int size)
{
    for(int i = 0; i < size; i++)
    {
        if (table[i])
        {
            stdData *temp1 = table[i];
            stdData *temp2;

            while(temp1)
            {
                temp2 = temp1;
                temp1 = temp1->next;
                free(temp2);
            }
        }
    }

    printf("\n Data freed\n");
}


int main()
{
    int size, code = 0;
    float gpa = 0.0;

    printf("Table's size: ");
    scanf("%d", &size);

    hashTable *table[size];
    startHashTable(table, size);
    
    srand(time(NULL));
    for(int i = 0; i < 20; i++)
    {
        code = rand() % 20;
        gpa = ((float)rand() / (float)RAND_MAX) * 10.0;
        insertData(table, code, gpa, size);
    }

    printData(table, size);
    
    printf("\nSearch data tests:\n");

    stdData *temp; 
    temp = searchData(table, 15, size);
    checkSearch(temp);
    temp = searchData(table, 10, size);
    checkSearch(temp);
    temp = searchData(table, 4, size);
    checkSearch(temp);
    temp = searchData(table, 22, size);
    checkSearch(temp);

    printf("\nDelete data tests:\n");
    deleteData(table, 20, size);
    deleteData(table, 4, size);
    deleteData(table, 5, size);
    deleteData(table, 18, size);

    printData(table, size);

    freeData(table, size);

    return 0;
}