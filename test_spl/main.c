/*
Program		: main_matriks.c
Deskripsi	: Driver / main program untuk ADT Matriks
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

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

void MenuSPLCremer();
void inputMatriks(int rows, int cols, float matriks[rows][cols]);
void displayMatriks(int rows, int cols, float matriks[rows][cols], float hasil[cols]);
void hitungSetiapDeterminan(int rows, int cols, float matriks[rows][cols], float hasil[cols], float determinanCremer[cols]);
bool isUpperTriangular(int ordo, float matriks[ordo][ordo]);
bool isLowerTriangular(int ordo, float matriks[ordo][ordo]);
float hitungDeterminanMatriksOBE(int ordo, float matriks[ordo][ordo]);
void potongMatriks(int ordo, float matriks[ordo][ordo], int excludeRow, int excludeCol, float submatrix[ordo - 1][ordo - 1]);

int main()
{
    MenuSPLCremer();

    return 0;
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
void inputHasil(int cols, float hasil[cols])
{
    for (int j = 0; j < cols; j++)
    {
        printf("Masukkan elemen matriks baris %d (dipisahkan oleh spasi): ", j + 1);
        scanf("%f", &hasil[j]);
    }
}

void displayMatriks(int rows, int cols, float matriks[rows][cols], float hasil[cols])
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        printf("|");
        for (j = 0; j < cols; j++)
        {
            printf("   %.2f   ", matriks[i][j]);
        }
        printf("|");
        printf("  %.2f\n",hasil[i]);
    }
}

void potongMatriks(int ordo, float matriks[ordo][ordo], int excludeRow, int excludeCol, float submatrix[ordo - 1][ordo - 1])
{
    int subRow = 0, subCol = 0;

    for (int i = 0; i < ordo; i++)
    {
        if (i != excludeRow)
        {
            for (int j = 0; j < ordo; j++)
            {
                if (j != excludeCol)
                {
                    submatrix[subRow][subCol] = matriks[i][j];
                    subCol++;
                }
            }
            subRow++;
            subCol = 0;
        }
    }
}

void MenuSPLCremer(){
    /*Kamus Data*/
    int ordo, pilihan;
    float determinan = 0;
    float determinanCremer[ordo];
    bool valid;
    char lagi;
    /*Algoritma*/
    system("cls");
    printf("\n============================================\n");
    printf("                DETERMINAN MATRIKS                \n");
    printf("==============================================\n");
    printf("Masukkan ordo matriks bujur sangkar: ");
    scanf("%d", &ordo);
    float matriks[ordo][ordo];
    float hasil[ordo];
    printf("Masukkan elemen matriks A: \n");
    inputMatriks(ordo, ordo, matriks);
    printf("Masukkan hasil spl :\n");
    inputHasil(ordo, hasil);
    printf("Matriks A : \n");
    displayMatriks(ordo, ordo, matriks, hasil);
    hitungSetiapDeterminan(ordo, ordo, matriks, hasil, determinanCremer);
    determinan = hitungDeterminanMatriksOBE(ordo, matriks);
    printf("\n**************************\n");
    printf("Determinan matriks A adalah %.2f\n", determinan);
    for (int i = 0; i < ordo; i++)
    {
        printf("det[%d] %d\t",i + 1 ,determinanCremer[i]);
    }
    printf("\n============================================\n");
    printf("Tekan enter untuk melanjutkan...");
    getch();
}

void hitungSetiapDeterminan(int rows, int cols, float matriks[rows][cols], float hasil[cols], float determinanCremer[cols]){
    float matriksTemp[rows][cols];
    printf("tesss\n\n");
    for (int ordo = 0; ordo < rows; ordo++)
    {
        for (int i = 0; i < cols; i++)
        {   
            for (int j = 0; j < cols; j++)
            {
                matriksTemp[i][j] = matriks[i][j];
                if (j == ordo )
                {
                    matriksTemp[i][j] = hasil[i];
                }
            }
        }
        printf("Ini matriks ke %d \n", ordo + 1);
        displayMatriks(rows, cols, matriksTemp, hasil);
        determinanCremer[ordo] = hitungDeterminanMatriksOBE(rows, matriksTemp);
    }
    
       
    printf("tesss\n\n");
}

float hitungDeterminanMatriksOBE(int ordo, float matriks[ordo][ordo])
{
    /*Kamus Data*/
    float skalar_temp;

    /*Algoritma*/
    if (!isUpperTriangular(ordo, matriks) && !isLowerTriangular(ordo, matriks))
    {
        for (int k = 0; k < ordo; k++)
        {
            printf("\n**************************\n");
            for (int i = k + 1; i < ordo; i++)
            {
                skalar_temp = matriks[i][k] / matriks[k][k];
                printf("Langkah %d: b%d' = b%d - (%.2f) * b%d'\n", k + 1, i + 1, i + 1, skalar_temp, k + 1);
                for (int j = k; j < ordo; j++)
                {
                    matriks[i][j] = matriks[i][j] - (matriks[k][j] * skalar_temp);
                }
            }

            // Menampilkan Setiap Langkah
            if (k == ordo - 1)
                printf("Bentuk Matriks Segitiga Atas Adalah : \n\n");
            else
                printf("\nBentuk Matriks Segitiga Atas setelah Langkah %d:\n\n", k + 1);
            for (int a = 0; a < ordo; a++)
            {
                printf("| ");
                for (int b = 0; b < ordo; b++)
                {
                    if (matriks[a][b] == -0)
                        matriks[a][b] = 0; // Mengubah '-0' menjadi '0'
                    printf("   %.2f   ", matriks[a][b]);
                }
                printf("|\n\n");
            }
        }
    }
    else
    {
        if (isUpperTriangular(ordo, matriks))
            printf("Matriks sudah berbentuk segitiga atas, maka tidak perlu OBE\n");
        else
            printf("Matriks sudah berbentuk segitiga bawah, maka tidak perlu OBE\n");
    }
    // Menghitung Determinan
    float determinan = 1;
    for (int i = 0; i < ordo; i++)
    {
        determinan *= matriks[i][i];
    }
    return determinan;
}

bool isUpperTriangular(int ordo, float matriks[ordo][ordo])
{
    for (int i = 1; i < ordo; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (matriks[i][j] != 0.0)
            {
                return false; // Ada elemen di bawah diagonal utama yang tidak nol
            }
        }
    }
    return true; // Semua elemen di bawah diagonal utama adalah nol
}

bool isLowerTriangular(int ordo, float matriks[ordo][ordo])
{
    for (int i = 0; i < ordo; i++)
    {
        for (int j = i + 1; j < ordo; j++)
        {
            if (matriks[i][j] != 0.0)
            {
                return false; // Ada elemen di atas diagonal utama yang tidak nol
            }
        }
    }
    return true; // Semua elemen di atas diagonal utama adalah nol
}