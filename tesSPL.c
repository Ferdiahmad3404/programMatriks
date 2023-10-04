#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printMatrix(double **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

bool banyakSolusi(double **matriks, int row, int column) {
    bool takHinggaBanyak = false;
    printf("%d\n", column);
    double array[column];
    int counter;
    for (int i = 0; i < row ; i++)
    {
        counter = 0;
        //insialisasi array
        for (int j = 0; j < column ; j++)
        {
          array[j] = matriks[i][j];
          printf("%f\n", matriks[i][j]);
          printf("%f\n", array[j]);
        }
        //pengecekan
        for (int j = 0; j < column ; j++)
        {
          if (array[j] == 0)
          {
            printf("tes\n");
            counter++;
          }
        }
        if (counter == column)
        {
            takHinggaBanyak = true;
            return takHinggaBanyak;
        }
    }
    return takHinggaBanyak;
}

bool takPunyaSolusi(double **matriks, int row, int column) {
    bool takPunyaSolusi = true;
    for (int i = 0; i < row ; i++)
    {
        for (int j = 0; j < column ; j++)
        {
            if (j != column-1)
            {
                if (matriks[i][j] != 0) {
                bool takPunyaSolusi = false;
                }
            }
            else
            {
                if (matriks[i][j] != 0)
                {
                    bool takPunyaSolusi = true;
                }   
            }
        }
    }
    return takPunyaSolusi;
}

int main() {
    int n;  // Jumlah variabel
    printf("Masukkan jumlah variabel: ");
    scanf("%d", &n);

    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)malloc((n + 1) * sizeof(double));
    }

    printf("Masukkan matriks koefisien A dan vektor hasil b:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Metode Gauss-Jordan
    for (int i = 0; i < n; i++) {
        // Mencari elemen pivot
        double pivot = matrix[i][i];

        // Menyederhanakan baris saat ini
        for (int j = 0; j <= n; j++) {
            matrix[i][j] /= pivot;
        }

        // Menghilangkan elemen non-nol di bawah elemen pivot
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j <= n; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }

    if (banyakSolusi(matrix, n, n+1))
    {
        printf("Solusi banyak\n");
    }
    else if (takPunyaSolusi(matrix, n, n+1))
    {
        printf("Tak punya solusi\n");
    }
    else
    {
        printf("Punya satu solusi\n");
    }
    
    printf("\nSolusi SPL:\n");
    for (int i = 0; i < n; i++) {

        printf("x%d = %.2f\n", i + 1, matrix[i][n]);
    }

    printMatrix(matrix, n,n+1);

    // Dealokasi matriks
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
