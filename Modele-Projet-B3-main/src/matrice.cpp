#include "matrice.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int** processMatrice(char matriceNonDecode[])
{
    int** matriceDecode = (int**)malloc(13 * sizeof(int*));
    if (matriceNonDecode == NULL) {
        return NULL;
    }

    for (int i = 0; i < 13; i++)
    {
        matriceDecode[i] = (int*)malloc(13 * sizeof(int));
        for (int j = 0; j < 13; j++)
        {
            matriceDecode[i][j] = matriceNonDecode[i * 13 + j] - '0'; // Convert char to int
        }
    }
    return matriceDecode;

}
