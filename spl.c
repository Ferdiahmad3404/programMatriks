/*
Program		: spl.c
Deskripsi	: Body prototype ADT SPL Matriks
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

void MenuSPL()
{
    /*Kamus Data*/
    int jml_persamaan, jml_variabel, pilihan;
    bool valid;
    char lagi;
    /*Algoritma*/
    system("cls");
    printf("\n============================================\n");
    printf("                SPL MATRIKS                \n");
    printf("==============================================\n");
    printf("Catatan:\n");
    printf("Jumlah Variable ini berlaku untuk semua persamaan.\nJika ada variabel yang sebenarnya tidak ada maka beri nilai 0 saja\n");
    printf("Masukkan jumlah persamaan: ");
    scanf("%d", &jml_persamaan);
    printf("Masukkan jumlah variabel: ");
    scanf("%d", &jml_variabel);
    float matriks[jml_persamaan][jml_variabel + 1];
    printf("Masukkan persamaan baris: \n");
    inputMatriks(jml_persamaan, jml_variabel + 1, matriks);
    printf("Matriks A: \n");
    displayMatriks(jml_persamaan, jml_variabel + 1, matriks);
    valid = false;
    lagi = 'y';
    while (valid == false && (lagi == 'y' || lagi == 'Y'))
    {
        displayMenuSPL();
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            printf("\n**************************\n");
            gaussJordan(jml_persamaan, jml_variabel + 1, matriks);
            printf("Hasil OBE: \n");
            displayMatriks(jml_persamaan, jml_variabel + 1, matriks);
            cekSolusiSPL(jml_persamaan, jml_variabel, matriks);
            break;
        case 2:
            splMetodeInverse(jml_persamaan, jml_variabel, matriks);
            break;
        case 3:
            splMetodeCramer(jml_persamaan, jml_variabel, matriks);
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
    printf("\n**************************\n");
    printf("Tekan enter untuk melanjutkan...");
    getch();
    return;
}

void splMetodeInverse(int jml_persamaan, int jml_variabel, float matriks[jml_persamaan][jml_variabel + 1])
{
    /*Kamus Data*/
    float matriksA[jml_persamaan][jml_variabel];
    float matriksB[jml_persamaan][1];

    /*Algoritma*/
    if (jml_persamaan != jml_variabel)
    {
        printf("Matriks tidak memiliki invers, maka solusi spl tidak bisa menggunakan metode ini\n");
        return;
    }
    else
    {
        for (int i = 0; i < jml_persamaan; i++)
        {
            for (int j = 0; j < jml_variabel; j++)
            {
                matriksA[i][j] = matriks[i][j];
            }
        }

        for (int i = 0; i < jml_persamaan; i++)
        {
            matriksB[i][0] = matriks[i][jml_variabel];
        }

        printf("Matriks A: \n");
        displayMatriks(jml_persamaan, jml_variabel, matriksA);
        printf("Matriks B: \n");
        displayMatriks(jml_persamaan, 1, matriksB);

        hitungInversMatriksOBE(jml_persamaan, matriksA);
        printf("Matriks A Invers: \n");
        displayMatriks(jml_persamaan, jml_variabel, matriksA);
        float matriksX[jml_persamaan][1];
        hitungPerkalianMatriks(jml_persamaan, jml_variabel, jml_persamaan, 1, matriksA, matriksB, matriksX);
        printf("Matriks Hasil: \n");
        displayMatriks(jml_persamaan, 1, matriksX);
        cekSolusiSPL(jml_persamaan, jml_variabel, matriksX);
    }
}

