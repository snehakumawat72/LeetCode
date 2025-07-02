class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer-Moore Voting Algorithm
        int candidate = 0;
        int count = 0;
        
        // Find the candidate
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        
        // Since problem guarantees majority element exists, return candidate
        return candidate;
    }
};