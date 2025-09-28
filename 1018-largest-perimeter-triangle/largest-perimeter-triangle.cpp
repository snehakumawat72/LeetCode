class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // Sort in descending order to try largest combinations first
        sort(nums.begin(), nums.end(), greater<int>());
        
        // Try every consecutive triplet
        for (int i = 0; i < nums.size() - 2; i++) {
            int a = nums[i];     // largest side
            int b = nums[i + 1]; // middle side  
            int c = nums[i + 2]; // smallest side
            
            // Check triangle inequality: sum of two smaller sides > largest side
            if (b + c > a) {
                return a + b + c;
            }
        }
        
        // No valid triangle found
        return 0;
    }
};