#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Kita ingin memproses array yang lebih pendek sebagai nums1 untuk mengoptimalkan Binary Search
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int totalKiri = (m + n + 1) / 2; // Jumlah elemen di bagian kiri setelah digabung
        
        int low = 0, high = m;
        
        while (low <= high) {
            // Potong nums1 di tengah-tengah
            int i = low + (high - low) / 2;
            // Sisanya diambil dari nums2 agar jumlah elemen bagian kiri pas
            int j = totalKiri - i;
            
            // Tentukan nilai batas dari potongan nums1
            int kiri1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int kanan1 = (i == m) ? INT_MAX : nums1[i];
            
            // Tentukan nilai batas dari potongan nums2
            int kiri2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int kanan2 = (j == n) ? INT_MAX : nums2[j];
            
            // Cek apakah pembagian potongan sudah benar dan valid
            if (kiri1 <= kanan2 && kiri2 <= kanan1) {
                // Jika total elemen ganjil, median adalah nilai terbesar di bagian kiri
                if ((m + n) % 2 == 1) {
                    return max(kiri1, kiri2);
                }
                // Jika total elemen genap, median adalah rata-rata dua nilai tengah
                return (max(kiri1, kiri2) + min(kanan1, kanan2)) / 2.0;
            }
            // Jika potongan nums1 terlalu ke kanan, geser pencarian ke kiri
            else if (kiri1 > kanan2) {
                high = i - 1;
            }
            // Jika potongan nums1 terlalu ke kiri, geser pencarian ke kanan
            else {
                low = i + 1;
            }
        }
        
        return 0.0;
    }
};
