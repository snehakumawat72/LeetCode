class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // Step 1: Count frequency of each element
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Find the maximum frequency
        int maxFreq = 0;
        for (const auto& pair : freq) {
            maxFreq = max(maxFreq, pair.second);
        }
        
        // Step 3: Count total elements with maximum frequency
        int totalCount = 0;
        for (const auto& pair : freq) {
            if (pair.second == maxFreq) {
                totalCount += pair.second;
            }
        }
        
        return totalCount;
    }
};