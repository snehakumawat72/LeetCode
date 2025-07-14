class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array for optimization
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int half = (total + 1) / 2; // +1 handles both odd and even cases
        
        int left = 0, right = m;
        
        while (left <= right) {
            // Partition nums1 at position i
            int i = (left + right) / 2;
            // Partition nums2 at position j such that left side has 'half' elements
            int j = half - i;
            
            // Get boundary elements
            int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRight1 = (i == m) ? INT_MAX : nums1[i];
            
            int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRight2 = (j == n) ? INT_MAX : nums2[j];
            
            // Check if we found the correct partition
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Found the correct partition
                if (total % 2 == 0) {
                    // Even number of elements - median is average of two middle elements
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    // Odd number of elements - median is the max of left side
                    return max(maxLeft1, maxLeft2);
                }
            }
            // Need to adjust partition
            else if (maxLeft1 > minRight2) {
                // Too many elements from nums1, move left
                right = i - 1;
            } else {
                // Too few elements from nums1, move right
                left = i + 1;
            }
        }
        
        return 0.0; // Should never reach here with valid input
    }
};

/*
Algorithm Explanation:

1. **Binary Search Approach**: Instead of merging arrays, we use binary search 
   to find the correct partition point.

2. **Partition Strategy**: We partition both arrays such that:
   - Left side has exactly (m+n+1)/2 elements
   - All elements on left ≤ all elements on right
   - maxLeft1 ≤ minRight2 and maxLeft2 ≤ minRight1

3. **Median Calculation**:
   - If total elements is even: median = (max(left side) + min(right side)) / 2
   - If total elements is odd: median = max(left side)

4. **Edge Cases**:
   - Use INT_MIN/INT_MAX for out-of-bounds elements
   - Ensure nums1 is smaller array for optimization

Time Complexity: O(log(min(m,n))) which satisfies O(log(m+n))
Space Complexity: O(1)

Example walkthrough for nums1=[1,3], nums2=[2]:
- m=2, n=1, total=3, half=2
- Try i=1: partition nums1 at [1|3], nums2 at [2|]
- maxLeft1=1, minRight1=3, maxLeft2=2, minRight2=∞
- Check: 1≤∞ ✓, 2≤3 ✓ → Valid partition
- Odd total → median = max(1,2) = 2
*/