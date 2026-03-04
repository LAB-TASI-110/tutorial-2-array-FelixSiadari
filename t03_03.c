// 12S25043 - Felix Abdiel Siadari

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    int min_val = INT_MAX;
    int max_val = INT_MIN;

    double rata_rata_terendah = DBL_MAX;
    // Variabel baru untuk rata-rata tertinggi
    double rata_rata_tertinggi = DBL_MIN; // Inisialisasi dengan nilai floating point terkecil

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
        }

        if (i >= 1) { // Butuh setidaknya 2 elemen untuk rata-rata pasangan
            double current_avg = (double)(arr[i-1] + arr[i]) / 2.0; 
            
            if (current_avg < rata_rata_terendah) {
                rata_rata_terendah = current_avg;
            }
            
            // Logika untuk rata-rata tertinggi
            if (current_avg > rata_rata_tertinggi) {
                rata_rata_tertinggi = current_avg;
            }
        }
    }

    printf("%d\n", min_val);
    printf("%d\n", max_val);
    
    if (n >= 2) {
        printf("%.2f\n", rata_rata_terendah);
        // Menampilkan rata-rata tertinggi
        printf("%.2f\n", rata_rata_tertinggi);
    }

    return 0;
}
