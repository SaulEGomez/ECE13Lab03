// **** Include libraries here ****
// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//CMPE13 Support Library
#include "BOARD.h"




// User libraries:
#include "MatrixMath.h"

// Module-level variables:
// MatrixPrint floats
float zero_matrix[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};

float test_matrix_print[3][3] = {
    {123.456, -12.3456, 1.2345},
    {-0.0001, 999.9999, -999.9999},
    {0.1111, 0.2222, 0.3333}
};

// MatrixEquals floats
float matrix1[3][3] = {{1.0f, 2.0f, 3.0f}, {4.0f, 5.0f, 6.0f}, {7.0f, 8.0f, 9.0f}};

float identical_matrix[3][3] = {{1.0f, 2.0f, 3.0f}, {4.0f, 5.0f, 6.0f}, {7.0f, 8.0f, 9.0f}};

float different_matrix[3][3] = {{1.0f, 2.0f, 3.0f}, {4.0f, 5.1f, 6.0f}, {7.0f, 8.0f, 9.0f}};

// MatrixAdd floats
float matrixA[3][3] = {
    {1.5, 2.5, 3.5},
    {4.5, 5.5, 6.5},
    {7.5, 8.5, 9.5}
};

float zeroMatrix[3][3] = {
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0}
};

float matrixB[3][3] = {
    {10.0, 20.0, 30.0},
    {40.0, 50.0, 60.0},
    {70.0, 80.0, 90.0}
};

float resultMatrix[3][3];

// MatrixMultiply floats
float matrixPatience[3][3] = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}
};

float matrixVoyage[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

float matrixQuest[3][3] = {
    {9, 8, 7},
    {6, 5, 4},
    {3, 2, 1}
};

float matrixResultant[3][3];

// MatrixScalarAdd floats
float matrixHarmony[3][3] = {
    {5.5, 6.5, 7.5},
    {8.5, 9.5, 10.5},
    {11.5, 12.5, 13.5}
};

float matrixSerenity[3][3];

// MatrixScalarMultiply floats
float matrixTranquility[3][3] = {
    {2, 4, 6},
    {8, 10, 12},
    {14, 16, 18}
};

float matrixDynamism[3][3]; 

// MatrixTrace floats
float matrixUnity[3][3] = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}
};

float matrixDiversity[3][3] = {
    {5, 1, 2},
    {3, -8, 7},
    {6, 5, 4}
};

// MatrixTranspose floats
float matrixSymmetric[3][3] = {
    {1, 2, 3},
    {2, 4, 5},
    {3, 5, 6}
};

float matrixAsymmetric[3][3] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8}
};

float transposedMatrix[3][3]; 

// MatrixSubmatrix floats
float testMatrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

float submatrixResult[2][2];

// MatrixDeterminant floats
float matrixWithZeroDet[3][3] = {
    {1, 2, 3},
    {2, 4, 6}, 
    {7, 8, 9}
};

float matrixWithNonZeroDet[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 10} 
};

// MatrixInverse floats
float matrixInvertible[3][3] = {
    {1, 2, 3},
    {0, 1, 4},
    {5, 6, 0}
};

float matrixNonInvertible[3][3] = {
    {1, 2, 3},
    {2, 4, 6}, 
    {4, 5, 6}
};

float inverseMatrix[3][3];

