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
Kelas		: 1B
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
#endif