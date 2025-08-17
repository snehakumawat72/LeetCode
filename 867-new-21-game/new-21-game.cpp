class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // Edge case: if k is 0, Alice never draws and stays at 0
        if (k == 0) return 1.0;
        
        // Edge case: if k + maxPts - 1 <= n, Alice always wins
        // because the maximum she can get is k-1 + maxPts
        if (k + maxPts - 1 <= n) return 1.0;
        
        // dp[i] = probability of getting <= n points starting from i points
        vector<double> dp(n + maxPts + 1, 0.0);
        
        // Base cases: if we're between k and n (inclusive), we stop and win
        for (int i = k; i <= n; i++) {
            dp[i] = 1.0;
        }
        
        // For points > n, probability is 0 (already initialized)
        
        // Use sliding window to maintain sum of dp[i+1] to dp[i+maxPts]
        double windowSum = 0.0;
        
        // Initialize window sum for i = k-1
        for (int j = k; j < k + maxPts; j++) {
            windowSum += dp[j];
        }
        
        // Work backwards from k-1 to 0
        for (int i = k - 1; i >= 0; i--) {
            dp[i] = windowSum / maxPts;
            
            // Update window for next iteration (i-1)
            // Remove dp[i + maxPts] and add dp[i]
            if (i + maxPts < dp.size()) {
                windowSum -= dp[i + maxPts];
            }
            windowSum += dp[i];
        }
        
        return dp[0];
    }
};