

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        
        while(x != 0) {
            int digit = x % 10;
            x = x / 10;
            
            // Check for overflow before multiplying by 10
            // For positive numbers: check against INT_MAX
            if(rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) {
                return 0;
            }
            // For negative numbers: check against INT_MIN
            if(rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) {
                return 0;
            }
            
            rev = rev * 10 + digit;
        }
        
        return rev;
    }
};