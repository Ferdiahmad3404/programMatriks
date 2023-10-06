/*
Program		: row_echelon.c
Deskripsi	: Body prototype ADT Row Echelon Matriks
Dibuat oleh :
            - Ferdi Ahmad Ariesta 	(221524041)
            - Mahardika Pratama 	(221524044)
            - Naia Siti Az-Zahra 	(221524052)
            - Rafif Shabi Prasetyo  (221524055)
            - Zahran Anugerah Rizqullah (221524063)
Kelompok	: 2
Kelas		: 1B
Jurusan     : Teknik Komputer dan Informatika
Prodi       : D4 Teknik Informatika
Angkatan    : 2022/2023
Tanggal		: 25 September 2023
===============================================*/

#include "matriks.h"

void MenuEselonBarisTereduksi()
{
    /*Kamus Data*/
    int rows, cols;
    /*Algoritma*/
    system("cls");
    printf("\n============================================\n");
    printf("          MATRIKS ESELON BARIS TEREDUKSI    \n");
    printf("============================================\n");
    printf("Masukkan jumlah baris matriks: ");
    scanf("%d", &rows);
    printf("Masukkan jumlah kolom matriks: ");
    scanf("%d", &cols);
    float matriks[rows][cols];
    printf("Masukkan elemen matriks A: \n");
    inputMatriks(rows, cols, matriks);
    printf("Matriks A: \n");
    displayMatriks(rows, cols, matriks);
    printf("\n**************************\n");
    gaussJordan(rows, cols, matriks);
    printf("\n**************************\n");
    printf("Matriks eselon baris tereduksi: \n");
    displayMatriks(rows, cols, matriks);
    printf("\n============================================\n");
    printf("Tekan enter untuk melanjutkan...");
    getch();
    return;
}

void MenuEselonBaris()
{
    /*Kamus Data*/
    int rows, cols;
    /*Algoritma*/
    system("cls");
    printf("\n============================================\n");
    printf("          MATRIKS ESELON BARIS    \n");
    printf("============================================\n");
    printf("Masukkan jumlah baris matriks: ");
    scanf("%d", &rows);
    printf("Masukkan jumlah kolom matriks: ");
    scanf("%d", &cols);
    float matriks[rows][cols];
    printf("Masukkan elemen matriks A: \n");
    inputMatriks(rows, cols, matriks);
    printf("Matriks A: \n");
    displayMatriks(rows, cols, matriks);
    printf("\n**************************\n");
    gaussElimination(rows, cols, matriks);
    printf("\n**************************\n");
    printf("Matriks eselon baris: \n");
    displayMatriks(rows, cols, matriks);
    printf("\n============================================\n");
    printf("Tekan enter untuk melanjutkan...");
    getch();
    return;
}

void gaussElimination(int rows, int cols, float matriks[rows][cols]) {
    int n = rows, counter = 1;  // Jumlah persamaan
    float *x = (float *)malloc(n * sizeof(float));

    for (int i = 0; i < n - 1; i++) {
        // Periksa apakah elemen pivot nol, dan tukar baris jika diperlukan
        if (matriks[i][i] == 0.0) {
            // Cari pivot non-nol di bawah baris saat ini
            int swapRow = -1;
            for (int k = i + 1; k < n; k++) {
                if (matriks[k][i] != 0.0) {
                    swapRow = k;
                    break;
                }
            }

            if (swapRow == -1) {
    			return;
            }

            // Tukar baris i dan swapRow
            for (int k = i; k < cols; k++) {
                matriks[i][k] = -matriks[i][k];
                float temp = matriks[i][k];
                matriks[i][k] = matriks[swapRow][k];
                matriks[swapRow][k] = temp;
            }
            
            printf("Langkah %d: Tukar baris b%d dengan b%d\n", counter, i + 1, swapRow + 1);
            counter++;
            displayMatriks(n, cols, matriks);
        }

        for (int j = i + 1; j < n; j++) {
            float ratio = matriks[j][i] / matriks[i][i];
            printf("Langkah %d: b%d' = b%d - (%.2f) * b%d'\n", counter, j + 1, j + 1, ratio, i + 1);
            counter++;
            for (int k = i; k < n + 1; k++) {
                matriks[j][k] = matriks[j][k] - ratio * matriks[i][k];
            }
            displayMatriks(n, cols, matriks);
        }
    }

    // Substitusi balik
    for (int i = n - 1; i >= 0; i--) {
        if (matriks[i][i] == 0.0) {
            return;
        }
        x[i] = matriks[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] = x[i] - matriks[i][j] * x[j];
        }
        x[i] = x[i] / matriks[i][i];
    }


    free(x);
}


void gaussJordan(int rows, int cols, float matriks[rows][cols])
{
    /*Kamus Data*/
    float skalar_temp;
	int counter = 1;
    /*Algoritma*/
    for (int k = 0; k < rows; k++)
    {
        if ((matriks[k][k]) != 1)
        {
            float skalar_temp = matriks[k][k];
            if (skalar_temp == 0)
                continue; // Menghindari pembagian oleh nol
            printf("\n**************************\n");
            printf("Langkah %d: b%d' = b%d * 1 / %.2f\n", counter, k + 1, k + 1, skalar_temp);
            counter++;
            for (int j = 0; j < cols; j++)
            {
                matriks[k][j] = ((matriks[k][j]) / skalar_temp);
            }
        }

        for (int i = 0; i < rows; i++)
        {
            if (i != k)
            {
                skalar_temp = matriks[i][k];
                printf("Langkah %d: b%d' = b%d - (%.2f) * b%d'\n",counter, i + 1, i + 1, skalar_temp, k + 1);
                counter++;
                for (int j = 0; j < cols; j++)
                {
                    matriks[i][j] = matriks[i][j] - (matriks[k][j] * skalar_temp);
                }
            }
        }

        // Menampilkan Setiap Langkah
        printf("\nBentuk Matriks Baris Tereduksi setelah Langkah %d:\n\n", k + 1);
        displayMatriks(rows, cols, matriks);
    }
}
