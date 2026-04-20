/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 2 - Data Manipulation and Ekxternal Files
 *   Hari dan Tanggal    : Senin, 20 April 2026
 *   Nama (NIM)          : Nahidl Denhaq Syaha
 *   Nama File           : Soal 1.c
 *   Deskripsi           : Program mendeteksi data kosong, memulihkannya, dan menghitung nilai total setelah dipulihkan
 * 
 */


#include <stdio.h>
  
#define INVALID -1

int main () {
    int n;

    scanf("%d", &n);

    int arr1[n];
    int arr2[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }    

    for (int i = 0; i < n; i++) {
        arr2[n - i - 1] = arr1[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr2[i] == INVALID) {
            count++;
        }
    }
    if (count == n) {
        for (int i = 0; i < n; i++) {
            arr2[i] = 0;
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (arr2[i] == INVALID) {
                int j = 1;
                int atas;
                int bawh;
                while (j < n) {
                    if (i + j >= n - 1) {
                        atas = n - 1;
                    } else {
                        atas = i + j;
                    }
                    if (i - j <= 0) {
                        bawh = 0;
                    } else {
                        bawh = i - j;
                    }

                    if (arr2[atas] != INVALID && arr2[bawh] != INVALID) {
                        if ((arr2[atas] + arr2[bawh]) % 2 != 0) {
                            arr2[i] = (arr2[atas] + arr2[bawh] - 1)/2;
                        } else {
                            arr2[i] = (arr2[atas] + arr2[bawh])/2;
                        }
                        break;
                    } else if (arr2[atas] != INVALID) {
                        arr2[i] = arr2[atas];
                        break; 
                    } else if (arr2[bawh] != INVALID) {
                        arr2[i] = arr2[bawh];
                        break;
                    } 
                    j++;
                }
            }
        }
    }
    int sum = 0;

    for (int i = 0; i < n; i++) {
        arr1[i] = arr2[n - i - 1];
        sum = sum + arr1[i];
    }

    printf("RECOVERED");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr1[i]);
    }
    printf("\nMAX_SUM %d", sum);return 0;

    return 0;
}  
