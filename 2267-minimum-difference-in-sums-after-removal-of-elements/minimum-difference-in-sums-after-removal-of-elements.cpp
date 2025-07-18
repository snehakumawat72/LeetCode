class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        
        // For each position i, we'll compute:
        // left_min[i] = sum of smallest n elements from nums[0..i]
        // right_max[i] = sum of largest n elements from nums[i..2*n-1]
        
        vector<long long> left_min(3 * n);
        vector<long long> right_max(3 * n);
        
        // Compute left_min using a max heap
        priority_queue<int> max_heap;
        long long sum = 0;
        
        // Initialize with first n elements
        for (int i = 0; i < n; i++) {
            max_heap.push(nums[i]);
            sum += nums[i];
        }
        left_min[n - 1] = sum;
        
        // Process remaining elements for left part
        for (int i = n; i < 2 * n; i++) {
            max_heap.push(nums[i]);
            sum += nums[i];
            
            // Remove the largest element if we have more than n elements
            sum -= max_heap.top();
            max_heap.pop();
            
            left_min[i] = sum;
        }
        
        // Compute right_max using a min heap
        priority_queue<int, vector<int>, greater<int>> min_heap;
        sum = 0;
        
        // Initialize with last n elements
        for (int i = 2 * n; i < 3 * n; i++) {
            min_heap.push(nums[i]);
            sum += nums[i];
        }
        right_max[2 * n] = sum;
        
        // Process remaining elements for right part (going backwards)
        for (int i = 2 * n - 1; i >= n; i--) {
            min_heap.push(nums[i]);
            sum += nums[i];
            
            // Remove the smallest element if we have more than n elements
            sum -= min_heap.top();
            min_heap.pop();
            
            right_max[i] = sum;
        }
        
        // Find minimum difference
        long long min_diff = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; i++) {
            min_diff = min(min_diff, left_min[i] - right_max[i + 1]);
        }
        
        return min_diff;
    }
};