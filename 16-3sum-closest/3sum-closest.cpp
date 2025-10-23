class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2]; // initial guess

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                
                // If this sum is closer to target, update
                if (abs(target - sum) < abs(target - closestSum)) {
                    closestSum = sum;
                }

                if (sum == target) {
                    return sum; // perfect match
                } else if (sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        return closestSum;
        
    }
};