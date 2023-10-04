#include <stdio.h>
#include <stdbool.h>

int main() {
    int column = 3, row = 2;
    double matriks[2][3] = {{0, 0, 1}, {1, 1, 1}};
    printf("%f\n", matriks[1][0]);
    bool takHinggaBanyak = false;
    printf("%d\n", column);
    double array[column];
    int counter;
    for (int i = 0; i < row ; i++)
    {
        counter = 0;
        //insialisasi array
        for (int j = 0; j < column ; j++)
        {
        array[j] = matriks[i][j];
        //   printf("%f\n", matriks[i][j]);
        printf("%f\n", array[j]);
        }
        //pengecekan
        for (int j = 0; j < column ; j++)
        {
          if (array[j] == 0)
          {
            printf("tes\n");
            counter++;
          }
        }
        if (counter == column)
        {
            printf("solusi banyak\n");
            takHinggaBanyak = true;
            return takHinggaBanyak;
        }
    }

    bool takPunyaSolusi = true;
    for (int i = 0; i < row ; i++)
    {
        for (int j = 0; j < column ; j++)
        {
            if (j != column-1)
            {
                if (matriks[i][j] != 0) {
                bool takPunyaSolusi = false;
                }
            }
            else
            {
                if (matriks[i][j] != 0)
                {
                    printf("tak punya solusi\n");
                    bool takPunyaSolusi = true;
                    return takPunyaSolusi;
                }
                
            }
            
        }
    }

}

// int takPunyaSolusi() {
//     int row, column;
//     bool takPunyaSolusi = true;
//     for (int i = 0; i < row ; i++)
//     {
//         int array[column] = {0};
//         for (int j = 0; j < column ; j++)
//         {
//             if (j != column-1)
//             {
//                 if (matriks[i][j] != 0) {
//                 bool takPunyaSolusi = false;
//                 }
//             }
//             else
//             {
//                 if (matriks[i][j] != 0)
//                 {
//                     bool takPunyaSolusi = true;
//                 }
                
//             }
            
//         }
//     }
// }