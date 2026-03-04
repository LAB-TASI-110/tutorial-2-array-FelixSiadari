// 12S25043 - Felix Abdiel Siadari

#include <stdio.h>
#include <limits.h>
#include <float.h> // Diperlukan untuk DBL_MAX, nilai batas double

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    int min_val = INT_MAX;
    int max_val = INT_MIN;

    // Untuk rata-rata terendah, kita perlu mencari pasangan berurutan dengan jumlah terkecil.
    // Inisialisasi rata_rata_terendah dengan nilai floating point terbesar agar perbandingan pertama benar.
    double rata_rata_terendah = DBL_MAX; 

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
        }

        // Hitung rata-rata pasangan berurutan jika ada setidaknya dua elemen
        if (i >= 1) { // Mulai dari elemen kedua (indeks 1)
            // Konversi ke double sebelum perhitungan untuk menghindari integer truncation
            double current_avg = (double)(arr[i-1] + arr[i]) / 2.0; 
            if (current_avg < rata_rata_terendah) {
                rata_rata_terendah = current_avg;
            }
        }
    }

    printf("%d\n", min_val);
    printf("%d\n", max_val);
    
    // Menampilkan rata-rata terendah dengan 2 digit presisi
    // % .2f akan membulatkan ke 2 desimal
    if (n >= 2) { // Pastikan ada setidaknya 2 elemen untuk menghitung rata-rata
        printf("%.2f\n", rata_rata_terendah);
    } else {
        // Handle kasus jika n < 2, tidak bisa menghitung rata-rata pasangan
        // Dalam konteks soal ini, diasumsikan n >= 2 dari contoh input.
        // Bisa juga mencetak pesan error atau nilai default.
        // Untuk kesederhanaan, jika n<2, kita tidak mencetak rata-rata.
    }

    return 0;
}