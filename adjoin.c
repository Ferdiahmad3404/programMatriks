/*
Program		: adjoin.c
Deskripsi	: Body prototype ADT adjoin Matriks
Dibuat oleh :
            - Ferdi Ahmad Ariesta 	(221524041)
            - Mahardika Pratama 	(221524044)
            - Naia Siti Az-Zahra 	(221524052)
            - Rafif Shabi Prasetyo  (221524055)
            - Zahran Anugerah Rizqullah (221524063)
Kelompok	: 2
Kelas		: 2B
Jurusan     : Teknik Komputer dan Informatika
Prodi       : D4 Teknik Informatika
Angkatan    : 2022/2023
Tanggal		: 25 September 2023
===============================================*/

#include "matriks.h"

void MenuAdjoinMatriks()
{
    /*Kamus Data*/
    int ordo;

    /*Algoritma*/
    system("cls");
    printf("\n============================================\n");
    printf("                DETERMINAN MATRIKS                \n");
    printf("==============================================\n");
    printf("Masukkan ordo matriks bujur sangkar: ");
    scanf("%d", &ordo);
    float matriks[ordo][ordo];
    printf("Masukkan elemen matriks A: \n");
    inputMatriks(ordo, ordo, matriks);
    printf("Matriks A : \n");
    displayMatriks(ordo, ordo, matriks);
    printf("\n**************************\n");
    float matriksHasil[ordo][ordo];
    hitungAdjoinMatriks(ordo, matriks, matriksHasil);
    printf("\nMatris Adjoin  A : \n");
    displayMatriks(ordo, ordo, matriksHasil);
    printf("\n============================================\n");
    printf("Tekan enter untuk melanjutkan...");
    getch();
    return;
}

void hitungAdjoinMatriks(int ordo, float matriks[ordo][ordo], float matriksHasil[ordo][ordo])
{
    /*Kamus Data*/
    int i, j;
    float matriks_temp[ordo][ordo];
    /*Algoritma*/
    
    for (i = 0; i < ordo; i++)
    {
        for (j = 0; j < ordo; j++)
        {
            matriks_temp[i][j] = hitungKofaktor(ordo, matriks, i, j);
        }
    }
    hitungTransposeMatriks(ordo, ordo, matriks_temp, matriksHasil);
}

float hitungKofaktor(int ordo, float matriks[ordo][ordo], int row, int col)
{

    float submatrix[ordo - 1][ordo - 1];
    potongMatriks(ordo, matriks, row, col, submatrix);
    float determinan_temp = hitungDeterminanMatriksKofaktor(ordo - 1, submatrix)*-1;
    float cofactor = pow(-1, row+col) * determinan_temp;
    if (cofactor == -0)
        cofactor = 0;
    printf("Cofactor dari matriks[%d][%d] = %.2f\n", row+1, col+1, cofactor);
    return cofactor;
}