class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result; // stores all distinct ORs of subarrays
        unordered_set<int> current; // stores ORs of subarrays ending at current position
        
        for (int num : arr) {
            unordered_set<int> next;
            next.insert(num);
            for (int val : current) {
                next.insert(val | num);
            }
            current = move(next);
            for (int val : current) {
                result.insert(val);
            }
        }
        
        return (int)result.size();
    }
};
