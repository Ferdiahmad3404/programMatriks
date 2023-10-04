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

#include "matriks.h"

int main()
{

    int pilihan = 0;
    while (pilihan != 99)
    {
        system("cls");
        displayMenu();
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            MenuOperasiMatriks();
            break;
        case 2:
            MenuEselonMatriks();
            break;
        case 3:
            MenuInversMatriks();
            break;
        case 4:
            MenuDeterminanMatriks();
            break;
        case 5:
            MenuAdjoinMatriks();
            break;
        case 6:
            MenuSPL();
            break;
        case 99:
            system("cls");
            printf("Terima kasih telah menggunakan program ini!\n");
            exit(1);
            break;
        default:
            system("cls");
            printf("Pilihan tidak tersedia!\n");
            break;
        }
    }

    return 0;
}