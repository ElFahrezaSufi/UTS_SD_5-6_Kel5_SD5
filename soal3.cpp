#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;

class Graf {
private:
    int jumlahTitik;                      // Menyimpan jumlah vertex (titik) dalam graf
    vector<vector<int>> matriksKeterhubungan; // Menyimpan hubungan antar titik dalam bentuk matriks

public:
    // Konstruktor untuk membuat graf dengan jumlah titik tertentu
    Graf(int banyakTitik) {
        jumlahTitik = banyakTitik;
        matriksKeterhubungan.resize(banyakTitik, vector<int>(jumlahTitik, 0));
    }

    // Fungsi untuk menambahkan hubungan (edge) antara dua titik
    void tambahHubungan(int i, int j) {
        if (i >= 0 && i < jumlahTitik && j >= 0 && j < jumlahTitik) {
            matriksKeterhubungan[i][j] = 1; // Hubungan dari i ke j
            matriksKeterhubungan[j][i] = 1; // Karena graf tidak berarah, tambahkan juga dari j ke i
        }
    }

    // Fungsi utama untuk menghitung penyebaran virus pada hari ke-K
    void hitungPenyebaranVirus(int titikAwal, int hariK) {
        vector<int> jarak(jumlahTitik, -1);  // Menyimpan "hari terinfeksi" tiap titik (-1 artinya belum terinfeksi)
        queue<int> antrianTitik;             // Antrian BFS untuk simulasi penyebaran virus

        // Titik awal langsung diset sebagai terinfeksi di hari ke-0
        jarak[titikAwal] = 0;
        antrianTitik.push(titikAwal);

        // Proses BFS — mensimulasikan penyebaran virus dari titik ke titik tetangga
        while (!antrianTitik.empty()) {
            int titikSekarang = antrianTitik.front();
            antrianTitik.pop();

            // Mengecek semua tetangga dari titikSekarang
            for (int i = 0; i < jumlahTitik; i++) {
                // Jika ada hubungan dan titik i belum terinfeksi
                if (matriksKeterhubungan[titikSekarang][i] == 1 && jarak[i] == -1) {
                    jarak[i] = jarak[titikSekarang] + 1; // Hari infeksi dihitung dari induknya + 1
                    antrianTitik.push(i);                // Masukkan ke antrian untuk disebarkan selanjutnya
                }
            }
        }

        // Menyimpan titik-titik yang terinfeksi tepat pada hari ke-K
        vector<int> terinfeksiHariK;
        for (int i = 0; i < jumlahTitik; i++) {
            if (jarak[i] == hariK) {
                terinfeksiHariK.push_back(i);
            }
        }

        // Mengurutkan hasil agar tampil rapi
        sort(terinfeksiHariK.begin(), terinfeksiHariK.end());

        // Menampilkan hasil penyebaran
        cout << "Titik yang terinfeksi pada hari ke-" << hariK << ": ";
        if (terinfeksiHariK.empty()) {
            cout << "(TIDAK ADA)" << endl;
        } else {
            for (int titik : terinfeksiHariK) {
                cout << titik << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V, E; // V = jumlah vertex, E = jumlah edge
    
    cout << "Masukkan jumlah Vertex dan edge: ";
    if (!(cin >> V >> E)) return 0;
    
    Graf graf(V);
    int u, v;
    
    cout << "Masukkan " << E << " pasangan hubungan pertemanan (u v):\n";
    for (int i = 0; i < E; ++i) {
        if (!(cin >> u >> v)) return 0;
        graf.tambahHubungan(u, v);
    }
    
    int titikAwal, hariK; 
    char pilihan;
    
    cout << "\n========================================\n";
    cout << "Graf berhasil dibuat. Mulai simulasi penyebaran virus.\n";
    
    do {
        // Input node awal dan hari ke-K yang ingin disimulasikan
        cout << "\nNode awal dan hari terinfeksi: ";
        if (!(cin >> titikAwal >> hariK)) break;

        graf.hitungPenyebaranVirus(titikAwal, hariK);
        
        // Pilihan untuk mengulang simulasi
        cout << "Ingin menguji lagi? (y/t): ";
        cin >> pilihan;
        
    } while (pilihan == 'y' || pilihan == 'Y');
    
    cout << "Program selesai. Terima kasih.\n";
    
    return 0;
}

/* PENJELASAN LOGIKA PROGRAM 

1  Representasi Graf:
   - Saya menggunakan **Matriks Keterhubungan (Adjacency Matrix)** untuk menyimpan siapa terhubung dengan siapa.
   - Matriks ini bersifat **simetris** karena hubungan pertemanan tidak berarah (A teman B berarti B juga teman A).

2️  Algoritma yang Dipakai:
   - Menggunakan **Breadth-First Search (BFS)**.
   - BFS cocok untuk menyimulasikan penyebaran virus karena berjalan "lapis demi lapis" — 
     persis seperti penyebaran harian dari satu titik ke tetangga terdekat.

3️  Mekanisme Perhitungan:
   - Vektor `jarak` menyimpan kapan (hari ke berapa) setiap titik terinfeksi.
   - `-1` berarti titik itu belum terinfeksi.
   - BFS dimulai dari `titikAwal` dengan jarak 0.
   - Setiap kali BFS berpindah ke tetangga, nilai `jarak` diisi `jarak[parent] + 1`.

4️  Output Akhir:
   - Setelah BFS selesai, semua titik yang `jarak[i] == hariK` dikumpulkan.
   - Jika tidak ada titik dengan jarak itu, berarti tidak ada yang terinfeksi di hari tersebut.
   - Hasil ditampilkan dalam urutan menaik.

*/
