class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        // Numbers ending with 0 (except 0 itself) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        // Reverse only half of the number to avoid overflow
        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }
        
        // For even number of digits: x == reversedHalf
        // For odd number of digits: x == reversedHalf / 10 (ignore middle digit)
        return x == reversedHalf || x == reversedHalf / 10;
    }
};