class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            // If it's an opening bracket, push it onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            // If it's a closing bracket
            else {
                // Check if stack is empty (no matching opening bracket)
                if (st.empty()) {
                    return false;
                }
                
                char top = st.top();
                st.pop();
                
                // Check if the closing bracket matches the opening bracket
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        
        // Stack should be empty if all brackets are properly matched
        return st.empty();
    }
};