#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    // Using a simple array/vector instead of unordered_map is faster due to contiguous memory (O(1) lookup)
    const vector<string> digitToChar = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(int i, string& curStr, const string& digits, vector<string>& res) {
        if (i == digits.length()) {
            res.push_back(curStr);
            return;
        }
        
        // Convert char digit to int index (e.g., '2' - '0' = 2)
        int digit = digits[i] - '0'; 
        
        for (char c : digitToChar[digit]) {
            curStr.push_back(c);                 // 1. Choose: Add char to the end of the shared string
            backtrack(i + 1, curStr, digits, res); // 2. Explore: Recurse without making copies
            curStr.pop_back();                  // 3. Unchoose: Backtrack by removing it (O(1))
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        
        // Optimization: Pre-allocate space in the result vector to prevent reallocation resizing overhead
        int totalCombinations = 1;
        for (char d : digits) {
            totalCombinations *= digitToChar[d - '0'].length();
        }
        res.reserve(totalCombinations);
        
        string curStr = "";
        // Pre-allocate internal string buffer capacity to avoid runtime string resizing
        curStr.reserve(digits.length()); 
        
        backtrack(0, curStr, digits, res);
        return res;
    }
};
