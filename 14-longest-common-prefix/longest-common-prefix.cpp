class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        
        // Use the first string as reference
        string prefix = strs[0];
        
        // Compare with each subsequent string
        for (int i = 1; i < strs.size(); i++) {
            // Reduce the prefix until it matches the beginning of current string
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                
                // If prefix becomes empty, no common prefix exists
                if (prefix.empty()) {
                    return "";
                }
            }
        }
        
        return prefix;
    }
};