class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int n = s.length();
        
        // Process the string in chunks of size k
        for (int i = 0; i < n; i += k) {
            string group = "";
            
            // Add characters from the original string
            for (int j = i; j < i + k && j < n; j++) {
                group += s[j];
            }
            
            // If this is the last group and it's incomplete, fill it
            while (group.length() < k) {
                group += fill;
            }
            
            result.push_back(group);
        }
        
        return result;
    }
};