/*
Program		: operation_matriks.c
Deskripsi	: Body prototype ADT Operasi Matriks
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

void MenuOperasiMatriks()
{
    int pilihan = 0;
    while (pilihan != 99)
    {
        system("cls");
        displayMenuOperasiMatriks();
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            PenjumlahanMatriks();
            break;
        case 2:
            PenguranganMatriks();
            break;
        case 3:
            PerkalianMatriks();
            break;
        case 4:
            TransposeMatriks();
            break;
        case 99:
            return;
            break;
        default:
            system("cls");
            printf("Pilihan tidak tersedia!\n");
            printf("Silakan masukkan pilihan yang sesuai!\n");
            printf("Tekan enter untuk melanjutkan...");
            getch();
            break;
        }
    }
}

// Fungsi untuk memeriksa ordo yang sesuai untuk penjumlahan dan pengurangan matriks
bool isAdditionSubtractionValid(int rowsA, int colsA, int rowsB, int colsB)
{
    if (rowsA > 0 && colsA > 0 && rowsB > 0 && colsB > 0)
    {
        return (rowsA == rowsB) && (colsA == colsB);
    }
    else
    {
        return false;
    }
}

// Fungsi untuk memeriksa ordo yang sesuai untuk perkalian matriks
bool isMultiplicationValid(int colsA, int rowsB)
{
    if (colsA > 0 && rowsB > 0)
    {
        return (colsA == rowsB);
    }
    else
    {
        return false;
    }
}

bool isTransposeValid(int rows, int cols)
{
    if (rows > 0 && cols > 0)
    {
        return (rows == cols);
    }
    else
    {
        return false;
    }
}

void PenjumlahanMatriks()
{
    /*Kamus Data*/
    int rowsA, colsA, rowsB, colsB;
    bool isValid = true;
    /*Algoritma*/
    while (isValid == true)
    {
        system("cls");
        printf("\n============================================\n");
        printf("          PENJUMLAHAN MATRIKS           \n");
        printf("============================================\n");
        printf("Masukkan ordo matriks A (m x n): ");
        scanf("%d %d", &rowsA, &colsA);
        printf("Masukkan ordo matriks B (m x n): ");
        scanf("%d %d", &rowsB, &colsB);
        if (isAdditionSubtractionValid(rowsA, colsA, rowsB, colsB))
        {
            float matriksA[rowsA][colsA], matriksB[rowsB][colsB], matriksC[rowsA][colsA];
            printf("Masukkan elemen matriks A:\n");
            inputMatriks(rowsA, colsA, matriksA);
            printf("Masukkan elemen matriks B:\n");
            inputMatriks(rowsB, colsB, matriksB);
            printf("Matriks A:\n");
            displayMatriks(rowsA, colsA, matriksA);
            printf("Matriks B:\n");
            displayMatriks(rowsB, colsB, matriksB);
            hitungPenjumlahanMatriks(rowsA, colsA, matriksA, matriksB, matriksC);
            printf("Hasil penjumlahan matriks A dan B:\n");
            displayMatriks(rowsA, colsA, matriksC);
            printf("Tekan enter untuk melanjutkan...");
            getch();
            return;
        }
        else
        {
            printf("Ordo matriks tidak sesuai!\n");
            printf("Silakan masukkan ordo matriks yang sesuai!\n");
            printf("Tekan enter untuk melanjutkan...");
            getch();
            continue;
        }
    }
}

