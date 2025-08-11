class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1000000007;
        
        // Extract powers of 2 from n's binary representation
        vector<int> powers;
        int bit = 0;
        while (n > 0) {
            if (n & 1) {
                powers.push_back(1 << bit); // 2^bit
            }
            n >>= 1;
            bit++;
        }
        
        // For each query, calculate the product
        vector<int> answers;
        for (auto& query : queries) {
            int left = query[0];
            int right = query[1];
            
            // Instead of multiplying large numbers, we add exponents
            long long totalExponent = 0;
            for (int i = left; i <= right; i++) {
                // Find the exponent of powers[i]
                int power = powers[i];
                int exponent = 0;
                while ((1 << exponent) != power) {
                    exponent++;
                }
                totalExponent += exponent;
            }
            
            // Calculate 2^totalExponent mod MOD using fast exponentiation
            long long result = 1;
            long long base = 2;
            long long exp = totalExponent;
            
            while (exp > 0) {
                if (exp & 1) {
                    result = (result * base) % MOD;
                }
                base = (base * base) % MOD;
                exp >>= 1;
            }
            
            answers.push_back(result);
        }
        
        return answers;
    }
};