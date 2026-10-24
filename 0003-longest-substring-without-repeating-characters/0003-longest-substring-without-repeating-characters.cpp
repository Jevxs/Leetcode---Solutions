class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Array untuk mencatat posisi terakhir dari setiap karakter (ASCII)
        // Diisi dengan -1 di awal karena kita belum melihat karakter apa pun
        vector<int> posisiTerakhir(256, -1);
        
        int panjangMaksimal = 0;
        int awalJendela = 0; // Batas kiri jendela kita
        
        // Loop menggunakan pointer 'akhirJendela' sebagai batas kanan jendela
        for (int akhirJendela = 0; akhirJendela < s.length(); akhirJendela++) {
            char karakterSekarang = s[akhirJendela];
            
            // Jika karakter ini sudah pernah dilihat DAN posisinya ada di dalam jendela kita saat ini
            if (posisiTerakhir[karakterSekarang] >= awalJendela) {
                // Geser batas kiri jendela ke satu langkah setelah posisi karakter kembar yang lama
                awalJendela = posisiTerakhir[karakterSekarang] + 1;
            }
            
            // Catat posisi paling baru dari karakter ini
            posisiTerakhir[karakterSekarang] = akhirJendela;
            
            // Hitung panjang jendela sekarang, dan bandingkan dengan rekor terpanjang sebelumnya
            int panjangJendelaSekarang = akhirJendela - awalJendela + 1;
            panjangMaksimal = max(panjangMaksimal, panjangJendelaSekarang);
        }
        
        return panjangMaksimal;
    }
};
