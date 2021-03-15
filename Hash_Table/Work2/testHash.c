/*Etapa 3:
Desenvolva um sistema para avaliação da função Hash. 
Implemente 2 funções Hash distintas. Este sistema irá utilizar uma tabela Hash de tamanho 100. 
A avaliação deverá executar um mesmo aquivo de entrada para cada função Hash implementada.
Para cada execução, contabilize o número de colisões que ocorreram.
Gere 10 entradas com 20, com 50 e 80 registros (total de 30 arquivos) diferentes que serão utilizadas nos testes. 
Em cada conjunto de 10 arquivos, 5 são do tipo 1 e 5 do tipo 2.
Ao final, elabore um relatório contendo a média do número de colisões entre os elementos para 
cada contexto avaliado (sugestão: utilize uma planilha eletrônica para tabular os resultados).*/

#include <stdio.h>
#include <stdlib.h>
#include "getFile.c"

int generateInput()
{
    int inputSize = 20, inputType;
    char fileName[30];
    for(int i = 0; i < 3; i++)
    {   
        inputType = 1;
        for(int j = 1; i <= 10; i++)
        {
            if(j == 6)
                inputType = 2;
            sprintf(fileName, "arq%d",j);
            
            createFile(inputSize,inputType,fileName);

        }
        inputSize += 30;
    }
}

int main()
{
    generateInput();
    
    return 0;
}
