/*Etapa 1:
Elabore um algoritmo que crie um arquivo de entrada com um conjunto de 
valores e suas respectivas chaves, para serem inseridos em uma tabela Hash. 
Este algoritmo recebe como parâmetro o número de elementos, o tipo das entradas 
e o nome do arquivo resultante.
Cada registro é posto em uma linha do arquivo e deve conter uma chave inteira 
com valor entre 0 e 1023, e um valor composto por 3 letras. Estes valores serão definidos aleatoriamente, 
mas garanta que não exitem chaves com valores repetidos.
São dois tipos de arquivos de entrada possíveis: 1) todas as chaves geradas têm valor par; 2) sem restrição.*/ 
#ifndef getFile_C
#define getFile_C

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


//Common function to both inputs
int getRandomKey(int randKey)
{
    randKey = rand() % 1024;
    return randKey;
}

char getRandomValue()
{
    return (rand() % (92 - 66) + 65); //ASCII codes for A to Z (Uppercased)
}

//  Checks if key's value is even for entry 1
int checkEvenKey(int evenKey)
{
    evenKey = getRandomKey(evenKey);
    while (evenKey % 2 != 0)
    {
        evenKey = getRandomKey(evenKey);
    }
    
    return evenKey;
}

// File creation function
void createFile(int inputSize, char inputType, char *fileName)
{
    FILE *dataFile;
    int key;
    char value[4];
    
    strcat(fileName, ".txt");
    puts(fileName);
    dataFile = fopen(fileName, "w");
    
    if(dataFile == NULL)
    {
        printf("File Error\n");
    }
    setbuf(dataFile, NULL);

    for (int i = 1; i <= inputSize; i++)
    {
        srand( (unsigned) i *time(NULL));
        
        if(inputType == '1')
            key = checkEvenKey(key);
        else
            key = getRandomKey(key);


        for (int c = 0; c < 3; c++)
        {
            value[c] = getRandomValue();
        }

        if(key < 0)
            key = key * (-1);

        fprintf(dataFile, "%d ", key);
        fputs(value, dataFile);
        fflush(dataFile);
        fprintf(dataFile,"\n");
        strcpy(value, "  ");

    }
    fclose(dataFile);
}


int main()
{
    int inputSize;
    char fileName[30], inputType;

    printf("\nNumber of itens: ");
    scanf("%d",&inputSize);
    printf("\nInput type (1-All key's values are even; 2- No restrictions): ");
    scanf(" %c", &inputType);
    while ((getchar()) != '\n');
    printf("\nFile name: ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[ strcspn( fileName, "\n" ) ] = '\0';

    if((inputType == '1' || inputType == '2'))
        createFile(inputSize, inputType, fileName);    

    return 0;
}

#endif

