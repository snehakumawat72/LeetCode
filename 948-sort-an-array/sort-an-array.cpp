class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
    
private:
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return; // Base case: single element or invalid range
        }
        
        int mid = left + (right - left) / 2; // Avoid overflow
        
        // Recursively sort both halves
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        
        // Merge the sorted halves
        merge(nums, left, mid, right);
    }
    
    void merge(vector<int>& nums, int left, int mid, int right) {
        // Create temporary arrays for left and right subarrays
        vector<int> leftArr(nums.begin() + left, nums.begin() + mid + 1);
        vector<int> rightArr(nums.begin() + mid + 1, nums.begin() + right + 1);
        
        int i = 0, j = 0, k = left;
        
        // Merge the two arrays back into nums[left..right]
        while (i < leftArr.size() && j < rightArr.size()) {
            if (leftArr[i] <= rightArr[j]) {
                nums[k] = leftArr[i];
                i++;
            } else {
                nums[k] = rightArr[j];
                j++;
            }
            k++;
        }
        
        // Copy remaining elements from leftArr, if any
        while (i < leftArr.size()) {
            nums[k] = leftArr[i];
            i++;
            k++;
        }
        
        // Copy remaining elements from rightArr, if any
        while (j < rightArr.size()) {
            nums[k] = rightArr[j];
            j++;
            k++;
        }
    }
};