void PenguranganMatriks()
{
    /*Kamus Data*/
    int rowsA, colsA, rowsB, colsB;
    bool isValid = true;
    /*Algoritma*/
    while (isValid == true)
    {
        system("cls");
        printf("\n============================================\n");
        printf("          PENGURANGAN MATRIKS           \n");
        printf("============================================\n");
        printf("Masukkan ordo matriks A (m x n): ");
        scanf("%d %d", &rowsA, &colsA);
        printf("Masukkan ordo matriks B (m x n): ");
        scanf("%d %d", &rowsB, &colsB);
        if (isAdditionSubtractionValid(rowsA, colsA, rowsB, colsB))
        {
            float matriksA[rowsA][colsA], matriksB[rowsB][colsB], matriksC[rowsA][colsA];
            printf("Masukkan elemen matriks A:\n");
            inputMatriks(rowsA, colsA, matriksA);
            printf("Masukkan elemen matriks B:\n");
            inputMatriks(rowsB, colsB, matriksB);
            printf("Matriks A:\n");
            displayMatriks(rowsA, colsA, matriksA);
            printf("Matriks B:\n");
            displayMatriks(rowsB, colsB, matriksB);
            hitungPenguranganMatriks(rowsA, colsA, matriksA, matriksB, matriksC);
            printf("Hasil pengurangan matriks A dan B:\n");
            displayMatriks(rowsA, colsA, matriksC);
            printf("Tekan enter untuk melanjutkan...");
            getch();
            return;
        }
        else
        {
            printf("Ordo matriks tidak sesuai!\n");
            printf("Silakan masukkan ordo matriks yang sesuai!\n");
            printf("Tekan enter untuk melanjutkan...");
            getch();
            continue;
        }
    }
}
void PerkalianMatriks()
{
    /* Kamus Data */
    int pilihan = 0;

    /* Algoritma */
    while (pilihan != 99)
    {
        system("cls");
        displayMenuOperasiPerkalianMatriks();
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            PerkalianMatriksScalar();
            break;
        case 2:
            PerkalianMatriksMatriks();
            break;
        case 99:
            return;
        default:
            printf("Pilihan tidak tersedia!\n");
            printf("Tekan enter untuk melanjutkan...");
            getch();
            break;
        }
    }
}

void PerkalianMatriksScalar()
{
    /* Kamus Data */
    int rowsA, colsA;
    float scalar;
    /* Algoritma */
    system("cls");
    printf("\n============================================\n");
    printf("          PERKALIAN MATRIKS SKALAR           \n");
    printf("============================================\n");
    printf("Masukkan ordo matriks A (m n): ");
    scanf("%d %d", &rowsA, &colsA);
    float matriksA[rowsA][colsA];
    printf("Masukkan elemen matriks A:\n");
    inputMatriks(rowsA, colsA, matriksA);
    printf("Matriks A:\n");
    displayMatriks(rowsA, colsA, matriksA);
    printf("Masukkan bilangan scalar: ");
    scanf("%f", &scalar);
    float matriks_hasil[rowsA][colsA];
    hitungPerkalianMatriksxSkalar(rowsA, colsA, matriksA, scalar, matriks_hasil);
    printf("Hasil perkalian matriks A dengan skalar:\n");
    displayMatriks(rowsA, colsA, matriks_hasil);
    printf("Tekan enter untuk melanjutkan...");
    getch();
    return;
}

void PerkalianMatriksMatriks()
{
    /* Kamus Data */
    int rowsA, colsA, rowsB, colsB;
    bool isValid = true;
    /* Algoritma */
    while (isValid == true)
    {
        system("cls");
        printf("\n============================================\n");
        printf("          PERKALIAN MATRIKS MATRIKS           \n");
        printf("============================================\n");
        printf("Masukkan ordo matriks A (m x n): ");
        scanf("%d %d", &rowsA, &colsA);
        printf("Masukkan ordo matriks B (m x n): ");
        scanf("%d %d", &rowsB, &colsB);
        if (isMultiplicationValid(colsA, rowsB))
        {
            float matriksA[rowsA][colsA], matriksB[rowsB][colsB], matriksC[rowsA][colsB];
            printf("Masukkan elemen matriks A:\n");
            inputMatriks(rowsA, colsA, matriksA);
            printf("Masukkan elemen matriks B:\n");
            inputMatriks(rowsB, colsB, matriksB);
            printf("Matriks A:\n");
            displayMatriks(rowsA, colsA, matriksA);
            printf("Matriks B:\n");
            displayMatriks(rowsB, colsB, matriksB);
            hitungPerkalianMatriks(rowsA, colsA, rowsB, colsB, matriksA, matriksB, matriksC);
            printf("Hasil perkalian matriks A dan B:\n");
            displayMatriks(rowsA, colsB, matriksC);
            printf("Tekan enter untuk melanjutkan...");
            getch();
            return;
        }
        else
        {
            printf("Ordo matriks tidak sesuai!\n");
            printf("Silakan masukkan ordo matriks yang sesuai!\n");
            printf("Tekan enter untuk melanjutkan...");
            getch();
            continue;
        }
    }
}


