#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    queue<string> normal;
    queue<string> darurat;

    for (int i = 0; i < N; i++) {
        string perintah, nama;
        cin >> perintah;

        if (perintah == "DATANG") {
            cin >> nama;
            normal.push(nama);
        } 
        else if (perintah == "DARURAT") {
            cin >> nama;
            darurat.push(nama);
        } 
        else if (perintah == "LAYANI") {
            if (!darurat.empty()) {
                cout << darurat.front() << endl;
                darurat.pop();
            } 
            else if (!normal.empty()) {
                cout << normal.front() << endl;
                normal.pop();
            } 
            else {
                cout << "TIDAK ADA PASIEN" << endl;
            }
        }
    }

    return 0;
}


// Penjelasan Algoritma:
// Program ini mensimulasikan sistem antrian rumah sakit dengan dua jenis antrian:
// Antrian normal → pasien biasa.
// Antrian darurat → pasien dengan kondisi darurat (prioritas lebih tinggi).

// Program ini menggunakan Queue dengan prinsip FIFO (First In, First Out):
// Elemen pertama yang masuk akan dilayani lebih dulu.

// Langkah-langkah:
// 1. Masukkan jumlah perintah yang akan dimasukkan

// 2. Perintah = "DATANG"
//      Artinya ada pasien normal datang, maka nama pasien dimasukkan ke antrian normal.
// 3. Perintah = "DARURAT"
//      Artinya ada pasien darurat datang, maka nama pasien dimasukkan ke antrian darurat.

// 4. Perintah = "LAYANI"
//      Artinya dokter melayani pasien berikutnya, dengan aturan:
//      Jika ada pasien darurat, layani dari darurat dulu.
//      Jika tidak ada pasien darurat, baru layani dari normal.

// Input dan Output sudah sesuai dengan Format dari soal.
