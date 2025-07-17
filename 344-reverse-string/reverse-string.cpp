class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s, 0,s.size()-1);}

      void reverse(vector<char>& s, int left, int right){
        if(left>=right) return;
        swap(s[left],s[right]);
        reverse(s, ++left, --right);
       
    }
};