void TransposeMatriks()
{
    /* Kamus Data */
    int rowsA, colsA;
    bool isValid = true;
    /*Algoritma*/
    while (isValid == true)
    {
        system("cls");
        printf("\n============================================\n");
        printf("          TRANSPOSE MATRIKS           \n");
        printf("============================================\n");
        printf("Masukkan ordo matriks A (m n): ");
        scanf("%d %d", &rowsA, &colsA);
        float matriksA[rowsA][colsA];
        float matriksHasil[colsA][rowsA];
        if (isTransposeValid(rowsA, colsA))
        {
            printf("Masukkan elemen matriks A:\n");
            inputMatriks(rowsA, colsA, matriksA);
            printf("Matriks A:\n");
            displayMatriks(rowsA, colsA, matriksA);
            hitungTransposeMatriks(rowsA, colsA, matriksA, matriksHasil);
            printf("Hasil transpose matriks A:\n");
            displayMatriks(colsA, rowsA, matriksHasil);
            printf("Tekan enter untuk melanjutkan...");
            getch();
            return;
        }
        else
        {
            printf("Ordo matriks tidak sesuai!\n");
            printf("Silakan masukkan ordo matriks yang sesuai!\n");
            printf("Tekan enter untuk melanjutkan...");
            getch();
            continue;
        }
    }
}

void hitungPenjumlahanMatriks(int rows, int cols, float matriksA[rows][cols], float matriksB[rows][cols], float matriksHasil[rows][cols])
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            matriksHasil[i][j] = matriksA[i][j] + matriksB[i][j];
        }
    }
}

void hitungPenguranganMatriks(int rows, int cols, float matriksA[rows][cols], float matriksB[rows][cols], float matriksHasil[rows][cols])
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            matriksHasil[i][j] = matriksA[i][j] - matriksB[i][j];
        }
    }
}

void hitungPerkalianMatriksxSkalar(int rows, int cols, float matriks[rows][cols], float skalar, float matriksHasil[rows][cols])
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            matriksHasil[i][j] = matriks[i][j] * skalar;
        }
    }
}

void hitungPerkalianMatriks(int rowsA, int colsA, int rowsB, int colsB, float matriksA[rowsA][colsA], float matriksB[rowsB][colsB], float matriksHasil[rowsA][colsB])
{
    int i, j, k;
    float temp;
    for (i = 0; i < rowsA; i++)
    {
        for (j = 0; j < colsB; j++)
        {
            temp = 0;
            for (k = 0; k < colsA; k++)
            {
                temp += matriksA[i][k] * matriksB[k][j];
            }
            matriksHasil[i][j] = temp;
        }
    }
}

void hitungTransposeMatriks(int rows, int cols, float matriks[rows][cols], float matriksHasil[cols][rows])
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            matriksHasil[j][i] = matriks[i][j];
        }
    }
}

void inputMatriks(int rows, int cols, float matriks[rows][cols])
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        printf("Masukkan elemen matriks baris %d (dipisahkan oleh spasi): ", i + 1);

        for (j = 0; j < cols; j++)
        {
            scanf("%f", &matriks[i][j]);
        }
    }
}


void displayMatriks(int rows, int cols, float matriks[rows][cols])
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        printf("|");
        for (j = 0; j < cols; j++)
        {	
        	if (matriks[i][j] == -0)
                matriks[i][j] = 0;
            printf("   %.2f   ", matriks[i][j]);
        }
        printf("|\n");
    }
}