void splMetodeCramer(int jml_persamaan, int jml_variabel, float matriks[jml_persamaan][jml_variabel + 1])
{
    /*Kamus Data*/
    float matriksA[jml_persamaan][jml_variabel];
    float matriksB[jml_persamaan][1];
    float matriksX[jml_persamaan][jml_variabel];
    float detA, det;
    float solusi1, solusi2, solusi3;

    /*Algoritma*/
    if (jml_persamaan != jml_variabel)
    {
        printf("Matriks tidak memiliki determinan, maka solusi spl tidak bisa menggunakan metode ini\n");
        return;
    }
    else
    {
        for (int i = 0; i < jml_persamaan; i++)
        {
            for (int j = 0; j < jml_variabel; j++)
            {
                matriksA[i][j] = matriks[i][j];
            }
        }

        for (int i = 0; i < jml_persamaan; i++)
        {
            matriksB[i][0] = matriks[i][jml_variabel];
        }

        printf("Matriks A: \n");
        displayMatriks(jml_persamaan, jml_variabel, matriksA);
        printf("Matriks B: \n");
        displayMatriks(jml_persamaan, 1, matriksB);

        detA = sarrus(matriksA);
        if (detA == 0){
            printf("Sistem persamaan linear tidak memiliki solusi.\n");
            return;
        }
        printf("Determinan A: %.2f\n", detA);

        // Isi Matriks X1
        for (int i = 0; i < jml_persamaan; i++)
        {
            for (int j = 0; j < jml_variabel; j++)
            {
                matriksX[i][j] = matriksA[i][j];
            }
        }

        for (int j = 0; j < jml_variabel; j++)
        {
            matriksX[j][0] = matriksB[j][0];
        }

        det = sarrus(matriksX);
        if (det == 0){
            printf("Sistem persamaan linear tidak memiliki solusi.\n");
            return;
        }
        solusi1 = det / detA;

        // Isi Matriks X2
        for (int i = 0; i < jml_persamaan; i++)
        {
            for (int j = 0; j < jml_variabel; j++)
            {
                matriksX[i][j] = matriksA[i][j];
            }
        }

        for (int j = 0; j < jml_variabel; j++)
        {
            matriksX[j][1] = matriksB[j][0];
        }

        det = sarrus(matriksX);
        if (det == 0){
            printf("Sistem persamaan linear tidak memiliki solusi.\n");
            return;
        }
        solusi2 = det / detA;

        // Isi Matriks X3
        for (int i = 0; i < jml_persamaan; i++)
        {
            for (int j = 0; j < jml_variabel; j++)
            {
                matriksX[i][j] = matriksA[i][j];
            }
        }

        for (int j = 0; j < jml_variabel; j++)
        {
            matriksX[j][2] = matriksB[j][0];
        }

        det = sarrus(matriksX);
        if (det == 0){
            printf("Sistem persamaan linear tidak memiliki solusi.\n");
            return;
        }
        solusi3 = det / detA;

        printf("Solusi SPL: \n");
        printf("x1 = %.2f\n", solusi1);
        printf("x2 = %.2f\n", solusi2);
        printf("x3 = %.2f\n", solusi3);
    }
}

void cekSolusiSPL(int jml_persamaan, int jml_variabel, float matriks[jml_persamaan][jml_variabel + 1])
{
    if (cekSolusiBanyak(jml_persamaan, jml_variabel, matriks))
    {
        printf("Sistem persamaan linear memiliki Solusi tak hingga banyak\n");
    }
    else if (cekTakPunyaSolusi(jml_persamaan, jml_variabel, matriks))
    {
        printf("Sistem persamaan linear memiliki tidak memiliki solusi\n");
    }
    else
    {
        printf("Sistem persamaan linear memiliki satu solusi:\n");
        for (int i = 0; i < jml_persamaan; i++)
        {
            printf("x%d = %.2f\n", i + 1, matriks[i][jml_variabel]);
        }
    }
}

bool cekSolusiBanyak(int jml_persamaan, int jml_variabel, float matriks[jml_persamaan][jml_variabel + 1])
{
    bool takHinggaBanyak = false;
    float array[jml_variabel + 1];
    int counter;
    for (int i = 0; i < jml_persamaan; i++)
    {
        counter = 0;
        // insialisasi array
        for (int j = 0; j < jml_variabel + 1; j++)
        {
            array[j] = matriks[i][j];
        }
        // pengecekan
        for (int j = 0; j < jml_variabel + 1; j++)
        {
            if (array[j] == 0)
            {
                counter++;
            }
        }
        if (counter == jml_variabel + 1)
        {
            takHinggaBanyak = true;
            return takHinggaBanyak;
        }
    }
    return takHinggaBanyak;
}

bool cekTakPunyaSolusi(int jml_persamaan, int jml_variabel, float matriks[jml_persamaan][jml_variabel + 1])
{
    bool takPunyaSolusi = false;
    int counter;
    for (int i = 0; i < jml_persamaan; i++)
    {
        counter = 0;
        for (int j = 0; j < jml_variabel + 1; j++)
        {
            if (j != jml_variabel)
            {
                if (matriks[i][j] == 0)
                {
                    counter++;
                }
            }
            else
            {
                if (matriks[i][j] != 0 && counter == jml_variabel)
                {
                    bool takPunyaSolusi = true;
                    return takPunyaSolusi;
                }
            }
        }
    }
    return takPunyaSolusi;
}
