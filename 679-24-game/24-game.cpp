class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }
    
private:
    const double EPS = 1e-6;
    
    bool solve(vector<double>& nums) {
        if (nums.size() == 1) {
            return abs(nums[0] - 24.0) < EPS;
        }
        
        // Try all pairs of numbers
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                double a = nums[i], b = nums[j];
                
                // Remove the two numbers we're operating on
                vector<double> remaining;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) {
                        remaining.push_back(nums[k]);
                    }
                }
                
                // Try all possible operations between a and b
                vector<double> results = {
                    a + b,    // addition
                    a - b,    // subtraction
                    b - a,    // subtraction (reverse)
                    a * b     // multiplication
                };
                
                // Division (check for zero)
                if (abs(b) > EPS) results.push_back(a / b);
                if (abs(a) > EPS) results.push_back(b / a);
                
                // For each result, recursively solve with remaining numbers
                for (double result : results) {
                    remaining.push_back(result);
                    if (solve(remaining)) {
                        return true;
                    }
                    remaining.pop_back();
                }
            }
        }
        
        return false;
    }
};