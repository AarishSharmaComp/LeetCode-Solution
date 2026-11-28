class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // base case: both strings are empty
        dp[0][0] = true;

        // base case: pattern is empty but string is not
        for(int i = 1; i <= n; i++) {
            dp[i][0] = false;
        }

        // base case: string is empty but pattern is not
        for(int j = 1; j <= m; j++) {
            if(p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1]; // '*' can match the empty sequence
            } else {
                dp[0][j] = false; // non-* character cannot match the empty string
            }
        }

        // fill the dp array
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1]; // characters match or pattern has '?', move to the next pair
                } else if(p[j - 1] == '*') {
                    // '*' can match zero or more characters
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false; // characters don't match and pattern doesn't have '?' or '*'
                }
            }
        }

        return dp[n][m];
    }
};