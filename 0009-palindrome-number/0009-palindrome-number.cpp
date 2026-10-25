class Solution {
public:
    bool isPalindrome(int x) {
        // neg num and num ending in 0
        // can't be palindromes, except 0 itself.
        if (x < 0 || (x% 10 == 0 && x != 0)) {
            return false;
        }

        int reversed = 0;

        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // even digits: x ==  reversed
        // odd digits : remove the middle digit from reversed
        return x == reversed || x == reversed/ 10;
    }
};