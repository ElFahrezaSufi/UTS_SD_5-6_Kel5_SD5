#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;

class Graph {
private:
    int numberVertex;
    vector<vector<int>> adjMatrix; 

public:
    Graph(int banyakTititk) {
        numberVertex = banyakTititk;
        adjMatrix.resize(banyakTititk, vector<int>(numberVertex, 0));
    }

    void addEdge(int i, int j) {
        if (i >= 0 && i < numberVertex && j >= 0 && j < numberVertex) {
            adjMatrix[i][j] = 1; 
            adjMatrix[j][i] = 1; 
        }
    }

    void solveVirusSpread(int startVertex, int K) {
        vector<int> distance(numberVertex, -1); 
        queue<int> titikVisit; 

        distance[startVertex] = 0;
        titikVisit.push(startVertex);

        while (!titikVisit.empty()) {
            int currentVertex = titikVisit.front();
            titikVisit.pop();

            for (int i = 0; i < numberVertex; i++) {
                if (adjMatrix[currentVertex][i] == 1 && distance[i] == -1) {
                    
                    distance[i] = distance[currentVertex] + 1;
                    titikVisit.push(i);
                }
            }
        }
        
        vector<int> infected_on_K;
        for (int i = 0; i < numberVertex; i++) {
            if (distance[i] == K) {
                infected_on_K.push_back(i);
            }
        }

        sort(infected_on_K.begin(), infected_on_K.end());
        
        cout << "Node terinfeksi: ";
        if (infected_on_K.empty()) {
            cout << "(TIDAK ADA)" << endl;
        } else {
            for (int node : infected_on_K) {
                cout << node << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V, E; 
    
    cout << "Masukkan jumlah vertex dan edge: ";
    if (!(cin >> V >> E)) return 0;
    
    Graph graph(V);
    int u, v;
    
    cout << "Masukkan " << E << " hubungan pertemanan (u v):\n";
    for (int i = 0; i < E; ++i) {
        if (!(cin >> u >> v)) return 0;
        graph.addEdge(u, v);
    }
    
    int startNode, K; 
    char choice;
    
    cout << "\n========================================\n";
    cout << "Graf berhasil dibuat. Mulai pengujian S & K.\n";
    
    do {
        cout << "\nMasukkan Node Awal (S) dan Hari Terinfeksi (K): ";
        if (!(cin >> startNode >> K)) break;

        graph.solveVirusSpread(startNode, K);
        
        cout << "Ulangi pengujian? (y/t): ";
        cin >> choice;
        
    } while (choice == 'y' || choice == 'Y');
    
    cout << "Program selesai. Terima kasih.\n";
    
    return 0;
}

// Penjelasan Algoritma/Logika Penyelesaian

/*
* Logika Penyelesaian Soal Nomor 3 (Penyebaran Virus pada Hari ke-K)
* 1. Representasi Graf:
Saya menggunakan Matriks Ketetanggaan (adjMatrix) untuk menyimpan hubungan pertemanan, yang diimplementasikan di dalam kelas Graph. Graf ini tak berarah.
* 2. Pemilihan Algoritma:
Sesuai instruksi soal, saya menggunakan **Breadth-First Search (BFS)**. BFS sangat tepat karena mampu mensimulasikan penyebaran virus "hari demi hari" atau "level demi level" (menghitung jarak terpendek/shortest path), yang setara dengan Hari ke-K terinfeksi.
* 3. Implementasi Jarak (Hari Infeksi):
- Saya menggunakan vektor `distance` untuk melacak hari terinfeksi setiap orang; nilai `-1` berarti belum terinfeksi.
- Node awal (`startVertex`) diset sebagai Hari ke-0.
- Saat BFS: Jika node `v` adalah tetangga node `u` yang belum terinfeksi, `distance[v]` dihitung sebagai `distance[u] + 1`. Ini adalah kunci untuk menentukan hari terinfeksi tercepat.
* 4. Pengumpulan dan Output Hasil:
- Setelah BFS, saya mencari semua node `i` yang memiliki `distance[i]` TEPAT sama dengan Hari yang ditanyakan (`K`).
- Hasilnya diurutkan secara menaik menggunakan `std::sort`.
- Jika tidak ada yang terinfeksi pada Hari ke-K, saya mencetak "(TIDAK ADA)".
*/