
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        // dp[i][j] represents if s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Empty string matches empty pattern
        dp[0][0] = true;
        
        // Handle patterns like a*, a*b*, a*b*c* which can match empty string
        for (int j = 2; j <= n; j += 2) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                char sc = s[i - 1];  // current character in string
                char pc = p[j - 1];  // current character in pattern
                
                if (pc == '*') {
                    // '*' matches zero or more of the preceding element
                    char prev = p[j - 2];  // preceding character
                    
                    // Case 1: Use * as zero occurrences (ignore prev and *)
                    dp[i][j] = dp[i][j - 2];
                    
                    // Case 2: Use * as one or more occurrences
                    // Check if current string char matches the preceding pattern char
                    if (prev == '.' || prev == sc) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else if (pc == '.' || pc == sc) {
                    // Current characters match (either exact match or '.')
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // If no match and no '*', dp[i][j] remains false
            }
        }
        
        return dp[m][n];
    }
};