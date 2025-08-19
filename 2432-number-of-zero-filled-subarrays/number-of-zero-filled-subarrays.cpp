class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        int consecutiveZeros = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                consecutiveZeros++;
            } else {
                // End of zero sequence, calculate subarrays
                if (consecutiveZeros > 0) {
                    result += (long long)consecutiveZeros * (consecutiveZeros + 1) / 2;
                    consecutiveZeros = 0;
                }
            }
        }
        
        // Handle case where array ends with zeros
        if (consecutiveZeros > 0) {
            result += (long long)consecutiveZeros * (consecutiveZeros + 1) / 2;
        }
        
        return result;
    }
};