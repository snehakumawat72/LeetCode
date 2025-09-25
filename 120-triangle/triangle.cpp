class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // Create a DP array, starting with the bottom row
        vector<int> dp = triangle[n - 1];
        
        // Work from bottom to top
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                // For position (i,j), we can come from (i+1,j) or (i+1,j+1)
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        
        return dp[0];
    }
};