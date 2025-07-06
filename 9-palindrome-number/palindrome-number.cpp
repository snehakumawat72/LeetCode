class Solution {
public:
    bool isPalindrome(int x) {
       
        //check for negative number
        if(x<0)  return false;

         //new method converting into string
        string s = to_string(x);
       int left=0;
       int right=s.size()-1;
       
       while(left<=right){
        if(s[left]!= s[right]) {
        
            return false;
            
        }
        right--;
        left++;
       }
       return true;
       
    }
};