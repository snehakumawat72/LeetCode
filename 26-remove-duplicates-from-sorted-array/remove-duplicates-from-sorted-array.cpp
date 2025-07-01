class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Handle edge case
        if (nums.empty()) {
            return 0;
        }
        
        // Method 1: Two-pointer approach (preferred)
        int writeIndex = 1; // Position to write the next unique element
        
        for (int readIndex = 1; readIndex < nums.size(); readIndex++) {
            // If current element is different from previous element
            if (nums[readIndex] != nums[readIndex - 1]) {
                nums[writeIndex] = nums[readIndex];
                writeIndex++;
            }
        }
        
        return writeIndex; // Number of unique elements
        
        
        // Method 2: Alternative approach (comparing with last unique element)
        /*
        int writeIndex = 0;
        
        for (int readIndex = 0; readIndex < nums.size(); readIndex++) {
            // If it's the first element or different from last unique element
            if (readIndex == 0 || nums[readIndex] != nums[writeIndex - 1]) {
                nums[writeIndex] = nums[readIndex];
                writeIndex++;
            }
        }
        
        return writeIndex;
        */
    }
};