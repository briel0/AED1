#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct Matriz {
    double** array;
    int rows;
    int cols;
};

Matriz* matriz_create(int rows, int cols){
    Matriz* matriz = malloc(sizeof(Matriz));

    matriz->array = malloc(sizeof(double*) * rows);

    for(int i = 0; i < rows; i++){
        matriz->array[i] = malloc(sizeof(double) * cols);
    }

    matriz->rows = rows;
    matriz->cols = cols;

    return matriz;
}

void matriz_destroy(Matriz* matriz){
    for(int i = 0; i < matriz->rows; i++){
        free(matriz->array[i]);
    }
    free(matriz->array);
    free(matriz);
}

void matriz_print(Matriz* matriz){
    for(int i = 0; i < matriz->rows; i++){
        for(int j = 0; j < matriz->cols; j++){
            printf("%.4f ", matriz->array[i][j]);
        }
        printf("\n");
    }
}

double matriz_get(Matriz* matriz, int row, int col){
    return matriz->array[row][col];
}

void matriz_set(Matriz* matriz, int row, int col, double value){
    matriz->array[row][col] = value;
}

int matriz_rows(Matriz* matriz){
    return matriz->rows;
}

int matriz_cols(Matriz* matriz){
    return matriz->cols;
}

bool matriz_equals(Matriz* matriz1, Matriz* matriz2){
    if(matriz1->rows != matriz2->rows || matriz1->cols != matriz2->cols){
        return false;
    }

    for(int i = 0; i < matriz1->rows; i++){
        for(int j = 0; j < matriz1->cols; j++){
            if(matriz1->array[i][j] != matriz2->array[i][j]){
                return false;
            }
        }
    }

    return true;
}

Matriz* matriz_add(Matriz* matriz1, Matriz* matriz2){
    if(matriz1->rows != matriz2->rows || matriz1->cols != matriz2->cols){
        return NULL; 
    }

    int rows = matriz1->rows;

    int cols = matriz1->cols;

    Matriz* result = matriz_create(rows, cols);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result->array[i][j] = matriz1->array[i][j] + matriz2->array[i][j];
        }
    }
    return result;
}

Matriz* matriz_sub(Matriz* matriz1, Matriz* matriz2){
    if(matriz1->rows != matriz2->rows || matriz1->cols != matriz2->cols){
        return NULL; 
    }

    int rows = matriz1->rows;

    int cols = matriz1->cols;

    Matriz* result = matriz_create(rows, cols);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result->array[i][j] = matriz1->array[i][j] - matriz2->array[i][j];
        }
    }
    return result;
}

Matriz* matriz_scalar_mul(Matriz* matriz, double scalar){

    int rows = matriz->rows;

    int cols = matriz->cols;

    Matriz* result = matriz_create(rows, cols);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result->array[i][j] = matriz->array[i][j] * scalar;
        }
    }
    return result;
}

Matriz* matriz_transpose(Matriz* matriz){

    int rows = matriz->rows;
    int cols = matriz->cols;

    Matriz* result = matriz_create(cols, rows);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result->array[i][j] = matriz->array[j][i];
        }
    }
    return result;
}

bool matriz_is_symmetric(Matriz* matriz){
    int rows = matriz->rows;
    int cols = matriz->cols;
    if(rows != cols){
        return false;
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matriz->array[i][j] != matriz->array[j][i]){
                return false;
            }
        }
    }
    return true;
}
