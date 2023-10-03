/*
Program		: ui_matriks.c
Deskripsi	: UI prototype ADT Matriks
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
Angkatan    : 2022
Tanggal		: 25 September 2023
===============================================*/

#include "matriks.h"

void displayMenu()
{
    printf("==================================\n");
    printf("           MENU MATRIKS           \n");
    printf("==================================\n");
    printf("1. Operasi Aritmatika Matriks    \n");
    printf("2. Matriks Eselon Baris	Tereduksi\n");
    printf("3. Matriks Invers                \n");
    printf("4. Determinan Matriks            \n");
    printf("5. Sistem Persamaan Linear       \n");
    printf("99. Keluar                        \n");
    printf("==================================\n");
    printf("Pilih operasi : ");
}

void displayMenuOperasiMatriks()
{
    printf("\n============================================\n");
    printf("          MENU OPERASI ARITMATIKA MATRIKS   \n");
    printf("============================================\n");
    printf("1. Penjumlahan Matriks                     \n");
    printf("2. Pengurangan Matriks                     \n");
    printf("3. Perkalian Matriks                       \n");
    printf("4. Transpos Matriks                        \n");
    printf("99. Kembali ke Menu Utama                   \n");
    printf("============================================\n");
    printf("Pilih operasi aritmatika : ");
}

void displayMenuOperasiPerkalianMatriks()
{
    printf("\n============================================\n");
    printf("          MENU OPERASI PERKALIAN MATRIKS    \n");
    printf("============================================\n");
    printf("1. Perkalian Matriks dengan Skalar          \n");
    printf("2. Perkalian Matriks dengan Matriks         \n");
    printf("99. Kembali ke Menu Utama                   \n");
    printf("============================================\n");
    printf("Pilih operasi perkalian : ");
}
