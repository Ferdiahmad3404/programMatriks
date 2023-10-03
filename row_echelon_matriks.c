/*
Program		: row_echelon_matriks.c
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

void MenuEselonMatriks()
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
    printf("Masukkan elemen matriks: \n");
    inputMatriks(rows, cols, matriks);
    printf("Matriks yang dimasukkan: \n");
    displayMatriks(rows, cols, matriks);
    printf("\n**************************\n");
    hitungEselonMatriks(rows, cols, matriks);
    printf("\n**************************\n");
    printf("Matriks eselon baris tereduksi: \n");
    displayMatriks(rows, cols, matriks);
    printf("\n============================================\n");
    printf("Tekan enter untuk melanjutkan...");
    getch();
    return;
}

void hitungEselonMatriks(int rows, int cols, float matriks[rows][cols])
{
    /*Kamus Data*/
    float skalar_temp;

    /*Algoritma*/
    for (int k = 0; k < rows; k++)
    {
        if ((matriks[k][k]) != 1)
        {
            float skalar_temp = matriks[k][k];
            if (skalar_temp == 0)
                continue; // Menghindari pembagian oleh nol
            printf("\n**************************\n");
            printf("Langkah %d: b%d' = b%d / %.1f\n", k + 1, k + 1, k + 1, skalar_temp);
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
                printf("Langkah %d: b%d' = b%d - (%.1f) * b%d'\n", k + 1, i + 1, i + 1, skalar_temp, k + 1);
                for (int j = 0; j < cols; j++)
                {
                    matriks[i][j] = matriks[i][j] - (matriks[k][j] * skalar_temp);
                }
            }
        }

        // Menampilkan Setiap Langkah
        printf("\nBentuk Matriks Baris Tereduksi setelah Langkah %d:\n\n", k + 1);
        for (int a = 0; a < rows; a++)
        {
            printf("| ");
            for (int b = 0; b < cols; b++)
            {
                if (matriks[a][b] == -0)
                    matriks[a][b] = 0; // Mengubah '-0' menjadi '0'
                printf("%.1f ", matriks[a][b]);
            }
            printf("|\n");
        }
    }
}
