// 12S25043 - Felix Siadari

#include <stdio.h> // Diperlukan untuk fungsi input/output seperti scanf dan printf
#include <limits.h> // Diperlukan untuk INT_MAX dan INT_MIN, nilai batas integer

int main() {
    int n; // Variabel untuk menyimpan jumlah bilangan yang akan dimasukkan
    
    // Membaca input pertama: nilai n
    scanf("%d", &n); 

    // Mendeklarasikan array untuk menyimpan n bilangan bulat
    // Ukuran array ditentukan secara dinamis setelah n diketahui.
    // Jika compiler tidak mendukung VLA (Variable Length Array), 
    // alternatifnya adalah menggunakan alokasi memori dinamis dengan malloc.
    // Namun, untuk tugas sederhana ini, VLA seringkali diterima.
    int arr[n]; 

    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan nilai integer terbesar
                          // Agar setiap input yang valid pasti lebih kecil dari ini
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan nilai integer terkecil
                          // Agar setiap input yang valid pasti lebih besar dari ini

    // Loop untuk membaca n bilangan bulat dan mencari nilai min/max
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Membaca setiap bilangan ke dalam array
        
        // Memperbarui nilai minimum jika ditemukan yang lebih kecil
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        
        // Memperbarui nilai maksimum jika ditemukan yang lebih besar
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Menampilkan nilai terkecil dan terbesar
    printf("%d\n", min_val);
    printf("%d\n", max_val);

    return 0; // Menandakan program berakhir dengan sukses
}