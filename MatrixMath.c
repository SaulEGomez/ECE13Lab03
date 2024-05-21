// Lab 03: Saul Gomez ECE 13 04/23/24

// **** Include libraries here ****
// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//CMPE13 Support Library
#include "BOARD.h"

// User libraries:
#include "MatrixMath.h"

#define FP_DELTA 0.0001

#define DIM 3

#define TRUE 1

#define FALSE 0

/******************************************************************************
 * Matrix Display:
 *****************************************************************************/
void MatrixPrint(float mat[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] > -FP_DELTA && mat[i][j] < FP_DELTA) {
                printf(" 0.0000 ");
            } else {
                printf("% 7.4f ", mat[i][j]);
            }
        }
        printf("\n");
    }
}


/******************************************************************************
 * Matrix - Matrix Operations
 *****************************************************************************/
// Matrix Equal Operation
int MatrixEquals(float mat1[3][3], float mat2[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (fabs(mat1[i][j] - mat2[i][j]) > FP_DELTA) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

// Matrix Addition
void MatrixAdd(float mat1[3][3], float mat2[3][3], float result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Matrix Multiply 
void MatrixMultiply(float mat1[3][3], float mat2[3][3], float result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0; 
            for (int k = 0; k < 3; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

 /******************************************************************************
 * Matrix - Scalar Operations
 *****************************************************************************/
// Matrix Scalar Add
void MatrixScalarAdd(float x, float mat[3][3], float result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = mat[i][j] + x;
        }
    }
}

// Matrix Scalar Multiply
void MatrixScalarMultiply(float x, float mat[3][3], float result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = mat[i][j] * x;
        }
    }
}

/******************************************************************************
 * Unary Matrix Operations
 *****************************************************************************/
// Matrix Trace
float MatrixTrace(float mat[3][3]) {
    float trace = 0.0;
    for (int i = 0; i < 3; i++) {
        trace += mat[i][i]; 
    }
    return trace;
}

// Matrix Transpose 
void MatrixTranspose(float mat[3][3], float result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

// Matrix Sub Matrix
void MatrixSubmatrix(int i, int j, float mat[3][3], float result[2][2]) {
    int row = 0, col;
    for (int x = 0; x < 3; x++) {
        if (x == i) continue; 
        col = 0;
        for (int y = 0; y < 3; y++) {
            if (y == j) continue; 
            result[row][col] = mat[x][y];
            col++;
        }
        row++;
    }
}

// Matrix Determinant 
float MatrixDeterminant(float mat[3][3]) {
    float det = 0.0;
    for (int i = 0; i < 3; i++) {
        det += (mat[0][i] * (mat[1][(i + 1) % 3] * mat[2][(i + 2) % 3] - mat[1][(i + 2) % 3] * mat[2][(i + 1) % 3]));
    }
    return det;
}

// Matrix Inverse
void MatrixInverse(float mat[3][3], float result[3][3]) {
    // Calculate the determinant
    float det = MatrixDeterminant(mat);
    if (det == 0) {
        return; 
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            float submat[2][2];
            int subi = 0;
            for (int ki = 0; ki < 3; ki++) {
                if (ki == i) continue;
                int subj = 0;
                for (int kj = 0; kj < 3; kj++) {
                    if (kj == j) continue;
                    submat[subi][subj] = mat[ki][kj];
                    subj++;
                }
                subi++;
            }

            float minor = submat[0][0] * submat[1][1] - submat[0][1] * submat[1][0];
            float cofactor = ((i + j) % 2 == 0 ? 1 : -1) * minor;
            result[j][i] = cofactor / det;  
        }
    }
}



