class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1000000007;
        
        // dp[i] = number of ways to make sum i
        vector<long long> dp(n + 1, 0);
        dp[0] = 1; // Base case: one way to make sum 0
        
        // Try each positive integer starting from 1
        for (int num = 1; ; num++) {
            long long power = 1;
            // Calculate num^x
            for (int i = 0; i < x; i++) {
                power *= num;
            }
            
            // If power exceeds n, no point in continuing
            if (power > n) break;
            
            // Update dp array backwards to avoid using updated values
            // For each possible sum from n down to power
            for (int sum = n; sum >= power; sum--) {
                dp[sum] = (dp[sum] + dp[sum - power]) % MOD;
            }
        }
        
        return (int)dp[n];
    }
};