#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> frequencyMap;
        
        // Count the frequency of each number in the array
        for (int num : arr) {
            frequencyMap[num]++;
        }
        
        int maxLucky = -1;
        
        // Iterate through the frequency map to find lucky numbers
        for (const auto& entry : frequencyMap) {
            int num = entry.first;
            int freq = entry.second;
            
            if (num == freq) {
                if (num > maxLucky) {
                    maxLucky = num;
                }
            }
        }
        
        return maxLucky;
    }
};