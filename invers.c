/*
Program		: invers.c
Deskripsi	: Body prototype ADT Invers Matriks
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

void MenuInversMatriks()
{
    /*Kamus Data*/
    int ordo, pilihan;
    bool valid;
    char lagi;
    /*Algoritma*/
    system("cls");
    printf("\n============================================\n");
    printf("                INVERS MATRIKS                \n");
    printf("==============================================\n");
    printf("Masukkan ordo matriks bujur sangkar: ");
    scanf("%d", &ordo);
    float matriks[ordo][ordo];
    float matrisInvers[ordo][ordo];
    printf("Masukkan elemen matriks A: \n");
    inputMatriks(ordo, ordo, matriks);
    printf("Matriks A: \n");
    displayMatriks(ordo, ordo, matriks);
    switch (ordo)
    {
    case 1:
        printf("\n**************************\n");
        printf("Matriks Invers A: |%.2f|\n", 1 / matriks[0][0]);
        break;
    case 2:
        valid = false;
        lagi = 'y';
        while (valid == false && lagi == 'y')
        {
            displayMenuInversMatriks2x2();
            scanf("%d", &pilihan);
            switch (pilihan)
            {
            case 1:
                hitungInversMatriks2x2(matriks, matrisInvers);
                printf("\n**************************\n");
                printf("Matriks Invers A: \n");
                displayMatriks(ordo, ordo, matrisInvers);
                break;
            case 2:
                hitungInversMatriksOBE(ordo, matriks);
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
            displayMenuInversMatriks3x3();
            scanf("%d", &pilihan);
            switch (pilihan)
            {
            case 1:
                hitungInversMatriksAdjoin(ordo, matriks, matrisInvers);
                printf("\n**************************\n");
                printf("Matriks Invers A: \n");
                displayMatriks(ordo, ordo, matrisInvers);
                break;
            case 2:
                hitungInversMatriksOBE(ordo, matriks);
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
    return;
}

void hitungInversMatriks2x2(float matriks[2][2], float matriksHasil[2][2])
{
    float determinan = hitungDeterminanMatriks2x2(matriks);
    if (determinan != 0)
    {
        matriksHasil[0][0] = matriks[1][1] / determinan;
        matriksHasil[0][1] = -matriks[0][1] / determinan;
        matriksHasil[1][0] = -matriks[1][0] / determinan;
        matriksHasil[1][1] = matriks[0][0] / determinan;
    }
    else
    {
        printf("Matriks tidak memiliki invers\n");
    }
}

void hitungInversMatriksAdjoin(int ordo, float matriks[ordo][ordo], float matriksHasil[ordo][ordo])
{
    float determinan = hitungDeterminanMatriksKofaktor(ordo, matriks);
    if (determinan != 0)
    {
        hitungAdjoinMatriks(ordo, matriks, matriksHasil);
        for (int i = 0; i < ordo; i++)
        {
            for (int j = 0; j < ordo; j++)
            {
                matriksHasil[i][j] /= determinan;
            }
        }
    }
    else
    {
        printf("Matriks tidak memiliki invers\n");
    }
}

void hitungInversMatriksOBE(int ordo, float matriks[ordo][ordo])
{
    // Matriks augmented [A | I]
    float augmentedMatrix[ordo][2 * ordo];

    // Inisialisasi matriks augmented
    for (int i = 0; i < ordo; i++)
    {
        for (int j = 0; j < ordo; j++)
        {
            augmentedMatrix[i][j] = matriks[i][j];
            // Matriks identitas di samping matriks A
            augmentedMatrix[i][j + ordo] = (i == j) ? 1.0 : 0.0;
        }
    }

    printf("\nMatriks Augmented Sebelum OBE:\n");
    displayMatriks(ordo, 2 * ordo, augmentedMatrix);

    // Terapkan OBE
    hitungEselonMatriks(ordo, 2 * ordo, augmentedMatrix);

    // Cetak matriks baris tereduksi
    printf("\nMatriks Baris Tereduksi:\n");
    displayMatriks(ordo, 2 * ordo, augmentedMatrix);

    // Periksa apakah matriks invers ditemukan
    int inversible = 1;
    for (int i = 0; i < ordo; i++)
    {
        if (augmentedMatrix[i][i] != 1.0)
        {
            inversible = 0;
            break;
        }
    }

    if (inversible)
    {
        // Cetak matriks invers
        printf("\nMatriks Invers A:\n");
        for (int i = 0; i < ordo; i++)
        {
            printf("| ");
            for (int j = ordo; j < 2 * ordo; j++)
            {
                printf("   %.2f   ", augmentedMatrix[i][j]);
            }
            printf("|\n\n");
        }
    }
    else
    {
        printf("\nMatriks tidak memiliki invers.\n");
    }
}
