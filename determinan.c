/*
Program		: determinan.c
Deskripsi	: Body prototype ADT Determinan Matriks
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

void MenuDeterminanMatriks()
{
    /*Kamus Data*/
    int ordo, pilihan;
    float determinan = 0;
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
    printf("Masukkan elemen matriks A: \n");
    inputMatriks(ordo, ordo, matriks);
    printf("Matriks A : \n");
    displayMatriks(ordo, ordo, matriks);
    switch (ordo)
    {
    case 1:
        printf("\n**************************\n");
        printf("Determinan matriks A adalah %.2f\n", matriks[0][0]);
        break;
    case 2:
        valid = false;
        lagi = 'y';
        while (valid == false && lagi == 'y')
        {
            displayMenuDeterminanMatriks2x2();
            scanf("%d", &pilihan);
            switch (pilihan)
            {
            case 1:
                printf("\n**************************\n");
                printf("det A = ad - bc\n");
                printf("det A = (%.2f * %.2f) - (%.2f * %.2f)\n", matriks[0][0], matriks[1][1], matriks[0][1], matriks[1][0]);
                determinan = hitungDeterminanMatriks2x2(matriks);
                printf("determinan matriks A adalah %.2f\n", determinan);
                break;
            case 2:
                determinan = hitungDeterminanMatriksOBE(ordo, matriks);
                printf("\n**************************\n");
                printf("Determinan matriks A adalah %.2f\n", determinan);
                break;
            default:
                printf("Pilihan tidak valid\n");
                valid = true;
                break;
            }
            if (valid)
            {
                valid = false;
            }
            else
            {
                printf("\n============================================\n");
                printf("Ingin menggunakan metode lain? (y/n) ");
                lagi = getch();
            }
        }
        break;
    default:
        valid = false;
        lagi = 'y';
        while (valid == false && lagi == 'y')
        {
            displayMenuDeterminanMatriks3x3();
            scanf("%d", &pilihan);
            switch (pilihan)
            {
            case 1:
                determinan = hitungDeterminanMatriksPerkalianElementer(ordo, matriks);
                printf("\n**************************\n");
                printf("Determinan matriks A adalah %.2f\n", determinan);
                break;
            case 2:
                determinan = hitungDeterminanMatriksOBE(ordo, matriks);
                printf("\n**************************\n");
                printf("Determinan matriks A adalah %.2f\n", determinan);
                break;
            case 3:
                determinan = hitungDeterminanMatriksKofaktor(ordo, matriks);
                printf("\n**************************\n");
                printf("Determinan matriks A adalah %.2f\n", determinan);
                break;
            default:
                printf("Pilihan tidak valid\n");
                valid = true;
                break;
            }
            if (valid)
            {
                valid = false;
            }
            else
            {
                printf("\n============================================\n");
                printf("Ingin menggunakan metode lain? (y/n) ");
                lagi = getch();
            }
        }
    }
    printf("\n============================================\n");
    printf("Tekan enter untuk melanjutkan...");
    getch();
}

float hitungDeterminanMatriks2x2(float matriks[2][2])
{
    /*Kamus Data*/
    float determinan;
    /*Algoritma*/
    determinan = (matriks[0][0] * matriks[1][1]) - (matriks[0][1] * matriks[1][0]);
    return determinan;
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

float hitungDeterminanMatriksPerkalianElementer(int ordo, float matriks[ordo][ordo])
{
    /*Kamus Data*/
    int i, j, counter, temp;
    float determinan = 0;
    float diagonal_satu = 0, diagonal_dua = 0;
    // Matriks augmented
    float augmentedMatrix[ordo][2 * ordo - 1];

    /*Algoritma*/
    // Inisialisasi matriks augmented
    for (int i = 0; i < ordo; i++)
    {
        for (int j = 0; j < ordo; j++)
        {
            augmentedMatrix[i][j] = matriks[i][j];
            // Matriks identitas di samping matriks A
            augmentedMatrix[i][j + ordo] = matriks[i][j];
        }
    }

    printf("\nMatriks Augmented :\n");
    displayMatriks(ordo, 2 * ordo - 1, augmentedMatrix);

    // Mencari determinan
    counter = 0;
    printf("\ndeterminan = ");
    printf("(");
    for (i = 0; i < ordo; i++)
    {
        temp = 1;
        printf("(");
        for (j = 0; j < ordo; j++)
        {
            temp *= augmentedMatrix[0 + j][0 + j + counter];
            printf("%.2f", augmentedMatrix[0 + j][0 + j + counter]);
            if (j < ordo - 1)
            {
                printf(" * ");
            }
        }
        printf(")");
        if (i < ordo - 1)
        {
            printf("+");
        }
        counter++;
        diagonal_satu += temp;
    }
    printf(") ");
    printf("- ");
    printf("(");
    counter = 0;
    for (i = 0; i < ordo; i++)
    {
        temp = 1;
        printf("(");
        for (j = 0; j < ordo; j++)
        {
            temp *= augmentedMatrix[0 + j][ordo - 1 - j + counter];
            printf("%.2f", augmentedMatrix[0 + j][ordo - 1 - j + counter]);
            if (j < ordo - 1)
            {
                printf(" * ");
            }
        }
        printf(")");
        if (i < ordo - 1)
        {
            printf("+");
        }
        counter++;
        diagonal_dua += temp;
    }
    printf("\ndeterminan = %.2f - %.2f", diagonal_satu, diagonal_dua);
    determinan = diagonal_satu - diagonal_dua;
    printf("\ndeterminan = %.2f\n", determinan);
    return determinan;
}

float hitungDeterminanMatriksKofaktor(int ordo, float matriks[ordo][ordo])
{
    float determinan = 0;

    if (ordo == 1)
    {
        return matriks[0][0];
    }

    for (int j = 0; j < ordo; j++)
    {
        float submatrix[ordo - 1][ordo - 1];
        potongMatriks(ordo, matriks, 0, j, submatrix);
        float determinan_temp = hitungDeterminanMatriksKofaktor(ordo - 1, submatrix);
        float cofactor = matriks[0][j] * pow(-1, 1 + j) * determinan_temp;
        determinan += cofactor;
    }
    return determinan;
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