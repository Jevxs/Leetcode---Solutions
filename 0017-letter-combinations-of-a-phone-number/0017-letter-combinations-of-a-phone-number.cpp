#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    vector<string> res;
    // Map digits to corresponding characters
    unordered_map<char, string> digitToChar = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, 
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, 
        {'8', "tuv"}, {'9', "wxyz"}
    };

    void backtrack(int i, string curStr, const string& digits) {
        // Base case: if current string length matches digits length
        if (curStr.length() == digits.length()) {
            res.push_back(curStr);
            return;
        }
        
        // Loop through all characters corresponding to the current digit
        for (char c : digitToChar[digits[i]]) {
            backtrack(i + 1, curStr + c, digits);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        res.clear(); // Clear results for multiple test cases
        
        if (!digits.empty()) {
            backtrack(0, "", digits);
        }
        
        return res;
    }
};
