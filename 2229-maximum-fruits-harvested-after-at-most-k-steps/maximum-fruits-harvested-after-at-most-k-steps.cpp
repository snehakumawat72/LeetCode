class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        
        // Precompute prefix sums for fruits reachable going left and right
        vector<int> leftSum(k + 1, 0);   // leftSum[i] = max fruits using exactly i steps going left
        vector<int> rightSum(k + 1, 0);  // rightSum[i] = max fruits using exactly i steps going right
        
        // Build leftSum array
        int leftTotal = 0;
        for (int i = n - 1; i >= 0; i--) {
            int pos = fruits[i][0];
            int amount = fruits[i][1];
            
            if (pos < startPos) {
                int steps = startPos - pos;
                if (steps <= k) {
                    leftTotal += amount;
                    leftSum[steps] = leftTotal;
                }
            }
        }
        
        // Forward fill leftSum (if we can reach position with x steps, 
        // we can reach all positions closer with x steps too)
        for (int i = 1; i <= k; i++) {
            leftSum[i] = max(leftSum[i], leftSum[i-1]);
        }
        
        // Build rightSum array
        int rightTotal = 0;
        for (int i = 0; i < n; i++) {
            int pos = fruits[i][0];
            int amount = fruits[i][1];
            
            if (pos > startPos) {
                int steps = pos - startPos;
                if (steps <= k) {
                    rightTotal += amount;
                    rightSum[steps] = rightTotal;
                }
            }
        }
        
        // Forward fill rightSum
        for (int i = 1; i <= k; i++) {
            rightSum[i] = max(rightSum[i], rightSum[i-1]);
        }
        
        // Check if there are fruits at starting position
        int startFruits = 0;
        for (auto& fruit : fruits) {
            if (fruit[0] == startPos) {
                startFruits = fruit[1];
                break;
            }
        }
        
        int maxHarvest = startFruits;
        
        // Try all combinations of left and right steps
        for (int leftSteps = 0; leftSteps <= k; leftSteps++) {
            // Case 1: Go left only
            maxHarvest = max(maxHarvest, startFruits + leftSum[leftSteps]);
            
            // Case 2: Go left first, then return and go right
            int remaining = k - 2 * leftSteps;  // Cost: leftSteps to go + leftSteps to return
            if (remaining >= 0) {
                int rightSteps = min(remaining, k);
                maxHarvest = max(maxHarvest, startFruits + leftSum[leftSteps] + rightSum[rightSteps]);
            }
        }
        
        // Try going right first, then left
        for (int rightSteps = 1; rightSteps <= k; rightSteps++) {
            int remaining = k - 2 * rightSteps;  // Cost: rightSteps to go + rightSteps to return
            if (remaining >= 0) {
                int leftSteps = min(remaining, k);
                maxHarvest = max(maxHarvest, startFruits + rightSum[rightSteps] + leftSum[leftSteps]);
            }
        }
        
        return maxHarvest;
    }
};

// Alternative cleaner implementation
class SolutionV2 {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int maxFruits = 0;
        
        // Find fruits at starting position
        for (auto& fruit : fruits) {
            if (fruit[0] == startPos) {
                maxFruits = fruit[1];
                break;
            }
        }
        
        // Try all possible left steps (0 to k)
        for (int leftSteps = 0; leftSteps <= k; leftSteps++) {
            int leftFruits = 0;
            int rightFruits = 0;
            
            // Calculate fruits going left
            int pos = startPos;
            int steps = leftSteps;
            for (int i = n - 1; i >= 0 && steps > 0; i--) {
                if (fruits[i][0] < startPos) {
                    int stepsNeeded = pos - fruits[i][0];
                    if (stepsNeeded <= steps) {
                        leftFruits += fruits[i][1];
                        steps -= stepsNeeded;
                        pos = fruits[i][0];
                    }
                }
            }
            
            // Calculate remaining steps for going right
            int remainingSteps = k - (leftSteps == 0 ? 0 : 2 * leftSteps);
            
            if (remainingSteps >= 0) {
                // Calculate fruits going right
                pos = startPos;
                steps = remainingSteps;
                for (int i = 0; i < n && steps > 0; i++) {
                    if (fruits[i][0] > startPos) {
                        int stepsNeeded = fruits[i][0] - pos;
                        if (stepsNeeded <= steps) {
                            rightFruits += fruits[i][1];
                            steps -= stepsNeeded;
                            pos = fruits[i][0];
                        }
                    }
                }
                
                maxFruits = max(maxFruits, maxFruits + leftFruits + rightFruits);
            }
        }
        
        return maxFruits;
    }
};

// Test function (not part of LeetCode solution)
#include <iostream>
#include <vector>
using namespace std;

void testSolution() {
    Solution sol;
    
    // Test case 1
    vector<vector<int>> fruits1 = {{2,8},{6,3},{8,6}};
    int result1 = sol.maxTotalFruits(fruits1, 5, 4);
    cout << "Test 1: " << result1 << " (expected: 9)" << endl;
    
    // Test case 2
    vector<vector<int>> fruits2 = {{0,9},{4,1},{5,7},{6,2},{7,4},{10,9}};
    int result2 = sol.maxTotalFruits(fruits2, 5, 4);
    cout << "Test 2: " << result2 << " (expected: 14)" << endl;
    
    // Test case 3
    vector<vector<int>> fruits3 = {{0,3},{6,4},{8,5}};
    int result3 = sol.maxTotalFruits(fruits3, 3, 2);
    cout << "Test 3: " << result3 << " (expected: 0)" << endl;
}