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
Kelas		: 1B
Jurusan     : Teknik Komputer dan Informatika
Prodi       : D4 Teknik Informatika
Angkatan    : 2022/2023
Tanggal		: 25 September 2023
===============================================*/

#include "matriks.h"

void MenuSPL()
{
    /*Kamus Data*/
    int jml_persamaan, jml_variabel;
    /*Algoritma*/
    system("cls");
    printf("\n============================================\n");
    printf("                SPL MATRIKS                \n");
    printf("==============================================\n");
    printf("Masukkan jumlah persamaan: ");
    scanf("%d", &jml_persamaan);
    printf("Masukkan jumlah variabel: ");
    scanf("%d", &jml_variabel);
    float matriks[jml_persamaan][jml_variabel + 1];
    printf("Masukkan persamaan baris: \n");
    inputMatriks(jml_persamaan, jml_variabel + 1, matriks);
    printf("Matriks A: \n");
    displayMatriks(jml_persamaan, jml_variabel + 1, matriks);
    printf("\n**************************\n");
    hitungEselonMatriks(jml_persamaan, jml_variabel + 1, matriks);
    printf("Hasil OBE: \n");
    displayMatriks(jml_persamaan, jml_variabel + 1, matriks);
    cekSolusiSPL(jml_persamaan, jml_variabel, matriks);
    printf("\n**************************\n");
    printf("Tekan enter untuk melanjutkan...");
    getch();
    return;
}

void cekSolusiSPL(int jml_persamaan, int jml_variabel, float matriks[jml_persamaan][jml_variabel + 1]){
	if(cekSolusiBanyak(jml_persamaan, jml_variabel, matriks)) {
		printf("Solusi banyak\n");
	}
	else if(cekTakPunyaSolusi(jml_persamaan, jml_variabel, matriks)) {
		printf("Tidak punya solusi\n");
	}else{
		printf("Sistem persamaan linear memiliki satu solusi:\n");
        for (int i = 0; i < jml_persamaan; i++) {
            printf("x%d = %.2f\n", i + 1, matriks[i][jml_variabel]);
        }
	}
}

bool cekSolusiBanyak(int jml_persamaan, int jml_variabel, float matriks[jml_persamaan][jml_variabel + 1])
{
    bool takHinggaBanyak = false;
    float array[jml_variabel + 1];
    int counter;
    for (int i = 0; i < jml_persamaan ; i++)
    {
        counter = 0;
        //insialisasi array
        for (int j = 0; j < jml_variabel + 1 ; j++)
        {
        array[j] = matriks[i][j];
        }
        //pengecekan
        for (int j = 0; j < jml_variabel + 1 ; j++)
        {
          if (array[j] == 0)
          {
            counter++;
          }
        }
        if (counter == jml_variabel + 1)
        {
            printf("solusi banyak\n");
            takHinggaBanyak = true;
            return takHinggaBanyak;
        }
    }
    return takHinggaBanyak;

}

bool cekTakPunyaSolusi(int jml_persamaan, int jml_variabel, float matriks[jml_persamaan][jml_variabel + 1]){
	bool takPunyaSolusi = false;
	int counter;
    for (int i = 0; i < jml_persamaan ; i++)
    {
    	counter = 0;
        for (int j = 0; j < jml_variabel + 1 ; j++)
        {
            if (j != jml_variabel)
            {
                if (matriks[i][j] == 0) {
                counter++;
                }
            }
            else
            {
                if (matriks[i][j] != 0 && counter == jml_variabel)
                {
                    printf("tak punya solusi\n");
                    bool takPunyaSolusi = true;
                    return takPunyaSolusi;
                }
            }
        }
    }
    return takPunyaSolusi;
}
