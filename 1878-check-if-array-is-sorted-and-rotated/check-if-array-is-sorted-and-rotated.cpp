

class Solution {
public:
    bool check(vector<int>& nums) {
        int countDrops = 0;
        int n = (int)nums.size();

        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            int next = nums[(i + 1) % n];

            // Check if current element is greater than the next element
            if (curr > next) {
                countDrops++;
                // More than one drop means not sorted & rotated
                if (countDrops > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};
