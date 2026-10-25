#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector<vector<bool>> dp(
            m + 1, vector<bool>(n + 1, false)
        );

        //empty string matches an empty pattern
        dp[0][0] = true;

        // pattern handle a*, a*b*, a*b*c*
        for (int j = 2; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j-2];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                //char match / patter has '.'
                if (p[j-1] == s[i-1] ||p[j-1] == '.') {

                    dp[i][j] = dp[i-1][j-1];
                    
                }

                //pattern has '*'
                else if (p[j-1] == '*') {
                    // opt 1 use 0 times
                    dp[i][j] = dp[i][j-2];

                    // op2 use 1/more
                    char prev = p[j-2];

                    if (prev == '.' || prev == s[i-1]) {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};