int main()
{
    BOARD_Init();

    printf("Beginning saegomez's mml test harness, compiled on %s %s\n", __DATE__, __TIME__);
    
    // Test Case 1 for MatrixPrint
    printf("Demonstrating MatrixPrint():\n");
    MatrixPrint(zero_matrix);

    // Test case 2 for MatrixPrint
    printf("Demonstrating MatrixPrint() with a test matrix:\n");
    MatrixPrint(test_matrix_print);

    // Test case 1 for MatrixEquals
    printf("\nTest Case 1: Matrices are identical\n");
    int result = MatrixEquals(matrix1, identical_matrix);
    printf("MatrixEquals(matrix1, identical_matrix) should return TRUE: %s\n", result ? "TRUE" : "FALSE");

    // Test case 2 for MatrixEquals
    printf("\nTest Case 2: Matrices are different\n");
    result = MatrixEquals(matrix1, different_matrix);
    printf("MatrixEquals(matrix1, different_matrix) should return FALSE: %s\n", result ? "TRUE" : "FALSE");

    // Test case 1 for MatrixAdd
    printf("\nTest Case 1: Adding a Zero Matrix\n");
    MatrixAdd(matrixA, zeroMatrix, resultMatrix);
    printf("Result of adding zero matrix to Matrix A:\n");
    MatrixPrint(resultMatrix);

    // Test case 2 for MatrixAdd
    printf("\nTest Case 2: Adding Two Non-Zero Matrices\n");
    MatrixAdd(matrixA, matrixB, resultMatrix);
    printf("Result of adding Matrix A to Matrix B:\n");
    MatrixPrint(resultMatrix);

    // Test case 1 for MatrixMultiply
    printf("\nTest Case 1: Multiplication by an Identity Matrix\n");
    MatrixMultiply(matrixVoyage, matrixPatience, matrixResultant);
    printf("Result of multiplying Matrix Voyage by an Identity Matrix:\n");
    MatrixPrint(matrixResultant);

    // Test case 2 for MatrixMultiply
    printf("\nTest Case 2: Multiplication of Two Non-Identity Matrices\n");
    MatrixMultiply(matrixVoyage, matrixQuest, matrixResultant);
    printf("Result of multiplying Matrix Voyage by Matrix Quest:\n");
    MatrixPrint(matrixResultant);

    // Test case 1 for MatrixScalarAdd
    printf("\nTest Case 1: Addition with Zero Scalar\n");
    MatrixScalarAdd(0, matrixHarmony, matrixSerenity);
    printf("Result of adding 0 to Matrix Harmony:\n");
    MatrixPrint(matrixSerenity);

    // Test case 2 for MatrixScalarAdd
    printf("\nTest Case 2: Addition with a Positive Scalar\n");
    MatrixScalarAdd(3.5, matrixHarmony, matrixSerenity);
    printf("Result of adding 3.5 to Matrix Harmony:\n");
    MatrixPrint(matrixSerenity);

    // Test case 1 for MatrixScalarMultiply
    printf("\nTest Case 1: Multiplication with Zero Scalar\n");
    MatrixScalarMultiply(0, matrixTranquility, matrixDynamism);
    printf("Result of multiplying Matrix Tranquility by 0:\n");
    MatrixPrint(matrixDynamism);

    // Test case 2 for MatrixScalarMultiply
    printf("\nTest Case 2: Multiplication with a Positive Scalar\n");
    MatrixScalarMultiply(2.5, matrixTranquility, matrixDynamism);
    printf("Result of multiplying Matrix Tranquility by 2.5:\n");
    MatrixPrint(matrixDynamism);

    // Test case 1 for MatrixTrace
    printf("\nTest Case 1: Trace of an Identity Matrix\n");
    float traceUnity = MatrixTrace(matrixUnity);
    printf("Trace of Matrix Unity (should be 3): %f\n", traceUnity);

    // Test case 2 for MatrixTrace
    printf("\nTest Case 2: Trace of a Non-Identity Matrix with Varied Elements\n");
    float traceDiversity = MatrixTrace(matrixDiversity);
    printf("Trace of Matrix Diversity (should be 1): %f\n", traceDiversity);

    // Test case 1 for MatrixTranspose
    printf("\nTest Case 1: Transpose of a Symmetric Matrix\n");
    MatrixTranspose(matrixSymmetric, transposedMatrix);
    printf("Original Matrix Symmetric:\n");
    MatrixPrint(matrixSymmetric);
    printf("Transposed Matrix Symmetric:\n");
    MatrixPrint(transposedMatrix);

    // Test case 2 for MatrixTranspose
    printf("\nTest Case 2: Transpose of a Non-Symmetric Matrix\n");
    MatrixTranspose(matrixAsymmetric, transposedMatrix);
    printf("Original Matrix Asymmetric:\n");
    MatrixPrint(matrixAsymmetric);
    printf("Transposed Matrix Asymmetric:\n");
    MatrixPrint(transposedMatrix);

    // Test case 1 for MatrixSubmatrix
    printf("\nTest Case 1: Submatrix by Removing First Row and First Column\n");
    MatrixSubmatrix(0, 0, testMatrix, submatrixResult);
    printf("Original Matrix:\n");
    MatrixPrint(testMatrix);
    printf("Submatrix (Removing first row and first column):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%f ", submatrixResult[i][j]);
        }
        printf("\n");
    }

    // Test case 2 for MatrixSubmatrix
    printf("\nTest Case 2: Submatrix by Removing Last Row and Last Column\n");
    MatrixSubmatrix(2, 2, testMatrix, submatrixResult);
    printf("Original Matrix:\n");
    MatrixPrint(testMatrix);
    printf("Submatrix (Removing last row and last column):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%f ", submatrixResult[i][j]);
        }
        printf("\n");
    }

    // Test case 1 for MatrixDeterminant
    printf("\nTest Case 1: Determinant of a Matrix with Zero Determinant\n");
    float detZero = MatrixDeterminant(matrixWithZeroDet);
    printf("Determinant of matrixWithZeroDet (should be 0): %f\n", detZero);

    // Test case 2 for MatrixDeterminant
    printf("\nTest Case 2: Determinant of a Matrix with Non-Zero Determinant\n");
    float detNonZero = MatrixDeterminant(matrixWithNonZeroDet);
    printf("Determinant of matrixWithNonZeroDet (should be non-zero): %f\n", detNonZero);

    // Test case 1 for MatrixInverse
    printf("\nTest Case 1: Inverse of a Matrix with Non-Zero Determinant\n");
    MatrixInverse(matrixInvertible, inverseMatrix);
    printf("Original Matrix Invertible:\n");
    MatrixPrint(matrixInvertible);
    printf("Inverse of Matrix Invertible:\n");
    MatrixPrint(inverseMatrix);

    // Test case 2 for MatrixInverse
    printf("\nTest Case 2: Attempted Inversion of a Matrix with Zero Determinant\n");
    MatrixInverse(matrixNonInvertible, inverseMatrix);
    printf("Original Matrix Non-Invertible:\n");
    MatrixPrint(matrixNonInvertible);
    printf("Resultant Matrix (should indicate non-inversion or be unchanged):\n");
    MatrixPrint(inverseMatrix);

    // Add more tests here!


    BOARD_End();
    while (1);
}

