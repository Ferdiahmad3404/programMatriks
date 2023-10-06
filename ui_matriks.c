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
Angkatan    : 2022/2023
Tanggal		: 25 September 2023
===============================================*/

#include "matriks.h"

void displayMenu()
{
    printf("==================================\n");
    printf("           MENU MATRIKS           \n");
    printf("==================================\n");
    printf("1. Operasi Aritmatika Matriks    \n");
    printf("2. Matriks Eselon Baris	         \n");
    printf("3. Matriks Eselon Baris	Tereduksi\n");
    printf("4. Matriks Invers                \n");
    printf("5. Determinan Matriks            \n");
    printf("6. Matriks Adjoin               \n");
    printf("7. Sistem Persamaan Linear       \n");
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

void displayMenuDeterminanMatriks2x2()
{
    printf("\n============================================\n");
    printf("            Metode Penyelesaian          \n");
    printf("==============================================\n");
    printf("1. Metode Perkalian Silang                    \n");
    printf("2. Metode OBE                                 \n");
    printf("==============================================\n");
    printf("Pilih metode penyelesaian: ");
}

void displayMenuDeterminanMatriks3x3()
{
    printf("\n============================================\n");
    printf("            Metode Penyelesaian          \n");
    printf("==============================================\n");
    printf("1. Metode Sarrus                               \n");
    printf("2. Metode OBE                                 \n");
    printf("3. Metode Ekspansi Kofaktor                   \n");
    printf("==============================================\n");
    printf("Pilih metode penyelesaian: ");
}

void displayMenuDeterminanMatriks()
{
    printf("\n============================================\n");
    printf("            Metode Penyelesaian          \n");
    printf("==============================================\n");
    printf("1. Metode OBE                                 \n");
    printf("2. Metode Ekspansi Kofaktor                   \n");
    printf("==============================================\n");
    printf("Pilih metode penyelesaian: ");
}

void displayMenuInversMatriks2x2()
{
    printf("\n============================================\n");
    printf("            Metode Penyelesaian          \n");
    printf("==============================================\n");
    printf("1. Metode Determinan                    \n");
    printf("2. Metode OBE                                 \n");
    printf("==============================================\n");
    printf("Pilih metode penyelesaian: ");
}

void displayMenuInversMatriks3x3()
{
    printf("\n============================================\n");
    printf("            Metode Penyelesaian          \n");
    printf("==============================================\n");
    printf("1. Metode Adjoin                    \n");
    printf("2. Metode OBE                                 \n");
    printf("==============================================\n");
    printf("Pilih metode penyelesaian: ");
}

void displayMenuSPL()
{
    printf("\n============================================\n");
    printf("            Metode Penyelesaian          \n");
    printf("==============================================\n");
    printf("1. Metode OBE                                 \n");
    printf("2. Metode Matriks Invers                      \n");
    printf("3. Metode Cramer                              \n");
    printf("==============================================\n");
    printf("Pilih metode penyelesaian: ");
}