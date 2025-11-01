// Soal 1: Circular Array Rotation (Rotasi Kiri)

#include <iostream>

using namespace std;

// Fungsi untuk melakukan rotasi kiri sebanyak d kali
void rotasiKiri(int arr[], int n, int d) {
    d = d % n; // antisipasi jika d > n

    for (int i = 0; i < d; i++) {
        // Simpan elemen pertama
        int temp = arr[0];

        // Geser semua elemen ke kiri satu posisi
        for (int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }

        // Pindahkan elemen pertama ke posisi terakhir
        arr[n - 1] = temp;
    }
}

int main() {
    int n, d;

    cout << "Masukkan jumlah elemen array: ";
    cin >> n;
    cout << "Masukkan jumlah rotasi kiri: ";
    cin >> d;

    int arr[n];
    cout << "Masukkan elemen-elemen array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Panggil fungsi rotasi
    rotasiKiri(arr, n, d);

    cout << "Array setelah rotasi kiri sebanyak " << d << " kali: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
-----------------------------------------------------------
Penjelasan Algoritma:
1. Program membaca jumlah elemen array (n) dan jumlah rotasi (d).
2. Fungsi rotasiKiri() melakukan rotasi kiri sebanyak d kali:
   - Simpan elemen pertama.
   - Geser semua elemen ke kiri satu posisi.
   - Pindahkan elemen pertama tadi ke posisi paling kanan.
3. Proses diulang sebanyak d kali untuk menghasilkan hasil akhir.
4. Operasi rotasi ini bersifat melingkar (circular array),
   sehingga elemen yang digeser keluar dari kiri akan muncul kembali di kanan.
-----------------------------------------------------------
Contoh:
Input:
n = 5
arr = [1, 2, 3, 4, 5]
d = 2

Output:
3 4 5 1 2
-----------------------------------------------------------
*/