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

    int count = 0;

    scanf("%d", &n);

    int arr1[n];
    int arr2[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
        arr1[i] = arr2[i];
    }    

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
            int kiri = 0;
            int kann = 0;
            if (arr2[i] == INVALID) {
                while (arr2[i - kiri] == INVALID && kiri <= i) {
                    kiri++;
                }
                while (arr2[kann + i] == INVALID && kann <= n - i - 1) {
                    kann++;
                }
                if (arr2[i - kiri] != INVALID && arr2[kann + i] != INVALID) {
                    if ((arr2[i - kiri] + arr2[kann + i]) % 2 != 0) {
                        arr2[i] = (arr2[i - kiri] + arr2[kann + i] - 1)/2;
                    } else {
                        arr2[i] = (arr2[i - kiri] + arr2[kann + i])/2;
                    }
                } else if (arr2[i - kiri] != INVALID) {
                    arr2[i] = arr2[i - kiri];
                } else if (arr2[kann + i] != INVALID) {
                    arr2[i] = arr2[kann + i];
                }
            }
        }
    }
    
    int sum = 0;
    for (int i = 0; i < 0; i++)  {
        if(arr2[i] >= 0) {
            sum = sum + arr2[i];
        }
        arr1[i] = arr2[i];
    }
    if (sum == 0) {
        sum = arr1[0];
        for (int i = 1; i < n; i++) {
            if (sum > arr1[i]) {
                sum = arr1[i];
            }
        }
    }

    printf("RECOVERED");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr1[i]);
    }
    printf("\nMAX_SUM %d", sum);return 0;

    return 0;
}   
