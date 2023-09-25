/*
Program		: body_matriks.c
Deskripsi	: Body prototype ADT Matriks
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

void displayMenu()
{
    printf("==================================\n");
    printf("           MENU MATRIKS           \n");
    printf("==================================\n");
    printf("1. Operasi Aritmatika Matriks    \n");
    printf("2. Operasi Baris Elementer      \n");
    printf("3. Matriks Invers                \n");
    printf("4. Determinan Matriks            \n");
    printf("5. Sistem Persamaan Linear       \n");
    printf("0. Keluar                        \n");
    printf("==================================\n");
    printf("Pilih operasi (0-5): ");
}