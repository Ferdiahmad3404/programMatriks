/*
Program		: matriks.h
Deskripsi	: Header untuk ADT Matriks
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

#ifndef matriks_h
#define matriks_h

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

void displayMenu();
// Operasi Aritmatika Matriks
void displayMenuOperasiMatriks();
void displayMenuOperasiPerkalianMatriks();
void MenuOperasiMatriks();
void PenjumlahanMatriks();
void PenguranganMatriks();
void PerkalianMatriks();
void PerkalianMatriksScalar();
void PerkalianMatriksMatriks();
void TransposeMatriks();
bool isAdditionSubtractionValid(int rowsA, int colsA, int rowsB, int colsB);
bool isMultiplicationValid(int colsA, int rowsB);
bool isTransposeValid(int rows, int cols);
void inputMatriks(int rows, int cols, float matriks[rows][cols]);
void displayMatriks(int rows, int cols, float matriks[rows][cols]);
void hitungPenjumlahanMatriks(int rows, int cols, float matriksA[rows][cols], float matriksB[rows][cols], float matriksHasil[rows][cols]);
void hitungPenguranganMatriks(int rows, int cols, float matriksA[rows][cols], float matriksB[rows][cols], float matriksHasil[rows][cols]);
void hitungPerkalianMatriksxSkalar(int rows, int cols, float matriks[rows][cols], float skalar, float matriksHasil[rows][cols]);
void hitungPerkalianMatriks(int rowsA, int colsA, int rowsB, int colsB, float matriksA[rowsA][colsA], float matriksB[rowsB][colsB], float matriksHasil[rowsA][colsB]);
void hitungTransposeMatriks(int rows, int cols, float matriks[rows][cols], float matriksHasil[cols][rows]);

// Matriks Eselon Baris
void MenuEselonBaris();
void MenuEselonBarisTereduksi();
void gaussJordan(int rows, int cols, float matriks[rows][cols]);
void gaussElimination(int rows, int cols, float matriks[rows][cols]);
void ConvertSegitigaAtas(int rows, int cols, float matriks[rows][cols]);
// Matriks Invers
void MenuInversMatriks();
void hitungInversMatriks2x2(float matriks[2][2], float matriksHasil[2][2]);
void hitungInversMatriksAdjoin(int ordo, float matriks[ordo][ordo], float matriksHasil[ordo][ordo]);
void hitungInversMatriksOBE(int ordo, float matriks[ordo][ordo]);
void displayMenuInversMatriks2x2();
void displayMenuInversMatriks3x3();

// Determinan Matriks
void displayMenuDeterminanMatriks();
void displayMenuDeterminanMatriks2x2();
void displayMenuDeterminanMatriks3x3();
void MenuDeterminanMatriks();
bool isUpperTriangular(int ordo, float matriks[ordo][ordo]);
bool isLowerTriangular(int ordo, float matriks[ordo][ordo]);
float hitungDeterminanMatriks2x2(float matriks[2][2]);
float hitungDeterminanMatriksOBE(int ordo, float matriks[ordo][ordo]);
float sarrus(float matriks[3][3]);
float hitungDeterminanMatriksKofaktor(int ordo, float matriks[ordo][ordo]);
void potongMatriks(int ordo, float matriks[ordo][ordo], int excludeRow, int excludeCol, float submatrix[ordo - 1][ordo - 1]);

// Adjoin Matriks
void MenuAdjoinMatriks();
void hitungAdjoinMatriks(int ordo, float matriks[ordo][ordo], float matriksHasil[ordo][ordo]);
float hitungKofaktor(int ordo, float matriks[ordo][ordo], int row, int col);

// sistem persamaan linear
void displayMenuSPL();
void MenuSPL();
void splMetodeInverse(int jml_persamaan, int jml_variabel, float matriks[jml_persamaan][jml_variabel + 1]);
void splMetodeCramer(int jml_persamaan, int jml_variabel, float matriks[jml_persamaan][jml_variabel + 1]);
void cekSolusiSPL(int jml_persamaan, int jml_variabel, float matriks[jml_persamaan][jml_variabel + 1]);
bool cekSolusiBanyak(int jml_persamaan, int jml_variabel, float matriks[jml_persamaan][jml_variabel + 1]);
bool cekTakPunyaSolusi(int jml_persamaan, int jml_variabel, float matriks[jml_persamaan][jml_variabel + 1]);
#endif