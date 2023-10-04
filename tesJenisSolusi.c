#include <stdio.h>

int main() {
    int n; // Jumlah persamaan
    printf("Masukkan jumlah persamaan: ");
    scanf("%d", &n);

    // Inisialisasi variabel untuk menghitung variabel bebas dan pengecualian
    int variabelBebas = 0;
    int pengecualian = 0;

    printf("Masukkan koefisien dan konstanta setiap persamaan (misal: 'a b c' untuk ax + by = c):\n");

    for (int i = 0; i < n; i++) {
        double a, b, c;
        printf("Persamaan %d: ", i + 1);
        scanf("%lf %lf %lf", &a, &b, &c);

        if (a == 0 && b == 0 && c != 0) {
            pengecualian = 1;
            break; // Ini adalah kasus SPL yang tidak memiliki solusi
        } else if (a == 0 && b == 0 && c == 0) {
            variabelBebas++;
        }
    }

    if (pengecualian) {
        printf("SPL tidak memiliki solusi (termasuk ke poin 3).\n");
    } else if (variabelBebas > 0) {
        printf("SPL memiliki solusi tak terbatas (termasuk ke poin 2).\n");
    } else {
        printf("SPL memiliki solusi unik (termasuk ke poin 1).\n");
    }

    return 0;
}
