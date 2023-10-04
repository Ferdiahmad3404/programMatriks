#include <stdio.h>
#include <stdlib.h>


void printMatrix(double **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int cekSolusi(double **matrix, int n) {
    // Banyak Solusi
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            if (matrix[i][j] == 0)
            {
                
            }
        }
    }
    
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

    //Cek jenis solusi


    printf("\nSolusi SPL:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, matrix[i][n]);
    }

    // Dealokasi matriks
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
