class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Find the maximum value in the array
        int maxVal = *max_element(nums.begin(), nums.end());
        
        int maxLength = 0;
        int currentLength = 0;
        
        // Find the longest contiguous sequence of maximum values
        for (int num : nums) {
            if (num == maxVal) {
                currentLength++;
                maxLength = max(maxLength, currentLength);
            } else {
                currentLength = 0;
            }
        }
        
        return maxLength;
    }
};