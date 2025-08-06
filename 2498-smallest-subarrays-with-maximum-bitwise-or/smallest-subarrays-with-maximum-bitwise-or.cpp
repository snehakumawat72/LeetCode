#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> answer(n);
        // To record the furthest index where bit b is found (initialized to -1)
        vector<int> bitPosition(31, -1);

        for (int i = n - 1; i >= 0; --i) {
            // For each bit, if set in nums[i], update its position
            for (int b = 0; b <= 30; ++b) {
                if ((nums[i] >> b) & 1) {
                    bitPosition[b] = i;
                }
            }
            
            // Determine how far we need to go to cover all bits
            int maxPos = i;
            for (int b = 0; b <= 30; ++b) {
                if (bitPosition[b] != -1) {
                    maxPos = max(maxPos, bitPosition[b]);
                }
            }
            
            answer[i] = maxPos - i + 1;
        }

        return answer;
    }
};
