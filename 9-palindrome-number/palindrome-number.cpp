class Solution {
public:
    bool isPalindrome(int x) {
     if(x<0) return false;  

     int org=x;
     int rev=0;
     while(x>0){
        int ld=x%10;
         // Check for overflow before multiplying by 10
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && ld > 7)) {
                return false;  // If reversing would overflow, it can't be a palindrome
            }
            
        rev= rev*10+ld;
        x=x/10;   
     }
    return rev==org;
    //TC- o(log10n)  SC-O(1)
       
    }
};