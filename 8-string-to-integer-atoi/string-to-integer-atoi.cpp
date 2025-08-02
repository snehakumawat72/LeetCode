class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        
        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Step 2: Determine sign
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Step 3: Convert digits to integer
        long result = 0;  // Use long to detect overflow
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // Check for overflow before adding the digit
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        // Step 4: Apply sign and ensure within 32-bit range
        result *= sign;
        
        // Clamp to 32-bit signed integer range
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;
        
        return (int)result;
    }
};

// Alternative implementation with more explicit overflow checking
class Solution_Alternative {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        
        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Step 2: Determine sign
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Step 3: Convert digits to integer
        int result = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // Check for overflow
            // For positive: result > (INT_MAX - digit) / 10
            // For negative: result > (INT_MAX + 1 - digit) / 10 (since INT_MIN = -INT_MAX - 1)
            if (sign == 1) {
                if (result > (INT_MAX - digit) / 10) {
                    return INT_MAX;
                }
            } else {
                if (result > (INT_MAX - digit) / 10) {
                    return INT_MIN;
                }
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        return result * sign;
    }
};